#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui a,b,c;
    cin>>a>>b>>c;
    cout<<fixed<<setprecision(3)<<((a+c)*(b+c)-c*c+c*c*M_PI/4)/10000;
    return 0;
}