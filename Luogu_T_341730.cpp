#include<bits/extc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    double c,i,g,m,x;
    cin>>c>>i>>g>>m>>x;
    cout<<fixed<<setprecision(2)<<c+i+g+(x-m);
    return 0;
}