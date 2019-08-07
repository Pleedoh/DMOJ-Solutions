#include <bits/stdc++.h>
#include <utility>
#include <algorithm>
#define ll long long
#define xc first
#define yc second
using namespace std;

pair<long long, long long> locs[3001];
ll dists[3001][3001];
ll ans[3001];
bool vis[3001];
int N;
void dijk(int s);
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	unsigned ll X, Q, x, y,t;
	cin>>N;
	for (int i = 0 ;i < N; i++) {
	    ans[i] = -1;
		dists[i][i] = 0;
		cin>>x>>y;
		locs[i] = make_pair(x, y);
		for (int j = 0; j < N; j++) {
			dists[i][j] = (locs[i].xc - locs[j].xc) * (locs[i].xc - locs[j].xc) + (locs[i].yc - locs[j].yc) * (locs[i].yc - locs[j].yc);
			dists[j][i] = dists[i][j];
		}
	}
	cin>>X>>Q;
	ans[X-1] = 0;
	dijk(X-1);
	sort(ans,ans+N);
	while (Q--) {
		cin>>t;
		cout<<upper_bound(ans,ans+N,t)-ans<<"\n";
	}
	return 0;
}
void dijk(int s) {
	vis[s] = true;
	for (int i = 0; i < N; i++) {
		if (!vis[i] && dists[s][i] != -1) {
			if (ans[s] + dists[s][i] < ans[i] || ans[i] == -1)
				ans[i] = ans[s] + dists[s][i];
		}
	}
	ll smallW=-1,node = -1;
	for(int i = 0; i < N;i++){
		if(!vis[i] && ans[i] != -1 && (ans[i] < smallW || smallW == -1)){
			smallW = ans[i];
			node = i;
		}
	}
	if(smallW != -1){
		dijk(node);
	}
}