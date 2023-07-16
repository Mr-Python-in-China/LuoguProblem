#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
template<typename T,typename compare=less<T>> class Unique{
protected:
    T val;
    size_t id;
    static size_t count;
    Unique(T const& x,size_t const& _id):val(x),id(_id){};
public:
    Unique(void):val(),id(count++){}
    Unique(T const& x):val(x),id(count++){}
    struct uqCmp{bool operator()(Unique const& x,Unique const& y) const{
        return x.val==y.val?x.id<y.id:x.val<y.val;
    }};
    friend istream& operator>>(istream& in,Unique& x){return in>>x.val;}
    friend ostream& operator<<(ostream& out,Unique const& x){return out<<x.val;}
    operator T(void) const{return val;}
    static Unique smallist(T const& x){return Unique(x,0);}
    static Unique biggist(T const& x){return Unique(x,-1);}
};
template<typename T,typename compare> size_t Unique<T, compare>::count = 0;
template<typename T> using pbds_tree=pbds::tree<Unique<T>,pbds::null_type,typename Unique<T>::uqCmp,pbds::rb_tree_tag,pbds::tree_order_statistics_node_update>;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,ans=0;int minmoney;
    cin>>n>>minmoney;
    while (n--){
        char opt;
        cin>>opt;
        pbds_tree<int> tree;
        switch (opt){
        case 'I':{
            int k;
            cin>>k;
            if (k>=minmoney) tree.insert(k);
            break;
        }case 'A':{
            int k;
            cin>>k;
            minmoney-=k;
            break;
        }case 'S':{
            int k;
            cin>>k;
            minmoney+=k;
            pbds_tree<int>::iterator end=tree.lower_bound(Unique<int>::smallist(minmoney));
        #ifdef debug
            cout<<"\033[31m"<<*end<<"\033[0m\n";
        #endif
            for (pbds_tree<int>::iterator it=tree.begin();it!=end;) 
                tree.erase(it++),ans++;
            break;
        }case 'F':{
            size_t k;
            cin>>k;
            cout<<(k>tree.size()?int(tree.order_of_key(--k)):-1)<<'\n';
            break;
        }
        }
        #ifdef debug
            cout<<"\033[32m"<<tree.size()<<"\033[0m\n";
        #endif
    }
    cout<<ans;
}