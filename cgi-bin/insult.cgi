#!/usr/bin/perl
##############################################################################
# Random Text                   Version 1.0                                  #
# Copyright 1996 Matt Wright    mattw@worldwidemart.com                      #
# Created 7/13/96               Last Modified 7/13/96                        #
# Scripts Archive at:           http://www.worldwidemart.com/scripts/        #
##############################################################################
# COPYRIGHT NOTICE                                                           #
# Copyright 1996 Matthew M. Wright  All Rights Reserved.                     #
#                                                                            #
# Random Text may be used and modified free of charge by anyone so long as   #
# this copyright notice and the comments above remain intact.  By using this #
# code you agree to indemnify Matthew M. Wright from any liability that      #  
# might arise from it's use.                                                 #  
#                                                                            #
# Selling the code for this program without prior written consent is         #
# expressly forbidden.  In other words, please ask first before you try and  #
# make money off of my program.                                              #
#                                                                            #
# Obtain permission before redistributing this software over the Internet or #
# in any other medium.  In all cases copyright and header must remain intact #
##############################################################################
# Define Variables                                                           #

# This is the file in which all of your random text phrases are stored.      #

$insult_adjective = "/www/docs/logopoeia.com/cgi-bin/insult_adjective.txt";
$insult_compound = "/www/docs/logopoeia.com/cgi-bin/insult_compound.txt";
$insult_noun = "//www/docs/logopoeia.com/cgi-bin/insult_noun.txt";

# The delimiter specifies how each phrase is distinguished from another.  For#
# instance, the common fortune file (a Unix program) is delimited by a new   #
# line followed by two % signs on the next line and then a new line.  This is#
# a pretty good format and you can read more about it in the README file.    #

$delimiter = "\n";

# Done             	                                                     #
##############################################################################

# Open the file containing phrases and read it in.

open(FILE1,"$insult_adjective");
@FILE1 = <FILE1>;
close(FILE1);
open(FILE2,"$insult_compound");
@FILE2 = <FILE2>;
close(FILE2);
open(FILE3,"$insult_noun");
@FILE3 = <FILE3>;
close(FILE3);

# Join these lines from the file into one large string.
$phrases1 = join('',@FILE1);
$phrases2 = join('',@FILE2);
$phrases3 = join('',@FILE3);

# Now split the large string according to the $delimiter.
@phrases1 = split(/$delimiter/,$phrases1);
@phrases2 = split(/$delimiter/,$phrases2);
@phrases3 = split(/$delimiter/,$phrases3);

# Invoke srand; with a seed of the time and pid.  If you are on a machine
# which doesn't put the pid into $$ (ie. Macintosh, Win NT, etc...), change
# this line to:  srand(time ^ 22/7);

srand(time ^ $$);

# Now pluck our random phrase out of the @phrases array!  But wait!  This
# only returns a number.

$phrase1 = rand(@phrases1);
$phrase2 = rand(@phrases2);
$phrase3 = rand(@phrases3);

# Print out the Content-type header, so the browser knows what's going on.

#print "Content-type: text/html\n\n";

# Change this number into the text we want to return and print it!

print "\n", "Thou ", $phrases1[$phrase1], " ", $phrases2[$phrase2], " ", $phrases3[$phrase3], "!\n";

# All Done!

exit;
