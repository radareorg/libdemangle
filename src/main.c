#include <libdemangle.h>

int main(int argc, const char **argv) {
	if (argc < 3) {
		eprintf ("Usage: ldmg [language] [symbol ...]\n");
		eprintf ("Languages: cxx, swift, rust, java, objc\n");
		return 1;
	}
	Demangle dt = libdemangle_select (argv[1]);
	if (dt) {
		char *r = dt (argv[1]);
		eprintf ("%s\n", r);
		free (r);
	}
	return 0;
}
