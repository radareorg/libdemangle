/* libdemangle - LGPL - Copyright 2020 - inisider */
/* radare - LGPL - Copyright 2015-2018 - inisider */

#include <libdemangle.h>
#include "./msvc_demangler.h"

R_API char *libdemangle_msvc(const char *str) {
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
