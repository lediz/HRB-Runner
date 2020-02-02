QUnit.test( "baseTypes", function( assert ) {
    var runner = new HRB();
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
});
