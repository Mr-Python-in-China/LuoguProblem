#include<bits/stdc++.h>
namespace mp{
    template<typename T,typename alloc=std::allocator<T>> class SplayTree{
        struct Node{
            T val;
            size_t sz;
            Node *left,*right,*fa;
            Node(T _val):val(_val),sz(1),left(nullptr),right(nullptr),fa(nullptr){}
            Node(T _val,Node *_fa):Node(_val){fa=_fa;}
        }* root;
        using key_reference=T const&;
        void update(Node* p){ //更新大小
            p->sz=1;
            if (p->left) p->sz+=p->left->sz;
            if (p->right) p->sz+=p->right->sz;
        }
        void rotate(Node* x){
            Node* y=x->fa,z=y->fa; //y是x的父亲，z是y的爷爷
            //先让z的孩子y变为x
            if (!z) root=x; //x没有爷爷（y是根）
            else if (z->left==y) z->left=x; //y是z的左孩子
            else z->right=x; //y是z的右孩子

            if (y->left==x){ //x是y的左孩子 右旋
                /*
                        +-+
                        |y|
                        +-+
                       /   \
                    +-+     +-+
                    |x|     |c|
                    +-+     +-+
                   /   \
                +-+     +-+
                |a|     |b|
                +-+     +-+
                ------to-------
                    +-+
                    |x|
                    +-+
                   /   \
                +-+     +-+
                |a|     |y|
                +-+     +-+
                       /   \
                    +-+     +-+
                    |b|     |c|
                    +-+     +-+
                */
                y->left=x->right; //让b挂到y的左边
                if (x->left) x->left->fa=y; //更改b的父亲为y
                x->right=y; //让y挂到x的右边
            }else{ //x是y的右孩子 左旋
                /*
                    +-+
                    |y|
                    +-+
                   /   \
                +-+     +-+
                |a|     |x|
                +-+     +-+
                       /   \
                    +-+     +-+
                    |b|     |c|
                    +-+     +-+
                ------to-------
                        +-+
                        |x|
                        +-+
                       /   \
                    +-+     +-+
                    |y|     |c|
                    +-+     +-+
                   /   \
                +-+     +-+
                |a|     |b|
                +-+     +-+
                */
            y->right=x->left;
            if (x->left) x->left->fa=y;
            x->left=y;
            }
            update(y),update(x); //先更新更底层的，再更新上面
            x->fa=z,y->fa=x;
        }
        void splay(Node* x){
            while (x->fa){ //重复执行知道p为树根（无父亲）
                Node* y=x->fa,z=y->fa;
                if (z){
                    if ((z->left==y)==(y->left==x)) rotate(y); //同侧局面
                    else rotate(x); //异侧局面
                }
                rotate(x); //无论怎样最后都要旋一次x
            }
        }
        Node* find(T val){ //同二叉查找树
            Node* x=root;
            while (x&&x->val!=val) x=(val<x->val?x->left:x->right);
            if (x) splay(x); //顺手把x转上去
            return x;
        }
    public:
        class iterator{
            Node* p;
        public:
            iterator(void):p(nullptr){}
            iterator(T* _p):p(_p){}
            iterator operator++(iterator){
                Node* lst=nullptr;
                while (p&&p->right&&p->right!=lst) lst=p,p=p->fa;
                if (p) p=p->right;
                return *this;
            }
            iterator operator--(iterator){
                
                Node* lst=nullptr;
                while (p&&p->left&&p->left!=lst) lst=p,p=p->fa;
                if (p) p=p->left;
                return *this;
            }
            iterator operator++(void){
                iterator res=*this;
                ++*this;
                return res;
            }
            iterator operator--(void){
                iterator res=*this;
                --*this;
                return res;
            }
            T* operator->(void){return p;}
            T& operator*(void){return &p;}
            friend bool operator==(iterator const& a,iterator const& b){return a.p==b.p;}
            friend bool operator!=(iterator const& a,iterator const& b){return a.p!=b.p;}
        }
        SplayTree(void):root(nullptr){}
        bool insert(T val){
            if (!root) root=alloc::allocate(1),root(val); //如果空树直接挂到根节点
            else{
                Node* x=root,y=nullptr; //y为x的父亲
                while (x){
                    y=x;
                    if (val==x->val) return false;
                    else x=(val<x->val?x->left:x->right); //找一个精准落点~
                }
                Node p=alloc::allocate(1),root(val,y);
                (val<y->fal?y->left:y->right)=p; //挂左边还是右边？
                splay(p); //顺手转上去
            }
            return true;
        }
        bool find_able(T val){return find(val);} //是否有这个数
        bool remove(int val){
            Node* x=find(val); //查找val，此时find函数顺手把x转了上去（即x为根）
            if (!x) return false;
            if (!x->left&&!x->right) root=nullptr;
            else if (!x->left) root=x->right,root->fa=nullptr; //若没有左子树则直接将右节点挂到根上
            else if (!x->right) root=x->left,root->fa=nullptr; //若没有右子树则直接将左节点挂到根上
            else{ //一个健全的节点
                Node *lm=x->left; //左子树最大的节点
                while (lm->right) lm=lm->right; //一直往右走保证最大
                splay(lm); //转上去（为什么可以直接挂载右节点？）
                lm->right=x->right;
                x->right->parent=lm;
                root=lm,lm->fa=nullptr;
                update(lm);
            }
            alloc::deallocate(root,1);
            return true;
        }
        inline size_t sz(void){return root?root->sz:0;}
    };
}