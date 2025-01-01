#!/bin/sh
# $Id: crackpot.sh,v 1.1 2002/07/09 10:59:46 smith Exp $
/usr/share/nginx/www/logopoeia.com/cgi-bin/dada /usr/share/nginx/www/logopoeia.com/cgi-bin/wisdom/crackpot.pb \
| perl -p -e \
'undef $/; \
s#>>#<h4 class="solutiontitle">#g; \
s#<<#</h4>#g; \
s#\*([^\*]+)\*\s+<([^>]+)>#<a href=\"http://$2\">$1</a>#g; \
s#\n\s*(1\.\s)#<ol>\n<li>#g; \
s#\n\s*([0-9]\.\s)#<li>#g; \
s#\n\.\.\.#</ol>#g; \
s#----##g;
s#\n\n#^LINEBREAK^#g;
s#\n##g;
s#\^LINEBREAK\^#\n#g';
#
# The perl stuff above:
#
#  * wraps the solution title in <strong>
#  * parses for web addresses and turns them into hyperlinks
#  * turns step into an ordered list
#  * strips out "----"
#  * replaces all blank lines with ^LINEBREAK^
