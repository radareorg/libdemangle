/* ldmg - LGPL - Copyright 2018-2020 - pancake */
/* radare - LGPL - Copyright 2013-2018 - pancake */

#include <ldmg.h>
#include "./cxx/demangle.h"

R_API bool ldmg_is_cxx(const char *name) {
	r_return_val_if_fail (name, false);
	if (!strncmp (name, "_Z", 2)) {
		return true;
	}
	if (!strncmp (name, "__Z", 3)) {
		return true;
	}
	return false;
}

R_API char *ldmg_cxx(const char *str) {
	// DMGL_TYPES | DMGL_PARAMS | DMGL_ANSI | DMGL_VERBOSE
	// | DMGL_RET_POSTFIX | DMGL_TYPES;
	int i;
#if WITH_GPL
	int flags = DMGL_NO_OPTS | DMGL_PARAMS;
#endif
	const char *prefixes[] = {
		"__symbol_stub1_",
		"reloc.",
		"sym.imp.",
		"imp.",
		NULL
	};
	char *tmpstr = strdup (str);
	char *p = tmpstr;

	if (p[0] == p[1] && *p == '_') {
		p++;
	}
	for (i = 0; prefixes[i]; i++) {
		int plen = strlen (prefixes[i]);
		if (!strncmp (p, prefixes[i], plen)) {
			p += plen;
			break;
		}
	}
	// remove CXXABI suffix
	char *cxxabi = strstr (p, "@@CXXABI");
	char *glibcxx = strstr (p, "@GLIBCXX");
	if (cxxabi) {
		*cxxabi = '\0';
	} else if (glibcxx) {
		if (p < glibcxx && glibcxx[-1] == '@') {
			glibcxx[-1] = '\0';
		} else {
			*glibcxx = '\0';
		}
	}
#if WITH_GPL
	char *out = cplus_demangle_v3 (p, flags);
#else
	/* TODO: implement a non-gpl alternative to c++v3 demangler */
	char *out = NULL;
#endif
	free (tmpstr);
	if (out) {
		r_str_replace_char (out, ' ', 0);
		char *sign = (char *)strchr (out, '(');
		if (sign) {
			char *str = out;
			char *ptr = NULL;
			char *nerd = NULL;
			for (;;) {
				ptr = strstr (str, "::");
				if (!ptr || ptr > sign) {
					break;
				}
				nerd = ptr;
				str = ptr + 1;
			}
			if (nerd && *nerd) {
				*nerd = 0;
#if 0
				if (binfile) {
					RBinSymbol *sym = r_bin_class_add_method (binfile, out, nerd + 2, 0);
					if (sym) {
						sym->vaddr = vaddr;
					}
				}
#endif
				*nerd = ':';
			}
		}
	}
	return out;
}
