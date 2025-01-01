#!/usr/bin/perl

# Get the input
read(STDIN, $buffer, $ENV{'CONTENT_LENGTH'});

# Split the name-value pairs
@pairs = split(/&/, $buffer);

foreach $pair (@pairs)
{
    ($name, $value) = split(/=/, $pair);

    # Un-Webify plus signs and %-encoding
    $value =~ tr/+/ /;
    $value =~ s/%([a-fA-F0-9][a-fA-F0-9])/pack("C", hex($1))/eg;

    # Uncomment for debugging purposes
    # print "Setting $name to $value<P>";

    $FORM{$name} = $value;
}

# If the comments are blank, then give a "blank form" response
&blank_response unless $FORM{'address'};

system "/usr/bin/telnet  $FORM{'address'}";

print "HTTP/1.0 302 Found\n";
print "Location: telnet://$FORM{'address'}:$FORM{'port'}\n\n";


# subroutine blank_response
sub blank_response
{
    print "Content-type: text/html\n\n";
    print "<html><head><title>Telnet Address Required</title></head><body>";
    print "<h1>Telnet Address Required</h1><hr>";
    print "You must fill in an address to telnet to.<br>";
    print "Please return to the last screen and re-enter an address or ";
    print "return to the <a href = file://localhost/usr/local/lib/menush/index.html>menu</a>";
    print "</body></html>";
    exit;
}




