#!/usr/bin/perl

# specially modified shortwave radio enlish broadcast preparation engine 
# smswe,cgi
# Copyright (c) Michael Smith aka Logopoeia <smswe@logopoeia.com>

$| = 1;
use CGI qw(:standard);
$query = new CGI;

$tempfile = "/scratch/radio/radio$$.txt";

# undefine line end so that we can slurp in whole chunks of text
# an do regex pattern matches 'gainst them
undef $/;

$trans =  $query->param('inputStream');

# if seed text is empty or user pressed "Random" button, run
# Prose program to general initial random text.

unless ($trans) {
  $trans = "`/www/docs/logopoeia.com/cgi-bin/prose.cgi`";
  #$trans = "`/www/docs/logopoeia.com/cgi-bin/crackpot.sh | sed 's/\^LINEBREAK\^//g' | sed 's/\!//g' | w3m -dump -T text/html`";
}

# well, the following subroutine calls could use a customization/
# parameterization layer, but hey it works as is for now

$trans = translate($trans, en_es);
$trans = translate($trans, es_en);
$trans = translate($trans, en_de);
$trans = translate($trans, de_en);
$trans = translate($trans, en_fr);
$trans = translate($trans, fr_en);
$trans = translate($trans, en_pt);
$trans = translate($trans, pt_en);

# replace any stray escaped spaces with nuthin
$trans =~ s/%20//gs;

# cut any "** times out **" text Babelfish sometimes generates
$trans =~ s/\*\*[^\*]*\*\*//gs;

# cut "of the, in the, the the" 
$trans =~ s/(((\sof)|(\sin)|(\sthe))\sthe\s)/ /gis;

# cut other "of", that, as, with 
$trans =~ s/(\sof\s|\sthat\s|\sas\s|\swith\s)/ /gis;

# cut other tone and ton 
$trans =~ s/(\stone\s|\ston\s)/ /gis;
$trans =~ s/(Tone\s|Ton\s)/ /gs;

print header;
print <<"EOF";
<?xml version='1.0' encoding='utf-8'?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
   "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en-US" xml:lang="en-US">
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <link rel="StyleSheet" href="smswe.css" type="text/css" />
    <title>specially modified shortwave English broadcast-ready text</title>
  </head>
  <body>
    <p class="text">$trans</p>
    <p class="about"><a href="http://logopoeia.com/radio/about.html" 
    >About this text</a></p>
  </body>
</html>
EOF

`rm $tempfile`;

sub translate {

    $text = shift;
    $lang = shift;
    
    # replace all whitespace with escaped space character
    $text =~ s/\s/%20/gs;

    # cut out apostrophe and double-quote and parens
    $text =~ s/'d/ had/gs;
    $text =~ s/'ve/ have/gs;
    $text =~ s/'ll/ will/gs;
    $text =~ s/'nt/ not/gs;
    $text =~ s/'/ i/gs;
    $text =~ s/"//gs;
    $text =~ s/&/ /gs;
    $text =~ s/\(//gs;
    $text =~ s/\)//gs;

    `echo $text | cat > $tempfile`;

    $url="http://babel.altavista.com/tr?doit=done&tt=urltext&trtext=`cat $tempfile`&lp=$lang";

    #$slurp_lit = "wget -O - $url"; 
    $slurp = `wget -O - "$url"`; 

    # -- Grab translated text --
    # --------------------------
    # First deal with case where translated text is short enough that
    # Babelfish returns is wrapped in a <textarea name="q"> box.

    $_ = $slurp;
    /name=\"q\"[^>]*>([^<]*)</;
    $text = $1;

    # If regex above returns nothing, translated text is too long for
    # Babelfish to return in <textarea>, so grab it instead from the 
    # <td bgcolor=white> it gets wrapped in that case.

    unless ($1) {
           $_ = $slurp;
           /white[^>]*><div[^>]*>([^<]*)</;
           $text = $1;
    }
    return $text;
}
