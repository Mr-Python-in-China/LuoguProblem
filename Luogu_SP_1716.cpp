#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using li=int;
struct interval{
    size_t l,r;
    interval(size_t _l,size_t _r):l(_l),r(_r){}
};
struct info{
    li sum=0;
    li msitv=0,mspre=0,msnxt=0;
    static info merge(info const& a,info const& b){
        info f;
        f.sum=a.sum+b.sum;
        f.msitv=max({a.msitv,b.msitv,a.msnxt+b.mspre});
        f.mspre=max(a.sum+b.mspre,a.mspre),
        f.msnxt=max(b.sum+a.msnxt,b.msnxt);
        return f;
    }
    static info none;
};
info info::none={0ll,numeric_limits<li>::min()>>1,numeric_limits<li>::min()>>1,numeric_limits<li>::min()>>1};
struct SGtree{
    struct node{
        interval itv;
        node* nodel,*noder;
        info f;
        bool in_interval(interval p){return p.l<=itv.l&&itv.r<=p.r;}
        bool no_matter(interval p){return p.r<=itv.l||itv.r<=p.l;}
        node(node&)=delete;
        node(interval p):itv(p),nodel(nullptr),noder(nullptr),f(){
            if (p.r-p.l>1){
                size_t mid=(p.r-p.l>>1)+p.l;
                nodel=new node({p.l,mid}),noder=new node({mid,p.r});
            }
        }
        void set(size_t p,li x){
            if (no_matter({p,p+1})) return;
            if (itv.r-itv.l>1){
                nodel->set(p,x),noder->set(p,x);
                f=f.merge(nodel->f,noder->f);
            }else f.msitv=f.mspre=f.msnxt=f.sum=x;
        }
        li get_sum(interval p){
            if (no_matter(p)) return 0;
            if (in_interval(p)) return f.sum;
            return nodel->get_sum(p)+noder->get_sum(p);
        }
        info get_inv_sm(interval p){
            if (no_matter(p)) return info::none;
            if (in_interval(p)) return f;
            return info::merge(nodel->get_inv_sm(p),noder->get_inv_sm(p));
        }
    }root;
    template<typename InputIterator,typename=_RequireInputIter<InputIterator>>
    SGtree(InputIterator it,size_t n):root({0,n}){
        root.set(0,*it);
        for (size_t i=1;i<n;++i) root.set(i,*++it);
    }
    li get_sum(interval p){return root.get_sum(p);}
    li get_val(size_t p){return get_sum({p,p+1});}
    void set(size_t p,li x){return root.set(p,x);}
    li get_inv_sm(interval v){return root.get_inv_sm(v).msitv;}
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,q;
    cin>>n;
    SGtree tree(istream_iterator<li>(cin),n);
    cin>>q;
    while (q--){
        char op;
        cin>>op;
        if (op=='0'){
            size_t x;li y;
            cin>>x>>y;
            tree.set(--x,y);
        }else{
            size_t l,r;cin>>l>>r;
            cout<<tree.get_inv_sm({--l,r})<<'\n';
        }
    }
    return 0;
}