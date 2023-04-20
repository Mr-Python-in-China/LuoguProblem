#include<bits/stdc++.h>
using namespace std;
using uli=unsigned long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    time_t n;
    cin>>n;n/=1000;
    tm t=*gmtime(&n);
    if (t.tm_hour<10) cout.put('0');
    cout<<t.tm_hour<<':';
    if (t.tm_min<10) cout.put('0');
    cout<<t.tm_min<<':';
    if (t.tm_sec<10) cout.put('0');
    cout<<t.tm_sec;
    return 0;
}