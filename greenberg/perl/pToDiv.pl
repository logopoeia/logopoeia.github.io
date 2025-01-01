undef $/; \
s@<br />([^<]*?)<span@$1<span@gis;
s@<span([^c]*?)class="indent-(.*?)">\&\#160\;\&\#160\;</span>@<div$1class="indent-$2">@gis;
