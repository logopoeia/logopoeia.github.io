#!/bin/sh
echo "Content-type: text/plain"
perl -w /home/s/smith/public-web/cgi-bin/write.cgi >& /tmp/error_msg
echo
cat /tmp/error_msg




