/* $Id: software_exec_in_a_box.js,v 1.13 2003/01/14 10:50:37 smith Exp $

   Copyright (C) 2002 by Logopoeia.

   This is a modified version of the application "BuzzPhraser",
   which is Copyright (C) 2000 by Doc Searls and Charles Roth.

   Permission is hereby granted, free of charge, to any person obtaining 
   a copy of this software and associated documentation files (the 
   "Software"), to deal in the Software without restriction, including 
   without limitation the rights to use, copy, modify, merge, publish, 
   distribute, sublicense, and/or sell copies of the Software, and to 
   permit persons to whom the Software is furnished to do so, subject 
   to the following conditions:

   The above copyright notice and this permission notice shall be 
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
   CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

   The original BuzzPhraser source code and documentation is
   available at: http://www.buzzphraser.com/

*/

phrases = new Array(); 

function zeroes(n) {
  newarray = new Array (n);
  for (i=0;   i<n;   ++i)  newarray[i] = 0;
  return (newarray);
}

function resetparms() {
  dp = document.panel;
  dp.dict.selectedIndex   = 0;
  dp.noun.selectedIndex   = 0;
  dp.suffix.selectedIndex = 0;
  dp.adnoun.selectedIndex = 1;
  dp.adject.selectedIndex = 1;
  dp.adverb.selectedIndex = 1;
  dp.prefix.selectedIndex = 0;
}

function addphrase() {
  dp = document.panel;
  dict     = techno;
  if (dp.dict.selectedIndex == 1)  dict = collab;
  n_noun   = parseInt(dp.noun.options  [dp.noun.selectedIndex].value);
  n_suffix = parseInt(dp.suffix.options[dp.suffix.selectedIndex].value);
  n_adnoun = parseInt(dp.adnoun.options[dp.adnoun.selectedIndex].value);
  n_adject = parseInt(dp.adject.options[dp.adject.selectedIndex].value);
  n_adverb = parseInt(dp.adverb.options[dp.adverb.selectedIndex].value);
  n_prefix = parseInt(dp.prefix.options[dp.prefix.selectedIndex].value);

  /*** Apply limits based on other parts of speech. */
  n_prefix = Math.min (n_prefix, n_adject);
  n_suffix = Math.min (n_suffix, n_adnoun);

  /*** Assemble the entire phrase, from right to left.  First noun(s),
    /    then their adnouns (with *their* suffixes), then adjectives
    /    (and *their* prefixes), and finally the adverb(s). */

  /*** Nouns */
  used = zeroes (dict.nouns.length);
  part = "";
  for (i=0;   i<n_noun;   ++i) {
    do { r = Math.floor (Math.random() * used.length); } while (used[r]) ;
    part = part + ' ' + dict.nouns[r];
    used[r] = 1;
  }
  phrase = part;

  /*** Adnouns (and suffixes) */
  used = zeroes(dict.adnouns.length);
  part = "";
  for (i=0;   i<n_adnoun;   ++i) {
    do { r = Math.floor (Math.random() * used.length); } 
    while (used[r]) ;
    word    = dict.adnouns[r];
    used[r] = 1;
    if (i < n_suffix)  
      word = word + dict.suffixes[Math.floor(Math.random() * 
          dict.suffixes.length)];
    part = part + ' ' + word;
  }
  phrase = part + phrase;

  /*** Adjectives (and prefixes) */
  used = zeroes(dict.adjectives.length);
  part = "";
  for (i=0;   i<n_adject;   ++i) {
    do { r = Math.floor (Math.random() * used.length); } 
    while (used[r]) ;
    word    = dict.adjectives[r];
    used[r] = 1;
    if (i < n_prefix)  
      word = dict.prefixes[Math.floor(Math.random() * 
          dict.prefixes.length)] + word;
    part = part + ' ' + word;
  }
  phrase = part + phrase;

  /*** Adverbs */
  used = zeroes (dict.adverbs.length);
  part = "";
  for (i=0;   i<n_adverb;   ++i) {
    do { r = Math.floor (Math.random() * used.length); } 
    while (used[r]) ;
    part = part + ' ' + dict.adverbs[r];
    used[r] = 1;
  }
  phrase = part + phrase;

  return (phrase);
}

function showthem() {
  pbd = parent.bot.document;
  pbd.open();
     pbd.write ('<html>\n');
     pbd.write ('  <body bgcolor="#ffffff" text="black">\n');
     pbd.write ('      <ul>\n');
     for (i=phrases.length-1;   i>=0;   --i)
        pbd.write ('        <li>' + phrases[i] + '</li>\n');
     pbd.write ('      </ul>\n');
     pbd.write ('  </body>\n');
     pbd.write ('</html>\n');
  pbd.close();
}

/*** Dictionaries: TechnoLatin, CollaboLatin, etc. */
var techno = new Object();
var collab = new Object();
var dict   = techno;

/*** noun_list */
techno.nouns = new Array (
    "Access", "Activities", "Activities", "Activation",
    "Adoption", "Alignment", "Alliance", "Analysis", "Aperture",
    "Architecture", "Automation", "Availability", "Barrier",
    "Behavior", "Breakthrough", "Business", "Buy In", "Capacity",
    "Center", "Capability", "Capacity", "Challenge", "Channel",
    "Commitment", "Competence", "Communications", "Compatibility",
    "Compliance", "Concept", "Component", "Configuration",
    "Connection", "Connectivity", "Constraints", "Content",
    "Context", "Contingency", "Control", "Convergence", "Core",
    "Credibility", "Criteria", "Data", "Decision", "Delivery",
    "Demand", "Development", "Design", "Differentiation",
    "Diffusion", "Ecology", "Ecosystem", "Engagement",
    "Enhancement", "Distribution", "Environment", "Evolution",
    "Exchange", "Feature", "Flexibility", "Flow", "Focus",
    "Framework", "Function", "Functionality", "Gap", "Generation",
    "Glare", "Growth", "Guideline", "Impact", "Implementation",
    "Incubation", "Influence", "Infrastructure", "Initiative",
    "Innovation", "Integration", "Intelligence", "Interface",
    "Leadership", "Leverage", "Life-Cycle", "Linkage",
    "Management", "Manipulation", "Map", "Matrix", "Mechanism",
    "Message", "Messaging", "Method", "Milestone", "Mobility",
    "Model", "Need", "Network", "Objective", "Offering",
    "Offerings", "Operation", "Opportunity", "Option", "Package",
    "Paradigm", "Parameter", "Partner", "Partnership",
    "Philosophy", "Platform", "Policy", "Portfolio", "Portal",
    "Position", "Positioning", "Potency", "Power", "Practices",
    "Process", "Processing", "Product", "Production",
    "Productivity", "Progress", "Proposition", "Protocol",
    "Provider", "Reference", "Relationship", "Redunancy",
    "Relevance", "Resource", "Revenue", "Roadblock", "Roadmap",
    "Server", "Service", "Services", "Shift", "Source",
    "Solution", "Specification", "Spending", "Standard",
    "Standards", "Strategy", "Structure", "Success", "Supplier",
    "Support", "Synchronization", "System", "Systems", "Target",
    "Team", "Technology", "Transactions", "Usage", "Utilization",
    "Vendor");

techno.suffixes = new Array (
    "-Access", "-Active", "-Area", "-Aware", "-Based", "-Capable",
    "-Class", "-Compatible", "-Connected", "-Dependent",
    "-Determinable", "-Driven", "-Enabled", "-Focused",
    "-Friendly", "-Grade", "-Intensive", "-Layer", "-Leading",
    "-Led", "-Level", "-Oriented", "-Phase", "-Powered", "-Ready",
    "-Referenced", "-Structured");

techno.prefixes = new Array (
    "Backward-", "Backwards-", "Client-", "Cross-", "Data-",
    "Demand-", "Extra-", "Low-", "High-", "Industry-", "Inter-",
    "Intra-", "Internet-", "Multi-", "Power-", "Server-", "Upward-",
    "Upwards-", "Web-");

techno.adnouns = new Array (
    "Account", "Activation", "Alternative", "Alliance",
    "Analysis", "Application", "Applications", "Architecture",
    "Area", "Automation", "Availability", "Breakthrough",
    "Business", "Capacity", "Carrier", "Channel", "Client",
    "Client-Server", "Commitment", "Compatibility", "Component",
    "Concept", "Configuration", "Connection", "Connectivity",
    "Context", "Contingency", "Control", "Convergence",
    "Customer-Satisfaction", "Customer", "Customer", "Deployment",
    "Design", "Development", "Device", "Differentiation",
    "Diffusion", "Distribution", "Ecosystem", "Enhancement",
    "Exchange", "Feature", "Field", "Freedom", "Function",
    "Functionality", "Generation", "Implementation", "Industry",
    "Infrastructure", "Initiative", "Innovation", "Integration",
    "Interface", "Knowledge", "Life-Cyle", "Location",
    "Management", "Market", "Matrix", "Media", "Messaging",
    "Method", "Movement", "Multimedia", "Network", "Objective",
    "Operation", "Option", "Paradigm", "Partner", "Partnership",
    "Philosophy", "Platform", "Policy", "Portal", "Power",
    "Process", "Product", "Production", "Program", "Progress",
    "Proposition", "Protocol", "Provider", "Quality",
    "Recognition", "Reference", "Release", "Resource", "Revenue",
    "Server", "Service", "Services", "Session", "Solution",
    "Standards", "Strategy", "Structure", "Success", "Support",
    "Supplier", "System", "Technology", "Usage", "User", "Value",
    "Vendor");

/*** adj_list */
techno.adjectives = new Array (
    "Active", "Accumulated", "Advanced", "Alternative",
    "Architectural", "Automated", "Balanced", "Best-of-Class",
    "Carrier-Class", "Centered", "Central", "Centralized",
    "Clear", "Committed", "Compatible", "Compelling",
    "Competitive", "Complementary", "Complete", "Complex",
    "Compliant", "Comprehensive", "Configurable", "Configured",
    "Consistent", "Contemporary", "Continuous", "Convergent",
    "Cooperative", "Credible", "Custom", "Customized",
    "Decentralized", "Dedicated", "Delegated", "Differentiated",
    "Direct", "Directed", "Disparate", "Distributed", "Durable",
    "Efficient", "Embedded", "Emerging", "Engineered", "Enhanced",
    "Extended", "Extensible", "External", "Flexible", "Full",
    "Functional", "Global", "High-Availability",
    "High-Visibility", "Ideal", "Implementable", "Increased",
    "Incremental", "Independent", "Innovative", "Innovative",
    "Instrumental", "Integrated", "Intelligent", "Intensive",
    "Interactive", "Interchangable", "Internal",
    "Internet-Enabled", "Interoperable", "Instrumental",
    "Integrated", "Intelligent", "Intelligent", "Intensive",
    "Interactive", "Interchangable", "Internal", "Interoperable",
    "Key", "Large-Scale", "Leading", "Leveraged", "Localized",
    "Logical", "Logistical", "Major", "Massive", "Maximized",
    "Mobile", "Modified", "Modular", "Monetized", "Multiple",
    "Multi-Purpose", "New", "Next-Generation", "Objective",
    "Open", "Operational", "Optimal", "Optimized", "Overall",
    "Packaged", "Parallel", "Personalized", "Positioned",
    "Positive", "Primary", "Proactive", "Productive",
    "Programatic", "Progressive", "Recognized", "Reciprocal",
    "Referenceable", "Refined", "Reinforced", "Relevant",
    "Reliable", "Resellable", "Responsive", "Robust", "Scalable",
    "Seamless", "Selectable", "Significant", "Smart",
    "Sophisticated", "Specialized", "Standards-Based",
    "State-of-the-Art", "Strategic", "Streamlined", "Structural",
    "Successful", "Sustainable", "Synchronized", "Tactical",
    "Tangible", "Technical", "Total", "Transferable",
    "Transitional", "Transparent", "Turnkey", "Ubiquitous",
    "Unique", "Unparalleled", "Validated", "Value-Added",
    "Vertical", "Wide", "Worldwide");

techno.adverbs = new Array (
    "Alternatively", "Automatically", "Centrally",
    "Competitively", "Completely", "Comprehensively",
    "Consistently", "Continuously", "Cooperatively", "Credibly",
    "Directly", "Efficiently", "Externally", "Flexibly", "Fully",
    "Globally", "Highly", "Ideally", "Incrementally",
    "Intelligently", "Intensively", "Interactively",
    "Interchangably", "Internally", "Intuitively", "Logically",
    "Logistically", "Newly", "Objectively", "Openly",
    "Operationally", "Optimally", "Positively", "Primarily",
    "Proactively", "Procedurally", "Productively",
    "Programatically", "Progressively", "Rapidly", "Reciprocally",
    "Responsively", "Routinely", "Seamlessly", "Significantly",
    "Strategically", "Structurally", "Substantially",
    "Successfully", "Tactically", "Technically", "Totally",
    "Transitionally", "Transparently", "Uncompromisingly",
    "Uniquely", "Upwardly", "Virtually");

collab.nouns = new Array (
    "Alignment", "Appliance", "Bandwidth", "Boundaries", "Bulletin", 
    "Bureaucracy", "Commitment", "Conference", "Consensus", "Consortia", 
    "Consultants", "Context", "Curriculum", "Developments", "Dialogue", 
    "Dimension", "Directions", "Discussion", "Energies", "Envelope", 
    "Exchange", "Expectations", "Facillitation", "Floor", "Ideas",
    "Implementation", "Infrastructure", "Inquiry", "Interactions",
    "Issues", "Journey", "Leadership", "Levels", "Management",
    "Material", "Medium", "Meeting", "Member", "Method", "Model",
    "Mood", "Movement", "Organization", "Performance", "Period",
    "Principle", "Process", "Processes", "Purpose", "Requirement",
    "Response", "Results", "Schedule", "Springboard", "Strategy",
    "Subscriber", "Support", "Synchronicity", "Teams", "Technology", "Template",
    "Term", "Theory", "Tools", "Touchpoints", "Universe",
    "Unoact", "Value", "Values", "Work");

collab.suffixes = new Array (
    "-Credited", "-Driven", "-Enabled", "-Facilitated", "-Focused", "-Goods", 
    "-Level", "-Managed", "-Networked", "-Process", 
    "-Term");

collab.prefixes = new Array (
    "Change-", "Cross-", "Meta-", "Non-", "Self-", "Team-");

collab.adnouns = new Array (
    "Bandwidth", "Belief", "Boundary", "Bulletin", "Challenge", "Complexity", 
    "Consensus", "Context", "Curriculum", "Dialogue", "Discussion", "Dream", 
    "Effectiveness", "Energy", "Engagement", "Human", "Impact", "Information", 
    "Infrastructure", "Intimacy", "Knowledge", "Leadership", "Learning", 
    "Meeting", "Membership", "Messaging", "Off-site", "On-site", "Online", 
    "Organization", "Outline", "Performance", "Phase", "Process", "Reality", 
    "Reference", "Research", "Sense", "Strategy", "Teaching", 
    "Teamwork", "Teamwork", "Technology", "Theory", "Time/space", "Variable");

collab.adjectives = new Array (
    "Arguable", "Articulated", "Asynchronous", "Basic", "Better", "Clatrified", 
    "Clear", "Coherent", "Collaborative", "Committed", "Complex", "Conceptual", 
    "Concrete", "Conscious", "Constrained", "Creative", "Defined", "Directional", 
    "Distributed", "Dynamic", "Effective", "Embodied", "Enhanced", "Eventual", 
    "Explicit", "External", "Graphic", "High", "Horizontal", "Huge", 
    "Imaginative", "Important", "Increasing", "Initial", "Intensive", 
    "Interactive", "Internal", "International", "Invaluable", "Leading", 
    "Linguistic", "Managed", "Multiple", "Multisensory", "Phased", "Physical", 
    "Positive", "Potential", "Predictable", "Reflexive", "Renewable", 
    "Requisite", "Semantic", "Shared", "Shared", "Solid", "Sophisticated", 
    "Spatial", "Structured", "Supportive", "Synchronous", "Tacit", "Theoretical", 
    "Trusted", "Trusted", "Trusted", "Universal", "Vertical", "Virtual");

collab.adverbs = new Array (
    "Actually", "Arguably", "Eventually", "Exponentially", "Frequently", 
    "Horizontally", "Increasingly", "Initially", "Institutionally", 
    "Occasionally", "Perfectly", "Personally", "Respectfully", "Surprisingly", 
    "Tightly", "Typically", "Ultimately", "Variably", "Vertically", 
    "Virtually");
