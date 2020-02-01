
func main(v,c)
    LOCAL a:=subFn(4,3)
    c:={2,3,4}
    c[2]:=10
    c[2]--
    ? "Hello", a, .f., {^ 2020-01-22 }, v, c[2]
return 5

function subFn(a,b)
    if a>b
        return a-b
    else
        return a+b
    endif
return 0
