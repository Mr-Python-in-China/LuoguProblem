#include<bits/stdc++.h>
using namespace std;
const int N=1003;
bool e[N][N],b[N],f[N],o;
int r,n,dfn[N],low[N],st[N],tp,id,ct,cl[N];
basic_string<int>dcc[N];
void tar(int x){//Tarjan求点双
	dfn[x]=low[x]=++id,st[++tp]=x;
	for(int i=1;i<=n;++i)if(e[x][i]){
		if(!dfn[i]){
			tar(i),low[x]=min(low[x],low[i]);
			if(low[i]>=dfn[x])for(dcc[++ct].clear(),dcc[ct]+=x;dcc[ct]+=st[tp],st[tp--]!=i;);
		}else low[x]=min(low[x],dfn[i]);
	}
}
void dfs(int x){//二分图染色
	for(int i=1;i<=n;++i)if(e[x][i]&&b[i]){
		if(cl[i]==2)cl[i]=!cl[x],dfs(i);
		else if(cl[i]==cl[x])o=1;
	}
}
int main(){
	int m,i,j;
	while(scanf("%d%d",&n,&m),n){
		memset(dfn+1,0,n*4),memset(f+1,1,n),id=ct=tp=0;
		for(i=1;i<=n;++i)memset(e[i]+1,1,n),e[i][i]=0;
		while(m--)scanf("%d%d",&i,&j),e[i][j]=e[j][i]=0;//建补图
		for(r=1;r<=n;++r)if(!dfn[r])tar(r);
		for(i=1;i<=ct;++i){
			for(int j:dcc[i])b[j]=1,cl[j]=2;
			o=cl[j=dcc[i][0]]=0,dfs(j);
			for(int j:dcc[i])if(b[j]=0,o)f[j]=0;
		}
		for(i=1,j=0;i<=n;++i)j+=f[i];
		printf("%d\n",j);
	}
	return 0;
}
