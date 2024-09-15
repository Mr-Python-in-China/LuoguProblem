import cyaron as c

N=10
while True:
    io=c.IO("/tmp/in")
    n=c.randint(2,N)
    io.input_writeln(n)
    flag=False
    while not flag:
        v=c.Vector.random(n,[(1,n)],c.vector.VectorRandomMode.repeatable)
        for i in v:
            if i[0]==1:
                flag=True
                break
    io.input_writeln(v)
    c.Compare.program('./SDSY1425.bitfile',std_program='./SDSY1425_std.bitfile',input=io)