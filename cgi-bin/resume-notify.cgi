#!/usr/bin/perl

$mailprog = '/usr/lib/sendmail';
$recipient = 'smith@io.com';

$time = localtime(time);

open (MAIL, "|$mailprog $recipient") || die "Can't open $mailprog!\n";

print MAIL "Subject: Resume accessed\n\n";
print MAIL "On $time, a user from $ENV{'REMOTE_HOST'} ($ENV{'REMOTE_ADDR'})\n";
print MAIL "linked in from $ENV{'HTTP_REFERER'} \n"; 
print MAIL "using $ENV{'HTTP_USER_AGENT'} \n"; 
print MAIL "and accessed your resume.\n\n";
close (MAIL);
   
