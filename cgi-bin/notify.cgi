#!/usr/bin/perl
$mailprog = '/usr/lib/sendmail';
       $recipient = 'smith@io.com';

        $time = localtime(time);
        $download_filepath = $ENV{'PATH_TRANSLATED'};

   open (MAIL, "|$mailprog $recipient") || die "Can't open $mailprog!\n";

   print MAIL "Subject: Download\n\n";
   print MAIL "On $time, a user from $ENV{'REMOTE_HOST'} ($ENV{'REMOTE_ADDR'}), ";
   print MAIL "using $ENV{'HTTP_USER_AGENT'} "; 
   print MAIL "successfully downloaded the file $download_filepath.\n\n";
   close (MAIL);
   
   $_ = $download_filepath;
   s#.*/(.*)#$1#;    
   $download_filename = $_;	

   print "Content-Type: application/msword\n";
   print "Content-Disposition: attachment; filename=$download_filename\n\n";
   print `cat $download_filepath`;
