module ldmg

#flag -I/Users/pancake/prg/libdemangle/src
#flag `pkg-config --cflags --libs r_util`
#flag /Users/pancake/prg/libdemangle/src/libldmg.a

#include <ldmg.h>

fn C.ldmg_cxx(a byteptr) byteptr
fn C.ldmg_swift(a byteptr) byteptr
fn C.ldmg_swift_sys(a byteptr) byteptr

pub fn swift(s string) string {
	t := C.ldmg_swift(s.str)
	r := tos2(t)
	C.free(t)
	return r
}

pub fn cxx(s string) string {
	t := C.ldmg_cxx(s.str)
	r := tos2(t)
	C.free(t)
	return r
}
