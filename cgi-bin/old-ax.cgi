#!/usr/bin/perl

# AXS Script Set, Logging Module, Version 2.01
#	Copyright 1997 by Fluid Dynamics <xav.com>.  Please adhere to 
#	the copyright notice and conditions of use which are described 
#	in the attached help file and hosted at the URL below.
#
# For latest version and help files, visit:
#	http://www.xav.com/scripts/axs
# __________________________________________________________________

$logfile = "/usr/u/s/smith/public-web/cgi-bin/log.txt";
$domain = 'http://www.io.com';
$header = "";


# Before running, scroll down 20 lines and look at the "Custom" 
# information for excluding servers.  See the attached instruction 
# for help with variables above.
#
# __________________________________________________________________



if ($ENV{'QUERY_STRING'} eq 'trans.gif')
	{
	&Print_Image;
	}
elsif ($ENV{'DOCUMENT_URI'})
	{
	print "$header\n \n";
	}
else
	{
	print "Location: $ENV{'QUERY_STRING'}\n\n";
	}
if (($ENV{'REMOTE_HOST'} eq $ENV{'REMOTE_ADDR'}) && ($ENV{'REMOTE_ADDR'} =~ /(\d+)\.(\d+)\.(\d+)\.(\d+)/))
	{
	$Address = pack('C4', $1, $2, $3, $4);
	$DNS_Address = (gethostbyaddr($Address, 2))[0];
	$ENV{'REMOTE_HOST'} = $DNS_Address if $DNS_Address;
	}
$ENV{'REMOTE_HOST'} =~ tr/[A-Z]/[a-z]/;


# CUSTOM1-Begin (see below)
#
# Now we ignore people who should be ignored.  Usually webmasters 
# place their own server names in the set below so that their own 
# hits don't offset the log file.  If you want to record every 
# single person, just delete everything between the CUSTOM1 flags.

# exit if ($ENV{'REMOTE_HOST'} =~ /io.com$/ ||
#	 $ENV{'REMOTE_HOST'} =~ /^ohaton.cs.ualberta.ca/ ||
#	 $ENV{'REMOTE_HOST'} =~ /^validator.w3.org/ ||
#	 $ENV{'REMOTE_ADDR'} =~ /^167.208/);


# CUSTOM1-End (delete through this line if you delete)


$logline = "|$ENV{'REMOTE_HOST'}|$ENV{'REMOTE_ADDR'}|";
$ENV{'HTTP_REFERER'} =~ s/\|//g;
$logline .= "$ENV{'HTTP_REFERER'}|";
$ENV{'QUERY_STRING'} = $ENV{'HTTP_REFERER'} if ($ENV{'QUERY_STRING'} eq 'trans.gif');
if ($ENV{'DOCUMENT_URI'})
	{$logline .= "$domain$ENV{'DOCUMENT_URI'}|";}
else
	{$logline .= "$ENV{'QUERY_STRING'}|";}
$logline .= "$ENV{'HTTP_USER_AGENT'}|";
($sec,$min,$hour,$mday,$mon,$year,$wday,$yday) = localtime(time);
$logline .= "$sec|$min|$hour|$mday|$mon|$year|$wday|$yday|";
$logline .= "export|" unless $ENV{'DOCUMENT_URI'};
$logline .= "\n";
open(LOG,">>$logfile");
print LOG $logline;
close(LOG);

sub Print_Image
{
$| = 1;
@Binary_Code = (71,73,70,56,57,97,1,0,1,0,128,255,0,192,192,192,0,0,0,
	33,249,4,1,0,0,0,0,44,0,0,0,0,1,0,1,0,0,1,1,50,0,59);
print "Pragma: no-cache\r\n";
print "Expires: Saturday, February 15, 1997 10:10:10 GMT\r\n";
# My most recent birthday was February 15...  ;)
print "Content-Type: image/gif\r\n\r\n";
binmode(STDOUT);
foreach (@Binary_Code)
	{
	$BinCode = pack("C",$_);
	print $BinCode;
	}
}
