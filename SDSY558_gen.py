import cyaron as c

N=50
while True:
    io=c.IO('/tmp/in')
    t=1
    io.input_writeln(t)
    for _ in range(t):
        n=c.randint(1,N)
        io.input_writeln(n)
        s=[i+1 for i in range(n)]
        p=0
        for i in range(n-1):
            p=(p+i)%(n-i)
            del s[p]
            if p==n-i-1:p=0
        io.output_writeln(s[0])
    c.Compare.program('./SDSY558.bitfile',input=io,std=io)
