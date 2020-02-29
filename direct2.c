/*
 * Harbour 3.2.0dev (r2001131815)
 * Microsoft Visual C++ 19.16.27034 (64-bit)
 * Generated C source from "direct2.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TEST );
HB_FUNC_STATIC( ADDSPAN );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_DIRECT2 )
{ "TEST", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TEST )}, NULL },
{ "CREATEELEMENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DOCUMENT", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "_TEXTCONTENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ONCLICK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDSPAN", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( ADDSPAN )}, NULL },
{ "APPENDCHILD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BODY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_DIRECT2, "direct2.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_DIRECT2
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_DIRECT2 )
   #include "hbiniseg.h"
#endif

HB_FUNC( TEST )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,5,0,48,1,0,98,2,0,106,7,
		98,117,116,116,111,110,0,112,1,80,1,36,6,0,
		48,3,0,95,1,106,10,99,108,105,99,107,32,109,
		101,33,0,112,1,73,36,7,0,48,4,0,95,1,
		89,13,0,1,0,0,0,176,5,0,12,0,6,112,
		1,73,36,8,0,48,6,0,48,7,0,98,2,0,
		112,0,95,1,112,1,73,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( ADDSPAN )
{
	static const HB_BYTE pcode[] =
	{
		116,8,0,36,12,0,103,1,0,100,8,28,43,36,
		13,0,48,1,0,98,2,0,106,5,115,112,97,110,
		0,112,1,82,1,0,36,14,0,48,6,0,48,7,
		0,98,2,0,112,0,103,1,0,112,1,73,36,16,
		0,48,3,0,103,1,0,106,20,72,101,108,108,111,
		32,102,114,111,109,32,72,97,114,98,111,117,114,32,
		0,103,2,0,72,112,1,73,36,17,0,104,2,0,
		122,135,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,8,0,2,0,116,8,0,121,82,2,0,7
	};

	hb_vmExecute( pcode, symbols );
}

