#!/usr/bin/perl
##############################################################################
# Guestbook                     Version 2.3.1                                #
# Copyright 1996 Matt Wright    mattw@worldwidemart.com                      #
# Created 4/21/95               Last Modified 10/29/95                       #
# Scripts Archive at:           http://www.worldwidemart.com/scripts/        #
##############################################################################
# COPYRIGHT NOTICE                                                           #
# Copyright 1996 Matthew M. Wright  All Rights Reserved.                     #
#                                                                            #
# Guestbook may be used and modified free of charge by anyone so long as     #
# this copyright notice and the comments above remain intact.  By using this #
# code you agree to indemnify Matthew M. Wright from any liability that      #  
# might arise from it's use.                                                 #  
#                                                                            #
# Selling the code for this program without prior written consent is         #
# expressly forbidden.  In other words, please ask first before you try and  #
# make money off of my program.                                              #
#                                                                            #
# Obtain permission before redistributing this software over the Internet or #
# in any other medium.	In all cases copyright and header must remain intact.#
##############################################################################
# Set Variables

$guestbookurl = "http://www.io.com/~smith/greenberg/guestbook.html";
$guestbookreal = "/usr/u/s/smith/public-web/greenberg/guestbook.html";
$guestlog = "/usr/u/s/smith/public-web/greenberg/guestlog.html";
$cgiurl = "http://www.io.com/~smith/cgi-bin/guestbook.cgi";
$date_command = "/bin/date";

# Set Your Options:
$mail = 1;              # 1 = Yes; 0 = No
$uselog = 1;            # 1 = Yes; 0 = No
$linkmail = 1;          # 1 = Yes; 0 = No
$separator = 1;         # 1 = <hr>; 0 = <p>
$redirection = 0;       # 1 = Yes; 0 = No
$entry_order = 1;       # 1 = Newest entries added first;
                        # 0 = Newest Entries added last.
$remote_mail = 1;       # 1 = Yes; 0 = No
$allow_html = 0;        # 1 = Yes; 0 = No
$line_breaks = 0;	# 1 = Yes; 0 = No

# If you answered 1 to $mail or $remote_mail you will need to fill out 
# these variables below:
$mailprog = '/usr/lib/sendmail';
$recipient = 'smith@io.com';

# Done
##############################################################################

# Get the Date for Entry
$date = `$date_command +"%A, %B %d, %Y at %T (%Z)"`; chop($date);
$shortdate = `$date_command +"%D %T %Z"`; chop($shortdate);

# Get the input
read(STDIN, $buffer, $ENV{'CONTENT_LENGTH'});

# Split the name-value pairs
@pairs = split(/&/, $buffer);

foreach $pair (@pairs) {
   ($name, $value) = split(/=/, $pair);

   # Un-Webify plus signs and %-encoding
   $value =~ tr/+/ /;
   $value =~ s/%([a-fA-F0-9][a-fA-F0-9])/pack("C", hex($1))/eg;
   $value =~ s/<!--(.|\n)*-->//g;

   if ($allow_html != 1) {
      $value =~ s/<([^>]|\n)*>//g;
   }

   $FORM{$name} = $value;
}

# Print the Blank Response Subroutines
&no_comments unless $FORM{'comments'};
&no_name unless $FORM{'realname'};

# Begin the Editing of the Guestbook File
open (FILE,"$guestbookreal") || die "Can't Open $guestbookreal: $!\n";
@LINES=<FILE>;
close(FILE);
$SIZE=@LINES;

# Open Link File to Output
open (GUEST,">$guestbookreal") || die "Can't Open $guestbookreal: $!\n";

for ($i=0;$i<=$SIZE;$i++) {
   $_=$LINES[$i];
   if (/<!--begin-->/) { 

      if ($entry_order eq '1') {
         print GUEST "<!--begin-->\n";
      }
   
      if ($line_breaks == 1) {
         $FORM{'comments'} =~ s/\cM\n/<br>\n/g;
      }

      print GUEST "\"$FORM{'comments'}\"<br><BR>\n";

      if ($FORM{'url'}) {
         print GUEST "<a href=\"$FORM{'url'}\">$FORM{'realname'}</a>";
      }
      else {
         print GUEST "$FORM{'realname'}";
      }

      if ( $FORM{'username'} ){
         if ($linkmail eq '1') {
            print GUEST " \&lt;<a href=\"mailto:$FORM{'username'}\">";
            print GUEST "$FORM{'username'}</a>\&gt;";
         }
         else {
            print GUEST " &lt;$FORM{'username'}&gt;";
         }
      }

      print GUEST "<br>\n";

      if ( $FORM{'city'} ){
         print GUEST "$FORM{'city'}";
      }
     
      if ( $FORM{'state'} ){
         print GUEST " $FORM{'state'}";
      }

      if ( $FORM{'country'} ){
         print GUEST " $FORM{'country'}";
      }

      if ($separator eq '1') {
         print GUEST "<BR>$date<hr>\n\n";
      }
      else {
         print GUEST "<BR>$date<p>\n\n";
      }

      if ($entry_order eq '0') {
         print GUEST "<!--begin-->\n";
      }

   }
   else {
      print GUEST $_;
   }
}

close (GUEST);

# Log The Entry

if ($uselog eq '1') {
   &log('entry');
}


#########
# Options

# Mail Option
if ($mail eq '1') {
   open (MAIL, "|$mailprog $recipient") || die "Can't open $mailprog!\n";

   print MAIL "Reply-to: $FORM{'username'} ($FORM{'realname'})\n";
   print MAIL "From: $FORM{'username'} ($FORM{'realname'})\n";
   print MAIL "Subject: Entry to Guestbook\n\n";
   print MAIL "You have a new entry in your guestbook:\n\n";
   print MAIL "------------------------------------------------------\n";
   print MAIL "$FORM{'comments'}\n";
   print MAIL "$FORM{'realname'}";

   if ( $FORM{'username'} ){
      print MAIL " <$FORM{'username'}>";
   }

   print MAIL "\n";

   if ( $FORM{'city'} ){
      print MAIL "$FORM{'city'}";
   }

   if ( $FORM{'state'} ){
      print MAIL " $FORM{'state'}";
   }

   if ( $FORM{'country'} ){
      print MAIL " $FORM{'country'}";
   }

   print MAIL "\n$date\n";
   print MAIL "------------------------------------------------------\n";

   close (MAIL);
}

if ($remote_mail eq '1' && $FORM{'username'}) {
   open (MAIL, "|$mailprog -t") || die "Can't open $mailprog!\n";

   print MAIL "To: $FORM{'username'}\n";
   print MAIL "From: $recipient\n";
   print MAIL "Subject: Samuel Greenberg guestbook\n\n";
   print MAIL "Thank you for adding the entry below to the \"Samuel Greenberg: American Poet\" guestbook at:\n\n";
   print MAIL "http://www.io.com/~smith/greenberg/guestbook.html\n\n";
   print MAIL "Your addition was very much appreciated.\n\n";
   print MAIL "------------------------------------------------------\n";
   print MAIL "$FORM{'comments'}\n";
   print MAIL "$FORM{'realname'}";

   if ( $FORM{'username'} ){
      print MAIL " <$FORM{'username'}>";
   }

   print MAIL "\n";

   if ( $FORM{'city'} ){
      print MAIL "$FORM{'city'}";
   }

   if ( $FORM{'state'} ){
      print MAIL " $FORM{'state'}";
   }

   if ( $FORM{'country'} ){
     print MAIL " $FORM{'country'}";
   }

   print MAIL "\n$date\n";
   print MAIL "------------------------------------------------------\n";

   close (MAIL);
}

# Print Out Initial Output Location Heading
if ($redirection eq '1') {
   print "Location: $guestbookurl\n\n";
}
else { 
   &no_redirection;
}

#######################
# Subroutines

sub no_comments {
   print "Content-type: text/html\n\n";
   print "<html><head><title>Error</title></head>\n";
   print "<body><h2>Please add a comment.</h2>\n";
   print "<P>Sorry. The Comments section in the guestbook form appears\n";
   print "to be blank, so your entry has not yet been added. Please\n";
   print "type a comment or question below and resubmit the form.</p>\n";
   print "<form method=POST action=\"$cgiurl\">\n";
   print "Your Name:<input type=text name=\"realname\" size=30 ";
   print "value=\"$FORM{'realname'}\"><br>\n";
   print "Comments:<br>\n";
   print "<textarea name=\"comments\" COLS=64 ROWS=4></textarea><p>\n";
   print "<input type=submit value=submit> | <input type=reset value=clear></form><hr>\n";
   print "Return to the <a href=\"$guestbookurl\">guestbook</a>.";
   print "\n</body></html>\n";

   # Log The Error
   if ($uselog eq '1') {
      &log('no_comments');
   }

   exit;
}

sub no_name {
   print "Content-type: text/html\n\n";
   print "<html><head><title>Error</title></head>\n";
   print "<body><h2>Please add your name.</h2>\n";
   print "<P>Sorry. The Name section in the guestbook form appears to\n";
   print "be blank, so your entry has not yet been added. Please\n";
   print "type a name below and resubmit the form.</p>\n";
   print "<form method=POST action=\"$cgiurl\">\n";
   print "Your Name:<input type=text name=\"realname\" size=30><br><BR>\n";
   print "Your comments have been retained.<p>\n";
   print "<input type=hidden name=\"comments\" ";
   print "value=\"$FORM{'comments'}\">\n";
   print "<input type=submit value=submit> | <input type=reset value=clear></form><hr>\n";
   print "Return to the <a href=\"$guestbookurl\">guestbook</a>.";
   print "\n</body></html>\n";

   # Log The Error
   if ($uselog eq '1') {
      &log('no_name');
   }

   exit;
}

# Log the Entry or Error
sub log {
   $log_type = $_[0];
   open (LOG, ">>$guestlog");
   if ($log_type eq 'entry') {
      print LOG "$ENV{'REMOTE_HOST'} - [$shortdate]<br>\n";
   }
   elsif ($log_type eq 'no_name') {
      print LOG "$ENV{'REMOTE_HOST'} - [$shortdate] - ERR: No Name<br>\n";
   }
   elsif ($log_type eq 'no_comments') {
      print LOG "$ENV{'REMOTE_HOST'} - [$shortdate] - ERR: No ";
      print LOG "Comments<br>\n";
   }
}

# Redirection Option
sub no_redirection {

   # Print Beginning of HTML
   print "Content-Type: text/html\n\n";
   print "<html><head><title>Thank You</title></head>\n";
   print "<body><h2>Thank You.</h2>\n";

   # Print Response
   print "Your entry has\n";
   print "been added to the guestbook.<hr>\n";
   print "Here is what you submitted:<p>\n";
   print "\"$FORM{'comments'}\"<br><br>\n";

   if ($FORM{'url'}) {
      print "<a href=\"$FORM{'url'}\">$FORM{'realname'}</a>";
   }
   else {
      print "$FORM{'realname'}";
   }

   if ( $FORM{'username'} ){
      if ($linkmail eq '1') {
         print " &lt;<a href=\"mailto:$FORM{'username'}\">";
         print "$FORM{'username'}</a>&gt;";
      }
      else {
         print " &lt;$FORM{'username'}&gt;";
      }
   }

   print "<br>\n";

   if ( $FORM{'city'} ){
      print "$FORM{'city'}";
   }

   if ( $FORM{'state'} ){
      print " $FORM{'state'}";
   }

   if ( $FORM{'country'} ){
      print " $FORM{'country'}";
   }

   print "<BR>$date<p>\n";

   # Print End of HTML
   print "<hr>\n";
   print "<P><a href=\"$guestbookurl\">Back to the guestbook.</a></P>\n";
   print "<P><B><U>Note</U>:</B> You may need to reload the guestbook page to see your entry.</P>\n";
   print "</body></html>\n";

   exit;
}


