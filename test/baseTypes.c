/*
 * Harbour 3.2.0dev (r2001131815)
 * Microsoft Visual C++ 19.16.27034 (64-bit)
 * Generated C source from "baseTypes.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( NILVALUE );
HB_FUNC( BOOLEANTRUE );
HB_FUNC( BOOLEANFALSE );
HB_FUNC( ZEROVALUE );
HB_FUNC( ONEVALUE );
HB_FUNC( UINT8VALUE );
HB_FUNC( UINT16VALUE );
HB_FUNC( UINT32VALUE );
HB_FUNC( INT8VALUE );
HB_FUNC( INT16VALUE );
HB_FUNC( INT32VALUE );
HB_FUNC( DOUBLEVALUE );
HB_FUNC( STRINGVALUE );
HB_FUNC( ARRAYVALUE );
HB_FUNC( ARRAYVALUE2 );


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_BASETYPES )
{ "NILVALUE", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( NILVALUE )}, NULL },
{ "BOOLEANTRUE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( BOOLEANTRUE )}, NULL },
{ "BOOLEANFALSE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( BOOLEANFALSE )}, NULL },
{ "ZEROVALUE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ZEROVALUE )}, NULL },
{ "ONEVALUE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ONEVALUE )}, NULL },
{ "UINT8VALUE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( UINT8VALUE )}, NULL },
{ "UINT16VALUE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( UINT16VALUE )}, NULL },
{ "UINT32VALUE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( UINT32VALUE )}, NULL },
{ "INT8VALUE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( INT8VALUE )}, NULL },
{ "INT16VALUE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( INT16VALUE )}, NULL },
{ "INT32VALUE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( INT32VALUE )}, NULL },
{ "DOUBLEVALUE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( DOUBLEVALUE )}, NULL },
{ "STRINGVALUE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( STRINGVALUE )}, NULL },
{ "ARRAYVALUE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ARRAYVALUE )}, NULL },
{ "ARRAYVALUE2", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ARRAYVALUE2 )}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_BASETYPES, "baseTypes.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_BASETYPES
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_BASETYPES )
   #include "hbiniseg.h"
#endif

HB_FUNC( NILVALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,1,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( BOOLEANTRUE )
{
	static const HB_BYTE pcode[] =
	{
		36,2,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( BOOLEANFALSE )
{
	static const HB_BYTE pcode[] =
	{
		36,3,0,9,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( ZEROVALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,4,0,121,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( ONEVALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,5,0,122,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( UINT8VALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,6,0,92,10,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( UINT16VALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,7,0,93,232,3,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( UINT32VALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,8,0,97,160,134,1,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( INT8VALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,9,0,92,246,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( INT16VALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,10,0,93,24,252,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( INT32VALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,11,0,97,96,121,254,255,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( DOUBLEVALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,12,0,101,234,46,68,84,251,33,9,64,10,11,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( STRINGVALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,13,0,106,11,72,101,108,108,111,87,111,114,108,
		100,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( ARRAYVALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,14,0,122,92,2,4,2,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( ARRAYVALUE2 )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,16,0,92,2,3,1,0,80,1,36,
		17,0,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

