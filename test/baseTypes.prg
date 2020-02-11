func nilValue(); return nil
func booleanTrue(); return .T.
func booleanFalse(); return .F.
func ZeroValue(); return 0
func OneValue(); return 1
func UInt8Value(); return 10
func UInt16Value(); return 1000
func UInt32Value(); return 100000
func Int8Value(); return -10
func Int16Value(); return -1000
func Int32Value(); return -100000
func DoubleValue(); return 3.14159265359
func StringValue(); return "HelloWorld"
func ArrayValue(); return {1,2}
func ArrayValue2()
    LOCAL a[2]
return a
func ArrayValue3()
    LOCAL a[2,3]
return a
func DateValue(); return {^ 2020-01-15 }
func DateValueTime(); return {^ 1987-12-01 12:34:56 }