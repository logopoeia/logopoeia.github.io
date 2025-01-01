#!/usr/bin/perl

###################################################################
#
# style.cgi (version .80 by smith@io.com)
#
# a Web interface to the GNU "style" program
#
####################################################################

$| = 1;
use CGI qw(:standard);
$query = new CGI;

$styleVersion = `/home/s/smith/bin/style --version`;
chop($styleVersion);

$_ = `/home/s/smith/bin/lynx -dump -nolist -pseudo_inlines dazel`;
#$_ = `/usr/bin/wget www.io.com/~smith/greenberg/ -O -`;

s@<script>[^<]+</script>@@g;
s@<style[^<]*</style>@@g;

s/<([^>]|\n)*>//g;

$_ = $query->param('inputStream');

s/\r\n/\n\n/g;

s/"//g;
s/\s+?'//g;
s/'\s+?//g;

s/ +/ /g;
s/\s+\n+/\n\n/g;
s/([^.!?:])\n\s*?\n/$1.\n\n/g;
s/&.+;\.*\n*//g;
s/[^\w\s.?!:;\[\]{}()-<>i|]/X/g;

$_ = `echo "$_" | /home/s/smith/bin/style`;
chop;

s@\n[^A-Z]*([A-Z][A-Za-z]+)[^A-Z: ]*\n@
\n<tr><td colspan=\"2\"><a name=\"$1\">&nbsp;</a><br><h2 class=\"section\">$1</h2></td></tr>\n@g;


s@\n[^F\n]+Formula[^\s]*\s+[^G]*Grade level.*\n@
<tr>
<th>Formula</th>
<th>Grade level</th>
</tr>@;


# create hyperlinks for formula names, and embed them
# and corresponding scores into HTML table rows

s@(([^\s\n:]+)[^:\n]*?):\s+([^.]+\.\d%*)\n@
<tr>
<td><a href=\"#$2\">$1</a>&nbsp;&nbsp;</td>
<td>$3</td>
</tr>@g;

s/>= /&gt;=&nbsp;/;
s/<= /&lt;=&nbsp;/;

# convert all other style result rows into HTML table rows

s@([^:\n]+):(.+)\n@
<tr>
<td>$1&nbsp;&nbsp;&nbsp;&nbsp;</td>
<td>$2</td>
</tr>\n@g;



# build the HTML

$htmlStream = "
<html>
<head>
<title>Results</title>
<link rel=\"StyleSheet\" href=\"ra.css\" type=\"text/css\">
</head>
<body>
<div align=\"center\">
<h1>Results</h1>
<p class=\"new\">
<a href=\"$ENV{'HTTP_REFERER'}\">Analyze another</a></p>
<hr>
<table>
$_
</table>
</div>
<br>
<hr>
<p class=\"description\">

    <a
     id=\"Flesch-Kincaid\"
     name=\"Flesch-Kincaid\">&#160;</a> 
    <h3
     class=\"scale\">
      Flesch-Kincaid Formula
    </h3>
    <p
     class=\"explanation\">
       The grade-level Flesch-Kincaid formula is based on training manuals for
       adult readers rather than on school textbooks.  Passages of dialog,
       which are usually a series of short sentences, will significantly lower
       a Kincaid score.
    </p>
<pre
 class=\"formula\">
    Flesch-Kincaid grade level = 11.8*syllables/words+0.39*words/sentences-15.59
</pre>
    <p
     class=\"back\">
      [ <a
       href=\"#top\">back to top</a> ]
    </p>
    <a
     id=\"ARI\"
     name=\"ARI\">&#160;</a> 
    <h3
     class=\"scale\">
      Automated Readability Index (ARI)
    </h3>
    <p
     class=\"explanation\">
    </p>
<pre
 class=\"formula\">
    ARI = 4.71*chars/words+0.5*words/sentences-21.43
</pre>
    <p
     class=\"back\">
       [ <a
       href=\"#top\">back to top</a> ]
    </p>
    <a
     id=\"SMOG\"
     name=\"SMOG\">&#160;</a> 
    <h3
     class=\"scale\">
      SMOG Formula
    </h3>
    <p
     class=\"explanation\">
       The grade-level SMOG formula tends to produce higher scores than other
       formulas because it is intended to predict the reading level necessary
       for \"100% comprehension\" of a passage.
    </p>
<pre
 class=\"formula\">
    SMOG formula = square root of ((words &gt;= 3 syll)*sentences*30) + 3
</pre>
    <p
     class=\"back\">
       [ <a
       href=\"#top\">back to top</a> ]
    </p>
    <a
     id=\"Gunning\"
     name=\"Gunning\">&#160;</a> 
    <h3
     class=\"scale\">
      Gunning Fog Index
    </h3>
    <p
     class=\"explanation\">
       The grade-level Gunning Fog Index only produces meaningful scores for
       passages that are <strong>at least 100 words long.</strong> A Gunning
       Fog Index score between 7 and 8 is usually cited as an \"ideal\"
       score, and some sources state that \"most\" people will have difficulty
       reading a passage that scores above 12.
    </p>
<pre
 class=\"formula\">
    Gunning Fog Index = 0.4*(words/sentences+100*((words &gt;= 3 syll)/words))
</pre>
    <p
     class=\"back\">
       [ <a
       href=\"#top\">back to top</a> ]
    </p>
    <a
     id=\"Coleman-Liau\"
     name=\"Coleman-Liau\">&#160;</a> 
    <h3
     class=\"scale\">
      Coleman-Liau Formula
    </h3>
    <p
     class=\"explanation\">
    </p>
<pre
 class=\"formula\">
    Coleman-Liau formula = 5.89*chars/words-0.3*sentences/(100*words)-15.8
</pre>
    <p
     class=\"back\">
       [ <a
       href=\"#top\">back to top</a> ]
    </p>
    <a
     id=\"Flesch\"
     name=\"Flesch\">&#160;</a> 
    <h3
     class=\"scale\">
      Flesch Reading Ease Formula
    </h3>
    <p
     class=\"explanation\">
       The Flesch Reading Ease formula is <strong>not a grade-level
       formula</strong>; instead, it rates the readability of a passage on a
       scale from 0 (very difficult) to 100 (very easy). That is, the
       <strong>higher</strong> a passage scores, the <strong>easier</strong> it
       should be to read. A Flesch score between 60 to 70 is often cited as the
       target for \"average\" readability.
    </p>
<pre
 class=\"formula\">
    Flesch Reading Ease = 206.835-84.6*syll/words-1.015*words/sentences
</pre>
    <p
     class=\"back\">
       [ <a
       href=\"#top\">back to top</a> ]
    </p>
<a name=\"aboutSentences\">&nbsp;</a>
<h3 class=\"sentenceExplanation\">Explanation of Sentence Data</h3>
       <ul>
       <li>A paragraph break is defined as either a single hard return or as
       <em>two or more</em> hard returns, depending on whether or not you have
       checked the \"Paragraph is anything followed by two or more hard
       returns\" box on the input form.  If the paragraph count seems to be
       wrong, try checking or unchecking the box on the input form, and then
       resubmit the passage for analysis.</li>
       <li>A sentence is defined as a sequence of words that  starts  with  a
       capitalized word and  ends with a period, colon, question mark
       or exclamation mark. Heads, subheads and so on that do not end with such
       punctuation are treated both as single sentences and single
       paragraphs.</li>
       <li>A word containing an apostrophe is counted as a single word, not two.
       <li>Numbers  are  counted  as single-syllable words.</li>
       <li> A single letter followed  by  a perios is considered a
       (non-sentence-ending) abbreviation. Various  multi-letter abbreviations
       are also recognized.</li>
       </ul>
    <p class=\"versionInfo\">
    <small>
    The data on this page was generated using the UNIX program 
    <strong>$styleVersion</strong>.
    </small>
    </p>
</body>
</html>";

$_ = `echo '$htmlStream' | /home/s/smith/bin/tidy -m`;

print header;
print;
