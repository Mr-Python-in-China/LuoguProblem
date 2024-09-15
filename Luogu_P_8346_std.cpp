#include<bits/stdc++.h>
#define N 2000005
#define ll long long
using namespace std;

int t,n,m,cnt;
vector<int> to[N];
int in[N];
bool del[N];

void solve(){
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v; v+=n; //右边的点重新编号
		to[u].push_back(v); in[v]++;
		to[v].push_back(u); in[u]++;
	}
	queue<int> q; cnt=0;
	for(int i=1;i<=2*n;i++)
		if(in[i]==1)q.push(i); //将入度为1的点入队
	while(!q.empty()){
		int now=q.front(),buf=0; q.pop();
		if(del[now]||in[now]!=1)continue; //如果已经没删掉了，或者入度不为1了，那就跳过。已经入队的点的状态也可能被改变，因为这里是左右两边一起迭代的。
		del[now]=true; cnt++; //删掉这个点，删掉的数量加1
		while(del[to[now][buf]])buf++; //找到仅存的那一条边
		del[to[now][buf]]=true; cnt++; //顺着仅存的边找到另一个点，删掉
		for(int i=0;i<to[to[now][buf]].size();i++) //删边，没有真的删，只是减少目标节点的入度，这也是为什么要用while找仅存的边。
			if(!del[to[to[now][buf]][i]]&&(--in[to[to[now][buf]][i]])==1)
				q.push(to[to[now][buf]][i]); //如果还没被删，并且入度减少为1了就入队
	}
	if(cnt==n*2)cout<<"Renko"<<endl; //全删了
	else cout<<"Merry"<<endl;  //没全删
	for(int i=1;i<=n*2;i++)in[i]=del[i]=0,to[i].clear(); //多组数据，要初始化
}

int main(){
	cin>>t;
	while(t--)solve();
	return 0;
}

