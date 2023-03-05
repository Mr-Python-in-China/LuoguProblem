#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
const size_t N=1e5+1;
struct op{bool type;ui val;};
template<typename T> inline T string_to_number(string s){
    T res=0;
    for (string::reference i:s) res=res*10+i-'0';
    return res;
}
const ui AND=0,OR=1,NOT=2;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    vector<op> exp;
    ui n;
    while (true){
        string s;
        cin>>s;
        if (isdigit(s[0])){
            n=string_to_number<ui>(s);
            break;
        }
        if (s[0]=='x')
            exp.push_back({0,string_to_number<ui>(s.substr(1))});
        else exp.push_back({1,(s[0]=='&'?AND:s[0]=='|'?OR:NOT)});
    }
    vector<bool> val(n);
    for (vector<bool>::reference i:val){bool b;cin>>b;i=b;}
    ui q;
    cin>>q;
    while (q--){
        ui p;
        cin>>p;p--;
        val[p]=!val[p];
        stack<char> opt;stack<ui> num;
        for (vector<op>::reverse_iterator it=exp.rbegin();it!=exp.rend();it++){
            if (it->type) opt.push(it->val);
            else if (opt.size()>1){
                if (opt.top()==NOT&&num.size()>=1){
                    bool tmp=val[num.top()];num.pop(),opt.pop();
                    num.push(!tmp);
                }else if (num.size()>=2){
                    bool tmp=num.top();num.pop();
                    opt.top()==AND?tmp&=num.top():tmp|=num.top();
                    num.pop(),opt.pop();
                    num.push(tmp);
                }
            }else num.push(it->val);
        }
        val[p]=!val[p];
        cout<<num.top()<<'\n';
    }
    return 0;
}