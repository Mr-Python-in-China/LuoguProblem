T=int(input())
while T:
    n=int(input())
    s=input()
    ans=0
    f=0
    for i in range(n):
        ans+=int(s[n-i-1])*f
        f=10*f+1
    print(ans+int(s))
    T-=1
