#include <ldmg.h>

R_API LdmgType ldmg_guess(const char *name) {
	if (ldmg_is_cxx (name)) {
		return LDMG_CXX;
	}
#if 0
	if (ldmg_is_java (name)) {
		return LDMG_JAVA;
	}
#endif
	return LDMG_UNKNOWN;
}

R_API LdmgCall ldmg_select(const char *name) {
	if (!strcmp (name, "swift")) {
		return ldmg_swift;
	}
	if (!strcmp (name, "swift_shell")) {
		return &ldmg_swift_shell;
	}
	if (!strcmp (name, "rust")) {
		return ldmg_rust;
	}
	if (!strcmp (name, "msvc")) {
		return ldmg_msvc;
	}
	if (!strcmp (name, "cxx")) {
		return ldmg_cxx;
	}
	return NULL;
}
