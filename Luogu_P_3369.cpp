#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
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
    size_t n;
    cin>>n;
    pbds_tree<int> tree;
    while (n--){
        char opt;
        cin>>opt;
        switch (opt){
        case '1':{
            int x;
            cin>>x;
            #ifdef debug
            cout<<"\033[31m1\033[0m";
            #endif
            tree.insert(x);
            break;
        }case '2':{
            int x;
            cin>>x;
            #ifdef debug
            cout<<"\033[31m2\033[0m";
            #endif
            pbds_tree<int>::iterator it=tree.lower_bound(Unique<int>::smallist(x));
            if (*it==x) tree.erase(it);
            break;
        }case '3':{
            int x;
            cin>>x;
            #ifdef debug
            cout<<"\033[31m3\033[0m";
            #endif
            cout<<tree.order_of_key(Unique<int>::smallist(x))-1<<'\n';
            break;
        }case '4':{
            size_t x;
            cin>>x;
            #ifdef debug
            cout<<"\033[31m4\033[0m";
            #endif
            pbds_tree<int>::iterator it=tree.find_by_order(x-1);
            cout<<*it<<'\n';
            break;
        }case '5':{
            int x;
            cin>>x;
            #ifdef debug
            cout<<"\033[31m5\033[0m";
            #endif
            pbds_tree<int>::iterator it=tree.lower_bound(Unique<int>::smallist(x));
            cout<<*prev(it)<<'\n';
            break;
        }case '6':{
            int x;
            cin>>x;
            #ifdef debug
            cout<<"\033[31m6\033[0m";
            #endif
            pbds_tree<int>::iterator it=tree.upper_bound(Unique<int>::biggist(x));
            cout<<*it<<'\n';
            break;
        }
        }
    }
    return 0;
}