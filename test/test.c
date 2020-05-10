#include <ldmg.h>

void test_swift(void) {
	ldmg_swift ("_TFSSCfT21_builtinStringLiteralBp8byteSizeBw7isASCIIBi1__SS");
}

void test_cxx(void) {
	// ldmg_swift ("_TFSSCfT21_builtinStringLiteralBp8byteSizeBw7isASCIIBi1__SS");
}

int main() {
	test_swift();
	test_swift_main();
	test_cxx();
}
