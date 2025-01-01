undef $/; \
s@class="poem-title">(.*?)</h2>@class="poem-title">$1</h2>\n<div class="poem">@gis;\
s@<p[^c]*?class="poem-nav">@</div>\n<p class="poem-nav">@gis;
