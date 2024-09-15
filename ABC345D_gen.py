import cyaron as c

K=7
N=10
while True:
    io=c.IO('/tmp/in')
    k=c.randint(1,K)
    n,m=c.randint(1,N),c.randint(1,N)
    io.input_writeln(k,n,m)
    for i in range(k):
        io.input_writeln(c.randint(1,N),c.randint(1,N))
    c.Compare.program('./ABC345D.bitfile',std_program='./ABC345D_std.bitfile',input=io)
