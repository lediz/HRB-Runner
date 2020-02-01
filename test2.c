/*
 * Harbour 3.2.0dev (r2001131815)
 * Microsoft Visual C++ 19.16.27034 (64-bit)
 * Generated C source from "test2.prg"
 */

#include "hbvmpub.h"
#include "hbpcode.h"
#include "hbinit.h"


HB_FUNC( MAIN );
HB_FUNC( SUBFN );
HB_FUNC_EXTERN( QOUT );


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_TEST2 )
{ "MAIN", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( MAIN )}, NULL },
{ "SUBFN", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( SUBFN )}, NULL },
{ "QOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( QOUT )}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_TEST2, "test2.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_TEST2
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_TEST2 )
   #include "hbiniseg.h"
#endif

HB_FUNC( MAIN )
{
   static const HB_BYTE pcode[] =
   {
	HB_P_FRAME, 1, 2,	/* locals, params */
/* 00003 */ HB_P_LINE, 3, 0,	/* 3 */
	HB_P_PUSHFUNCSYM, 1, 0,	/* SUBFN */
	HB_P_PUSHBYTE, 4,	/* 4 */
	HB_P_PUSHBYTE, 3,	/* 3 */
	HB_P_FUNCTIONSHORT, 2,
	HB_P_POPLOCALNEAR, 3,	/* A */
/* 00017 */ HB_P_LINE, 4, 0,	/* 4 */
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_PUSHBYTE, 3,	/* 3 */
	HB_P_PUSHBYTE, 4,	/* 4 */
	HB_P_ARRAYGEN, 3, 0,	/* 3 */
	HB_P_POPLOCALNEAR, 2,	/* C */
/* 00031 */ HB_P_LINE, 5, 0,	/* 5 */
	HB_P_PUSHBYTE, 10,	/* 10 */
	HB_P_PUSHLOCALNEAR, 2,	/* C */
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_ARRAYPOP,
/* 00041 */ HB_P_LINE, 6, 0,	/* 6 */
	HB_P_PUSHLOCALNEAR, 2,	/* C */
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_ARRAYPUSHREF,
	HB_P_DECEQPOP,
/* 00050 */ HB_P_LINE, 7, 0,	/* 7 */
	HB_P_PUSHBYTE, 4,	/* 4 */
	HB_P_PUSHLOCALNEAR, 2,	/* C */
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_ARRAYPUSH,
	HB_P_DIVIDE,
	HB_P_POPLOCALNEAR, 1,	/* V */
/* 00063 */ HB_P_LINE, 8, 0,	/* 8 */
	HB_P_PUSHTIMESTAMP, 247, 132, 37, 0, 128, 41, 179, 2,	/* 2020-01-22 12:34:56.000 */
	HB_P_PUSHLOCALNEAR, 2,	/* C */
	HB_P_ONE,
	HB_P_ARRAYPOP,
/* 00079 */ HB_P_LINE, 9, 0,	/* 9 */
	HB_P_PUSHLOCALNEAR, 2,	/* C */
	HB_P_ONE,
	HB_P_ARRAYPUSHREF,
	HB_P_ONE,
	HB_P_PLUSEQPOP,
/* 00088 */ HB_P_LINE, 10, 0,	/* 10 */
	HB_P_PUSHFUNCSYM, 2, 0,	/* QOUT */
	HB_P_PUSHSTRSHORT, 6,	/* 6 */
	'H', 'e', 'l', 'l', 'o', 0, 
	HB_P_PUSHLOCALNEAR, 3,	/* A */
	HB_P_FALSE,
	HB_P_PUSHDATE, 247, 132, 37, 0,	/* 20200122 */
	HB_P_PUSHLOCALNEAR, 1,	/* V */
	HB_P_PUSHLOCALNEAR, 2,	/* C */
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_ARRAYPUSH,
	HB_P_PUSHLOCALNEAR, 2,	/* C */
	HB_P_ONE,
	HB_P_ARRAYPUSH,
	HB_P_DOSHORT, 7,
/* 00123 */ HB_P_LINE, 11, 0,	/* 11 */
	HB_P_PUSHBYTE, 5,	/* 5 */
	HB_P_RETVALUE,
	HB_P_ENDPROC
/* 00130 */
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( SUBFN )
{
   static const HB_BYTE pcode[] =
   {
	HB_P_FRAME, 0, 2,	/* locals, params */
/* 00003 */ HB_P_LINE, 14, 0,	/* 14 */
	HB_P_PUSHLOCALNEAR, 1,	/* A */
	HB_P_PUSHLOCALNEAR, 2,	/* B */
	HB_P_GREATER,
	HB_P_JUMPFALSENEAR, 12,	/* 12 (abs: 00023) */
/* 00013 */ HB_P_LINE, 15, 0,	/* 15 */
	HB_P_PUSHLOCALNEAR, 1,	/* A */
	HB_P_PUSHLOCALNEAR, 2,	/* B */
	HB_P_MINUS,
	HB_P_RETVALUE,
	HB_P_ENDPROC,
/* 00023 */ HB_P_LINE, 17, 0,	/* 17 */
	HB_P_PUSHLOCALNEAR, 1,	/* A */
	HB_P_PUSHLOCALNEAR, 2,	/* B */
	HB_P_PLUS,
	HB_P_RETVALUE,
	HB_P_ENDPROC
/* 00033 */
   };

   hb_vmExecute( pcode, symbols );
}

