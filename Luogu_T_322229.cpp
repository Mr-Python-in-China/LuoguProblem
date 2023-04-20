#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    cout<<((a<60&&b>=60&&c>=60)||(a>=60&&b<60&&c>=60)||(a>=60&&b>=60&&c<60)||(a>=60&&b>=60&&c>=60)?"PASS":"FAIL")<<'\n'
        <<(double(a*d+b*e+c*f)/(d+e+f)>=60?"PASS":"FAIL");
    return 0;
}