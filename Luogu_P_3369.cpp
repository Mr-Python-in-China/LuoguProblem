#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
template<typename T,typename alloc=allocator<T>> class Splay_base{
    struct node;
    using node_ptr=node*;
    struct node{
        node_ptr f,s[2];
        node(node_ptr fa):f(fa),s({nullptr,nullptr}){}
        bool son_type(void){return f->r==this;}
        node_ptr minimum(void){
            node_ptr res=this;
            while (res->s[0]) res=res->s[0];
            return res;
        }
        node_ptr maximum(void){
            node_ptr res=this;
            while (res->s[1]) res=res->s[1];
            return res;
        }
    } header;    // trick: header->f==root(), header->s[0]==root()->minimum(), header->s[1]==root()->maximum()
    class iterator{
        using iterator_category=bidirectional_iterator_tag;
        using value_type=T;
        using difference_type=ptrdiff_t;
        using pointer=T*;
        using reference=T&;

    };
    node_ptr& root(void){return header->f;}
    void rotate(node_ptr x){
        bool t=x->son_type();
        node_ptr fa=x->f;
        x->f=fa->f;if (fa->f) fa->f->s[fa->son_type()]=x;    // 重新与 fa 的父节点连接
        fa->s[t]=x->s[t];if (x->s[t]) x->s[t]->f=fa;    // 重新连接 x 的子结点
        fa->f=x,x->s[!t]=fa;    // 将 fa 与 x 交换父子关系
    }
    void splay(node_ptr x){
        for (node_ptr fa=x->f;x!=root();rotate(x),fa=x->f)
            if (fa->f) rotate(x->son_type()==fa->son_type()?fa:x);
        header->f=x;
    }
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    
    return 0;
}