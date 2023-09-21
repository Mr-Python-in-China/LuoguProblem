import cyaron as c
from random import shuffle

N=10
while True:
    io=c.IO("test.in")
    n=c.randint(2,N)
    a=c.Vector.random(n-1,[N**2],1)
    io.input_writeln(1)
    io.input_writeln(n)
    io.input_writeln(a)
    c.Compare.program("./CF1851D.bitfile",input=io,std_program="./CF1851D_std.bitfile")