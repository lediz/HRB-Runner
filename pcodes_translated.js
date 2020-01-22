//from harbour\include\hbpcode.h
HRB.prototype.runCode = function(context,code,args) {
    var view = new DataView(code);
    var pCounter = 0;
    var stack = [];
    while(true) {
        var pCode = view.getUint8(pCounter);
        switch(pCode) {
        case   0 :               /* HB_P_AND performs the logical AND of two latest stack values, removes them and places result */
        case   1 :             /* HB_P_ARRAYPUSH places on the virtual machine stack an array element */
        case   2 :              /* HB_P_ARRAYPOP pops a value from the eval stack into an array element */
        case   3 :              /* HB_P_ARRAYDIM instructs the virtual machine to build an array with some specific dimensions */
        case   4 :              /* HB_P_ARRAYGEN instructs the virtual machine to build an array and load element from the stack */
        case   5 :                 /* HB_P_EQUAL check if the latest two values on the stack are equal, removing them and leaving the result */
        case   6 :              /* HB_P_ENDBLOCK end of a codeblock definition */
        case   7 :               /* HB_P_ENDPROC instructs the virtual machine to end execution */
        case   8 :          /* HB_P_EXACTLYEQUAL check if the latest two values on the stack are exactly equal, removing them and leaving the result */
        case   9 :                 /* HB_P_FALSE pushes false on the virtual machine stack */
        case  10 :               /* HB_P_FORTEST For STEP. If step > 1 less. If step < 1 greater. */
        case  11 :              /* HB_P_FUNCTION instructs the virtual machine to execute a function saving its result */
        case  12 :         /* HB_P_FUNCTIONSHORT instructs the virtual machine to execute a function saving its result */
        case  13 :                 /* HB_P_FRAME instructs the virtual machine about how many parameters and locals a function uses */
        case  14 :               /* HB_P_FUNCPTR returns a function address pointer */
        case  15 :               /* HB_P_GREATER checks if the second latest value on the stack is greater that the latest one */
        case  16 :          /* HB_P_GREATEREQUAL checks if the second latest value on the stack is greater equal that the latest one, leaves the result only */
        case  17 :                   /* HB_P_DEC decrements the latest value on the virtual machine stack */
        case  18 :                /* HB_P_DIVIDE divides the latest two values on the stack, removing them and leaving the result */
        case  19 :                    /* HB_P_DO instructs the virtual machine to execute a function discarding its result */
        case  20 :               /* HB_P_DOSHORT instructs the virtual machine to execute a function discarding its result */
        case  21 :             /* HB_P_DUPLICATE places a copy of the latest virtual machine stack value on to the stack */
        case  22 :         /* HB_P_PUSHTIMESTAMP places a timestamp constant value on the virtual machine stack */
        case  23 :                   /* HB_P_INC increments the latest value on the virtual machine stack */
        case  24 :              /* HB_P_INSTRING checks if the second latest value on the stack is a substring of the latest one */
        case  25 :              /* HB_P_JUMPNEAR jumps to a relative offset 1 Byte */
        case  26 :                  /* HB_P_JUMP jumps to a relative offset 2 Bytes */
        case  27 :               /* HB_P_JUMPFAR jumps to a relative offset 3 Bytes */
        case  28 :         /* HB_P_JUMPFALSENEAR checks a logic expression of the stack and jumps to a relative offset */
        case  29 :             /* HB_P_JUMPFALSE checks a logic expression of the stack and jumps to a relative offset */
        case  30 :          /* HB_P_JUMPFALSEFAR checks a logic expression of the stack and jumps to a relative offset */
        case  31 :          /* HB_P_JUMPTRUENEAR checks a logic expression of the stack and jumps to a relative offset */
        case  32 :              /* HB_P_JUMPTRUE checks a logic expression of the stack and jumps to a relative offset */
        case  33 :           /* HB_P_JUMPTRUEFAR checks a logic expression of the stack and jumps to a relative offset */
        case  34 :             /* HB_P_LESSEQUAL checks if the second latest value on the stack is less equal that the latest one, leaves the result only */
        case  35 :                  /* HB_P_LESS checks if the second latest value on the stack is less that the latest one */
        case  36 :                  /* HB_P_LINE currently compiled source code line number */
        case  37 :             /* HB_P_LOCALNAME sets the name of local variable */
        case  38 :              /* HB_P_MACROPOP compile and run - pop a value from the stack */
        case  39 :       /* HB_P_MACROPOPALIASED compile and run - pop a field value from the stack */
        case  40 :             /* HB_P_MACROPUSH compile and run - leave the result on the stack */
        case  41 :         /* HB_P_MACROARRAYGEN generate array from arguments set on HVM stack { &var } */
        case  42 :         /* HB_P_MACROPUSHLIST compile and run - leave the result on the stack */
        case  43 :        /* HB_P_MACROPUSHINDEX push array items using macro array index */
        case  44 :         /* HB_P_MACROPUSHPARE compile and run - leave the result on the stack */
        case  45 :      /* HB_P_MACROPUSHALIASED compile and run - leave the field value on the stack */
        case  46 :           /* HB_P_MACROSYMBOL compile into a symbol name (used in function calls) */
        case  47 :             /* HB_P_MACROTEXT macro text substitution */
        case  48 :               /* HB_P_MESSAGE sends a message to an object */
        case  49 :                 /* HB_P_MINUS subs the latest two values on the stack, removing them and leaving the result */
        case  50 :               /* HB_P_MODULUS calculates the modulus of the two values on the stack, removing them and leaving the result */
        case  51 :            /* HB_P_MODULENAME sets the name of debugged module */
/* start: pcodes generated by the macro compiler - the symbol address is used */
        case  52 :              /* HB_P_MMESSAGE */
        case  53 :      /* HB_P_MPOPALIASEDFIELD */
        case  54 :        /* HB_P_MPOPALIASEDVAR */
        case  55 :             /* HB_P_MPOPFIELD */
        case  56 :            /* HB_P_MPOPMEMVAR */
        case  57 :     /* HB_P_MPUSHALIASEDFIELD */
        case  58 :       /* HB_P_MPUSHALIASEDVAR */
        case  59 :            /* HB_P_MPUSHBLOCK */
        case  60 :            /* HB_P_MPUSHFIELD */
        case  61 :           /* HB_P_MPUSHMEMVAR */
        case  62 :        /* HB_P_MPUSHMEMVARREF */
        case  63 :              /* HB_P_MPUSHSYM */
        case  64 :         /* HB_P_MPUSHVARIABLE */
/* end: */
        case  65 :                  /* HB_P_MULT multiplies the latest two values on the stack, removing them and leaving the result */
        case  66 :                /* HB_P_NEGATE numerically negates the latest value on the stack */
        case  67 :                  /* HB_P_NOOP no operation */
        case  68 :                   /* HB_P_NOT logically negates the latest value on the stack */
        case  69 :              /* HB_P_NOTEQUAL checks if the latest two stack values are equal, leaves just the result */
        case  70 :                    /* HB_P_OR performs the logical OR of two latest stack values, removes them and places result */
        case  71 :             /* HB_P_PARAMETER creates PRIVATE variables and assigns values to functions parameters */
        case  72 :                  /* HB_P_PLUS adds the latest two values on the stack, removing them and leaving the result */
        case  73 :                   /* HB_P_POP removes the latest value from the stack */
        case  74 :              /* HB_P_POPALIAS pops the item from the eval stack and selects the current workarea */
        case  75 :       /* HB_P_POPALIASEDFIELD pops aliased field */
        case  76 :   /* HB_P_POPALIASEDFIELDNEAR pops aliased field */
        case  77 :         /* HB_P_POPALIASEDVAR pops aliased variable (either a field or a memvar) */
        case  78 :              /* HB_P_POPFIELD pops unaliased field */
        case  79 :              /* HB_P_POPLOCAL pops the contents of the virtual machine stack onto a local variable */
        case  80 :          /* HB_P_POPLOCALNEAR pops the contents of the virtual machine stack onto a local variable */
        case  81 :             /* HB_P_POPMEMVAR pops the contents of a memvar variable to the virtual machine stack */
        case  82 :             /* HB_P_POPSTATIC pops the contents of the virtual machine stack onto a static variable */
        case  83 :           /* HB_P_POPVARIABLE pops the contents of an undeclared variable from the virtual machine stack */
        case  84 :                 /* HB_P_POWER calculates the power of the two values on the stack, removing them and leaving the result */
        case  85 :             /* HB_P_PUSHALIAS saves the current workarea number on the eval stack */
        case  86 :      /* HB_P_PUSHALIASEDFIELD pushes aliased field */
        case  87 :  /* HB_P_PUSHALIASEDFIELDNEAR pushes aliased field */
        case  88 :        /* HB_P_PUSHALIASEDVAR pushes aliased variable (either a field or a memvar) */
        case  89 :             /* HB_P_PUSHBLOCK start of a codeblock definition */
        case  90 :        /* HB_P_PUSHBLOCKSHORT start of a codeblock definition */
        case  91 :             /* HB_P_PUSHFIELD pushes an unaliased field */
        case  92 :              /* HB_P_PUSHBYTE places a 1 byte integer number on the virtual machine stack */
        case  93 :               /* HB_P_PUSHINT places an integer number on the virtual machine stack */
        case  94 :             /* HB_P_PUSHLOCAL pushes the contents of a local variable to the virtual machine stack */
        case  95 :         /* HB_P_PUSHLOCALNEAR pushes the contents of a local variable to the virtual machine stack */
        case  96 :          /* HB_P_PUSHLOCALREF pushes a local variable by reference to the virtual machine stack */
        case  97 :              /* HB_P_PUSHLONG places an integer number on the virtual machine stack */
        case  98 :            /* HB_P_PUSHMEMVAR pushes the contents of a memvar variable to the virtual machine stack */
        case  99 :         /* HB_P_PUSHMEMVARREF pushes the a memvar variable by reference to the virtual machine stack */
        case 100 :               /* HB_P_PUSHNIL places a nil on the virtual machine stack */
        case 101 :            /* HB_P_PUSHDOUBLE places a double number on the virtual machine stack */
        case 102 :              /* HB_P_PUSHSELF pushes Self for the current processed method */
        case 103 :            /* HB_P_PUSHSTATIC pushes the contents of a static variable to the virtual machine stack */
        case 104 :         /* HB_P_PUSHSTATICREF pushes the a static variable by reference to the virtual machine stack */
        case 105 :               /* HB_P_PUSHSTR places a string on the virtual machine stack */
        case 106 :          /* HB_P_PUSHSTRSHORT places a string on the virtual machine stack */
        case 107 :               /* HB_P_PUSHSYM places a symbol on the virtual machine stack */
        case 108 :           /* HB_P_PUSHSYMNEAR places a symbol on the virtual machine stack */
        case 109 :          /* HB_P_PUSHVARIABLE pushes the contents of an undeclared variable to the virtual machine stack */
        case 110 :              /* HB_P_RETVALUE instructs the virtual machine to return the latest stack value */
        case 111 :                  /* HB_P_SEND send operator */
        case 112 :             /* HB_P_SENDSHORT send operator */
        case 113 :              /* HB_P_SEQBEGIN BEGIN SEQUENCE */
        case 114 :                /* HB_P_SEQEND END SEQUENCE */
        case 115 :            /* HB_P_SEQRECOVER RECOVER statement */
        case 116 :                /* HB_P_SFRAME sets the statics frame for a function */
        case 117 :               /* HB_P_STATICS defines the number of statics variables for a PRG */
        case 118 :            /* HB_P_STATICNAME sets the name of static variable */
        case 119 :             /* HB_P_SWAPALIAS restores the current workarea number from the eval stack */
        case 120 :                  /* HB_P_TRUE pushes true on the virtual machine stack */
        case 121 :                  /* HB_P_ZERO places a ZERO on the virtual machine stack */
        case 122 :                   /* HB_P_ONE places a ONE on the virtual machine stack */
        case 123 :             /* HB_P_MACROFUNC execute a function saving its result */
        case 124 :               /* HB_P_MACRODO execute a function discarding its result */
        case 125 :              /* HB_P_MPUSHSTR Macro compiled pushed string */
        case 126 :       /* HB_P_LOCALNEARADDINT Add/Subtract specified int into specified local without using the stack. */
        case 127 :          /* HB_P_MACROPUSHREF Reference to macro variable @&mvar */
        case 128 :          /* HB_P_PUSHLONGLONG places an integer number on the virtual machine stack */
        case 129 :             /* HB_P_ENUMSTART Start of FOR EACH loop */
        case 130 :              /* HB_P_ENUMNEXT Next item of FOR EACH loop */
        case 131 :              /* HB_P_ENUMPREV Previous item of FOR EACH loop */
        case 132 :               /* HB_P_ENUMEND End of FOR EACH loop */
        case 133 :                /* HB_P_SWITCH SWITCH using long values */
        case 134 :              /* HB_P_PUSHDATE places a data constant value on the virtual machine stack */
/* optimization of inlined math operations */
        case 135 :             /* HB_P_PLUSEQPOP adds a value to the variable reference */
        case 136 :            /* HB_P_MINUSEQPOP subs a value from the variable reference */
        case 137 :             /* HB_P_MULTEQPOP multiplies a variable reference by a value */
        case 138 :              /* HB_P_DIVEQPOP divides the var reference by a value */
        case 139 :                /* HB_P_PLUSEQ adds a value to the variable reference, leave result on the stack */
        case 140 :               /* HB_P_MINUSEQ subs a value from the variable reference, leave result on the stack */
        case 141 :                /* HB_P_MULTEQ multiplies a variable reference by a value, leave result on the stack */
        case 142 :                 /* HB_P_DIVEQ divides the var reference by a value, leave result on the stack */
        case 143 :       /* HB_P_WITHOBJECTSTART start WITH OBJECT code */
        case 144 :     /* HB_P_WITHOBJECTMESSAGE push message for WITH OBJECT */
        case 145 :         /* HB_P_WITHOBJECTEND end WITH OBJECT code */
        case 146 :             /* HB_P_MACROSEND send operator with macro list params */
        case 147 :           /* HB_P_PUSHOVARREF pushes reference to object variable */
        case 148 :          /* HB_P_ARRAYPUSHREF pushes reference to array element */
        case 149 :                /* HB_P_VFRAME frame with variable number of parameters */
        case 150 :            /* HB_P_LARGEFRAME frame with more then 255 locals */
        case 151 :           /* HB_P_LARGEVFRAME frame with variable number of parameters and more then 255 locals */
        case 152 :         /* HB_P_PUSHSTRHIDDEN places a "hidden" string on the virtual machine stack */
        case 153 :           /* HB_P_LOCALADDINT Add/Subtract specified int into specified local without using the stack. */
        case 154 :              /* HB_P_MODEQPOP calculates the modulus of var reference and a value */
        case 155 :              /* HB_P_EXPEQPOP calculates the power of var reference and a value */
        case 156 :                 /* HB_P_MODEQ calculates the modulus of var reference and a value, leave result on the stack */
        case 157 :                 /* HB_P_EXPEQ calculates the power of var reference and a value, leave result on the stack */
        case 158 :             /* HB_P_DUPLUNREF places a copy of the latest virtual machine stack value on to the stack and unreference the source one */
        case 159 :       /* HB_P_MPUSHBLOCKLARGE code block generated by the macro compiler larger then 64 KiB */
        case 160 :         /* HB_P_MPUSHSTRLARGE Macro compiled pushed string */
        case 161 :        /* HB_P_PUSHBLOCKLARGE start of a codeblock definition */
        case 162 :          /* HB_P_PUSHSTRLARGE places a string on the virtual machine stack */
        case 163 :                  /* HB_P_SWAP swap n+1 times two items starting from the most top one on the virtual machine stack */
        case 164 :           /* HB_P_PUSHVPARAMS push variable function/method parameters on HVM stack */
        case 165 :             /* HB_P_PUSHUNREF push unreferenced top item on HVM stack */
        case 166 :             /* HB_P_SEQALWAYS set BEGIN SEQUENCE/ALWAYS section */
        case 167 :           /* HB_P_ALWAYSBEGIN start ALWAYS section */
        case 168 :             /* HB_P_ALWAYSEND finish ALWAYS section */
        case 169 :              /* HB_P_DECEQPOP decrements the var reference */
        case 170 :              /* HB_P_INCEQPOP increments the var reference */
        case 171 :                 /* HB_P_DECEQ decrements the var reference, leave result on the stack */
        case 172 :                 /* HB_P_INCEQ increments the var reference, leave result on the stack */
        case 173 :              /* HB_P_LOCALDEC decrements the local variable */
        case 174 :              /* HB_P_LOCALINC increments the local variable */
        case 175 :          /* HB_P_LOCALINCPUSH increments the local variable, push result on the stack */
        case 176 :           /* HB_P_PUSHFUNCSYM places a symbol on the virtual machine stack */
        case 177 :               /* HB_P_HASHGEN instructs the virtual machine to build a hash and load element from the stack */
        case 178 :              /* HB_P_SEQBLOCK set BEQIN SEQUENCE WITH block */
        case 179 :         /* HB_P_THREADSTATICS mark thread static variables */
        case 180 :           /* HB_P_PUSHAPARAMS push array items on HVM stack */
   //HB_P_LAST_PCODE             /* 181 this defines the number of defined pcodes */
        }
    }
}