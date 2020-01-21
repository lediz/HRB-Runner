/*
 * Harbour 3.2.0dev (r2001131815)
 * Microsoft Visual C++ 19.16.27034 (64-bit)
 * Generated C source from "test1.prg"
 */

#include "hbvmpub.h"
#include "hbpcode.h"
#include "hbinit.h"


HB_FUNC( TEST1 );
HB_FUNC( MAIN );
HB_FUNC_EXTERN( QOUT );


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_TEST1 )
{ "TEST1", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TEST1 )}, NULL },
{ "MAIN", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( MAIN )}, NULL },
{ "QOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( QOUT )}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_TEST1, "test1.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_TEST1
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_TEST1 )
   #include "hbiniseg.h"
#endif

HB_FUNC( TEST1 )
{
   static const HB_BYTE pcode[] =
   {
	HB_P_ENDPROC
/* 00001 */
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( MAIN )
{
   static const HB_BYTE pcode[] =
   {
/* 00000 */ HB_P_LINE, 3, 0,	/* 3 */
	HB_P_PUSHFUNCSYM, 2, 0,	/* QOUT */
	HB_P_PUSHSTRSHORT, 6,	/* 6 */
	'H', 'e', 'l', 'l', 'o', 0, 
	HB_P_DOSHORT, 1,
	HB_P_ENDPROC
/* 00017 */
   };

   hb_vmExecute( pcode, symbols );
}

