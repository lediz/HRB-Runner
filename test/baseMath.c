/*
 * Harbour 3.2.0dev (r2001131815)
 * Microsoft Visual C++ 19.16.27034 (64-bit)
 * Generated C source from "baseMath.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( NEGATE );
HB_FUNC( ADD );
HB_FUNC( SUB );
HB_FUNC( MUL );
HB_FUNC( DIV );
HB_FUNC( LOGAND );
HB_FUNC( LOGOR );


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_BASEMATH )
{ "NEGATE", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( NEGATE )}, NULL },
{ "ADD", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ADD )}, NULL },
{ "SUB", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( SUB )}, NULL },
{ "MUL", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( MUL )}, NULL },
{ "DIV", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( DIV )}, NULL },
{ "LOGAND", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( LOGAND )}, NULL },
{ "LOGOR", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( LOGOR )}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_BASEMATH, "baseMath.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_BASEMATH
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_BASEMATH )
   #include "hbiniseg.h"
#endif

HB_FUNC( NEGATE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,1,0,95,1,66,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( ADD )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,2,0,95,1,95,2,72,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( SUB )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,3,0,95,1,95,2,49,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( MUL )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,4,0,95,1,95,2,65,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( DIV )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,5,0,95,1,95,2,18,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( LOGAND )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,6,0,95,1,21,28,5,73,95,2,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( LOGOR )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,7,0,95,1,21,31,5,73,95,2,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

