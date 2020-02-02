/*
 * Harbour 3.2.0dev (r2001131815)
 * Microsoft Visual C++ 19.16.27034 (64-bit)
 * Generated C source from "compare.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( EQUAL );
HB_FUNC( DIFFERENT );
HB_FUNC( GREATERFN );
HB_FUNC( GREATEREQUAL );
HB_FUNC( LOWERFN );
HB_FUNC( LOWEREQUAL );


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_COMPARE )
{ "EQUAL", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( EQUAL )}, NULL },
{ "DIFFERENT", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( DIFFERENT )}, NULL },
{ "GREATERFN", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( GREATERFN )}, NULL },
{ "GREATEREQUAL", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( GREATEREQUAL )}, NULL },
{ "LOWERFN", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( LOWERFN )}, NULL },
{ "LOWEREQUAL", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( LOWEREQUAL )}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_COMPARE, "compare.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_COMPARE
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_COMPARE )
   #include "hbiniseg.h"
#endif

HB_FUNC( EQUAL )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,1,0,95,1,95,2,5,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( DIFFERENT )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,2,0,95,1,95,2,69,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( GREATERFN )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,3,0,95,1,95,2,15,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( GREATEREQUAL )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,4,0,95,1,95,2,16,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( LOWERFN )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,5,0,95,1,95,2,35,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( LOWEREQUAL )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,6,0,95,1,95,2,34,110,7
	};

	hb_vmExecute( pcode, symbols );
}

