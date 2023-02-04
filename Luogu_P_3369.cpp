#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
const size_t NULLPOS=-1;
template<typename T> class splay{
	struct node{
		size_t child[2],fa,size,cnt;T val;
		node(T _val,size_t _fa=NULLPOS,size_t cnt=1,size_t l=NULLPOS,size_t r=NULLPOS){
			val=_val,child[0]=l,child[1]=r,fa=_fa,size=cnt;
		}
		inline static bool operator<(const node a,const node b){return a.val<b.val;}
	};
	vector<node> tree;
	size_t root=NULLPOS;
	inline void pushup(size_t pos){
		tree[pos].size=cnt;
	}
	void rotate(size_t pos,bool dc){
		T& fa=tree[pos].fa;
		tree[fa].child[!dc]=tree[pos].child[dc];
		tree[tree[pos].child[dc]].fa=fa;
		if (~tree[fa].fa) tree[tree[fa].fa].child[tree[tree[fa].fa].child[1]==fa]=pos;
		tree[pos].fa=tree[fa].fa;
		tree[pos].child[dc]=fa;
		tree[fa].fa=pos;
		pushup(fa);
	}
	void shift_to(size_t pos,size_t goal){
		while (tree[pos].fa!=goal){
			if (tree[tree[pos].fa].fa==goal) rotate(pos,tree[tree[pos].fa].child[0]==pos);
			else{
				T& fa=tree[pos].fa;
				bool c=tree[tree[fa].fa].child[0]==y;
				if (tree[fa].child[c]==pos) rotate(pos,!c);
				else rotate(fa,c);
				rotate(pos,c);
			}
		}
		pushup(x);
		if (!~goal) root=x;
	}
	T get_max(size_t x){
		while (~tree[x].son[1]) x=tree[x].son[1];
		return x;
	}
	bool remove_root(void){
		if (~root){
			if (~tree[root].son[0]){
				T m=get_max(tree[root].son[0]);
				shift_to(m,root);
				tree[m].son[1]=tree[root].son[1];
				pre[tree[root].son[1]]=m;
				root=m;
				pre[root]=NULLPOS;
				pushup(root);
			}else root=tree[root].son[1],pre[root]=NULLPOS;
			return true;
		}else return false;
	}
	bool remove_node(size_t x){
		shift_to(x,NULLPOS);
		remove_root();
	}
	void find(const T x,size_t& u,size_t& fa){
		u=root,fa=NULLPOS;
		while (~u&&tree[u].val!=x) 
			fa=u,u=tree[u].son[x>tree[u].val];
	}
public:
	void insert(const T x){
		if (~root){
			size_t u,fa;
			find(x,u,fa);
			if (~u) tree[u].cnt++;
			else{
				u=tree.size();
				tree.push_back(node(x,fa))
				tree[fa].son[x>tree[ff].val]=u;
			}
			shift_to(u,NULLPOS);
		}else{
			root=tree.size();
			tree.push_back(node(x));
		}
	}
	bool erase(const T x){
		size_t u,fa;
		find(x,u,fa);
		if (~u){
			if (!--tree[u].cnt) remove_root();
			return true;
		}else return false;
	}
};
#define ID 0
int main(void){
	ios::sync_with_stdio(false),cin.tie(nullptr);

}