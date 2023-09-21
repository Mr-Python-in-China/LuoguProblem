#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
struct pos{
    size_t x,y;
    friend istream& operator>>(istream& in,pos& p){return in>>p.x>>p.y;}
};
template<typename T> class PrefixSum2D{
    vector<vector<T>> sum;
public:
    template<typename S>
    PrefixSum2D(vector<vector<S>> const& a):sum(a.size()+1,vector<T>(a.front().size()+1)){
        size_t const n=sum.size(),m=sum.front().size();
        for (size_t i=0;i<n;i++) for (size_t j=0;j<m;j++)
            sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+a[i][j];
    }
    T get_sum(size_t ax,size_t ay,size_t bx,size_t by) const{
        return sum[bx][by]+sum[ax][ay]-sum[ax][by]-sum[bx][ay];
    }
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    vector<size_t> ldx,ldy;
    vector<pos> p(m);
    for (pos& i:p){
        cin>>i;
        ldx.push_back(i.x),ldy.push_back(i.y);
    }
    sort(ldx.begin(),ldx.end()),sort(ldy.begin(),ldy.end());
    ldx.erase(unique(ldx.begin(),ldx.end()),ldx.end()),ldy.erase(unique(ldy.begin(),ldy.end()),ldy.end());
    vector<vector<bool>> trees(n,vector<bool>(m));
    for (pos& i:p){
        i.x=lower_bound(ldx.cbegin(),ldx.cend(),i.x)-ldx.cbegin(),
        i.y=lower_bound(ldy.cbegin(),ldy.cend(),i.y)-ldy.cbegin();
        trees[i.x][i.y]=true;
    }
    PrefixSum2D<size_t> s(trees);
    for (vector<pos>::const_iterator it=p.begin();it<p.end();it++) for (vector<pos>::const_iterator jt=p.begin();jt<p.end();jt++){
        if (it->x<jt->x&&ldx[jt->x]-ldy[it->x]>=abs(int(ldy[it->y]-ldy[jt->y]))){
            size_t miny=min(it->y,jt->y),maxy=max(it->y,jt->y);
            size_t leftline,rightline;
            {
                size_t l=0,r=miny;
                while (l<r){
                    size_t mid=((r-l)>>1)+l;
                    if (s.get_sum(it->x+1,0,jt->x,mid)<s.get_sum(it->x+1,0,jt->x,miny)) r=mid-1;
                    else l=mid;
                }
                leftline=l;
            }
            {
                size_t l=0,r=miny;
                while (l<r){
                    size_t mid=((r-l)>>1)+l;
                    if (s.get_sum(it->x+1,0,jt->x,mid)<s.get_sum(it->x+1,0,jt->x,miny)) r=mid-1;
                    else l=mid;
                }
                rightline=l;
            }
        }
        if (it->y<jt->y&&jt->y-it->y>=abs(int(it->x-jt->x))){

        }
    }
    return 0;
}