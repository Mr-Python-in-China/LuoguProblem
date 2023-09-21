gcd=lambda a,b:b if a%b==0 else gcd(b,a%b)
lcm=lambda a,b:a*b//gcd(a,b)
def f(a:list)->bool:
    times=1
    g=a[0]
    l=a[0]
    for i in a:
        times*=i
        g,l=gcd(g,i),lcm(l,i)
    return g*l==times

t=int(input())
while t:
    n=int(input())
    a=[int(i) for i in input().split(' ')]
    print("Yes" if f(a) else "No")
    t-=1
