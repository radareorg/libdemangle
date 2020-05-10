#include <r_cons.h>
#include <ldmg.h>

typedef struct {
	const char *sym;
	const char *dem;
} Test;

Test swift_tests[] = {
{
	"_TWPu0_Rq_Ss14CollectionType_GVSs17MapCollectionViewq_q0__Ss23_CollectionDefaultsTypeSs_8",
	"<generic _CollectionDefaultsType>"
},
{
	"_TWPurGVSs15CollectionOfOneq__Ss14CollectionTypeSs_248",
	"CollectionOfOne<generic CollectionType><generic S>"
},
{
	"_TFSSCfT21_builtinStringLiteralBp8byteSizeBw7isASCIIBi1__SS"
	,"Swift.String.init (_builtinStringLiteral(Builtin.RawPointer byteSize__Builtin.Word isASCII__Builtin.Int1 _) -> String"
	//, "Swift.String.init (Swift.String.Type) -> (_builtinStringLiteral : Builtin.RawPointer, byteSize : Builtin.Word, isASCII : Builtin.Int1) -> Swift.String
},{
	"_TFC10swifthello5Hellog5WorldSS" // getter
	,"swifthello.Hello.World.getter__String"
	// swifthello.Hello.World.getter : Swift.String
},{
	"_TFC10swifthello5Hellom5WorldSS" // getter
	,"swifthello.Hello.World.method__String"
},{
	"_TFC10swifthello5Hellos5WorldSS" // getter
	,"swifthello.Hello.World.setter__String"
},{
	"_TFSSCfMSSFT21_builtinStringLiteralBp8byteSizeBw7isASCIIBi1__SS"
	,"Swift.String.init (_builtinStringLiteral(Builtin.RawPointer byteSize__Builtin.Word isASCII__Builtin.Int1 _) -> String"
},{
	"_TF10swifthello3norFT_Si"
	,"swifthello.nor () -> Swift.Int"
},{
	"_TFSs7printlnU__FQ_T_"
	,"println.<A>(A) -> ()"
},{
	"_TFSsa6C_ARGVGVSs20UnsafeMutablePointerGS_VSs4Int8__"
	,"C_ARGV<generic UnsafeMutablePointer><generic Int8>"
},{
	"_TFC10FlappyBird9GameScene10resetScenefS0_FT_T_"
	,"FlappyBird.GameScene.resetScene (self) -> (__ _) ()" // XXX this is not correct
},{
	"__TFC4main8BarClass8sayHellofT_T_"
	,"main.BarClass.sayHello"
},{
	"__TFC4main4TostCfT_S0_"
	,"main.Tost.allocator"
},{
	"__TFC4main4TostD"
	,"main.Tost.deallocator"
},{
	"__TFC4main4TostcfT_S0_"
	,"main.Tost.constructor"
},{
	"__TF4main4moinFT_Si"
	,"main.moin () -> Swift.Int"
},{
	"__TFC4main4Tostg3msgSS"
	,"main.Tost.msg.getter__String"
},{
	"__TMC4main4Tost"
	,"main.Tost..metadata"
},{
	"__TMLC4main4Tost"
	,"main.Tost..lazy.metadata"

},{
	"__TMaC4main4Tost"
	,"main.Tost..accessor.metadata"
	//,"_lazy cache variable for type metadata for main.Tost"
},{
	"__TMmC4main4Tost"
	,"main.Tost..metaclass"
},{
	"__TFV4main7Balanceg5widthSd"
	,"main.Balance.width.getter__Double"
},{
	"__TWoFC4main4TostCfT_S0_"
	,"Tost.allocator..init.witnesstable"
},{
	"__TMBi256_"
	,"_..metadata"
},{
	"__TWvdvC4main4Tost3msgSS"
	,"main.Tost.msg__String..field"
},{
	"__TIFC10Moscapsule10MQTTClient11unsubscribeFTSS17requestCompletionGSqFTOS_10MosqResultSi_T___T_A0_"
	,"Moscapsule.MQTTClient.unsubscribe ()"
////imp._TIFC10Moscapsule10MQTTClient11unsubscribeFTSS17requestCompletionGSqFTOS_10MosqResultSi_T___T_A0_
},{
	"__TWaC4main8FooClassS_9FoodClassS_"
	,"main.FooClass..FoodClass..protocol"
},{
	"__TFe4mainRxCS_8FooClassxS_9FoodClassrS1_8sayHellofT_T_"
	,"main..FooClass..FoodClass..sayHello..extension"
},{
	"_TTSg5P____TFs27_allocateUninitializedArrayurFBwTGSax_Bp_",
	"P____(GenericSpec F)_allocateUninitializedArray -> Builtin.RawPointer" // TODO poor translation
	// "generic specialization <protocol<>> of Swift._allocateUninitializedArray <A> (Builtin.Word) -> ([A], Builtin.RawPointer)"
},{
	"_TIFs5printFTGSaP__9separatorSS10terminatorSS_T_A0_",
	"print (__Array P)", // TODO: poor translation
	//"Swift.(print ([protocol<>], separator : Swift.String, terminator : Swift.String) -> ()).(default argument 1)"
},{
	"__TZFsoi2eeuRxs9EquatablerFTGSqx_GSqx__Sb",
	"Swift..Equatable () -> Bool"
},{
	// _direct field offset for main.Tost.msg : Swift.String
	NULL, NULL
}};

int test_swift_main(int argc, char **argv) {
	int rc = 0;
	char *ret;
	if (argc > 1) {
		ret = ldmg_swift (argv[1]);
		if (ret) {
			printf ("%s\n", ret);
			free (ret);
		}
	} else {
		int i = 0;
		for (i=0; swift_tests[i].sym; i++) {
			Test *test = &swift_tests[i];
			printf ("[>>] %s\n", test->sym);
			ret = ldmg_swift (test->sym);
			if (ret) {
				if (test->dem && !strcmp (ret, test->dem)) {
					printf (Color_GREEN"[OK]"Color_RESET"  %s\n", ret);
				} else {
					printf (Color_RED"[XX]"Color_RESET"  %s\n", ret);
					printf (Color_YELLOW"[MUSTBE]"Color_RESET"  %s\n", test->dem);
					rc = 1;
				}
				free (ret);
			} else {
				printf (Color_RED"[XX]"Color_RESET"  \"(null)\"\n");
				printf (Color_YELLOW"[MUSTBE]"Color_RESET"  %s\n", test->dem);
				rc = 1;
			}
		}
	}
	return rc;
}
