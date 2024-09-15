import cyaron as c

N=4
while True:
    io=c.IO('/tmp/in')
    n=c.randint(2,N)
    k=c.randint(2,n)
    m=c.randint(n-1,n*(n-1)//2)
    graph=c.Graph.graph(n, m, directed=True, weight_limit=(1,10))
    io.input_writeln(1)
    io.input_writeln(n,m,k)
    io.input_writeln(graph.to_str(shuffle=True))
    io.input_writeln(c.Vector.random(k,[(1,n)]))
    c.Compare.program('./Luogu_P_5304.bitfile',std_program='./Luogu_P_5304_std.bitfile',input=io)
