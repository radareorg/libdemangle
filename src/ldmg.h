#ifndef INCLUDE_LIBDEMANGLE_H
#define INCLUDE_LIBDEMANGLE_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <r_util.h>
#include "./config.h"

#if 0
#define ut8 unsigned char
#define ut64 unsigned long long
#define R_API
#define R_IPI
#endif

typedef enum ldmg_type {
	LDMG_SWIFT,
	LDMG_CXX,
	LDMG_JAVA,
	LDMG_MSVC,
	LDMG_OBJC,
	LDMG_RUST,
	LDMG_SWIFT_SHELL,
	LDMG_UNKNOWN = -1,
} LdmgType;

typedef char *(*LdmgCall)(const char *s);

const char *ldmg_version;
// demanglers //
char *ldmg_swift(const char *s);
char *ldmg_swift_shell(const char *s);
char *ldmg_swift_dylib(const char *s);
char *ldmg_msvc(const char *str);
char *ldmg_rust(const char *str);
char *ldmg_objc(const char *str);
char *ldmg_cxx(const char *str);
char *ldmg_java(const char *str);

bool ldmg_is_cxx(const char *name);
bool ldmg_is_java(const char *name);

LdmgType ldmg_guess(const char *str);
LdmgCall ldmg_byname(const char *name);


#endif
