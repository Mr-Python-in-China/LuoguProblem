#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using li=long long int;
template<typename T> class SGtree{
    class node{
        T val,lazy;
        size_t itvl,itvr;
        node* nodel,*noder;
        bool in_inrerval(size_t l,size_t r){return l<=itvl&&itvr<=r;}
        bool no_matter(size_t l,size_t r){return r<=itvl||itvr<=l;}
    public:
        node(typename vector<T>::const_iterator beg,typename vector<T>::const_iterator end,size_t p):
            lazy(),itvl(p),itvr(end-beg+p),nodel(nullptr),noder(nullptr){
            if (itvr-itvl>1){
                nodel=new node(beg,beg+(end-beg >>1),p),
                noder=new node(beg+(end-beg >>1),end,p+(end-beg >>1));
                val=nodel->val+noder->val;
            }else val=*beg;
        }
        node(size_t l,size_t r):val(),lazy(),itvl(l),itvr(r),nodel(nullptr),noder(nullptr){
            if (itvr-itvl>1){
                nodel=new node(l,l+(r-l >>1)),
                noder=new node(l+(r-l >>1),r);
                val=l+r;
            }else val=T();
        }
        void update(void){
            val+=(itvr-itvl)*lazy;
            if (itvr-itvl>1) nodel->lazy+=lazy,noder->lazy+=lazy;
        }
        void add_interval(size_t l,size_t r,T const& v){
            if (no_matter(l,r)) return;
            if (in_inrerval(l,r)) lazy+=v;
            else nodel->add_interval(l,r,v),noder->add_interval(l,r,v);
        }
        T get_sum(size_t l,size_t r){
            if (no_matter(l,r)) return 0;
            update();
            if (in_inrerval(l,r)) return val;
            else return nodel->get_sum(l,r)+noder->get_sum(l,r);
        }
    } root;
public:
    SGtree(vector<T> const& a):root(a.begin(),a.end(),0){}
    SGtree(size_t n,istream& in):root(0,n){
        for (size_t i=0;i<n;i++){
            T x;
            in>>x;
            root.add_interval(i,i+1,x);
        }
    }
    void add_interval(size_t l,size_t r,T const& v){root.add_interval(l,r,v);}
    T get_sum(size_t l,size_t r){return root.get_sum(l,r);}
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    SGtree<li> tree(n,cin);
    while (m--){
        char c;size_t x,y;
        cin>>c>>x>>y;
        if (c=='1'){
            li k;
            cin>>k;
            tree.add_interval(--x,y,k);
        }else cout<<tree.get_sum(--x,y)<<'\n';
    }
    return 0;
}