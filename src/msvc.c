/* ldmg - LGPL - Copyright 2020 - pancake */
/* radare - LGPL - Copyright 2015-2018 - inisider */

#include <ldmg.h>
#include "./msvc_demangler.h"

R_API char *ldmg_msvc(const char *str) {
	char *out = NULL;
	SDemangler *mangler = 0;

	create_demangler (&mangler);
	if (!mangler) {
		return NULL;
	}
	if (init_demangler (mangler, (char *)str) == eDemanglerErrOK) {
		mangler->demangle (mangler, &out/*demangled_name*/);
	}
	free_demangler (mangler);
	return out;
}
