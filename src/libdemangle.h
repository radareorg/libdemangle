#ifndef INCLUDE_LIBDEMANGLE_H
#define INCLUDE_LIBDEMANGLE_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <r_util.h>

#if 0
#define ut8 unsigned char
#define ut64 unsigned long long
#define R_API
#define R_IPI
#endif

typedef enum libdemangle_type {
	LDMG_SWIFT,
	LDMG_CXX,
	LDMG_JAVA,
	LDMG_MSVC,
	LDMG_SWIFT_SHELL,
	LDMG_UNKNOWN = -1,
} DemangleType;

typedef char *(*Demangle)(const char *s);

char *libdemangle_swift(const char *s);
char *libdemangle_swift_shell(const char *s);
char *libdemangle_msvc(const char *str);
char *libdemangle_cxx(const char *str);
char *libdemangle_java(const char *str);

R_API bool libdemangle_is_cxx(const char *name);
R_API bool libdemangle_is_java(const char *name);

DemangleType libdemangle_guess(const char *str);
Demangle libdemangle_select(const char *name);


#endif
