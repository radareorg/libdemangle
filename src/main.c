/* ldmg - LGPL - Copyright 2020 - pancake */

#include <ldmg.h>

int main(int argc, const char **argv) {
	if (argc < 3) {
		eprintf ("Usage: ldmg [language] [symbol ...]\n");
		eprintf ("Languages: cxx, swift, rust, java, objc\n");
		return 1;
	}
	LdmgCall dt = ldmg_select (argv[1]);
	if (dt) {
		char *r = dt (argv[2]);
		if (r) {
			eprintf ("%s\n", r);
			free (r);
			return 0;
		}
	}
	return 1;
}
