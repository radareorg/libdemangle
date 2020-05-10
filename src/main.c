/* ldmg - LGPL - Copyright 2020 - pancake */

#include <ldmg.h>

int main(int argc, const char **argv) {
	if (argc < 3) {
		eprintf ("Usage: ldmg [language] [symbol ...]\n");
		eprintf ("Languages: cxx, swift, rust, java, objc\n");
		return 1;
	}
	LdmgCall demangle = ldmg_byname (argv[1]);
	if (demangle) {
		char *r = demangle (argv[2]);
		if (r) {
			eprintf ("%s\n", r);
			free (r);
			return 0;
		}
	}
	return 1;
}
