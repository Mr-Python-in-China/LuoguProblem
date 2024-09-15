import cyaron as c
import string
import random

N=3
T=1
while True:
    io=c.IO("in.in")
    t=c.randint(1,T)
    io.input_writeln(t)
    for i in range(t):
        n=c.randint(1,N)
        p=c.randint(1,n*(n+1)>>1)
        s=''.join((random.choice(string.ascii_lowercase) for i in range(n)))
        io.input_writeln(s)
        io.input_writeln(p)
    c.Compare.program("./CF1886C.bitfile",input=io,std_program="./CF1886C_std.bitfile")