#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
size_t fun(string::const_iterator const& begin,string::const_iterator const& end){
    size_t x=begin==end?0:fun(begin,prev(end))*26+*prev(end)-'a'+1;
    return x;
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    string s;
    cin>>s;
    cout<<fun(s.cbegin(),s.cend())+1;
    return 0;
}