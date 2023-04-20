#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    //ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t m,n;
    cin>>m>>n;
    const size_t weight=(1<<(m-2))*6-1;
    vector<vector<char>> mp(1,vector<char>(weight,' '));
    vector<size_t> high(1);
    {
        size_t far=3,length=6;
        for (size_t i=0;i<weight;i+=length)
            mp.back()[i]=mp.back()[i+far+1]='o';
        for (size_t i=1;i<m;i++){
            size_t jl,jr,start=(length-3-far)>>1;
            for (jl=1,jr=far;jl<jr;jl++,jr--){
                mp.push_back(vector<char>(weight,' '));
                for (size_t k=start;k<weight;k+=length)
                    mp.back()[k+jl]='/',mp.back()[k+jr]='\\';
            }
            mp.push_back(vector<char>(weight,' '));
            far=length-1,length<<=1,start=(length-3-far)>>1;
            for (size_t i=start;i<weight;i+=length){
                mp.back()[i]='o';
                if (i+far+1<weight) mp.back()[i+far+1]='o';
            }
        }
    }
    for (vector<vector<char>>::const_reverse_iterator it=mp.crbegin();it!=mp.crend();it++){
        for (const char& j:*it) cout<<j;
        cout<<'\n';
    }
    while (m--){
        size_t x,y;
        cin>>x>>y;
        --x,--y;
        size_t length=(weight+1)>>x;
    }
    return 0;
}