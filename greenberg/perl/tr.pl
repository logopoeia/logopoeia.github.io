undef $/; \
s@<table align=center border="0" cellspacing="0">\n<tr>\n<td>\n(<a name=".*?">&nbsp;</a>(.*?))</td></tr></table>@$1@gis; \
s@<p align=center><strong>(.*?)</strong>\n</p>\n<p align=left>@<h2 class="poem-title">$1</h2>\n<p class="poem">@gis; \
s@<p align=center><small><a href="#top">@<p class="poem-nav"><small><a href="#top">@gis
