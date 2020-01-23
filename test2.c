/*
 * Harbour 3.2.0dev (r1811161533)
 * Microsoft Visual C++ 19.15.26730 (64-bit)
 * Generated C source from "test2.prg"
 */

#include "hbvmpub.h"
#include "hbpcode.h"
#include "hbinit.h"


HB_FUNC( TEST2 );
HB_FUNC( MAIN );
HB_FUNC( SUBFN );
HB_FUNC_EXTERN( QOUT );


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_TEST2 )
{ "TEST2", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TEST2 )}, NULL },
{ "MAIN", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( MAIN )}, NULL },
{ "SUBFN", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( SUBFN )}, NULL },
{ "QOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( QOUT )}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_TEST2, "test2.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_TEST2
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_TEST2 )
   #include "hbiniseg.h"
#endif

HB_FUNC( TEST2 )
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
	HB_P_FRAME, 1, 2,	/* locals, params */
/* 00003 */ HB_P_LINE, 3, 0,	/* 3 */
	HB_P_PUSHFUNCSYM, 2, 0,	/* SUBFN */
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_PUSHBYTE, 3,	/* 3 */
	HB_P_FUNCTIONSHORT, 2,
	HB_P_POPLOCALNEAR, 3,	/* A */
/* 00017 */ HB_P_LINE, 4, 0,	/* 4 */
	HB_P_PUSHFUNCSYM, 3, 0,	/* QOUT */
	HB_P_PUSHSTRSHORT, 6,	/* 6 */
	'H', 'e', 'l', 'l', 'o', 0, 
	HB_P_PUSHLOCALNEAR, 3,	/* A */
	HB_P_FALSE,
	HB_P_PUSHDATE, 247, 132, 37, 0,	/* 20200122 */
	HB_P_PUSHLOCALNEAR, 1,	/* V */
	HB_P_DOSHORT, 5,
/* 00043 */ HB_P_LINE, 5, 0,	/* 5 */
	HB_P_PUSHBYTE, 5,	/* 5 */
	HB_P_RETVALUE,
	HB_P_ENDPROC
/* 00050 */
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( SUBFN )
{
   static const HB_BYTE pcode[] =
   {
	HB_P_FRAME, 0, 2,	/* locals, params */
/* 00003 */ HB_P_LINE, 8, 0,	/* 8 */
	HB_P_PUSHLOCALNEAR, 1,	/* A */
	HB_P_PUSHLOCALNEAR, 2,	/* B */
	HB_P_GREATER,
	HB_P_JUMPFALSENEAR, 12,	/* 12 (abs: 00023) */
/* 00013 */ HB_P_LINE, 9, 0,	/* 9 */
	HB_P_PUSHLOCALNEAR, 1,	/* A */
	HB_P_PUSHLOCALNEAR, 2,	/* B */
	HB_P_MINUS,
	HB_P_RETVALUE,
	HB_P_ENDPROC,
/* 00023 */ HB_P_LINE, 11, 0,	/* 11 */
	HB_P_PUSHLOCALNEAR, 1,	/* A */
	HB_P_PUSHLOCALNEAR, 2,	/* B */
	HB_P_PLUS,
	HB_P_RETVALUE,
	HB_P_ENDPROC
/* 00033 */
   };

   hb_vmExecute( pcode, symbols );
}

