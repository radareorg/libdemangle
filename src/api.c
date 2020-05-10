#include <libdemangle.h>

R_API DemangleType libdemangle_guess(const char *name) {
	if (libdemangle_is_cxx (name)) {
		return LDMG_CXX;
	}
#if 0
	if (libdemangle_is_java (name)) {
		return LDMG_JAVA;
	}
#endif
	return LDMG_UNKNOWN;
}

R_API Demangle libdemangle_select(const char *name) {
	if (!strcmp (name, "swift")) {
		return libdemangle_swift;
	}
	if (!strcmp (name, "swift_shell")) {
		return &libdemangle_swift_shell;
	}
	if (!strcmp (name, "msvc")) {
		return libdemangle_msvc;
	}
	if (!strcmp (name, "cxx")) {
		return libdemangle_cxx;
	}
}
