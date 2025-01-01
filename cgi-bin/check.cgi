#!/usr/local/bin/perl -w
#
# W3C HTML Validation Service
# A CGI script to retrieve and validate an HTML file
#
# Copyright 1995-1999 Gerald Oskoboiny <gerald@w3.org>
#
# This source code is available under the license at:
#     http://www.w3.org/Consortium/Legal/copyright-software
#
# $Id: check,v 1.46 1999/10/27 20:25:33 gerald Exp $

#
# Load modules
use strict;
use LWP::UserAgent;
use URI::Escape;
use CGI::Carp;
use CGI qw(:cgi -newstyle_urls -private_tempfiles);
use Text::Wrap;

#
# Define global constants
use constant TRUE  => 1;
use constant FALSE => 0;
use constant UNDEF => undef;

#############################################################################
# Constant definitions
#############################################################################

my $cvsrevision	= '$Revision: 1.46 $';
my $cvsdate	= '$Date: 1999/10/27 20:25:33 $';

my $logfile	= "/var/log/httpd/val-svc";

my $uri_def_uri	= "http://www.w3.org/Addressing/#terms";
my $faqloc	= "http://www.cs.duke.edu/~dsb/kgv-faq/";
my $faqerrloc	= "${faqloc}errors.html";
my $abs_svc_uri	= "http://validator.w3.org/";
my $rel_img_uri	= "/images/";
my $abs_img_uri	= "${abs_svc_uri}images/";
my $maintainer	= 'gerald@w3.org';

my $sgmlstuff	= "/usr/local/src/validator/htdocs/sgml-lib";
my $sp		= "/usr/local/bin/nsgmls";
my $nkf		= "/usr/local/bin/nkf";

my $sgmldecl	= "$sgmlstuff/REC-html40-19980424/HTML4.decl";
my $xhtmldecl	= "$sgmlstuff/PR-xhtml1-19990824/xhtml1.dcl";
my $xmldecl	= "$sgmlstuff/sp-1.3/pubtext/xml.dcl";

my $revision	= "version .80";

my ( $validity, $version, $document_type, %undef_frag,
    $effective_charset, $charsets_differ,
    $lastmod, $catalog, $command, @fake_errors,
    $guessed_doctype, $doctype, $line, $col, $type, $msg, $diff,
    $pos, $indent, $gifname, $alttext, $gifhw, $nicegifname, $pedanticflags,
    $pedantic_blurb, $level, $prevlevel, $i, $prevdata, $uri );

my $notice		= '';
			# "<p><strong>Note: This service will be ...</strong>";

umask( 022 );
my $weblint		= "/usr/bin/weblint";
my $html32_doctype	= qq{<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 3.2//EN">};
my $html40t_doctype	= qq{<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" "http://www.w3.org/TR/REC-html40/loose.dtd">};
my $html40f_doctype	= qq{<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Frameset//EN" "http://www.w3.org/TR/REC-html40/frameset.dtd">};
my $xhtmlt_doctype	= qq{<!DOCTYPE HTML PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"};
my $temp		= "/tmp/validate.$$";
my $lt			= "\020";
my $gt			= "\021";
my $gifborder		= " border=0";

my @options = qw(weblint pw outline ss sp noatt);

#############################################################################
# Array of FPIs -> plain text version strings
#############################################################################

my %pub_ids = (
    '-//IETF//DTD HTML Level 0//EN//2.0', 'HTML 0.0',
    '-//IETF//DTD HTML Strict Level 0//EN//2.0', 'Strict HTML 0.0',

    '-//IETF//DTD HTML 2.0 Level 1//EN', 'HTML 1.0',
    '-//IETF//DTD HTML 2.0 Strict Level 1//EN', 'Strict HTML 1.0',

    '-//IETF//DTD HTML 2.0 Strict//EN', 'Strict HTML 2.0',
    '-//IETF//DTD HTML 2.0//EN', 'HTML 2.0',
    '-//IETF//DTD HTML 2.1E//EN', 'HTML 2.1E',

  '-//AS//DTD HTML 3.0 asWedit + extensions//EN', 'HTML 3.0 (AdvaSoft version)',
    '-//IETF//DTD HTML 3.0//EN', 'HTML 3.0 (Beta)',
    '-//W3O//DTD W3 HTML Strict 3.0//EN//', 'Strict HTML 3.0 (Beta)',

    '-//Sun Microsystems Corp.//DTD HotJava HTML//EN', 'Hotjava-HTML',
'-//Sun Microsystems Corp.//DTD HotJava Strict HTML//EN', 'Strict Hotjava-HTML',
    '-//WebTechs//DTD Mozilla HTML 2.0//EN', 'Netscape-HTML',
    '-//Netscape Comm. Corp. Strict//DTD HTML//EN', 'Strict Netscape-HTML',
    '-//Microsoft//DTD Internet Explorer 2.0 HTML//EN', 'MSIE-HTML',
    '-//Microsoft//DTD Internet Explorer 2.0 HTML Strict//EN', 'Strict MSIE-HTML',
    '-//Microsoft//DTD Internet Explorer 3.0 HTML//EN', 'MSIE 3.0 HTML',
    '-//Microsoft//DTD Internet Explorer 3.0 HTML Strict//EN', 'Strict MSIE 3.0 HTML',
    '-//OReilly and Associates//DTD HTML Extended 1.0//EN', 'O\'Reilly HTML Extended v1.0',
    '-//OReilly and Associates//DTD HTML Extended Relaxed 1.0//EN', 'O\'Reilly HTML Extended Relaxed v1.0',

    '-//IETF//DTD HTML V2.2//EN', 'HTML 2.2',
    '-//W3C//DTD HTML 1996-01//EN', 'HTML 1996-01',
    '-//W3C//DTD HTML 3.2 Final//EN', '<a href="http://www.w3.org/TR/REC-html32">HTML 3.2</a>',
    '-//W3C//DTD HTML Experimental 970421//EN', '<a href="http://www.w3.org/TR/NOTE-html-970421.html">HTML 3.2 + Style</a>',
    '+//Silmaril//DTD HTML Pro v0r11 19970101//EN', '<a href="http://www.ucc.ie/doc/www/html/dtds/htmlpro.html">HTML Pro</a>',
    '-//Spyglass//DTD HTML 2.0 Extended//EN', 'Spyglass HTML 2.0 Extended',
    'http://www.w3.org/MarkUp/Cougar/Cougar.dtd', '<a href="http://www.w3.org/MarkUp/Cougar/">HTML Level "Cougar"</a>',
    '-//W3C//DTD HTML 4.0//EN', '<a href="http://www.w3.org/TR/REC-html40/">HTML 4.0</a> Strict',
    '-//W3C//DTD HTML 4.0 Transitional//EN', '<a href="http://www.w3.org/TR/REC-html40/">HTML 4.0</a> Transitional',
    '-//W3C//DTD HTML 4.0 Frameset//EN', '<a href="http://www.w3.org/TR/PR-html40/">HTML 4.0</a> Frameset',
    '-//W3C//DTD HTML 4.01//EN', '<a href="http://www.w3.org/TR/1999/PR-html40-19990824/">HTML 4.01</a> Strict',
    '-//W3C//DTD HTML 4.01 Transitional//EN', '<a href="http://www.w3.org/TR/1999/PR-html40-19990824/">HTML 4.01</a> Transitional',
    '-//W3C//DTD HTML 4.01 Frameset//EN', '<a href="http://www.w3.org/TR/1999/PR-html40-19990824/">HTML 4.01</a> Frameset',
    '-//W3C//DTD XHTML 1.0 Strict//EN', '<a href="http://www.w3.org/TR/1999/PR-xhtml1-19990824/">XHTML 1.0</a> Strict',
    '-//W3C//DTD XHTML 1.0 Transitional//EN', '<a href="http://www.w3.org/TR/1999/PR-xhtml1-19990824/">XHTML 1.0</a> Transitional',
    '-//W3C//DTD XHTML 1.0 Frameset//EN', '<a href="http://www.w3.org/TR/1999/PR-xhtml1-19990824/">XHTML 1.0</a> Frameset',
    'XML', '<a href="http://www.w3.org/TR/REC-xml">XML</a>'

);

#############################################################################
# Array of errors -> fragment identifiers for error explanation links
#############################################################################

my %frag = (
    'entity end not allowed in comment', 'unterm-comment-1',
    'name start character invalid only s and comment allowed in comment declaration', 'unterm-comment-2',
    'name character invalid only s and comment allowed in comment declaration', 'unterm-comment-2',
    'unknown declaration type FOO', 'bad-comment',
    'character FOO not allowed in attribute specification list', 'attr-char',
    'an attribute value must be a literal unless it contains only name characters', 'attr-quoted',
    'syntax of attribute value does not conform to declared value', 'bad-attr-char',
    'length of attribute value must not exceed LITLEN less NORMSEP', 'name-length',
    'element FOO undefined', 'undef-tag',
    'element FOO not allowed here', 'not-allowed',
    'there is no attribute FOO', 'undef-attr',
    'FOO is not a member of the group specified in the declared value of this attribute', 'undef-attr-val',
    'FOO is not a member of a group specified for any attribute', 'bad-abbrev-attr',
    'end tag for FOO omitted but its declaration does not permit this', 'no-end-tag',
    'end tag for element FOO which is not open', 'floating-close',
    'end tag for FOO which is not finished', 'omitted-content',
    'start tag for FOO omitted but its declaration does not permit this', 'no-start-tag',
    'general entity FOO not defined and no default entity', 'bad-entity',
    'non SGML character number', 'bad-char',
    'cannot generate system identifier for entity FOO', 'bad-pub-id'

#    'error', 'frag',
#    'character data is not allowed here', 'frag',

);

#############################################################################
# Set up some signal handlers in case we get killed before exiting naturally
#############################################################################

$SIG{'TERM'} = 'erase_stuff';
$SIG{'KILL'} = 'erase_stuff';
$SIG{'PIPE'} = 'IGNORE';
# $SIG{'CHLD'} = 'erase_stuff';

#############################################################################
# Process CGI variables
#############################################################################

#
# Create a new CGI object.
my $q = new CGI;

#
# Backwards compatibility; see
# http://lists.w3.org/Archives/Public/www-validator/1999JulSep/0197
# http://lists.w3.org/Archives/Public/www-validator/1999JulSep/0212
if (scalar $q->param) {
    foreach my $param ($q->param) {
        $q->param($param, TRUE) unless $q->param($param);
    }
}

#
# Futz the URI so "/referer" works.
if ($q->path_info eq '/referer') {
    $q->param('uri', $q->referer);
}

#
# Use "url" unless a "uri" was also given.
if ($q->param('url') and not $q->param('uri')) {
    $q->param('uri', $q->param('url'));
}

#
# Send them to the homepage unless we can extract a URI from either of the
# acceptable sources: uri, url or /referer.
&redirect_to_home_page unless length($q->param('uri')) > 5;

#
# Munge the URI to include commonly omitted prefixes/suffixes.
$q->param('uri', $q->param('uri') . '/')   unless $q->param('uri') =~ m(/);
$q->param('uri', 'http://' . $q->param('uri')) if $q->param('uri') =~ m(^www)i;

#############################################################################
# Output validation results
#############################################################################

my $header = <<"EOF";
Content-Type: text/html

$html40t_doctype
<html>

  <head>
    <title>Results</title>
  </head>

  <body bgcolor="#FFFFFF" text="#000000" link="#0000ee" vlink="#551a8b">


$notice
EOF

unless($q->param('uri') =~ m(^http://)) {
     print $header;
     print <<"EOF";
<p>
  Sorry, this type of URI is not supported by this service.
</p>

<p>
  URIs should be in the form:
</p>

<blockquote>
  <code>$abs_svc_uri</code>
</blockquote>

EOF

    &clean_up_and_exit;
}

my $ua = new LWP::UserAgent;
$ua->agent( "Readability Analyzer/$revision " . $ua->agent );
$ua->parse_head(0);  # we want to parse the http-equiv stuff ourselves, for now
my $request = new HTTP::Request(GET => $q->param('uri'));

# if we got a Authorization header from the client, it means
# that the client is back at it after being prompted for
# a password: let's insert the header as is in the outgoing request
if($ENV{HTTP_AUTHORIZATION}){
    $request->headers->header(Authorization => $ENV{HTTP_AUTHORIZATION});
}

my $response = $ua->request($request);
if ( $response->code != 200 ) {
    if ( $response->code == 401 ) {
	$response->headers->www_authenticate =~ /Basic realm=\"([^\"]+)\"/;
	my $realm = $1;
	my $resource = $response->request->url;
	my $authHeader = $response->headers->www_authenticate;
	&print_401_auth_required_message( $resource, $realm, $authHeader );
    }
    else {
	print $header;
	&print_unknown_http_error_message( $q->param('uri'), $response->code,
	    $response->message );
    }
    &clean_up_and_exit;
}

my $content_type = $response->headers->header("Content-Type");

if ( ( $content_type =~ /text\/xml/i ) ||
     ( $content_type =~ /image\/svg/i ) ||
     ( $content_type =~ /application\/smil/i ) ||
     ( $content_type =~ /application\/xml/i ) ) {
    $document_type = "xml";
}
elsif ($content_type =~ /text\/html/i) {
    $document_type = "html";
}
else {
    print $header;
    print <<"EOF";

<p>
  Sorry, I am unable to validate this document because its returned
  content-type was <code>$content_type</code>, which is not
  currently supported by this service.
</p>
EOF

    &clean_up_and_exit;
}

my $jump_links = &build_jump_links;
my $count = 1; # @@ should loop over many uris instead

print $header;
print <<"EOF";

$jump_links
EOF

$uri = $q->param('uri');

$_ = `/home/s/smith/bin/lynx -dump -nolist -pseudo_inlines -verbose $uri`;

s/_|\[LINK\]|\[USEMAP\]//g;
s/\n[\t\f\r ]+/\n/g;

s/"//g;
s/\s+?'//g;
s/'\s+?//g;

s/[\t\f\r]+/ /g;
s/\s+\n+/\n\n/g;
s/([^.!?:])\n\s*?\n/$1.\n\n/g;
s/&.+;\.*\n*//g;
s/[^\w\s.?!:;\[\]{}()-<>i|]/X/g;


print "<pre>";
print $_;
print "</pre>";



sub output_doctype_spiel {

    print <<"EOF";

    <p>
      You should make the first line of your HTML document a DOCTYPE
      declaration, like this:
    </p>

    <pre>
      &lt;!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 3.2//EN"&gt;
      &lt;HTML&gt;
	&lt;HEAD&gt;
	  &lt;TITLE&gt;Title&lt;/TITLE&gt;
	&lt;/HEAD&gt;

	&lt;BODY&gt;
	  &lt;-- ... body of document ... --&gt;
	&lt;/BODY&gt;
      &lt;/HTML&gt;</pre>

    <p>
      Or, if you are using features from <a
      href="http://www.w3.org/TR/REC-html40/">HTML 4.0</a>,
      one of these:
    </p>

    <pre>
      &lt;!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0//EN"&gt;
      &lt;!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN"&gt;
      &lt;!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Frameset//EN"&gt;</pre>

EOF

}

sub output_closing {

    print <<"EOF";

<hr>

<address>
  <a href="http://validator.w3.org/check/referer"><img
     src="http://validator.w3.org/images/vh40" height=31 width=88
     align=right border=0 alt="Valid HTML 4.0!"></a>
  <a href="/feedback.html">Gerald Oskoboiny</a><br>
  $cvsdate
</address>

</body>

</html>
EOF

}

sub erase_stuff {

    unlink $temp           or warn "unlink($temp) returned: $!\n";
    unlink "$temp.esis"    or warn "unlink($temp.esis) returned: $!\n";
    unlink "$temp.weblint";

}

sub make_log_entry {

    my $msgindex;

    open(LOG,">>$logfile") || die "couldn't append to log: $!";
    print LOG "$ENV{REMOTE_HOST}\t$validity $version\t", $q->param('uri'), "\n";
    foreach $msgindex (keys %undef_frag) {
	print LOG "frag not defined for msgindex: $msgindex\n";
    }
    close( LOG ) || die "couldn't close log: $!";

}

sub clean_up_and_exit {

    &output_closing;
    &erase_stuff;
#    &make_log_entry;
    exit;

}

sub redirect_to_home_page {

    print "Status: 301 Moved Permanently\n";
    print "Content-Type: text/html\n";
    print "Location: http://www.io.com/~smith/va/\n\n";
    print "<title>Moved!</title>\n";
    print "<p>\n";
    print "  Please see <a href=\"http://validator.w3.org/\">the validation service's home page.</a>\n";
    print "</p>\n";

    &clean_up_and_exit;

}

sub build_jump_links {

    my $text;
    my $count = 0;

    $count++ if $q->param('ss');
    $count++ if $q->param('sp');
    $count++ if $q->param('weblint');
    $count++ if $q->param('outline');

    if ( $count ) {
	$text .= "  <p>\n    Jump to: ";
	if ( $q->param('weblint') ) {
	    $text .= "<a\n      href=\"#weblint\">Weblint Results</a>";
	    $count--;
	    $text .= " or " if ( $count == 1 );
	    $text .= ", "   if ( $count >  1 );
	}
	if ( $q->param('outline') ) {
	    $text .= "<a\n      href=\"#outline\">Outline</a>";
	    $count--;
	    $text .= " or " if ( $count == 1 );
	    $text .= ", "   if ( $count >  1 );
	}
	if ( $q->param('ss') ) {
	    $text .= "<a\n      href=\"#source\">Source Listing</a>";
	    $count--;
	    $text .= " or " if ( $count == 1 );
	    $text .= ", "   if ( $count >  1 );
	}
	if ( $q->param('sp') ) {
	    $text .= "<a\n      href=\"#parse\">Parse Tree</a>";
	}
	$text .= ".\n  </p>\n\n";
    }
    return $text;

}

sub check_for_doctype {
    # check if the document has a doctype; if it doesn't, try to
    # guess an appropriate one given the elements used
    #
    # returns 2 values:
    #
    # first value: 0 or 1:
    #     if 0, there was a doctype already present;
    #     if 1, there wasn't a doctype
    #
    # second value:
    #     the inferred doctype, if any

    my $fileref = shift;		# a reference to @file, for efficiency
    my @file = @$fileref;		# dereference $fileref

    foreach $count (0..$#file) {
	$line = $file[$count];

	# does an HTML element precede the doctype on the same line?
	last if $line =~ /<[a-z].*<!doctype/i;

	if ( $line =~ /<!doctype/i ) {	# found a doctype
	    my $dttext = join( "", @file[$count..$count+5] );
	    $dttext =~ s/\n//g;
	    $dttext =~ s/.*doctype\s+html\s+public\s*["']//i;
	    $dttext =~ s/["'].*//;	# strip everything except the FPI
	        # @@ should make sure both quote chars were the same
	    return 0, $dttext;
	}

	$line =~ s/<!(?:--(?:[^-]|-[^-])*--\s*)+>//go;	# strip comments,
	    # so the next line doesn't find commented-out markup etc.
	    # (this doesn't handle multi-line comments, unfortunately)

	last if ( $line =~ /<[a-z]/i );		# found an element

    }

    # do several loops of increasing lengths to avoid iterating over
    # the whole file if possible.
    #
    # these heuristics could be improved a lot.

    foreach $line (@file[0..20]) {
	return 1, $xhtmlt_doctype if $line =~ /xmlns\s*=/i;
    }

    foreach $line (@file[0..20]) {
	return 1, $html40f_doctype if $line =~ /<frame/i;
    }

    foreach $line (@file[0..20]) {
	return 1, $html40t_doctype if $line =~ /<(table|body )/i;
    }

    # go through the whole file
    foreach $line (@file) {
	return 1, $html40t_doctype if $line =~ /<(table|body )/i;
    }

    foreach $line (@file) {
	return 1, $html32_doctype if $line =~ /<center>/i;
	return 1, $html32_doctype if $line =~ /<[h0-9p]*\s*align\s*=\s*center>/i;
    }

    # no luck earlier; guess HTML 4.0 transitional
    return 1, $html40t_doctype;

}

sub print_401_auth_required_message {

    my $resource = shift;
    my $realm = shift;
    my $authHeader = shift;

    print <<"EOF";
Status: 401 Authorization Required
WWW-Authenticate: $authHeader
Connection: close
Content-Type: text/html

<!DOCTYPE HTML PUBLIC \"-//IETF//DTD HTML 2.0//EN\">
<HTML><HEAD>
<TITLE>401 Authorization Required</TITLE>
</HEAD><BODY>
<H1>Authorization Required</H1>
<p>
  Sorry, I am not authorized to access the specified URI.
</p>

<p>
  The URI you specified,
</p>

<blockquote>
  <code><a href="$resource">$resource</a></code>
</blockquote>

<p>
  returned a 401 "authorization required" response when I tried
  to download it.
</p>

<p>
  You should have been prompted by your browser for a
  username/password pair; if you had supplied this information, I
  would have forwarded it to your server for authorization to
  access the resource. You can use your browser's "reload" function
  to try again, if you wish.
</p>

<p>
  Of course, you may not want to trust me with this information,
  which is fine. I can tell you that I don't log it or do
  anything else nasty with it, and you can <a
  href="http://validator.w3.org/source/">download the source for
  this service</a> to see what it does, but you have no guarantee
  that this is actually the code I'm using; you basically have to
  decide whether to trust me or not. :-)
</p>

<p>
  Note that you shouldn't use HTTP Basic Authentication for
  anything which really needs to be private, since the password
  goes across the network unencrypted.
</p>
EOF

}

sub print_unknown_http_error_message {

    my $uri = shift;
    my $code = shift;
    my $message = shift;

    print <<"EOF";
  <p>
    I got the following unexpected response when trying to
    retrieve <code><a href="$uri">$uri</a></code>:
  </p>

  <blockquote>
    <code>$code $message</code>
  </blockquote>

  <p>
    Please make sure you have entered the URI correctly.
  </p>

EOF

}

sub output_css_validator_blurb {

    my $uri = shift;

    print <<"EOHD";
  <p>
    If you use <a href="http://www.w3.org/Style/css/">CSS</a>
    in your document, you should also <a
    href="http://jigsaw.w3.org/css-validator/validator?uri=$uri">check
    it for validity</a> using W3C's <a
    href="http://jigsaw.w3.org/css-validator/">CSS
    Validation Service</a>.
  </p>

EOHD

}

sub html_element_ref {

    # returns a URI pointing to docs on the HTML element given as $1

    my $element = shift;

    # the following hash was produced with:
    #
    # GET http://www.htmlhelp.com/reference/html40/alist.html > /tmp/e
    # egrep '^  <li' /tmp/e | \
    #     perl -pe 's|.*href="([^"]*)">(.*)</a>.*|\t"\L$2\E" => "$1",|'

    my %html_element_hash = (
	"a" => "special/a.html",
	"abbr" => "phrase/abbr.html",
	"acronym" => "phrase/acronym.html",
	"address" => "block/address.html",
	"applet" => "special/applet.html",
	"area" => "special/area.html",
	"b" => "fontstyle/b.html",
	"base" => "head/base.html",
	"basefont" => "special/basefont.html",
	"bdo" => "special/bdo.html",
	"big" => "fontstyle/big.html",
	"blockquote" => "block/blockquote.html",
	"body" => "html/body.html",
	"br" => "special/br.html",
	"button" => "forms/button.html",
	"caption" => "tables/caption.html",
	"center" => "block/center.html",
	"cite" => "phrase/cite.html",
	"code" => "phrase/code.html",
	"col" => "tables/col.html",
	"colgroup" => "tables/colgroup.html",
	"dd" => "lists/dd.html",
	"del" => "phrase/del.html",
	"dfn" => "phrase/dfn.html",
	"dir" => "lists/dir.html",
	"div" => "block/div.html",
	"dl" => "lists/dl.html",
	"dt" => "lists/dt.html",
	"em" => "phrase/em.html",
	"fieldset" => "forms/fieldset.html",
	"font" => "special/font.html",
	"form" => "forms/form.html",
	"frame" => "frames/frame.html",
	"frameset" => "frames/frameset.html",
	"h1" => "block/h1.html",
	"h2" => "block/h2.html",
	"h3" => "block/h3.html",
	"h4" => "block/h4.html",
	"h5" => "block/h5.html",
	"h6" => "block/h6.html",
	"head" => "head/head.html",
	"hr" => "block/hr.html",
	"html" => "html/html.html",
	"i" => "fontstyle/i.html",
	"iframe" => "special/iframe.html",
	"img" => "special/img.html",
	"input" => "forms/input.html",
	"ins" => "phrase/ins.html",
	"isindex" => "block/isindex.html",
	"kbd" => "phrase/kbd.html",
	"label" => "forms/label.html",
	"legend" => "forms/legend.html",
	"li" => "lists/li.html",
	"link" => "head/link.html",
	"map" => "special/map.html",
	"menu" => "lists/menu.html",
	"meta" => "head/meta.html",
	"noframes" => "frames/noframes.html",
	"noscript" => "block/noscript.html",
	"object" => "special/object.html",
	"ol" => "lists/ol.html",
	"optgroup" => "forms/optgroup.html",
	"option" => "forms/option.html",
	"p" => "block/p.html",
	"param" => "special/param.html",
	"pre" => "block/pre.html",
	"q" => "special/q.html",
	"s" => "fontstyle/s.html",
	"samp" => "phrase/samp.html",
	"script" => "special/script.html",
	"select" => "forms/select.html",
	"small" => "fontstyle/small.html",
	"span" => "special/span.html",
	"strike" => "fontstyle/strike.html",
	"strong" => "phrase/strong.html",
	"style" => "head/style.html",
	"sub" => "special/sub.html",
	"sup" => "special/sup.html",
	"table" => "tables/table.html",
	"tbody" => "tables/tbody.html",
	"td" => "tables/td.html",
	"textarea" => "forms/textarea.html",
	"tfoot" => "tables/tfoot.html",
	"th" => "tables/th.html",
	"thead" => "tables/thead.html",
	"title" => "head/title.html",
	"tr" => "tables/tr.html",
	"tt" => "fontstyle/tt.html",
	"u" => "fontstyle/u.html",
	"ul" => "lists/ul.html",
	"var" => "phrase/var.html"
    );

    return "http://www.htmlhelp.com/reference/html40/" .
        $html_element_hash{"\L$element"};
}

