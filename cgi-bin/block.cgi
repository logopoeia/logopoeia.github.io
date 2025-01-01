#!/usr/bin/perl

	$email = 'smith@io.com';
	$main_page = 'http://www.io.com/~smith';
	$mailprog = '/usr/sbin/sendmail';

if ($ENV{'REMOTE_HOST'} !~ /io.com$/ &&
    $ENV{'REMOTE_ADDR'} !~ /^167.208/)
{
    open(MAIL,"|$mailprog -t");
    print MAIL "To: $email\n";
    print MAIL "From: guardian\@xav.com (Apache Guardian)\n";
    print MAIL "Subject: Guardian Report [Access blocked.]\n";
    print MAIL "X-Priority: 1 (Highest)\n\n";
    print MAIL "Flags tripped for attempted access to $ENV{'REDIRECT_URL'}\n";
    print MAIL "by $ENV{'REMOTE_HOST'}.\n\n";
    if ($ENV{'HTTP_REFERER'})
    {
	@terms = split(/\//,$ENV{'HTTP_REFERER'});
	print MAIL "Visitor linked in from $ENV{'HTTP_REFERER'}. ";
	print MAIL "You may wish to contact the administrator of $terms[0]//$terms[2].\n\n";
    }
    else
    {print MAIL "No referring URL was logged in association with this visit.\n\n";}
    print MAIL "Details follow:\n\n";
    foreach $key (sort keys %ENV)
    {print MAIL "$key: $ENV{$key}\n";}
    close(MAIL);
}

# Next print an explanation for the visitor:
print "Content-type: text/html\n\n";
print <<EOM;
<html>
<head><title>Access Blocked</title></head>
<body bgcolor="#ffffff" link="#ce0000" vlink="#ce0000" alink="#ffffff">
<h2><tt>Access blocked.</tt></h2>
<blockquote>\n<b>
The site administrator has been notified of the environmental variables associated with your request.
</b></blockquote>\n</body>\n</html>\n
EOM
