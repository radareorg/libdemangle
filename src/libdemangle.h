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

char *libdemangle_swift(const char *s, bool syscmd);
char *libdemangle_msvc(const char *str);
char *libdemangle_cxx(const char *str, ut64 vaddr);

#endif
