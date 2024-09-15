import re
import string

def rd(s,i):
    if s[i]=='-':
        flag=True
        i+=1
    else:
        flag=False
    res=0
    while s[i] in string.digits:
        res=res*10+int(s[i])
        i+=1
    if flag:res*=-1
    return res,i

s=input()
if not re.match(r"^\/fill\ ~-*\d*\ ~-*\d*\ ~-*\d*\ ~-*\d*\ ~-*\d*\ ~-*\d*\ tnt\ 0\ replace\ air$",s):
    print("Error")
else:
    a=[0,0,0,0,0,0]
    i=7
    for j in range(6):
        a[j],i=rd(s,i)
        i+=2
    print(max(abs(a[3]-a[0]),1)*max(abs(a[4]-a[1]),1)*max(abs(a[5]-a[2]),2))