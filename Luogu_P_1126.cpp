#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using uc=unsigned char;
enum Robot_Operator{Creep,Walk,Run,Left,Right};
const char F[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
struct robot{
    uc x,y,f;
    robot(uc _x,uc _y,char _f):x(_x),y(_y),f(_f=='N'?0:_f=='E'?1:_f=='S'?2:3){};
    robot op(uc opt) const{
        robot n(*this);
        switch (opt){
        case Creep:n.x+=F[f][0]*1,n.y+=F[f][1]*1;break;
        case Walk:n.x+=F[f][0]*2,n.y+=F[f][1]*2;break;
        case Run:n.x+=F[f][0]*3,n.y+=F[f][1]*3;break;
        case Left:n.f+=1,n.f%=4;break;
        case Right:n.f+=3,n.f%=4;break;
        }
        return n;
    }
    inline friend bool operator==(const robot a,const robot b){return a.x==b.x&&a.y==b.y&&a.f==b.f;}
    inline friend ostream& operator<<(ostream& op,const robot x){
        return op<<x.x+0<<','<<x.y+0<<':'<<x.f+0;
    }
};
namespace std{
    template<> struct hash<robot>{
        size_t operator()(const robot x) const{
            hash<uc> h;
            return (h(x.x)<<16)+(h(x.y)<<8)+(h(x.f)<<0);
        }
    };
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    vector<vector<bool>> mp(n,vector<bool>(m));
    for (vector<vector<bool>>::reference i:mp) for (vector<bool>::reference j:i){
        bool b;cin>>b;j=b;
    }
    size_t p1,p2,p3,p4;char p5;
    cin>>p1>>p2>>p3>>p4>>p5;
    queue<robot> q({robot(p1,p2,p5)});
    unordered_map<robot,size_t> vis;
    vis[robot(p1,p2,p5)]=0;
    while (!q.empty()){
        const robot p=q.front();q.pop();
        //cout<<p<<":\n";
        if (p.x==p3&&p.y==p4) cout<<vis[p],exit(0);
        for (uc i=Creep;i<=Right;i++){
            const robot np=p.op(i);
            if (np.x<=0||np.y<=0||np.x>=n||np.y>=m||vis.count(np)) goto No;
            switch (i){
            case Run:
                if (mp[np.x-1-(F[np.f][0]<<1)][np.y-1-(F[np.f][1]<<1)]||
                    mp[np.x-1-(F[np.f][0]<<1)][np.y-(F[np.f][1]<<1)]||
                    mp[np.x-(F[np.f][0]<<1)][np.y-1-(F[np.f][1]<<1)]||
                    mp[np.x-(F[np.f][0]<<1)][np.y-(F[np.f][1]<<1)])
                    goto No;
            case Walk:
                if (mp[np.x-1-F[np.f][0]][np.y-1-F[np.f][1]]||
                    mp[np.x-1-F[np.f][0]][np.y-F[np.f][1]]||
                    mp[np.x-F[np.f][0]][np.y-1-F[np.f][1]]||
                    mp[np.x-F[np.f][0]][np.y-F[np.f][1]])
                    goto No;
            case Creep:
                if (mp[np.x-1][np.y-1]||
                    mp[np.x-1][np.y]||
                    mp[np.x][np.y-1]||
                    mp[np.x][np.y])
                    goto No;
            }
            //cout<<p<<"->"<<np<<'\n',
            vis[np]=vis[p]+1,q.push(np);
            No:;
        }
    }
    cout<<"-1";
    return 0;
}