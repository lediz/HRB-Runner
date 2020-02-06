/*
 * Harbour 3.2.0dev (r2001131815)
 * Microsoft Visual C++ 19.16.27034 (64-bit)
 * Generated C source from "directHB.prg"
 */

#include "hbvmpub.h"
#include "hbpcode.h"
#include "hbinit.h"


HB_FUNC( TEST );


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_DIRECTHB )
{ "TEST", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TEST )}, NULL },
{ "CREATEELEMENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DOCUMENT", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "_TEXTCONTENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "APPENDCHILD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BODY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_DIRECTHB, "directHB.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_DIRECTHB
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_DIRECTHB )
   #include "hbiniseg.h"
#endif

HB_FUNC( TEST )
{
   static const HB_BYTE pcode[] =
   {
	HB_P_FRAME, 1, 0,	/* locals, params */
/* 00003 */ HB_P_LINE, 5, 0,	/* 5 */
	HB_P_MESSAGE, 1, 0,	/* CREATEELEMENT */
	HB_P_PUSHMEMVAR, 2, 0,	/* DOCUMENT */
	HB_P_PUSHSTRSHORT, 5,	/* 5 */
	's', 'p', 'a', 'n', 0,
	HB_P_SENDSHORT, 1,
	HB_P_POPLOCALNEAR, 1,	/* OSPAN */
/* 00023 */ HB_P_LINE, 6, 0,	/* 6 */
	HB_P_MESSAGE, 3, 0,	/* _TEXTCONTENT */
	HB_P_PUSHLOCALNEAR, 1,	/* OSPAN */
	HB_P_PUSHSTRSHORT, 19,	/* 19 */
	'H', 'e', 'l', 'l', 'o', ' ', 'f', 'r', 'o', 'm', ' ', 'H', 'a', 'r', 'b', 'o', 'u', 'r', 0,
	HB_P_SENDSHORT, 1,
	HB_P_POP,
/* 00055 */ HB_P_LINE, 8, 0,	/* 8 */
	HB_P_MESSAGE, 4, 0,	/* APPENDCHILD */
	HB_P_MESSAGE, 5, 0,	/* BODY */
	HB_P_PUSHMEMVAR, 2, 0,	/* DOCUMENT */
	HB_P_SENDSHORT, 0,
	HB_P_PUSHLOCALNEAR, 1,	/* OSPAN */
	HB_P_SENDSHORT, 1,
	HB_P_POP,
	HB_P_ENDPROC
/* 00075 */
   };

   hb_vmExecute( pcode, symbols );
}

