module main

import ldmg


fn d(s string) {
	println('Demangling .. $s')
	r := ldmg.swift(s)
	println('demangled $r')
}

fn main() {
	d('_TWPu0_Rq_Ss14CollectionType_GVSs17MapCollectionViewq_q0__Ss23_CollectionDefaultsTypeSs_8')
}
