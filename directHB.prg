memvar document

proc test()
    LOCAL oSpan
    oSpan := document:createElement("span")
    oSpan:textContent := "Hello from Harbour"
    document:body:appendChild(oSpan);
