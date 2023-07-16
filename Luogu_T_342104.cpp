#include<bits/extc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    ui timer=0;
    while (n--){
        ui sz;bool like;
        cin>>sz>>like;
        timer+=(like?sz:10);
    }
    cout<<timer;
    return 0;
}