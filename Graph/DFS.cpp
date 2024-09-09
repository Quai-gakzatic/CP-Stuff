#include<bits/stdc++.h>
using namespace std;
#define nm '\n'
const int mx=1e5+123;
vector<int>adj[mx];
int n,m;
char ch[25][25];
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
bool vis[25][25];
bool valid(int a,int b){
	return a>=0 && a<n && b>=0 && b<m && !vis[a][b] && ch[a][b]=='.';
}
long long dfs(int in,int jn){
	vis[in][jn]=1;
	long long c=0;
	for(int i=0;i<4;i++){
		int a=in+x[i];
		int b=jn+y[i];
		if(valid(a,b)){
			c=c+1+dfs(a,b);
		}
	}
	return c;
}
int main(){
	ios_base::sync_with_stdio(0);
	 cin.tie();
	 int t;
	 cin>>t;
	 for(int k=1;k<=t;k++){
	 	cout<<"Case "<<k<<":";
	 	memset(vis,0,sizeof(vis));
	 	cin>>m>>n;
	 	 int st,ed;
	 	 for(int i=0;i<n;i++){
	 	 	for(int j=0;j<m;j++){
	 	 		cin>>ch[i][j];
	 	 		if(ch[i][j]=='@'){
	 	 			st=i;
	 	 			 ed=j;
	 	 		}
	 	 	}
	 	 }
	 	 cout<<dfs(st,ed)+1<<nm;
	 }
return 0;

}