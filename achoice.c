/*
 * Harbour 3.2.0dev (r2001131815)
 * Microsoft Visual C++ 19.16.27034 (64-bit)
 * Generated C source from "achoice.prg"
 */

#include "hbvmpub.h"
#include "hbpcode.h"
#include "hbinit.h"


HB_FUNC( ACHOICE );
HB_FUNC( MAIN );
HB_FUNC_EXTERN( SCROLL );
HB_FUNC_EXTERN( SETPOS );
HB_FUNC_EXTERN( SETCOLOR );
HB_FUNC_EXTERN( SETCURSOR );
HB_FUNC_EXTERN( ASIZE );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( QOUT );
HB_FUNC_EXTERN( MAXROW );
HB_FUNC( CUSERFUNCTION );
HB_FUNC_EXTERN( LASTKEY );
HB_FUNC_EXTERN( ROW );
HB_FUNC_EXTERN( COL );
HB_FUNC_EXTERN( DEVPOS );
HB_FUNC_EXTERN( DEVOUT );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( PADR );
HB_FUNC_EXTERN( HB_NTOS );


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_ACHOICE )
{ "ACHOICE", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( ACHOICE )}, NULL },
{ "MAIN", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( MAIN )}, NULL },
{ "SCROLL", {HB_FS_PUBLIC}, {HB_FUNCNAME( SCROLL )}, NULL },
{ "SETPOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETPOS )}, NULL },
{ "SETCOLOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETCOLOR )}, NULL },
{ "SETCURSOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETCURSOR )}, NULL },
{ "ASIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASIZE )}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "QOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( QOUT )}, NULL },
{ "MAXROW", {HB_FS_PUBLIC}, {HB_FUNCNAME( MAXROW )}, NULL },
{ "CUSERFUNCTION", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( CUSERFUNCTION )}, NULL },
{ "LASTKEY", {HB_FS_PUBLIC}, {HB_FUNCNAME( LASTKEY )}, NULL },
{ "ROW", {HB_FS_PUBLIC}, {HB_FUNCNAME( ROW )}, NULL },
{ "COL", {HB_FS_PUBLIC}, {HB_FUNCNAME( COL )}, NULL },
{ "DEVPOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( DEVPOS )}, NULL },
{ "DEVOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( DEVOUT )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "PADR", {HB_FS_PUBLIC}, {HB_FUNCNAME( PADR )}, NULL },
{ "HB_NTOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_NTOS )}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_ACHOICE, "achoice.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_ACHOICE
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_ACHOICE )
   #include "hbiniseg.h"
#endif

HB_FUNC( ACHOICE )
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
	HB_P_FRAME, 5, 0,	/* locals, params */
/* 00003 */ HB_P_LINE, 131, 0,	/* 131 */
	HB_P_PUSHSTRSHORT, 12,	/* 12 */
	'A', 'G', 'R', 'I', '-', 'P', 'L', 'A', 'N', 'T', 'S', 0, 
	HB_P_PUSHSTRSHORT, 26,	/* 26 */
	'A', 'L', 'A', 'N', ' ', 'R', '.', ' ', 'S', 'M', 'I', 'T', 'H', ' ', 'G', 'R', 'E', 'E', 'N', 'H', 'O', 'U', 'S', 'E', 'S', 0, 
	HB_P_PUSHSTRSHORT, 27,	/* 27 */
	'A', 'L', 'L', 'A', 'N', ' ', 'M', 'U', 'R', 'R', 'A', 'Y', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 14,	/* 14 */
	'A', 'P', 'O', 'P', 'K', 'A', ' ', 'F', 'O', 'R', 'E', 'S', 'T', 0, 
	HB_P_PUSHSTRSHORT, 22,	/* 22 */
	'L', 'I', 'G', 'H', 'T', ' ', 'H', 'O', 'U', 'S', 'E', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'I', 'E', 'S', 0, 
	HB_P_PUSHSTRSHORT, 9,	/* 9 */
	'B', 'A', 'U', 'C', 'O', 'M', 39, 'S', 0, 
	HB_P_PUSHSTRSHORT, 23,	/* 23 */
	'B', 'A', 'Y', ' ', 'H', 'I', 'L', 'L', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 18,	/* 18 */
	'B', 'A', 'Y', 'W', 'O', 'O', 'D', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'I', 'E', 'S', 0, 
	HB_P_PUSHSTRSHORT, 16,	/* 16 */
	'B', 'I', 'G', ' ', 'O', 'A', 'K', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 14,	/* 14 */
	'C', ' ', '&', ' ', 'N', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 23,	/* 23 */
	'C', 'H', 'A', 'R', 'L', 'E', 'S', ' ', 'Q', 'U', 'A', 'L', 'I', 'T', 'Y', ' ', 'P', 'L', 'A', 'N', 'T', 'S', 0, 
	HB_P_PUSHSTRSHORT, 14,	/* 14 */
	'C', 'O', 'N', 'N', 'E', 'L', 'L', ' ', 'F', 'A', 'R', 'M', 'S', 0, 
	HB_P_PUSHSTRSHORT, 22,	/* 22 */
	'D', 'E', 'W', 'A', 'R', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'I', 'E', 'S', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 18,	/* 18 */
	'D', 'I', 'A', 'M', 'O', 'N', 'D', ' ', 'T', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 28,	/* 28 */
	'D', 'I', 'S', 'T', 'I', 'N', 'C', 'T', 'I', 'V', 'E', ' ', 'P', 'A', 'L', 'M', 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'I', 'E', 'S', 0, 
	HB_P_PUSHSTRSHORT, 15,	/* 15 */
	'D', 'O', 'N', 'K', 'A', 'Y', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 27,	/* 27 */
	'D', 'O', 'U', 'G', ' ', 'I', 'N', 'G', 'R', 'A', 'M', ' ', '&', ' ', 'S', 'O', 'N', 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 24,	/* 24 */
	'D', 'R', 'I', 'F', 'T', 'W', 'O', 'O', 'D', ' ', 'G', 'A', 'R', 'D', 'E', 'N', 'S', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 25,	/* 25 */
	'E', 'L', 'V', 'A', ' ', 'P', 'L', 'A', 'N', 'T', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 7,	/* 7 */
	'E', 'R', 'I', 'N', 'O', 'N', 0, 
	HB_P_PUSHSTRSHORT, 14,	/* 14 */
	'E', 'V', 'A', 'N', 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 13,	/* 13 */
	'F', 'A', 'N', 'C', 'Y', ' ', 'P', 'L', 'A', 'N', 'T', 'S', 0, 
	HB_P_PUSHSTRSHORT, 21,	/* 21 */
	'F', 'L', '.', 'P', 'L', 'A', 'N', 'T', ' ', 'G', 'R', 'O', 'W', 'E', 'R', 'S', 'C', 'O', 'O', 'P', 0, 
	HB_P_PUSHSTRSHORT, 20,	/* 20 */
	'F', 'L', 'O', 'R', 'I', 'D', 'A', ' ', 'C', 'A', 'C', 'T', 'U', 'S', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 29,	/* 29 */
	'F', 'L', 'O', 'W', 'E', 'R', 'I', 'N', 'G', ' ', 'T', 'R', 'E', 'E', ' ', 'G', 'R', 'O', 'W', 'E', 'R', 'S', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 19,	/* 19 */
	'F', 'L', 'O', 'W', 'E', 'R', 'W', 'O', 'O', 'D', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 20,	/* 20 */
	'F', 'O', 'L', 'I', 'A', 'G', 'E', ' ', 'F', 'A', 'C', 'T', 'O', 'R', 'Y', ' ', 'T', 'O', 'O', 0, 
	HB_P_PUSHSTRSHORT, 28,	/* 28 */
	'G', 'A', 'T', 'O', 'R', ' ', 'G', 'R', 'O', 'W', 'E', 'R', 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 30,	/* 30 */
	'G', 'A', 'Z', 'E', 'B', 'O', ' ', 'L', 'A', 'N', 'D', 'S', 'C', 'A', 'P', 'E', ' ', 'D', 'E', 'S', 'I', 'G', 'N', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 16,	/* 16 */
	'G', 'E', 'M', ' ', 'O', 'R', 'N', 'A', 'M', 'E', 'N', 'T', 'A', 'L', 'S', 0, 
	HB_P_PUSHSTRSHORT, 16,	/* 16 */
	'G', 'R', 'A', 'N', 'N', 'Y', 39, 'S', ' ', 'G', 'A', 'R', 'D', 'E', 'N', 0, 
	HB_P_PUSHSTRSHORT, 19,	/* 19 */
	'G', 'R', 'A', 'Y', 39, 'S', ' ', 'O', 'R', 'N', 'A', 'M', 'E', 'N', 'T', 'A', 'L', 'S', 0, 
	HB_P_PUSHSTRSHORT, 19,	/* 19 */
	'G', 'R', 'E', 'E', 'N', ' ', 'M', 'A', 'S', 'T', 'E', 'R', 'S', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 21,	/* 21 */
	'G', 'R', 'E', 'E', 'N', ' ', 'M', 'E', 'A', 'D', 'O', 'W', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 21,	/* 21 */
	'P', 'I', 'X', 'L', 'E', 'Y', 39, 'S', ' ', 'P', 'L', 'A', 'N', 'T', ' ', 'P', 'L', 'A', 'C', 'E', 0, 
	HB_P_PUSHSTRSHORT, 25,	/* 25 */
	'H', 'A', 'R', 'R', 'I', 'S', 'O', 'N', 39, 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 14,	/* 14 */
	'G', ' ', '&', ' ', 'G', ' ', 'F', 'O', 'L', 'I', 'A', 'G', 'E', 0, 
	HB_P_PUSHSTRSHORT, 21,	/* 21 */
	'I', 'V', 'E', 'Y', 39, 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 19,	/* 19 */
	'J', 'B', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'I', 'E', 'S', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 14,	/* 14 */
	'J', 'O', 'N', 39, 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 28,	/* 28 */
	'J', 'O', 'N', 'E', 'S', ' ', '&', ' ', 'J', 'O', 'N', 'E', 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 16,	/* 16 */
	'K', 'A', 'G', 'E', 'R', 39, 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 19,	/* 19 */
	'K', 'I', 'R', 'K', 'L', 'A', 'N', 'D', 39, 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 19,	/* 19 */
	'L', 'A', 'N', 'D', ' ', 'O', 'F', ' ', 'B', 'R', 'O', 'M', 'E', 'L', 'I', 'A', 'D', 'S', 0, 
	HB_P_PUSHSTRSHORT, 24,	/* 24 */
	'L', 'A', 'N', 'D', 'S', 'C', 'A', 'P', 'E', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 23,	/* 23 */
	'L', 'I', 'E', 'W', 'A', 'L', 'D', 39, 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 22,	/* 22 */
	'L', 'L', 'O', 'Y', 'D', ' ', '&', ' ', 'R', 'I', 'N', 'G', 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 15,	/* 15 */
	'L', 'O', 'N', 'G', ' ', 'V', 'A', 'N', ' ', 'D', 'O', 'U', 'N', 'G', 0, 
	HB_P_PUSHSTRSHORT, 26,	/* 26 */
	'M', 'A', 'P', 'E', 'L', 39, 'S', ' ', 'L', 'A', 'N', 'D', 'S', 'C', 'A', 'P', 'E', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 28,	/* 28 */
	'M', 'I', 'L', 'E', 'S', 'T', 'O', 'N', 'E', ' ', 'A', 'G', 'R', 'I', 'C', 'U', 'L', 'T', 'U', 'R', 'E', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 24,	/* 24 */
	'M', 'O', 'J', 'I', 'C', 'A', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ' ', '&', ' ', 'F', 'R', 'U', 'I', 'T', 'S', 0, 
	HB_P_PUSHSTRSHORT, 15,	/* 15 */
	'N', 'E', 'L', 'S', 'O', 'N', 39, 'S', ' ', 'R', 'O', 'S', 'E', 'S', 0, 
	HB_P_PUSHSTRSHORT, 13,	/* 13 */
	'P', 'A', 'R', 'K', ' ', 'G', 'A', 'R', 'D', 'E', 'N', 'S', 0, 
	HB_P_PUSHSTRSHORT, 16,	/* 16 */
	'P', 'A', 'U', 'L', ' ', 'L', 'U', 'K', 'A', 'S', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 15,	/* 15 */
	'P', 'E', 'C', 'K', 'E', 'T', 'T', 39, 'S', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 21,	/* 21 */
	'P', 'E', 'N', 'A', 'N', 'G', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 19,	/* 19 */
	'P', 'I', 'N', 'E', 'S', ' ', 'I', 'I', 'I', ' ', 'N', 'U', 'R', 'E', 'R', 'I', 'E', 'S', 0, 
	HB_P_PUSHSTRSHORT, 17,	/* 17 */
	'P', 'I', 'N', 'E', 'V', 'I', 'E', 'W', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 20,	/* 20 */
	'P', 'O', 'U', 'L', ' ', 'J', 'E', 'N', 'S', 'E', 'N', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 12,	/* 12 */
	'R', '.', 'P', '.', ' ', 'W', 'E', 'L', 'K', 'E', 'R', 0, 
	HB_P_PUSHSTRSHORT, 29,	/* 29 */
	'R', 'I', 'C', 'H', 'A', 'R', 'D', ' ', 'R', 'O', 'G', 'E', 'R', 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 20,	/* 20 */
	'S', 'P', 'R', 'I', 'N', 'G', ' ', 'H', 'I', 'L', 'L', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 19,	/* 19 */
	'T', '.', 'O', '.', ' ', 'M', 'A', 'H', 'A', 'F', 'F', 'E', 'Y', ',', ' ', 'J', 'R', '.', 0, 
	HB_P_PUSHSTRSHORT, 15,	/* 15 */
	'T', 'U', 'C', 'K', 'E', 'R', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 20,	/* 20 */
	'T', 'U', 'R', 'T', 'L', 'E', ' ', 'P', 'O', 'N', 'D', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 22,	/* 22 */
	'T', 'U', 'T', 'T', 'L', 'E', 39, 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 14,	/* 14 */
	'V', 'A', 'L', 'L', 'E', 'Y', ' ', 'C', 'A', 'C', 'T', 'U', 'S', 0, 
	HB_P_PUSHSTRSHORT, 20,	/* 20 */
	'W', 'H', 'I', 'S', 'P', 'E', 'R', ' ', 'W', 'I', 'N', 'D', 'S', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 26,	/* 26 */
	'W', 'H', 'I', 'T', 'E', ' ', 'R', 'O', 'S', 'E', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'I', 'E', 'S', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 8,	/* 8 */
	'W', 'O', 'O', 'D', 'W', 'A', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 13,	/* 13 */
	'F', 'L', 'O', 'R', 'I', '-', 'D', 'E', 'S', 'I', 'G', 'N', 0, 
	HB_P_PUSHSTRSHORT, 25,	/* 25 */
	'G', 'R', 'E', 'E', 'N', ' ', 'A', 'C', 'R', 'E', 'S', ' ', 'F', 'O', 'L', 'I', 'A', 'G', 'E', ',', ' ', 'I', 'N', 'C', 0, 
	HB_P_PUSHSTRSHORT, 12,	/* 12 */
	'F', 'L', 'O', 'R', 'A', 'L', ' ', 'E', 'X', 'P', 'O', 0, 
	HB_P_PUSHSTRSHORT, 15,	/* 15 */
	'T', 'O', 'R', 'R', 'E', 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 12,	/* 12 */
	'D', 'A', 'R', 'R', 'Y', 'L', ' ', 'K', 'O', 'O', 'N', 0, 
	HB_P_PUSHSTRSHORT, 16,	/* 16 */
	'T', 'R', 'I', 'S', 'T', 'A', 'R', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 17,	/* 17 */
	'K', 'A', 'Y', ' ', 'W', 'E', 'S', 'T', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 15,	/* 15 */
	'J', 'A', 'Y', 'M', 'A', 'R', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 24,	/* 24 */
	'J', ' ', 'D', ' ', 'F', ' ', 'L', 'A', 'N', 'D', 'S', 'C', 'A', 'P', 'E', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 21,	/* 21 */
	'D', 'E', 'R', 'O', 'O', 'S', 'E', ' ', 'P', 'L', 'A', 'N', 'T', 'S', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 14,	/* 14 */
	'T', 'H', 'E', ' ', 'T', 'R', 'E', 'E', 'H', 'O', 'U', 'S', 'E', 0, 
	HB_P_PUSHSTRSHORT, 24,	/* 24 */
	'C', 'O', 'S', 'T', 'E', 'L', 'L', 'O', 39, 'S', ' ', 'A', 'R', 'E', 'C', 'A', 'S', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 16,	/* 16 */
	'F', 'L', 'O', 'R', 'I', 'C', 'O', ' ', 'F', 'O', 'L', 'I', 'A', 'G', 'E', 0, 
	HB_P_PUSHSTRSHORT, 12,	/* 12 */
	'T', 'H', 'E', ' ', 'N', 'A', 'T', 'I', 'V', 'E', 'S', 0, 
	HB_P_PUSHSTRSHORT, 15,	/* 15 */
	'G', 'R', 'E', 'E', 'N', 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 18,	/* 18 */
	'S', 'T', 'E', 'W', 'A', 'R', 'T', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'I', 'E', 'S', 0, 
	HB_P_PUSHSTRSHORT, 20,	/* 20 */
	'G', ' ', '&', ' ', 'T', ' ', 'F', 'O', 'L', 'I', 'A', 'G', 'E', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 19,	/* 19 */
	'G', 'O', 'O', 'D', ' ', 'T', 'I', 'M', 'E', 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 27,	/* 27 */
	'C', 'O', 'N', 'C', 'E', 'P', 'T', 'S', ' ', 'I', 'N', ' ', 'G', 'R', 'E', 'E', 'N', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 27,	/* 27 */
	'D', 'U', 'N', 'N', ' ', 'B', 'R', 'O', 'T', 'H', 'E', 'R', 'S', ' ', 'C', 'I', 'T', 'R', 'U', 'S', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 23,	/* 23 */
	'J', 'O', 'H', 'N', ' ', 'P', 'L', 'A', 'N', 'K', ' ', 'G', 'R', 'E', 'E', 'N', 'H', 'O', 'U', 'S', 'E', 'S', 0, 
	HB_P_PUSHSTRSHORT, 25,	/* 25 */
	'G', 'R', 'E', 'E', 'N', 'E', 'R', ' ', 'P', 'A', 'S', 'T', 'U', 'R', 'E', 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 18,	/* 18 */
	'M', 'U', 'L', 'V', 'E', 'H', 'I', 'L', 'L', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 10,	/* 10 */
	'A', ' ', 'N', 'U', ' ', 'L', 'E', 'A', 'F', 0, 
	HB_P_PUSHSTRSHORT, 18,	/* 18 */
	'I', 'V', 'Y', ' ', 'D', 'E', 'S', 'I', 'G', 'N', 'S', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 16,	/* 16 */
	'B', ' ', '&', ' ', 'C', ' ', 'T', 'R', 'O', 'P', 'I', 'C', 'A', 'L', 'S', 0, 
	HB_P_PUSHSTRSHORT, 28,	/* 28 */
	'S', 'P', 'A', 'N', 'I', 'S', 'H', ' ', 'R', 'I', 'V', 'E', 'R', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 28,	/* 28 */
	'J', 'A', 'C', 'K', ' ', 'C', 'H', 'R', 'I', 'S', 'T', 'M', 'A', 'S', ' ', '&', ' ', 'A', 'S', 'S', 'O', 'C', 'I', 'A', 'T', 'E', 'S', 0, 
	HB_P_PUSHSTRSHORT, 19,	/* 19 */
	'S', 'P', 'E', 'C', 'I', 'A', 'L', 'I', 'S', 'T', ' ', 'G', 'R', 'O', 'W', 'E', 'R', 'S', 0, 
	HB_P_PUSHSTRSHORT, 22,	/* 22 */
	'H', 'O', 'M', 'R', 'I', 'C', 'H', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 26,	/* 26 */
	'C', 'O', 'U', 'N', 'T', 'R', 'Y', 'S', 'I', 'D', 'E', ' ', 'F', 'O', 'L', 'I', 'A', 'G', 'E', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 12,	/* 12 */
	'R', 'F', 'J', ' ', 'C', 'O', 'M', 'P', 'A', 'N', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 26,	/* 26 */
	'L', 'A', 'K', 'E', ' ', 'B', 'R', 'A', 'N', 'T', 'L', 'E', 'Y', ' ', 'P', 'L', 'A', 'N', 'T', ' ', 'C', 'O', 'R', 'P', '.', 0, 
	HB_P_PUSHSTRSHORT, 10,	/* 10 */
	'M', 'A', 'R', 'I', 'S', 'T', 'Y', 'M', 'E', 0, 
	HB_P_PUSHSTRSHORT, 23,	/* 23 */
	'M', 'E', 'R', 'I', 'S', 'T', 'E', 'M', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 27,	/* 27 */
	'T', 'R', 'O', 'P', 'I', 'C', ' ', 'D', 'E', 'C', 'O', 'R', ' ', '-', ' ', 'E', 'A', 'R', 'L', ' ', 'W', 'I', 'L', 'S', 'O', 'N', 0, 
	HB_P_PUSHSTRSHORT, 19,	/* 19 */
	'U', 'R', 'Q', 'U', 'H', 'A', 'R', 'T', 39, 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 18,	/* 18 */
	'A', 'C', 'E', ' ', 'P', 'L', 'A', 'N', 'T', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 27,	/* 27 */
	'H', 'A', 'T', 'T', 'A', 'W', 'A', 'Y', 'S', ' ', 'G', 'R', 'E', 'E', 'N', 'H', 'O', 'U', 'S', 'E', ',', ' ', 'I', 'N', 'C', '.', 0, 
	HB_P_PUSHSTRSHORT, 22,	/* 22 */
	'F', 'l', 'o', 'r', 'i', 'd', 'a', ' ', 'P', 'l', 'a', 'n', 't', ' ', 'G', 'r', 'o', 'w', 'e', 'r', 's', 0, 
	HB_P_PUSHSTRSHORT, 15,	/* 15 */
	'J', 'u', 'n', 'i', 'o', 'r', ' ', 'N', 'u', 'r', 's', 'e', 'r', 'y', 0, 
	HB_P_PUSHSTRSHORT, 22,	/* 22 */
	'F', 'o', 'x', 39, 's', ' ', 'N', 'u', 'r', 's', 'e', 'r', 'i', 'e', 's', ',', ' ', 'I', 'n', 'c', '.', 0, 
	HB_P_PUSHSTRSHORT, 16,	/* 16 */
	'V', 'a', 'u', 'g', 'h', 'a', 'n', ' ', 'N', 'u', 'r', 's', 'e', 'r', 'y', 0, 
	HB_P_PUSHSTRSHORT, 15,	/* 15 */
	'M', 'E', 'R', 'R', 'Y', 'G', 'R', 'O', ' ', 'F', 'A', 'R', 'M', 'S', 0, 
	HB_P_PUSHSTRSHORT, 20,	/* 20 */
	'A', 'L', 'L', ' ', 'S', 'E', 'A', 'S', 'O', 'N', 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 18,	/* 18 */
	'B', 'E', 'N', 'C', 'H', 'M', 'A', 'R', 'K', ' ', 'F', 'O', 'L', 'I', 'A', 'G', 'E', 0, 
	HB_P_PUSHSTRSHORT, 16,	/* 16 */
	'S', 'A', 'M', 'M', 'Y', 39, 'S', ' ', 'N', 'U', 'R', 'S', 'E', 'R', 'Y', 0, 
	HB_P_PUSHSTRSHORT, 17,	/* 17 */
	'S', 'U', 'N', 'S', 'H', 'I', 'N', 'E', ' ', 'G', 'R', 'O', 'W', 'E', 'R', 'S', 0, 
	HB_P_PUSHSTRSHORT, 24,	/* 24 */
	'B', 'l', 'o', 'o', 'm', 'i', 'n', 'g', '-', 'F', 'i', 'e', 'l', 'd', 's', ' ', 'N', 'u', 'r', 's', 'e', 'r', 'y', 0, 
	HB_P_ARRAYGEN, 119, 0,	/* 119 */
	HB_P_POPLOCALNEAR, 1,	/* APROMPTS */
/* 02559 */ HB_P_LINE, 133, 0,	/* 133 */
	HB_P_ARRAYGEN, 0, 0,	/* 0 */
	HB_P_POPLOCALNEAR, 2,	/* APERMITS */
/* 02567 */ HB_P_LINE, 138, 0,	/* 138 */
	HB_P_PUSHFUNCSYM, 2, 0,	/* SCROLL */
	HB_P_DOSHORT, 0,
	HB_P_PUSHFUNCSYM, 3, 0,	/* SETPOS */
	HB_P_ZERO,
	HB_P_ZERO,
	HB_P_DOSHORT, 2,
/* 02582 */ HB_P_LINE, 140, 0,	/* 140 */
	HB_P_PUSHFUNCSYM, 4, 0,	/* SETCOLOR */
	HB_P_PUSHSTRSHORT, 18,	/* 18 */
	'G', 'B', '+', '/', 'B', ',', 'G', 'R', '+', '/', 'R', ',', ',', ',', 'W', '/', 'N', 0, 
	HB_P_DOSHORT, 1,
/* 02610 */ HB_P_LINE, 142, 0,	/* 142 */
	HB_P_PUSHFUNCSYM, 5, 0,	/* SETCURSOR */
	HB_P_ONE,
	HB_P_DOSHORT, 1,
/* 02619 */ HB_P_LINE, 144, 0,	/* 144 */
	HB_P_PUSHFUNCSYM, 6, 0,	/* ASIZE */
	HB_P_PUSHLOCALNEAR, 2,	/* APERMITS */
	HB_P_PUSHFUNCSYM, 7, 0,	/* LEN */
	HB_P_PUSHLOCALNEAR, 1,	/* APROMPTS */
	HB_P_FUNCTIONSHORT, 1,
	HB_P_DOSHORT, 2,
/* 02636 */ HB_P_LINE, 146, 0,	/* 146 */
	HB_P_ONE,
	HB_P_PUSHUNREF,
	HB_P_POPLOCALNEAR, 3,	/* X */
	HB_P_JUMPNEAR, 27,	/* 27 (abs: 02670) */
/* 02645 */ HB_P_LINE, 147, 0,	/* 147 */
	HB_P_PUSHSTRSHORT, 2,	/* 2 */
	'V', 0, 
	HB_P_PUSHLOCALNEAR, 1,	/* APROMPTS */
	HB_P_PUSHLOCALNEAR, 3,	/* X */
	HB_P_ARRAYPUSH,
	HB_P_INSTRING,
	HB_P_NOT,
	HB_P_PUSHLOCALNEAR, 2,	/* APERMITS */
	HB_P_PUSHLOCALNEAR, 3,	/* X */
	HB_P_ARRAYPOP,
/* 02664 */ HB_P_LINE, 146, 0,	/* 146 */
	HB_P_LOCALINCPUSH, 3, 0,	/* X */
	HB_P_PUSHFUNCSYM, 7, 0,	/* LEN */
	HB_P_PUSHLOCALNEAR, 1,	/* APROMPTS */
	HB_P_FUNCTIONSHORT, 1,
	HB_P_GREATER,
	HB_P_JUMPFALSENEAR, 223,	/* -33 (abs: 02645) */
/* 02680 */ HB_P_LINE, 152, 0,	/* 152 */
	HB_P_ONE,
	HB_P_PUSHUNREF,
	HB_P_POPLOCALNEAR, 5,	/* NCNTR */
	HB_P_JUMPNEAR, 36,	/* 36 (abs: 02723) */
/* 02689 */ HB_P_LINE, 153, 0,	/* 153 */
	HB_P_FALSE,
	HB_P_PUSHLOCALNEAR, 2,	/* APERMITS */
	HB_P_PUSHLOCALNEAR, 5,	/* NCNTR */
	HB_P_ARRAYPOP,
/* 02698 */ HB_P_LINE, 154, 0,	/* 154 */
	HB_P_FALSE,
	HB_P_PUSHLOCALNEAR, 2,	/* APERMITS */
	HB_P_PUSHFUNCSYM, 7, 0,	/* LEN */
	HB_P_PUSHLOCALNEAR, 1,	/* APROMPTS */
	HB_P_FUNCTIONSHORT, 1,
	HB_P_PUSHLOCALNEAR, 5,	/* NCNTR */
	HB_P_MINUS,
	HB_P_ONE,
	HB_P_PLUS,
	HB_P_ARRAYPOP,
/* 02717 */ HB_P_LINE, 152, 0,	/* 152 */
	HB_P_LOCALINCPUSH, 5, 0,	/* NCNTR */
	HB_P_PUSHBYTE, 17,	/* 17 */
	HB_P_GREATER,
	HB_P_JUMPFALSENEAR, 219,	/* -37 (abs: 02689) */
/* 02728 */ HB_P_LINE, 156, 0,	/* 156 */
	HB_P_FALSE,
	HB_P_PUSHLOCALNEAR, 2,	/* APERMITS */
	HB_P_PUSHBYTE, 32,	/* 32 */
	HB_P_ARRAYPOP,
/* 02737 */ HB_P_LINE, 157, 0,	/* 157 */
	HB_P_FALSE,
	HB_P_PUSHLOCALNEAR, 2,	/* APERMITS */
	HB_P_PUSHBYTE, 33,	/* 33 */
	HB_P_ARRAYPOP,
/* 02746 */ HB_P_LINE, 158, 0,	/* 158 */
	HB_P_FALSE,
	HB_P_PUSHLOCALNEAR, 2,	/* APERMITS */
	HB_P_PUSHBYTE, 34,	/* 34 */
	HB_P_ARRAYPOP,
/* 02755 */ HB_P_LINE, 161, 0,	/* 161 */
	HB_P_PUSHFUNCSYM, 0, 0,	/* ACHOICE */
	HB_P_PUSHBYTE, 5,	/* 5 */
	HB_P_PUSHBYTE, 10,	/* 10 */
	HB_P_PUSHBYTE, 20,	/* 20 */
	HB_P_PUSHBYTE, 70,	/* 70 */
	HB_P_PUSHLOCALNEAR, 1,	/* APROMPTS */
	HB_P_PUSHLOCALNEAR, 2,	/* APERMITS */
	HB_P_PUSHSTRSHORT, 14,	/* 14 */
	'c', 'U', 's', 'e', 'r', 'F', 'u', 'n', 'c', 't', 'i', 'o', 'n', 0, 
	HB_P_FUNCTIONSHORT, 7,
	HB_P_POPLOCALNEAR, 4,	/* NCHOICE */
/* 02793 */ HB_P_LINE, 163, 0,	/* 163 */
	HB_P_PUSHFUNCSYM, 3, 0,	/* SETPOS */
	HB_P_ZERO,
	HB_P_ZERO,
	HB_P_DOSHORT, 2,
/* 02803 */ HB_P_LINE, 165, 0,	/* 165 */
	HB_P_PUSHFUNCSYM, 8, 0,	/* QOUT */
	HB_P_PUSHLOCALNEAR, 4,	/* NCHOICE */
	HB_P_DOSHORT, 1,
/* 02813 */ HB_P_LINE, 167, 0,	/* 167 */
	HB_P_PUSHLOCALNEAR, 4,	/* NCHOICE */
	HB_P_ZERO,
	HB_P_GREATER,
	HB_P_JUMPFALSENEAR, 15,	/* 15 (abs: 02835) */
/* 02822 */ HB_P_LINE, 168, 0,	/* 168 */
	HB_P_PUSHFUNCSYM, 8, 0,	/* QOUT */
	HB_P_PUSHLOCALNEAR, 1,	/* APROMPTS */
	HB_P_PUSHLOCALNEAR, 4,	/* NCHOICE */
	HB_P_ARRAYPUSH,
	HB_P_DOSHORT, 1,
/* 02835 */ HB_P_LINE, 170, 0,	/* 170 */
	HB_P_PUSHFUNCSYM, 3, 0,	/* SETPOS */
	HB_P_PUSHFUNCSYM, 9, 0,	/* MAXROW */
	HB_P_FUNCTIONSHORT, 0,
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_MINUS,
	HB_P_ZERO,
	HB_P_DOSHORT, 2,
/* 02852 */ HB_P_LINE, 172, 0,	/* 172 */
	HB_P_ENDPROC
/* 02856 */
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( CUSERFUNCTION )
{
   static const HB_BYTE pcode[] =
   {
	HB_P_FRAME, 4, 3,	/* locals, params */
/* 00003 */ HB_P_LINE, 178, 0,	/* 178 */
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_POPLOCALNEAR, 4,	/* NRETVAL */
/* 00010 */ HB_P_LINE, 179, 0,	/* 179 */
	HB_P_PUSHFUNCSYM, 11, 0,	/* LASTKEY */
	HB_P_FUNCTIONSHORT, 0,
	HB_P_POPLOCALNEAR, 5,	/* NKEY */
/* 00020 */ HB_P_LINE, 181, 0,	/* 181 */
	HB_P_PUSHFUNCSYM, 12, 0,	/* ROW */
	HB_P_FUNCTIONSHORT, 0,
	HB_P_POPLOCALNEAR, 6,	/* NROW */
/* 00030 */ HB_P_LINE, 182, 0,	/* 182 */
	HB_P_PUSHFUNCSYM, 13, 0,	/* COL */
	HB_P_FUNCTIONSHORT, 0,
	HB_P_POPLOCALNEAR, 7,	/* NCOL */
/* 00040 */ HB_P_LINE, 186, 0,	/* 186 */
	HB_P_PUSHFUNCSYM, 14, 0,	/* DEVPOS */
	HB_P_ZERO,
	HB_P_PUSHBYTE, 20,	/* 20 */
	HB_P_DOSHORT, 2,
	HB_P_PUSHFUNCSYM, 15, 0,	/* DEVOUT */
	HB_P_PUSHFUNCSYM, 16, 0,	/* STR */
	HB_P_PUSHLOCALNEAR, 6,	/* NROW */
	HB_P_PUSHBYTE, 3,	/* 3 */
	HB_P_FUNCTIONSHORT, 2,
	HB_P_PUSHSTRSHORT, 2,	/* 2 */
	' ', 0, 
	HB_P_PLUS,
	HB_P_PUSHFUNCSYM, 16, 0,	/* STR */
	HB_P_PUSHLOCALNEAR, 7,	/* NCOL */
	HB_P_PUSHBYTE, 3,	/* 3 */
	HB_P_FUNCTIONSHORT, 2,
	HB_P_PLUS,
	HB_P_DOSHORT, 1,
/* 00080 */ HB_P_LINE, 190, 0,	/* 190 */
	HB_P_PUSHLOCALNEAR, 1,	/* NMODE */
	HB_P_ZERO,
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 41,	/* 41 (abs: 00128) */
/* 00089 */ HB_P_LINE, 191, 0,	/* 191 */
	HB_P_PUSHFUNCSYM, 14, 0,	/* DEVPOS */
	HB_P_ZERO,
	HB_P_ZERO,
	HB_P_DOSHORT, 2,
	HB_P_PUSHFUNCSYM, 15, 0,	/* DEVOUT */
	HB_P_PUSHFUNCSYM, 17, 0,	/* PADR */
	HB_P_PUSHFUNCSYM, 18, 0,	/* HB_NTOS */
	HB_P_PUSHLOCALNEAR, 2,	/* NCURELEMENT */
	HB_P_FUNCTIONSHORT, 1,
	HB_P_PUSHBYTE, 10,	/* 10 */
	HB_P_FUNCTIONSHORT, 2,
	HB_P_DOSHORT, 1,
/* 00118 */ HB_P_LINE, 192, 0,	/* 192 */
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_POPLOCALNEAR, 4,	/* NRETVAL */
	HB_P_JUMP, 163, 0,	/* 163 (abs: 00288) */
/* 00128 */ HB_P_LINE, 193, 0,	/* 193 */
	HB_P_PUSHLOCALNEAR, 1,	/* NMODE */
	HB_P_ONE,
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 32,	/* 32 (abs: 00167) */
/* 00137 */ HB_P_LINE, 194, 0,	/* 194 */
	HB_P_PUSHFUNCSYM, 14, 0,	/* DEVPOS */
	HB_P_ZERO,
	HB_P_ZERO,
	HB_P_DOSHORT, 2,
	HB_P_PUSHFUNCSYM, 15, 0,	/* DEVOUT */
	HB_P_PUSHSTRSHORT, 11,	/* 11 */
	'H', 'i', 't', ' ', 'T', 'o', 'p', ' ', ' ', ' ', 0, 
	HB_P_DOSHORT, 1,
	HB_P_JUMPNEAR, 123,	/* 123 (abs: 00288) */
/* 00167 */ HB_P_LINE, 196, 0,	/* 196 */
	HB_P_PUSHLOCALNEAR, 1,	/* NMODE */
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 32,	/* 32 (abs: 00207) */
/* 00177 */ HB_P_LINE, 197, 0,	/* 197 */
	HB_P_PUSHFUNCSYM, 14, 0,	/* DEVPOS */
	HB_P_ZERO,
	HB_P_ZERO,
	HB_P_DOSHORT, 2,
	HB_P_PUSHFUNCSYM, 15, 0,	/* DEVOUT */
	HB_P_PUSHSTRSHORT, 11,	/* 11 */
	'H', 'i', 't', ' ', 'B', 'o', 't', 't', 'o', 'm', 0, 
	HB_P_DOSHORT, 1,
	HB_P_JUMPNEAR, 83,	/* 83 (abs: 00288) */
/* 00207 */ HB_P_LINE, 199, 0,	/* 199 */
	HB_P_PUSHLOCALNEAR, 1,	/* NMODE */
	HB_P_PUSHBYTE, 3,	/* 3 */
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 73,	/* 73 (abs: 00288) */
/* 00217 */ HB_P_LINE, 200, 0,	/* 200 */
	HB_P_PUSHFUNCSYM, 14, 0,	/* DEVPOS */
	HB_P_ZERO,
	HB_P_ZERO,
	HB_P_DOSHORT, 2,
	HB_P_PUSHFUNCSYM, 15, 0,	/* DEVOUT */
	HB_P_PUSHSTRSHORT, 11,	/* 11 */
	'E', 'x', 'c', 'e', 'p', 't', 'i', 'o', 'n', ' ', 0, 
	HB_P_DOSHORT, 1,
/* 00245 */ HB_P_LINE, 202, 0,	/* 202 */
	HB_P_PUSHLOCALNEAR, 5,	/* NKEY */
	HB_P_PUSHBYTE, 13,	/* 13 */
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 10,	/* 10 (abs: 00263) */
/* 00255 */ HB_P_LINE, 203, 0,	/* 203 */
	HB_P_ONE,
	HB_P_POPLOCALNEAR, 4,	/* NRETVAL */
	HB_P_JUMPNEAR, 27,	/* 27 (abs: 00288) */
/* 00263 */ HB_P_LINE, 204, 0,	/* 204 */
	HB_P_PUSHLOCALNEAR, 5,	/* NKEY */
	HB_P_PUSHBYTE, 27,	/* 27 */
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 10,	/* 10 (abs: 00281) */
/* 00273 */ HB_P_LINE, 205, 0,	/* 205 */
	HB_P_ZERO,
	HB_P_POPLOCALNEAR, 4,	/* NRETVAL */
	HB_P_JUMPNEAR, 9,	/* 9 (abs: 00288) */
/* 00281 */ HB_P_LINE, 207, 0,	/* 207 */
	HB_P_PUSHBYTE, 3,	/* 3 */
	HB_P_POPLOCALNEAR, 4,	/* NRETVAL */
/* 00288 */ HB_P_LINE, 211, 0,	/* 211 */
	HB_P_PUSHLOCALNEAR, 4,	/* NRETVAL */
	HB_P_RETVALUE,
	HB_P_ENDPROC
/* 00295 */
   };

   hb_vmExecute( pcode, symbols );
}

