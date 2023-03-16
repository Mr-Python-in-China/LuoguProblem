#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using uli=unsigned long long int;
class SGtree{
    size_t lv,rv;
    SGtree *left,*right;
    uli sum,lazy;
    void update(void){
        if (!lazy) return;
        sum+=lazy*(rv-lv);
        if (rv-lv>1) left->lazy+=lazy,right->lazy+=lazy;
        lazy=0;
    }
    public:
    SGtree(size_t l,size_t r):lv(l),rv(r),sum(0),lazy(0){
        if (r-l>1) left=new SGtree(l,(l+r)>>1),right=new SGtree((l+r)>>1,r);
        else left=right=nullptr;
    }
    SGtree(size_t l,size_t r,const vector<uli>& arr):lv(l),rv(r),lazy(0){
        if (r-l>1) 
            left=new SGtree(l,(l+r)>>1,arr),right=new SGtree((l+r)>>1,r,arr),
            sum=left->sum+right->sum;
        else left=right=nullptr,sum=arr[l];
    }
    ~SGtree(void){delete left,delete right;}
    uli query(size_t l,size_t r){
        update();
        if (l<=lv&&r>=rv) return sum;
        uli res=0;
        if (l<((lv+rv)>>1)) res+=left->query(l,r);
        if (((lv+rv)>>1)<r) res+=right->query(l,r);
        return res;
    }
    void add(size_t p,uli val){adds(p,p+1,val);}
    void adds(size_t l,size_t r,uli val){
        if (l<=lv&&r>=rv) lazy+=val;
        else{
            update();
            if (l<((lv+rv)>>1)) left->adds(l,r,val);
            if (((lv+rv)>>1)<r) right->adds(l,r,val);
            sum=left->sum+left->lazy*(left->rv-left->lv)
                +right->sum+right->lazy*(right->rv-right->lv);
        }
    }
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    vector<uli> a(n);
    for (vector<uli>::reference i:a) cin>>i;
    SGtree tr(0,n,a);
    while (m--){
        char c;
        size_t x,y;
        cin>>c>>x>>y;
        if (c=='1'){
            uli k;
            cin>>k;
            tr.adds(--x,y,k);
        }else cout<<tr.query(--x,y)<<'\n';
        ;
    }
    return 0;
}