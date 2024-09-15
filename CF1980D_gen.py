import cyaron as c
from math import gcd

N=10
while True:
    io=c.IO("/tmp/in")
    io.input_writeln(1)
    n=c.randint(3,N)
    arr=c.Vector.random(n,[(1,20)],c.vector.VectorRandomMode.repeatable)
    flag=False
    for i in range(n):
        a=[]
        for j in arr:a.append(j[0])
        del a[i]
        b=[gcd(a[j],a[j+1]) for j in range(n-2)]
        flag=True
        for j in range(n-3):
            if b[j]>b[j+1]:
                flag=False
                break
        if flag:
            io.output_writeln("YES")
            break
    if not flag:
        io.output_writeln("NO")
    io.input_writeln(n)
    io.input_writeln(arr)
    c.Compare.program("./CF1980D.bitfile",input=io,std=io)