import cyaron as c

N=3
W=10
while True:
    io=c.IO("/tmp/in")
    n=c.randint(2,N)
    m=c.randint(1,N)
    k=c.randint(1,N)
    io.input_writeln(1)
    io.input_writeln(n,m,k)
    io.input_writeln(c.Vector.random(n,[(1,W)],c.vector.VectorRandomMode.repeatable))
    io.input_writeln(c.Vector.random(m,[(1,W)],c.vector.VectorRandomMode.repeatable))
    io.input_writeln(c.Vector.random(k,[(1,W)],c.vector.VectorRandomMode.repeatable))
    c.Compare.program('./CF1941F.bitfile',std_program='./tmp.bitfile',input=io)