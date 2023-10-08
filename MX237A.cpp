#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
struct SGtree{
    struct node{
        uli val;uli sum;
        node* nodel,*noder;
        size_t itvl,itvr;
        bool in_interval(size_t l,size_t r){return l<=itvl&&itvr<=r;}
        bool no_matter(size_t l,size_t r){return r<=itvl||itvr<=l;}
        node(size_t ql,size_t qr):itvl(ql),itvr(qr),val(-1),sum(){
            if (itvr-itvl==1);
            else{
                size_t mid=((itvr-itvl)>>1)+itvl;
                nodel=new node(itvl,mid),noder=new node(mid,itvr);
            }
        }
        void pushdown(void){
            if (val==-1) return;
            nodel->val=val,noder->val=val;
            nodel->sum=(nodel->itvr-nodel->itvl)*nodel->val,noder->sum=(noder->itvr-noder->itvl)*noder->val;
            val=-1;
        }
        void edit_inv(size_t l,size_t r,uli x){
            if (itvr-itvl!=1) pushdown();
            if (no_matter(l,r)) return;
            if (in_interval(l,r)) val=x,sum=(itvr-itvl)*x;
            else{
                nodel->edit_inv(l,r,x),noder->edit_inv(l,r,x);
                sum=nodel->sum+noder->sum;
            }
        }
    }root;
    SGtree(size_t n):root(0,n){}
    uli sum(void){return root.sum;}
    void edit_inv(size_t l,size_t r,uli x){return root.edit_inv(l,r,x);}
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    vector<pair<uli,uli>> a(n);
    for (pair<uli,uli>& i:a) cin>>i.first>>i.second,i.first>>=1,i.second>>=1;
    sort(a.begin(),a.end(),[](pair<uli,uli> const& a,pair<uli,uli> const& b){return a.first<b.first;});
    SGtree tree(1e7+1);
    for (pair<uli,uli>& i:a) tree.edit_inv(0,i.second,i.first);
    cout<<(tree.sum()<<2);
    return 0;
}