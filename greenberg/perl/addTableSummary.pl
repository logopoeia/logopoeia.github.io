undef $/; \
s@<table([^a-z]*?)([a-z])@<table$1summary=""$1$2@gis;
