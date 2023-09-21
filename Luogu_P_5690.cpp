#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int m,d;
    cin>>m>>d;
    m=abs(m),d=abs(d);
    if(d>0&&d<=28)
        if(m>0&&m<=12)cout<<0;
        else cout<<1;
    else if(d==29||d==30)
        if(m==2||m==0||m>12)cout<<1;
        else cout<<0;
    else if(d==31)
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) cout<<0;
        else if(m==2||m==4||m==6||m==9||m==11||m>=13&&m<=19) cout<<1;
        else if(m%10==4||m%10==6||m%10==9) cout<<2;
        else cout<<1;
    else if(m==0||m>12) cout<<2;
    else cout<<1;
    return 0;
}