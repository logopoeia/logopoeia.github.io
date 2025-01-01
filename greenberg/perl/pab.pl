undef $/; \
s@<div[^c]*?class="poem">@@gis; \
s@<h2[^c]*?class="poem-title">@<div class="poem">\n<h2 class="poem-title">@gis;
