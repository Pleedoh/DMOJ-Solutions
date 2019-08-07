#include <bits/stdc++.h>
#include <queue>
#define s(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
using namespace std;
int graph[1001][1001];
int ans[1001][1001];
int main(){
	memset(ans, -1, sizeof(ans));
	int N,M,T,Q,x,y;
	s(N);
	s(M);
	s(T);
	while(M--){
		s(x);
		s(y);
		graph[x][y] = T;
	}
	for(int s = 1; s<= N;s++){//starting node
		ans[s][s] = 0;
		queue<int> todo;
		todo.push(s);
		int i;
		while(!todo.empty()){
			i = todo.front();//friend
			todo.pop();
			for(int j = 1; j <= N; j++){//friends of friends
				if(graph[i][j] > 0 && ans[s][j] == -1){
					ans[s][j] = ans[s][i] + T;
					todo.push(j);
				}
			}
		}
	}
	s(Q);
	while(Q--){
		s(x);
		s(y);
		if(ans[x][y] == -1) cout<<"Not enough hallways!\n";
		else cout<<ans[x][y]<<"\n";
	}
	return 0;
}