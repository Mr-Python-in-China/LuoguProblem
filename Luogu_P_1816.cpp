#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr);
	ui n,m;
	cin>>n>>m;
	vector<vector<ui>> stmax(ceil(log2(n)),vector<ui>(n)),stmin(ceil(log2(n)),vector<ui>(n));
	for (ui i=0;i<n;i++) cin>>stmax[0][i],stmin[0][i]=stmax[0][i];
	for (ui i=1;i<stmax.size();i++){
		ui len=1<<i;
		for (ui j=0;j+len<=n;j++)
			stmax[i][j]=max(stmax[i-1][j],stmax[i-1][j+(len>>1)]);
	}
	for (ui i=1;i<stmin.size();i++){
		ui len=1<<i;
		for (ui j=0;j+len<=n;j++)
			stmin[i][j]=min(stmin[i-1][j],stmin[i-1][j+(len>>1)]);
	}
	while (m--){
		ui l,r;
		cin>>l>>r;
		l--,r--;
		ui k=log2(r-l+1);
		cout<<min(stmin[k][l],stmin[k][r-(1<<k)+1])<<' ';
	}
	return 0;
}