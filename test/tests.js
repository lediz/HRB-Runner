

QUnit.test( "baseTypes", function( assert ) {
    var runner = new HRB();
    // func booleanTrue(); return .T.
    assert.equal( runner.runCode({},(new Int8Array([120,110,7])).buffer,[]), true);

    // func booleanFalse(); return .T.
    assert.equal( runner.runCode({},(new Int8Array([9,110,7])).buffer,[]), false);

    // func ZeroValue(); return 0
    assert.equal( runner.runCode({},(new Int8Array([121,110,7])).buffer,[]), 0);
    // func OneValue(); return 1
    assert.equal( runner.runCode({},(new Int8Array([122,110,7])).buffer,[]), 1);
    // func UInt8Value(); return 10
    assert.equal( runner.runCode({},(new Int8Array([92,10,110,7])).buffer,[]), 10);
    // func UInt16Value(); return 1000
    assert.equal( runner.runCode({},(new Int8Array([93,232,3,110,7])).buffer,[]), 1000);
    // func UInt32Value(); return 100000
    assert.equal( runner.runCode({},(new Int8Array([97,160,134,1,0,110,7])).buffer,[]), 100000);
    // func Int8Value(); return -10
    assert.equal( runner.runCode({},(new Int8Array([92,246,110,7])).buffer,[]), -10);
    // func Int16Value(); return -1000
    assert.equal( runner.runCode({},(new Int8Array([93,24,252,110,7])).buffer,[]), -1000);
    // func Int32Value(); return -100000
    assert.equal( runner.runCode({},(new Int8Array([97,96,121,254,255,110,7])).buffer,[]), -100000);
});