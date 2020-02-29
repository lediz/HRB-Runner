memvar document

proc test()
    LOCAL oBtn
    oBtn := document:createElement("button")
    oBtn:textContent := "click me!"
    oBtn:onclick := {|e| AddSpan()}
    document:body:appendChild(oBtn)

static proc AddSpan()
    static oSpan, n:=0
    if oSpan==nil
        oSpan := document:createElement("span")
        document:body:appendChild(oSpan)
    endif
    oSpan:textContent := "Hello from Harbour " + n
    n+=1
