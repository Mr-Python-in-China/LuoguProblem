m,n=(int(i) for i in input().split(' '))
n-=m
if (n==1 or n==2):
    print('1')
a,b=1,1
for i in range(1,n):a,b=b,a+b
print(b)