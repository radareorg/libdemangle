void test_swift(void) {
	libdemangle_swift ("_TFSSCfT21_builtinStringLiteralBp8byteSizeBw7isASCIIBi1__SS");
}

void test_cxx(void) {
	// libdemangle_swift ("_TFSSCfT21_builtinStringLiteralBp8byteSizeBw7isASCIIBi1__SS");
}

int main() {
	test_swift();
	test_swift_main();
	test_cxx();
}
