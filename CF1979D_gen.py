import cyaron as c

K=20
D=20
while True:
    k=c.randint(1,K)
    n=k*c.randint(1,D)
    arr=c.Vector.random(n,[(0,1)],c.vector.VectorRandomMode.repeatable)
    io=c.IO("/tmp/in","/tmp/out")
    io.input_writeln(1)
    io.input_writeln(n,k)
    io.input_writeln(arr)
    
    a=[bool(i[0]) for i in arr]
    ans=-1
    for i in range(n,0,-1):
        d=a[i:]+a[i-1::-1]
        flag=d[0]
        ans=i
        for j in range(0,n,k):
            if d[j:j+k]!=[flag]*k:
                ans=-1
                break
            flag=not flag
        if ans!=-1:
            break
    io.output_writeln(ans)
    c.Compare.program('./CF1979D.bitfile',input=io,std=io)
