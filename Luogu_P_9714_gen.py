import cyaron as c

T=30
N=100
V=50
while True:
    io=c.IO("1.in")
    t=c.randint(1,T)
    io.input_writeln(t)
    for i in range(t):
        n=c.randint(1,N)
        t=c.Vector.random(n,[(1,V)],1)
        b=c.Vector.random(n,[(1,V)],1)
        io.input_writeln(n)
        io.input_writeln(t)
        io.input_writeln(b)
    c.Compare.program("./Luogu_P_9714.bitfile",input=io,std_program="./Luogu_P_9714_std.bitfile")