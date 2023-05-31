#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    stack<int> stk;
    while (n--){
        char op;int x;
        cin>>op>>x;
        if (op=='1') stk.push(x);
        else{
            size_t cnt=0;
            while (!stk.empty()&&stk.top()!=x) cnt++,stk.pop();
            if (!stk.empty()) cnt++,stk.pop();
            cout<<cnt<<'\n';
        }
    }
    return 0;
}