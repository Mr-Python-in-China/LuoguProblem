#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui n;
    cin>>n;
    ui m=-2;
    while ((1<<(m+=2))<n);
    cout<<m-2;
    return 0;
}