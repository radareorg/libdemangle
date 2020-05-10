#include <ldmg.h>

R_API const char *ldmg_version = LDMG_VERSION;

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

R_API LdmgCall ldmg_bytype(LdmgType type) {
	// return ldmg_types[type];
	return NULL;
}

struct {
	const char *name;
	LdmgCall call;
} ldmg_types [] = {
	{ "swift", ldmg_swift },
	{ "swift_shell", ldmg_swift_shell },
	{ "cxx", ldmg_cxx },
	{ "java", ldmg_java },
	{ "objc", ldmg_objc },
	{ "rust", ldmg_rust },
	{ NULL, NULL }
};

R_API LdmgCall ldmg_byname(const char *name) {
	size_t i;
	for (i = 0; ldmg_types[i].name; i++) {
		if (!strcmp (ldmg_types[i].name, name)) {
			return ldmg_types[i].call;
		}
	}
	return NULL;
}
