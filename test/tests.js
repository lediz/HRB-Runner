// 28/181 codes tested
QUnit.test( "baseTypes", function( assert ) {
    var runner = new HRB();
    // TESTING:
    // HB_P_PUSHNIL, HB_P_RETVALUE, HB_P_ENDPROC
    // HB_P_TRUE, HB_P_FALSE, HB_P_ZERO, HB_P_ONE
    // HB_P_PUSHBYTE, HB_P_PUSHINT, HB_P_PUSHLONG
    // HB_P_PUSHDOUBLE, HB_P_PUSHSTRSHORT, HB_P_ARRAYPOP,
    // HB_P_ARRAYGEN,  HB_P_FRAME, HB_P_ARRAYDIM, HB_P_POPLOCALNEAR
    // func nilValue(); return nil
    assert.equal( runner.runCode({},(new Int8Array([100,110,7])).buffer,[]), undefined, "nilvalue");
    // func booleanTrue(); return .T.
    assert.equal( runner.runCode({},(new Int8Array([120,110,7])).buffer,[]), true, "Logical true");
    // func booleanFalse(); return .T.
    assert.equal( runner.runCode({},(new Int8Array([9,110,7])).buffer,[]), false, "Logical false");

    // func ZeroValue(); return 0
    assert.equal( runner.runCode({},(new Int8Array([121,110,7])).buffer,[]), 0, "numeric zero");
    // func OneValue(); return 1
    assert.equal( runner.runCode({},(new Int8Array([122,110,7])).buffer,[]), 1, "numeric one");
    // func UInt8Value(); return 10
    assert.equal( runner.runCode({},(new Int8Array([92,10,110,7])).buffer,[]), 10, "numeric 10");
    // func UInt16Value(); return 1000
    assert.equal( runner.runCode({},(new Int8Array([93,232,3,110,7])).buffer,[]), 1000, "numeric 1000");
    // func UInt32Value(); return 100000
    assert.equal( runner.runCode({},(new Int8Array([97,160,134,1,0,110,7])).buffer,[]), 100000, "numeric 100000");
    // func Int8Value(); return -10
    assert.equal( runner.runCode({},(new Int8Array([92,246,110,7])).buffer,[]), -10, "numeric -10");
    // func Int16Value(); return -1000
    assert.equal( runner.runCode({},(new Int8Array([93,24,252,110,7])).buffer,[]), -1000, "numeric -1000");
    // func Int32Value(); return -100000
    assert.equal( runner.runCode({},(new Int8Array([97,96,121,254,255,110,7])).buffer,[]), -100000, "numeric -100000");
    //func DoubleValue(); return 3.14159265359
    assert.equal( runner.runCode({},(new Int8Array([101,234,46,68,84,251,33,9,64,10,11,110,7])).buffer,[]), 3.14159265359, "numeric pi");
    //func StringValue(); return "HelloWorld"
    assert.equal( runner.runCode({},(new Int8Array([106,11,72,101,108,108,111,87,111,114,108,100,0,110,7])).buffer,[]), "HelloWorld", "character HelloWorld");
    //func ArrayValue(); return {1,2}
    assert.deepEqual( runner.runCode({},(new Int8Array([122,92,2,4,2,0,110,7])).buffer,[]), [1,2], "array direct");
    //func ArrayValue2(); return Array(2)
    assert.deepEqual( runner.runCode({},(new Int8Array([13,1,0,36,16,0,92,2,3,1,0,80,1,36,17,0,95,1,110,7])).buffer,[]), [undefined,undefined], "array empty");
});

QUnit.test( "dateTimeTypes", function( assert ) {
    var runner = new HRB();
    // func date1(); return {^ 2020-01-01 }
    assert.equal( runner.runCode({},(new Int8Array([134,226,132,37,0,110,7])).buffer,[]) - new Date(2020,0,1), 0, "simple date");
    // func dateTime1(); return {^ 2020-01-01 12:34:56.1 }
    assert.equal( runner.runCode({},(new Int8Array([22,226,132,37,0,228,41,179,2,110,7])).buffer,[])- new Date(2020,0,1,12,34,56,100),0, "simple datetime ");
});

QUnit.test( "comparissons", function( assert ) {
    var runner = new HRB();
    // testing
    // HB_P_EQUAL, HB_P_NOTEQUAL, HB_P_GREATER, HB_P_GREATEREQUAL
    // HB_P_LESS, HB_P_LESSEQUAL,
    //func Equal(a,b); return a=b
    var Equal = (a,b) => runner.runCode({},(new Int8Array([13,0,2,95,1,95,2,5,110,7])).buffer,[a,b]);
    //func Different(a,b); return a==b
    var Different = (a,b) => runner.runCode({},(new Int8Array([13,0,2,95,1,95,2,69,110,7])).buffer,[a,b]);
    //func GreaterFn(a,b); return a>b
    var GreaterFn = (a,b) => runner.runCode({},(new Int8Array([13,0,2,95,1,95,2,15,110,7])).buffer,[a,b]);
    //func GreaterEqual(a,b); return a>=b
    var GreaterEqual = (a,b) => runner.runCode({},(new Int8Array([13,0,2,95,1,95,2,16,110,7])).buffer,[a,b]);
    //func LowerFn(a,b); return a<b
    var LowerFn = (a,b) => runner.runCode({},(new Int8Array([13,0,2,95,1,95,2,35,110,7])).buffer,[a,b]);
    //func LowerEqual(a,b); return a<=b
    var LowerEqual = (a,b) => runner.runCode({},(new Int8Array([13,0,2,95,1,95,2,34,110,7])).buffer,[a,b]);

    assert.equal( Equal(1,1), true, "compare equal number true");
    assert.equal( Equal(1,2), false, "compare equal number false");
    assert.equal( Equal("a","a"), true, "compare equal character true");
    assert.equal( Equal("a","b"), false, "compare equal character false");

    assert.equal( Different(1,2), true, "compare different number true");
    assert.equal( Different(1,1), false, "compare different number false");
    assert.equal( Different("a","b"), true, "compare different character true");
    assert.equal( Different("a","a"), false, "compare different character false");

    assert.equal( GreaterFn(2,1), true, "compare greater number true");
    assert.equal( GreaterFn(2,2), false, "compare greater number false");
    assert.equal( GreaterFn(1,2), false, "compare greater number false");

    assert.equal( GreaterEqual(2,1), true, "compare greater equal number true");
    assert.equal( GreaterEqual(2,2), true, "compare greater equal number true");
    assert.equal( GreaterEqual(1,2), false, "compare greater equal number false");

    assert.equal( LowerFn(1,2), true, "compare lower number true");
    assert.equal( LowerFn(2,2), false, "compare lower number false");
    assert.equal( LowerFn(2,1), false, "compare lower number false");

    assert.equal( LowerEqual(1,2), true, "compare lower equal number true");
    assert.equal( LowerEqual(2,2), true, "compare lower equal number true");
    assert.equal( LowerEqual(2,1), false, "compare lower equal number false");
});

QUnit.test( "base math", function( assert ) {
    var runner = new HRB();
    // TESTING
    // HB_P_NEGATE, HB_P_PLUS, HB_P_MINUS, HB_P_MULT, HB_P_DIVIDE
    // HB_P_DUPLICATE, HB_P_POP
    // function negate(a); return -a
    var neg = (a) => runner.runCode({},(new Int8Array([13,0,1,95,1,66,110,7])).buffer,[a]);
    //function add(a,b); return a+b
    var add = (a,b) => runner.runCode({},(new Int8Array([13,0,2,95,1,95,2,72,110,7])).buffer,[a,b]);
    //function sub(a,b); return a-b
    var sub = (a,b) => runner.runCode({},(new Int8Array([13,0,2,95,1,95,2,49,110,7])).buffer,[a,b]);
    //function mul(a,b); return a*b
    var mul = (a,b) => runner.runCode({},(new Int8Array([13,0,2,95,1,95,2,65,110,7])).buffer,[a,b]);
    //function div(a,b); return a/b
    var div = (a,b) => runner.runCode({},(new Int8Array([13,0,2,95,1,95,2,18,110,7])).buffer,[a,b]);
    assert.equal( neg(0.1), -0.1, "negate number");
    assert.equal( add(1,2), 3, "sum 2 numbers int");
    assert.equal( add(0.1,0.2), 0.1+0.2, "sum 2 numbers float");
    assert.equal( sub(1,2), -1, "sub 2 numbers int");
    assert.equal( sub(0.1,0.2), -0.1, "sub 2 numbers float");
    assert.equal( mul(2,3), 6, "mul 2 numbers int");
    assert.equal( mul(0.2,3.0), 0.2*3, "mul 2 numbers float");
    assert.equal( div(1,2), 0.5, "div 2 numbers int");
    assert.equal( div(0.1,0.2), 0.5, "div 2 numbers float");

    assert.equal( add("1","2"), "12", "sum string");
    // function logAnd(a,b); return a .and. b
    var logAnd = (a,b) => runner.runCode({},(new Int8Array([13,0,2,95,1,21,28,5,73,95,2,110,7])).buffer,[a,b]);
    // function logOr(a,b); return a .or. b
    var logOr  = (a,b) => runner.runCode({},(new Int8Array([13,0,2,95,1,21,31,5,73,95,2,110,7])).buffer,[a,b]);
    assert.equal( logAnd(false,false), false, "logical and 1");
    assert.equal( logAnd(false, true), false, "logical and 2");
    assert.equal( logAnd( true,false), false, "logical and 3");
    assert.equal( logAnd( true, true),  true, "logical and 4");
    assert.equal(  logOr(false,false), false, "logical or 1");
    assert.equal(  logOr(false, true),  true, "logical or 2");
    assert.equal(  logOr( true,false),  true, "logical or 3");
    assert.equal(  logOr( true, true),  true, "logical or 4");
});