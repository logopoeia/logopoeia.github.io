#!/usr/bin/perl

$| = 1;
use CGI qw(:standard);
$query = new CGI;

$filename = $query->param('file-to-upload');

open(UPLOAD, ">uploadedFile"{);
print UPLOAD <$filename>;
close(UPLOAD);
