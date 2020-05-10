module ldmg

#flag -I../../src
#flag `pkg-config --cflags --libs r_util`
#flag ../../src/libldmg.a

#include <ldmg.h>

fn C.ldmg_cxx(a byteptr) byteptr
fn C.ldmg_swift(a byteptr) byteptr
fn C.ldmg_swift_sys(a byteptr) byteptr

// cpub var C.ldmg_version byteptr 

pub fn swift(s string) string {
	t := C.ldmg_swift(s.str)
	r := tos2(t)
	C.free(t)
	return r
}

pub fn version() string {
	return tos2(byteptr(C.ldmg_version))
}

pub fn cxx(s string) string {
	t := C.ldmg_cxx(s.str)
	r := tos2(t)
	C.free(t)
	return r
}
