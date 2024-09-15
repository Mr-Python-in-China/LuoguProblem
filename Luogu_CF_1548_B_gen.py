import cyaron as c


T=1
N=5
W=10
while True:
    io=c.IO("/tmp/inp.in")
    t=c.randint(1,T)
    io.input_writeln(t)
    for i in range(t):
        n=c.randint(1,N)
        io.input_writeln(n)
        a=c.Vector.random(n,[(1,W)],1)
        io.input_writeln(a)
    c.Compare.program("./Luogu_CF_1548_B.bitfile",input=io,std_program="./Luogu_CF_1548_B_std.bitfile")

