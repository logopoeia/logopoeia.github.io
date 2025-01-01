undef $/; \
s@<table([^"]*?)"@<table$1summary=""$1"@gis;
s@<span([^c]*?)class="indent-(.*?)">\&\#160\;\&\#160\;</span>@<div$1class="indent-$2">@gis;
