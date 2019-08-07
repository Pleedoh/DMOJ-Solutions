#include <bits/stdc++.h>
#define s(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
using namespace std;
struct tile {
	bool vis = false;
	bool isTele = false;
};
tile skool[1000][1000];
int dist[1000][1000];
int R, C;
bool valid(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C)
		return false;
	if (skool[r][c].vis)
		return false;
	return true;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
	int sr, sc, fr, fc,T,tr,tc;
	string line;
	cin >> R >> C;
	cin >> sr >> sc;
	cin >> fr >> fc;
	for (int i = 0; i < R; i++) {
		cin >> line;
		for (int j = 0; j < C; j++) {
			if (line[j] == 'X')
				skool[i][j].vis = true;
		}
	}
	cin>> T;
	for (int t = 0; t < T; t++) {
		cin>>tr>>tc;
		skool[tr][tc].isTele = true;
	}
	queue<pair<int,int> > todo;
	pair<int,int> s = make_pair(sr,sc);
	skool[s.first][s.second].vis = true;
	todo.push(s);
	while (!todo.empty()) {
		s = todo.front();
		todo.pop();
		if (valid(s.first + 1, s.second)) {
			todo.push(make_pair(s.first + 1, s.second));
			skool[s.first + 1][s.second].vis = true;
			dist[s.first + 1][s.second] = dist[s.first][s.second] + 1;
		}
		if (valid(s.first - 1, s.second)) {
			todo.push(make_pair(s.first - 1, s.second));
			skool[s.first - 1][s.second].vis = true;
			dist[s.first - 1][s.second] = dist[s.first][s.second] + 1;
		}
		if (valid(s.first, s.second + 1)) {
			todo.push(make_pair(s.first, s.second + 1));
			skool[s.first][s.second + 1].vis = true;
			dist[s.first][s.second + 1] = dist[s.first][s.second] + 1;
		}
		if (valid(s.first, s.second - 1)) {
			todo.push(make_pair(s.first, s.second - 1));
			skool[s.first][s.second - 1].vis = true;
			dist[s.first][s.second - 1] = dist[s.first][s.second] + 1;
		}
	} //end of bfs
	int std = dist[fr][fc]; //shortest teleporter distance
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (skool[i][j].isTele && skool[i][j].vis) {
				if (dist[i][j] < std)
					std = dist[i][j];
			}
		}
	}
	cout<<dist[fr][fc] - std;
	return 0;
}