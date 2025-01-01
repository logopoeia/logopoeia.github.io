/* 
 * $Id: crackpot.pb,v 1.13 2002/07/11 04:21:18 smith Exp $
 *
 * this is a variant of the original 
 * crackpot.pb script (copyright 1995
 * Andrew C. Bulhak)
 * 
 * with additions from Michael Smith
 * to power the wisdom mill at:
 * http://www.logopoeia.com/wisdom/
 *
 * please don't redistribute this file 
 *
 */

Start: S;

#include <stdmap.pbi>
#include <format.pbi>

// rules

S: PROLOGUE TITLE(title>upcase) 
	BODY 
	sentence-stream+ PBRK 
	paranoid-sentence-stream+ PBRK 
	factoid-paragraph PBRK
	exhortation EPILOGUE ;

title: "\n>> " solution 
       [""|
        ": " 
	[ "the " ["solution"|"answer"] " to all " problem-types " problems"
	| "the end of " evils
	]
       ]
	" <<\n"
;

// bits used in paranoid sentences

destroyed-something:

 	  ["burned down the Great Library of Alexandria"
	  |"destroyed Solomon's temple"
	  |"destroyed the Colossus of Rhodes"
	  |"built Weather Mountain"
	  |"hid the Holy Grail" 
	  |"hid the Ark of the Covenant"
	  |"built the Great Pyramid at Giza"
	  |"constructed Stonehenge"
	  |"have criminalized LSD"
	  |"spread a secret mind-control substance using an altered electrolyte formula in ballooned/leaking capacitors"
	  
	  ]

    " to " ulterior-purpose
;

screwed-with-great-pyramid:

 	    ["moved the Great Pyramid"
	    |"changed the Great Pyramid's height"
	    ] 

	    " to destroy its " 
	
	    ["astronomical"
	    |"astrological"
	    |"geometric"
	    |"harmonic"
	    ]
	    
	    " alignment. "
;

//
// Sentences
//

// paranoid sentences, i.e., those about conspiracies, suppression, etc.

paranoid-sentence-stream:

	they
	" destroyed " 
	one-who-knew-too-much 
	" because "
	
	"he " 

	["knew too much. "
	|"chanced upon these secrets. "
	|"uncovered these secrets. "
	|"accidentally discovered these secrets. "
	]

	| one-who-knew-too-much
	" knew " 

	["too much"
	|"all"
	|"everything"
	]
	
	" about "
	solution 
	
	"; that is why "
	they

	" "

	["destroyed"
	|"eliminated"
	|"annihilated"
	|"silenced"
	]

	" him. "

	| "All "

	["books"
	|"historical accounts"
	|"historical records"
	|"of the world's religious texts"
	]

	" were " 
	
	["altered"
	|"rewritten"
	]
	
	" to " ulterior-purpose

	| ["The speed of light"
	  | "Our DNA"
	  ] 

	" was altered to "

	ulterior-purpose


	| specific-they

	  " are using "

           [
	    [ muscle-pawns 
	    | conspirator-pawns]

	    " as " 

	    ["muscle"
	     |"instruments"
	     |"puppets"
	     |"pawns"
	     |"tools"

	    ] 

	  
	    " in their "
	  
	    ["master plan"
	    |"scheme"
	    |"plot"

	    ]
	   |
	   seemingly-benign-pawns
	   |
	   sinister-technology
	  ]
	    
	  " to "

	ulterior-purpose

	
	| "They altered " 
	
	  ["the Bible"
	  |"the speed of light"
	  |"the Sphinx"
	  |"the Dead Sea Scrolls"
	  |"the Nag Hammadi Library"
	  |"our DNA"
	  |"the HyperNet"
	  |"the Apache Web Server default configuration file"
	  |"the gcc compiler internals"
	  |"the Linux kernel"
	  ]

	  " to " ulterior-purpose


	| "They " 
          [destroyed-something
	  |destroyed-something
	  |destroyed-something
	  |screwed-with-great-pyramid
 	  ]


	| "They have suppressed the facts about " 

	  ["UFOs"
	  |"ESP"
	  |"XHTML"
	  |"the South African grooved spheres"
	  |"the Zagreb mummy"
	  |"the HyperNet"
	  |"the Voynich Manuscript"
	  |"the superiority of quoted attribute values"
	  |"the value of the XML empty-tag syntax"
	  |"black holes"
	  |"the value of namespaces"
	  |"the value of draconian error-handling"
	  |"the value of XML/XHTML well-formedness"
	  |"dark matter"
	  |"the technical merits of the Ogg Theora video codec"
	  ]

	  " to " ulterior-purpose

	| they 

	  " "
	
	 ["don't want anyone to know the"

	|"are " 
	
	  ["ruthlessly"
	  |"systematically"]

	  " "
	
	  "suppressing"
	
	  " knowledge of the"
	]

	" " 
	something-of-issue solution
	
	[""|" and "
	
	"will"

	" "
	
	["destroy"
	|"exterminate"
	|"annihilate"
	] 

        " anyone who "
	
	["gets in their way"
	|"confronts them"
	|"exposes their secrets"
	]
	
	", as they did "
	
	one-who-knew-too-much 

	] ". "

	;


ulterior-purpose: ["hide"|"conceal"] " the " something-of-issue solution ". ";

// "the cosmic secret of *", "the truth about *"

something-of-issue: cond-upcase([

        [""
	|"cosmic "
	]

	"truth"
	])

	" about "

	| cond-upcase([

	[""
	|"cosmic "
	]
	
	"secret"
	
	]) " of "
;

they:	v-them<<new-they | new-they ;

new-they: general-they | specific-they | specific-they
           | specific-they | specific-they
;

general-they: ["THEY"
	  | "they" 
          | "they"
	  ]
;

absolute-secret-master-conspirators:
          "the Illuminati"
	  | "the Nine Unknown Men"
	  | "the Black Lodge"
	  | "the Secret Masters"
	  | "the Six-Fingered Hand"
	  | "the Secret Overlords"
	  | "the Secret Underground "
	    [""
	    |"World "
	    ] 
	    "Society" 
	  | "the College of Cardinals" 
	  | ["GOD"
	    |"God"
	    |"Yahweh"
	    ] " and his "
	       ["followers"
	       ]
;

conspirator-pawns:
	  "the Rosicrucians" 
	  | "the Knights Templar"
	  | "the Jesuits"
	  | "the Rothschilds"
	  | "the Club of Rome"
	  | "the Pope Ratzinger-led Vatican"
	  | "the Trilateral Commission"
	  | "David Rockefeller and Henry Kissinger"
	  | "the Council on Foreign Relations"
	  | "the major browser vendors"
	  | "Opera, Mozilla, Apple, Google, and Microsoft"
	  | "the masters of the worldwide money "
	    ["conspiracy"
	    |"cabal"
	    ]
          | "the Roman Catholic Church"
       	  | "the Freemasons"
       	  | "the W3C"
       	  | "the W3C TAG"
	  | "the Opera, Mozilla, Apple, Google, and Microsoft browser-development teams"

;

muscle-pawns:
	  "the FBI"
	  | "the Mafia"
	  | "the Cosa Nostra"
	  | "the Council on Foreign Relations"
	  | "the National Security Agency"
	  | "the W3C TAG"
	  | "Opera, Mozilla, Apple, Google, and Microsoft"
	  | "the major browser vendors"

;

specific-they:
          [ absolute-secret-master-conspirators
	  | conspirator-pawns]

	  [""
	  |""
	  |""
	  |""
	  |""
	  |" and their "
	  
	    ["agents"
	     |"minions"
	     |"instruments"
	     |"puppets"
	     |"pushpuppets"
	     |"slaves"
	     |"thugs"
	     |"playthings"
	     |"little ragdolls"
	     |"talking monkeys"
	     |"pawns"
	     |"tools"
	     |"servants"
	     |"henchmen"
	     |"lapdogs"
	     |"accomplices"
	     |"accessories"

	    ]

	    ", "

          [ muscle-pawns 
	  | conspirator-pawns]
	  
	  ", "]
;

seemingly-benign-pawns:
         "so-called "
	   ["'anti-terrorism' efforts"
	   |"'public-health' organizations"
	   |"'public-education' systems"
	   
	   ]

	|"the United Nations"
	|"the W3C"
	|"the W3C TAG"
	|"the W3C HTML Working Group"
	|"the W3C XHTML2 Working Group"
	|"the Unicode Consortium"
	|"the major browser vendors"
	|"Opera, Mozilla, Apple, Google, and Microsoft"
	|"the MP/LA Expert Group"
	|"the ECMAScript Technical Committee"
	|"the Centers for Disease Control"
	|"NASA"
	|"the World Trade Organization"
	|"the High-frequency Active Auroral Research Project"
;

sinister-technology:
        ["Very"|"Extreme"|"Ultra"] " Low Frequency radio waves"
	|[""|"Tesla-style"] " electromagnetic manipulation of the "
	   ["ionosphere"|"Van Allen belts"|"atmosphere"]
	|"flouridated drinking water"
	|"non-well-formed HTML"
	|"well-defined HTML error handling"
	|"the XMLHttpRequest object"
	|"the HyperNet"
	|"manipulation of the world's drinking-water supply"
	|"HAARP antenna arrays"
	|"the MPEG4 video codec"
	|"microchip" ["s implanted in newborns"|" implants"]
	|"manipulation of natural bioelectrical resonance frequencies"
;

one-who-knew-too-much: "Wilhelm Reich"
                       | "Galileo"
		       | "Giordano Bruno" 
		       | "Jacques de Molay"
                       | "JFK"
		       | "Judas"
		       | "Pope John Paul I"
		       | "Fibonacci"
	               | "Jesus"
		       | "John the Baptist"
		       | "Michael Servetus"
	               | "Robert Oppenheimer"
	               | "*Samuel Greenberg* <www.logopoeia.com/greenberg/>"
	               | "*Novalis* <www.logopoeia.com/novalis/>"
                       | "Tesla"
;

sentence-stream: simple-statement justification 
	law 

	[ " is encoded in "
        | " is embedded in "
        | " is encrypted in "
        | " is enciphered within "
        | " is backward-masked within "
        ]

	[ "the Bible"
	|"*Highlights Magazine* <www.highlights.com/magazine>"
	|"*Guideposts Magazine* <www.guideposts.com/>"
	|"Reader's Digest"
	|"the Lascaux cave paintings"
	|"the Gospel of Thomas"
	|"the works of Shakespeare"
	|"the Ogg Theora video codec"
	|"the MPEG4 video codec"
	|"the *HTML5 specification* <www.whatwg.org/specs/web-apps/current-work/>"
	|"*Anne van Kesteren's weblog* <annevankesteren.nl/>"
	|"video presentations at the *standardssuck site* <standardssuck.org/>"
	|"the *WebKit memes site* <webkitmemes.tumblr.com/>"
	|"the *W3C memes site* <w3cmemes.tumblr.com/>"
	|"the decimal expansion of pi"
	|"the Voynich Manuscript"
	|"the Dead Sea Scrolls"
	|"the Nag Hammadi Library"
	|"Tesla's missing papers"
	|"the Torah"
	|"the US one dollar bill"
	|"*specially modified shortwave radio english* <www.logopoeia.com/radio/>"
	  " broadcasts"
	|"the novel "
	   "*Killoyle* <www.logopoeia.com/killoyle/>"
	    " by Roger Boylan"
	|"the works of "
	    "*Samuel Greenberg* <www.logopoeia.com/greenberg/>"
	|"Novalis's "
	   "*Hymns to the Night* <www.logopoeia.com/novalis/hymns.html>"
	|"*xmlhack* <xmlhack.com>"
	   " Editor's Newswire stories"
	|"a 'faulty' electrolyte formula in ballooned/leaking capacitors"

	]
	
	[". "
	|". "
	|". "
	|". "
	|". "
	|". "
	 |" using "
	   ["interlocking"
	   ]
	   " "
	   ["sets of Fibonacci sequences"
	   ]
	   ". "
	]
	
	| 
	[
	    ["Great"
	    |"Eminent"
	    ]
	    
	    " "
	    
	    ["minds"
	    |"thinkers"
	    |"men"
	    |"scientists"
	    |"visionaries"
	    |"researchers"
	    ]

	    " throughout history: "
	    
	    [eminent ", "]+ " etc, "

	    " agree on "

	  |"The "
	  
	    [ "Aztecs"
	    | "ancient Egyptians"
	    | "Sumerians"
	    | "Mayans" 
	    | "Zoroastrians"
	    | "Essenes"
	    | "Gnostics"
	    | "Nag Hammadi"
	    | "Toltecs" 
	    | "makers of Stonehenge"
	    | "ancient Druids" 
	    | "Vikings"
	    | "Manichaeans" 
	    | "Cathars"
	    | "Albigensians" 
	    | "ancient Hebrews" 
	    | "statue builders of Easter Island"
	    | "Etruscans"
	    | "Alchemists"
	    | "Atlanteans" 
	    | "Pyramid builders" 
	    | "Anasazi" 
	    | "ancient astronauts" 
	    | "Old Testament prophets" 
	    ]

	   " knew that "
	]

	  law " is the " 
	  
		[ "guiding principle of"
		| "governing law of"
		| "fundamental truth behind"
		| trans-adj " principle behind" 
		] " "
		
        	["all creation"
		| "the stars"
		| "all nature"
		| "the Universe"
        	| "all religions"
		]
	". "

	| "ALL "
	
	["historical "
	|"modern"
	|"human"
	|"of mankind's"
	|"of the world's"
	]

	" "

	["evils"
	|"problems"
	|"social ills"
	|"misconceptions"
	|"inequalities"
	] 

	" stem from the failure to "
	
	["embrace"
	|"recognise"
	|"accept"
	]  

	" "
	
	[""
	|"and "
	
	["live by"
	|"be governed by"
	]

	" "
	
	]
	law ". "
;

eminent: "Einstein"
         | "Newton"
	 | "Tesla" 
	 | "Galileo"
	 | "Copernicus" 
	 | "Dr Seuss" 
	 | "Roger Bacon"
	 | "Fred Brooks"
	 | "Bjoern Hoermann"
	 | "Evel Knievel"
	 | "Donald Knuth"
	 | "Unfrozen Caveman Laywer"
	 | "Kwai-Chang Caine"
	 | "Douglas Crockford"
	 | "Zack A. Shaw"
	 | "Pimp Bot"
	 | "Steve Jobs"
	 | "Jack Handey"
	 | "Paracelsus"
	 | "Descartes"  
	 | "Al'Khwarizmi"
	 | "Al-Jabr"
	 | "Anne van Kesteren"
	 | "Roger and Mike"
	 | "Ian Hickson"
	 | "Philip 'canvex' Taylor"
	 | "Roy Fielding"
	 | "the W3C TAG"
	;

simple-statement: numeric-analogy(["two"|"three"|"four"|"five"|"six"|"seven"|"eight"|"twelve"]);

numeric-analogy(number): "Just as there are " [""|"only "]  number " " 
	@number>append-things ", there are " [""|"only "]  number " " 
	@number>append-things ". "
;

justification: solution [" is the logical result of " | " is an inevitable outcome of " | " follows directly from "] cond-upcase(new-law) ". "
;

append-things:
	".*" -> "$"/"-things"
;

two-things: "sides to a coin"
  |  "sides to a story"
  |  "ways a pendulum can swing"
;

three-things: "entities in the Holy Trinity"
              | "dimensions"
	      | "horns on a triceratops"
	      | "feet in a yard"
	      | "colors on the flag" 
	      | "colors on a traffic signal"
	      | "rings in a three-ring circus"
	      | "wheels on a tricyle"
	      | "letters in the word 'W3C'"
	      | "days in a three-day weekend"
	      | "component colours in white light" 
	      | "primary colors"
	      | "sides to a triangle"
	      | "corners on a three-cornered hat"
;

four-things: "seasons"
             | "cardinal directions" 
	     | "points on a compass"
	     | "letters in the true name of God"
	     | "gospels in the Bible"
	     | "suits in a deck of cards"
	     | "leaves on a four-leafed clover"
	     | "legs on a chair"
	     | "legs on a table"
	     | "major oceans"
	     | "weeks in a month"
	     | "letters in the word 'HTML'"
	     | "quarters to one US dollar"
	     | "temperaments"
	     | "Horseman of the Apocalypse"
	     | "days in a four-day weekend"
	     | "corners of the World"
	     | "races of " ["Man"|"humanity"] 
	     | "fundamental elements"
	     | "sides on a square"
	     | "characters in the string 'H264'"
;

five-things: "axioms of Euclid's Geometry" 
             | "fingers on a human hand"
	     | "sides to the pyramid on the US dollar bill"
	     | "sides on the Pentagon building"
	     | "corners on a pentagram"
	     | "pennies to one US nickel"
	     | "rings in the Olympic symbol"
	     | "days in a working week"
	     | "senses"
	     | "petals on a wild rose"
	     | "vowels in the Alphabet"
	     | "letters in the word 'XHTML'"
	     | "letters in the word 'HTML5'"
	     | "types of major organs in the human body"
	     | "Great Lakes"
	     | "major browser vendors"
;

six-things: "continents" 
             | "days in a Japanese work week"
             | "corners on the Star of David"
	     | "legs on an insect"
	     | "feet in a fathom"
	     | "sides on dice"
	     | "letters in the name of the Antichrist"
	     | "players on an ice hockey team"
	     | "sides to a honeycomb"
	     | "fingers on a six-fingered man's hand"
;

seven-things: "days in the week"
              | "cavities in the human body"
              | "electrons in a nitrogen atom"
	      | "deadly sins"
	      | "wonders in the ancient world"
	      | "Liberal Arts"
	      | "Ages of Man"
	      
;

eight-things: "notes in an octave"
              | "legs on a " ["spider"|"scorpion"|"octopus"]
	      | "cylinders in a V-8 engine"
	      | "pints in a gallon"

;

twelve-things: "Apostles"
               | "hours on a clock"
	       | "inches in a foot" 
	       | "months in a year"
	       | "signs of the Zodiac"
	       | "eggs in a dozen"
	       | "members on a jury"
	       | "days of Christmas"
	       | "tones on the chromatic scale"
	       | "sides on a pair of dice"
;

// concrete factoids

factoid-paragraph:
	concrete-factoid factoid-consequence
;

factoid-consequence:
	cond-upcase("only") 
	" from " law " can one "

	["derive"
	|"compute"
	|"calculate"
	] " the "
	
	cond-upcase([
	"true structure of matter"
	|"missing mass of the universe"
	|"true orbits of the planets"
	|"universe's missing day"
	|"true distance to the nearest inhabited solar systems"
	|"codes for unlocking the secrets hidden in our DNA"
	|"codes for unlocking the truths suppressed throughout history"
	|"truth about the ballooned/leaking capacitor electrolyte formula conspiracy"

	]) ". ";

concrete-factoid: number-name " is " bogus-number ". "
	| "the true " [""|"hidden "|"suppressed "] "value of pi is 3 point "
	["0"|"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"]+ 
	[""|"; all " 
	
	["mathematics textbooks"
	|"religious texts"
	|"mathematical laws"

	] " have been "

	["altered"
	|"rewritten"
	|"changed"

	]" to "
	
	["hide"
	|"conceal"

	] " this"]
	". "
;

number-name: "the " 
	cond-upcase([
	  ["cosmic"
	  |"universal"

	  ]
	  
	  " " law-adj " constant"]);

bogus-number: ["1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"] 
	["0"|"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"]* 
	[""|"." [["0"|"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"]+]+ ]
;

//
// Exhortations and the like
//

exhortation: cond-upcase([[

	"End "
	
	evils
	] " -- " imperative])

	| {num_steps=3..5; step=1}
	"\n\n"
	%repeat(step,num_steps)
	
	"\n..." 
	[""
	| "IT'S THAT EASY!" 
	| "NOTHING COULD BE SIMPLER!"]
;

step: $step ". "
	[
	 [["Adopt"
	  |"Learn"
	  |"Memorize"
	
	  ] " " solution "." 
         
	  |
	  ["Drink the holy fire."
	  ]
	 ]
	
	|

	[["Adopt"
	|"Accept"
	
	] " " solution " as"
	
	|
	
	"Make " solution 
	| "Let " solution " be"

	]" your guide." 
	
	|

	"Reject the "
	
	[cond-upcase(evil-adj) | cond-upcase(foolish-adj)]

	[""|" and " [cond-upcase(evil-adj) | cond-upcase(foolish-adj)] 

	] " " ["doctrine of"
	      |"dogma of"
	      |"belief in"
	      |"notion of"

	      ] " "
		[
		"'one man, one vote'"
		|"participatory democracy"
		|"decentralized extensibility"
		|"XML namespaces"
		|"draconian error-handling"
		|"elective democracy"
		|"'civilization'"
		|"'human rights'"
		|"'government by the people, for the people'"
		|"the Golden Rule"
		|"self-denial"
		|"'affordable computing'"
		// |"the spherical Earth"

		] "." |

	["Turn away from"
	|"Free yourself from"

	]

	" "
	
	["the"
	|"Satan's"
	|"the One World Government's"
	|"the worldwide money conspiracy's"

	] 
        
	" "

	[""
	|"secret"

	]

	" "

	["international"
	|"global"
	|"worldwide"
	|"underground"

	]

	" "

	["money-power"
	 |"media-brainwashing"
	 |"truth-suppression"
	 |"thought-suppression"

	]

	" "
	
	["empire"
	|"cartel"
	|"police force"
	|"machine"

	]"."
	] "\n"
	{ step=step+1 }
;

evil-adj: "evil"
          | "immoral" 
	  | "Satanic" 
	  | "demonic"
          | "anti-democratic"
;

foolish-adj: "misguided" 
             | "short-sighted"
	     | "hopelessly myopic" 
	     | "foolish" 
	     | "senseless"
	     | "absurd"
	     | "thoughtless" 
	     | "counter-productive" 
	     | "undiscerning"
	     | "preposterous" 
	     | "bizarre"
;

imperative: "adopt "

[ solution | long-solution ] " now!. " ;

long-solution: ["government"
               |"religion"
	       |"a personal philosophy"
	       
	       ] " based on " solution
;

problem-types: problem-type ", " problem-type " and " problem-type
;

problem-type: "economic"
              | "political"
	      | "financial"
	      | "health"
              | "moral"
	      | "philosophical" 
	      | "religious"
	      | "social" 
	      | "psychological"
	      | "energy"
	      | "sexual"
	      | "spiritual"
;

achievements: achievement
	| [ achievement ", " ] + achievement " and " achievement
	| [ achievement ", " ] "etc "
;

achievement: ["immeasurable"
             |"ultimate"
	     
	     ] " " 

             ["personal satisfaction"
	     |"peace"
	     |"happiness"

	     ]

	| [ "ultimate " | "" ] achievement-2;

achievement-2:

	"enlightenment" 
	| "omniversal awareness" 
	| "tantric sexual self-awareness"
	| "cosmic power" ;

evils: evil ", " [ evil ", " ] + "etc";

evil: "wars"
      | "unemployment" 
      | "racism"
      | "poverty" 
      | "famine"
      | "violence" 
      | "disease"
      | "drug addiction" 
      | "overpopulation"
      | "terrorism" 
      | "sexual frustration"
      | "pollution"
;

solution:
	theory-name " " 
	[ "physics" 
	| "biophysics"
	| "kinematics"
	| "astrochemistry"
	| "psycho-" ["history"|"history"|"history"|"ceramics"]
	| "mechanics"
	| "optics"
	| "theory"
	| "mathematics"
	| "science"

	] | law | law
	;

law:	v-law-1<<new-law | v-law-2<<new-law
	| v-law-1<<new-law | v-law-2<<new-law
	| new-law ;

new-law:	 ["the law of " law-name|"the LAW of " law-name>upcase]
	| "the " ["" | trans-adj " "] ["principle of " | "precept of "| "rule of "] law-name
	| "the " ["" | trans-adj>upcase " "] ["principle of " | "precept of " | "rule of "] law-name

	| law-adj " law"

// not strictly laws per se, but similar enough grammatically
	| "the cycle of " law-name
;

// transcendental adjectives: "the * principle of Universal Normalisation"

trans-adj: "indisputable" 
           | "scientific"
	   | "fundamental" 
	   | "unarguable" 
	   | "self-evident" 
;

// laws: "the law of *"

law-name: law-adj " " law-subject
	| law-adj " " law-subject
	| law-adj "-" law-adj " " law-subject
;

law-adj:
[""|""|"electro-"|"vibro-"|"pseudo-"|"psycho-"|"astro-"|"meta-"|"anti-"|"quasi-"|"bio-"]
         ["volumetric" 
	 | "atomic" 
	 | "harmonic" 
	 | "universal" 
	 | "spontaneous"
         | "cosmic" 
	 | "psychic" 
	 | "consciousness" 
	 | "natural" 
	 | "time" 
	 | "temporal" 
	 | "luminescent" 
	 | "democratic" 
	 | "socialist"
	 | "humanitarian"
	 | "nihilistic"
	 | "pendulum"
	 | "HyperNet"
		 | "tantric" 
	 ]
;

law-subject: "normalisation" 
             | "conduction"
	     | "entropy"
	     | "order"
             | "equivalence" 
	     | "equilibrium"
	     | "stability"
	     | "instability"
	     | "neutralization"
	     | "reactivity"
	     | "metamorphosis"
	     | "justice" 
	     | "duality" 
	     | "compensation" 
	     | "equality" 
	     | "inequality"
;

// theory names: "* physics"

theory-name: ["resonation" 
             | "vibrational" 
	     | "object-oriented"
	     | "analytical"
	     | "arithmetic"
	     | "transactional"
	     | "functional"
	     | "relational"
	     | "transformational"
	     | "non-denominational"
             | "anti-dynamic" 
	     | "anti-mechanical" 
		 | "tantric" 
	     ]

	| theory-adj " " theory-subject " " theory-modality
	| theory-adj " " theory-modality
;

theory-adj: "unified" 
            | "resonating"
	    | "harmonic"
	    | "cosmic" 
	    | "total"
	    | "timbral"
	    | "spontaneous"
	    | "universal" 
	    | "pendulum" 
	    | "HyperNet" 
	    | "symmetrical"
	    | "quantum" 
	    | "kinetic" 
	    | "Holy Ghost" 
	    | "Holy Spirit"
	    | "Holy Ghost" 
	    | "Holy Spirit"
	    | "Holy Ghost"
	    | "Holy Spirit"
;

theory-subject: "reality" 
                | "energy" 
		| "gravity"
		| "magnetism"
		| "fusion"
		| "radiation"
                | "electricity"
		| "cosmology" 
		| "chaos" 
		| "entropy"
;

theory-modality: "field" 
                 | "wave"
		 | "raster"
		 | "vector" 
		 | "matrix" 
		 | "tantric" 
	    | "pendulum" 
	    | "HyperNet" 
;

// utility rules

cond-upcase(foo): foo | foo>upcase | foo | foo>upcase ;
