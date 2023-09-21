#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui a,b;
    cin>>a>>b;
    cout<<(((a==1+1+1||a==1+1+4||a==1+4+4||a==4+4+4)&&b==0)||
        ((a==1+1||a==1+4||a==4+4)&&(b==2||b==3||b==5||b==6))||
        ((a==1||a==4)&&(b==2+2||b==2+3||b==2+5||b==2+6||b==3+3||b==3+5||b==3+6||b==5+5||b==5+6||b==6+6))||
        (a==0&&(b==2+2+2||b==2+2+3||b==2+2+5||b==2+2+6||b==2+3+3||b==2+3+5||b==2+3+6||b==2+5+5||b==2+5+6||b==2+6+6||
                b==3+3+3||b==3+3+5||b==3+3+6||b==3+5+5||b==3+5+6||b==3+6+6||
                b==5+5+5||b==5+5+6||b==5+6+6||b==6+6+6))
        ?"Yes":"No");
    return 0;
}