#include <ldmg.h>

int test_swift_main(int argc, char **argv);

void test_swift(void) {
	ldmg_swift ("_TFSSCfT21_builtinStringLiteralBp8byteSizeBw7isASCIIBi1__SS");
}

void test_cxx(void) {
	// ldmg_swift ("_TFSSCfT21_builtinStringLiteralBp8byteSizeBw7isASCIIBi1__SS");
}

int main(int argc, char **argv) {
	test_swift();
	test_swift_main(argc, argv);
	test_cxx();
}
