import cyaron as c
import tqdm

N=100
W=int(1e9)
for _ in tqdm.trange(10000):
    io=c.IO("/tmp/in")
    n=c.randint(2,N)
    x=c.randint(0,W)
    io.input_writeln(n,x)
    io.input_writeln(c.Vector.random(n,[(0,W)],c.vector.VectorRandomMode.repeatable))
    c.Compare.program('./SDSY501.bitfile',std_program='./SDSY501_std.bitfile',input=io)