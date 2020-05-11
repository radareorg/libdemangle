module main

import ldmg


fn d(s string) {
	println('Demangling .. $s')
	r := ldmg.swift(s)
	println('demangled $r')
}

fn main() {
	dd := ldmg.by_name('swift') or {
		eprintln(err)
		exit(1)
	}

	println(dd('_TWPu0_Rq_Ss14CollectionType_GVSs17MapCollectionViewq_q0__Ss23_CollectionDefaultsTypeSs_8'))

	d('_TWPu0_Rq_Ss14CollectionType_GVSs17MapCollectionViewq_q0__Ss23_CollectionDefaultsTypeSs_8')
	println(ldmg.version())
}
