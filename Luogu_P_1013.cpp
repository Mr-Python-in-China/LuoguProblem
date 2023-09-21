#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
using con=array<char,3>;
[[noreturn]] void ERR(void){
    cout<<"ERROR!";
#ifdef debug
    throw;
#else
    exit(0);
#endif
}
template<size_t N> istream& operator>>(istream& in,array<char,N>& arr){
    return in>>arr.data();
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;--n;
    vector<char> header(n);
    vector<ui> ans(n,-1);
    unordered_map<char,size_t> mapper;
    vector<vector<con>> table(n,vector<con>(n));
    {
        char tmp;
        cin>>tmp;
        if (tmp!='+') ERR();
    }
    for (size_t i=0;i<n;++i) cin>>header[i],mapper[header[i]]=i;
    for (size_t i=0;i<n;i++){
        {
            char tmp;
            cin>>tmp;
            if (tmp!=header[i]) ERR();
        }
        for (size_t j=0;j<i;++j){
            cin>>table[i][j];
            if (table[i][j]!=table[j][i]) ERR();
        }
        for (size_t j=i;j<n;++j) cin>>table[i][j];
    }
    for (size_t i=0;i<n;++i) for (size_t j=0;j<n;++j){
        if (!mapper.count(table[i][j][0])) ERR();
        if (table[i][j][1]&&!mapper.count(table[i][j][1])) ERR();
    }
    char number1=0;
    for (size_t i=0;i<n;++i) for (size_t j=0;j<n;++j)
        if (table[i][j][1])
            if (number1)
                if (number1!=table[i][j][0]) ERR();
                else;
            else number1=table[i][j][0];
    ans[mapper[number1]]=1;

    for (size_t i=0;i<n;++i){
        bool flag=true;
        for (size_t j=0;j<n;++j)
            if (table[i][j][1]||table[i][j][0]!=header[j]){
                flag=false;
                break;
            }
        if (flag){
            ans[i]=0;
            break;
        }
    }
    size_t jz=2;
    for (char i=table[mapper[number1]][mapper[number1]][0];i!=number1;i=table[mapper[i]][mapper[number1]][0],++jz){
        if (ans[mapper[i]]!=-1) ERR();
        ans[mapper[i]]=jz;
    }
    for (ui const& i:ans) if (i==-1) ERR();
    for (size_t const& i:ans) if (i==-1) ERR();
    for (size_t i=0;i<n;++i) for (size_t j=0;j<n;++j){
        if ((table[i][j][1]&&ans[i]+ans[j]!=ans[mapper[table[i][j][0]]]*jz+ans[mapper[table[i][j][1]]])
            ||(!table[i][j][1]&&ans[i]+ans[j]!=ans[mapper[table[i][j][0]]]))
            ERR();
    }
    for (size_t i=0;i<n;++i) cout<<header[i]<<'='<<ans[i]<<' ';
    cout<<'\n'<<jz;
    return 0;
}