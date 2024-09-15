import cyaron as c

N=80
K=int(1e9)
while True:
    io=c.IO("/tmp/in")
    n=c.randint(2,N)
    io.input_writeln(n)
    for i in range(n):
        io.input_writeln(c.Vector.random(n,[(90000000,K)],c.vector.VectorRandomMode.repeatable))
    for i in range(n):
        io.input_writeln(c.Vector.random(n-1,[(90000000,K)],c.vector.VectorRandomMode.repeatable))
    for i in range(n-1):
        io.input_writeln(c.Vector.random(n,[(90000000,K)],c.vector.VectorRandomMode.repeatable))
    c.Compare.program('./ABC334F.bitfile',std_program='python ./ABC334F_std.py',input=io)
