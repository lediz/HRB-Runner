/*
 * Harbour 3.2.0dev (r2001131815)
 * Microsoft Visual C++ 19.16.27034 (64-bit)
 * Generated C source from "dateTimeTypes.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( DATE1 );
HB_FUNC( DATETIME1 );


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_DATETIMETYPES )
{ "DATE1", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( DATE1 )}, NULL },
{ "DATETIME1", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( DATETIME1 )}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_DATETIMETYPES, "dateTimeTypes.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_DATETIMETYPES
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_DATETIMETYPES )
   #include "hbiniseg.h"
#endif

HB_FUNC( DATE1 )
{
	static const HB_BYTE pcode[] =
	{
		36,1,0,134,226,132,37,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( DATETIME1 )
{
	static const HB_BYTE pcode[] =
	{
		36,2,0,22,226,132,37,0,228,41,179,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

