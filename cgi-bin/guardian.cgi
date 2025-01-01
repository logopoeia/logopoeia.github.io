#!/usr/bin/perl

# Apache Guardian, Version 1.0
#	Copyright 1997 by Fluid Dynamics <xav.com>
#	You are free to use the script, but please ask before you 
#	distribute it.
#
# For latest version and help files, visit:
#	http://www.xav.com/scripts/guardian
# __________________________________________________________________


# Enter your email address:

	$email = 'smith@io.com';

# Enter the URL of your main page:

	$main_page = 'http://www.logopoeia.com/';

# Enter the URL to your search page, if you have one.  If not, just 
# delete this line:



# Enter the location of sendmail on your system if it differs from 
# the default:

	$mailprog = '/usr/sbin/sendmail';

# No further editing is necessary, but feel free to play around...
# 
# __________________________________________________________________


# First label the error:
$code = "Restricted Access" if ($ENV{'QUERY_STRING'} eq '401');
$code = "Forbidden" if ($ENV{'QUERY_STRING'} eq '403');
$code = "File Not Found" if ($ENV{'QUERY_STRING'} eq '404');
$code = "Method Not Allowed" if ($ENV{'QUERY_STRING'} eq '405');
$code = "Conflict" if ($ENV{'QUERY_STRING'} eq '409');
$code = "Precondition Failed" if ($ENV{'QUERY_STRING'} eq '412');
$code = "Internal Server Error" if ($ENV{'QUERY_STRING'} eq '500');

# Next, mail a summary to the site administrator--
# as long as the remote host/address does not match
# any of the patterns listed

# if ($ENV{'REMOTE_HOST'} !~ /xxxxxx$/ &&
#     $ENV{'REMOTE_ADDR'} !~ /^999999/)
#  {
#     open(MAIL,"|$mailprog -t");
#     print MAIL "To: $email\n";
#     print MAIL "From: guardian\@xav.com (Apache Guardian)\n";
#     print MAIL "Subject: Guardian Report [$code]\n";
#     print MAIL "X-Priority: 1 (Highest)\n\n";
#     print MAIL "Flags tripped for attempted access to $ENV{'REDIRECT_URL'}\n";
#     print MAIL "by $ENV{'REMOTE_HOST'}.\n\n";
#     if ($ENV{'HTTP_REFERER'})
#     {
# 	@terms = split(/\//,$ENV{'HTTP_REFERER'});
# 	print MAIL "Visitor linked in from $ENV{'HTTP_REFERER'}. ";
# 	print MAIL "You may wish to contact the administrator of $terms[0]//$terms[2].\n\n";
#     }
#     else
#     {print MAIL "No referring URL was logged in association with this visit.\n\n";}
#     print MAIL "Details follow:\n\n";
#     foreach $key (sort keys %ENV)
#     {print MAIL "$key: $ENV{$key}\n";}
#     close(MAIL);
#}

# Next print an explanation for the visitor:
print "Content-type: text/html\n\n";
print <<EOM;
<HTML>
<HEAD><TITLE>Apache Guardian: $code</TITLE></HEAD>
<BODY BGCOLOR="#FFFFFF" LINK="#CE0000" VLINK="#CE0000" ALINK="#FFFFFF">
<H2><TT>$code (Apache Error $ENV{'QUERY_STRING'})</TT></H2>
<BLOCKQUOTE>\n<B>
EOM
if ($ENV{'QUERY_STRING'} eq '401')
	{&explain_401;}
elsif ($ENV{'QUERY_STRING'} eq '404')
	{&explain_404;}
elsif ($ENV{'QUERY_STRING'} eq '405')
	{&explain_405;}
elsif ($ENV{'QUERY_STRING'} eq '409')
	{&explain_409;}
elsif ($ENV{'QUERY_STRING'} eq '412')
	{&explain_412;}
elsif ($ENV{'QUERY_STRING'} eq '500')
	{&explain_500;}
else
	{&default;}
print "</B></BLOCKQUOTE>\n</BODY>\n</HTML>\n";


sub explain_401
{
print <<EOM;
The file you requested has been password protected, and you are not authorized to access it. The site administrator has been notified of this error and the specific details (environmental variables) associated with your request.
EOM
}


sub explain_404
{
print <<EOM;
The server could not find the file you requested, for one of the following reasons.
<br>
<ul>
<li>You typed in a URL incorrectly.
<li>You arrived from a <A HREF=$ENV{HTTP_REFERER}>referring page</A> via a link containing a bad directory name or filename.
<li>The file you're looking for may have been moved or renamed.
</ul>
<br>

To find what you're looking for, try starting from this site's <A HREF="$main_page">index page</A>, or contact <A HREF="mailto:$email">smith\@io.com</A> \(the site administrator\).
EOM
}


sub explain_405
{
print <<EOM;
The request method you've attempted to use is not allowed for the URL you've specified. For help doing whatever it is you're trying to do, contact <A HREF="mailto:$email">smith\@io.com</A> \(the site administrator\), who has been notified of the error and the specific details (environmental variables) associated with your request.
EOM
}


sub explain_409
{
print <<EOM;
Your request conflicts with another request, or with this server's configuration. The site administrator has been notified of the error and the specific details (environmental variables) associated with the request.
EOM
}


sub explain_412
{
print <<EOM;
You sent a request with preconditions in the header, and one or more of these preconditions was false. The site administrator has been notified of the error and the specific details (environmental variables) associated with the request.
EOM
}


sub explain_500
{
print <<EOM;
Your request has generated an error within the server on which this site resides. If you are using a script, and you've recently altered the code, you may try to isolate the error by running <TT>perl -w $ENV{'REDIRECT_SCRIPT_FILENAME'}</TT>. Otherwise, for help doing whatever it is you're attempting to do, try contacting <A HREF="mailto:$email">smith\@io.com</A> \(the site administrator\), who has been notified of the error and the specific details (environmental variables) associated with your request.
EOM
}


sub default
{
print <<EOM;
<p align=left>The server could not process your request, for one of these reasons:
</p>
<ul>
<li>You typed in a URL incorrectly.
<li>You arrived from a <A HREF=$ENV{HTTP_REFERER}>referring page</A> via a link with a bad directory name or filename.
<li>The file you're looking for may have been moved or renamed.
<li>You attempted to list the contents of a directory.<br>
 (This site does not allow anonymous directory listing or browsing)
</ul>
To find what you're looking for, try starting from the <A HREF="$main_page">index page</A>, or contact <A HREF="mailto:$email">smith\@io.com</A>.
EOM
}

