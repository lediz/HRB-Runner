
func main(v,c)
    LOCAL a:=subFn(4,3)
    c:={2,3,4}
    c[2]:=10
    c[2]--
    v := 4/c[2]
    c[1] = {^ 2020-01-22 12:34:56 }
    c[1]+=1
    ? "Hello", a, .f., {^ 2020-01-22 }, v, c[2],  c[1]
return 5

function subFn(a,b)
    if a>b
        return a-b
    else
        return a+b
    endif
return 0
