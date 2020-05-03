/**
 * Jared Bentvelsen
 * https://dmoj.ca/problem/ccc20s2
 * May 2 2020
 */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
#define s(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define fi first
#define se second

using namespace std;

int N, M;
int g[1001][1001];
bool v[1000001];

vector<pair<int,int>> factor(int n){
    vector<pair<int,int>> f;

    for(int i = 1; i <= sqrt(n);i++){
        if(n % i == 0){
            f.push_back(make_pair(i,n/i));
        }
    }

    return f;
}

bool bfs(){
    queue<pair<int,int>> q;
    v[g[1][1]] = 1;
    q.push(make_pair(1,1));
    pair<int,int> s;

    while(!q.empty()){
        s = q.front();
        q.pop();

        for(auto p : factor(g[s.fi][s.se])){
            if(p.fi <= M && p.se <= N && !v[g[p.fi][p.se]] || (p.se == M && p.fi == N)){
                if(p.se == M && p.fi == N)
                    return 1;
                q.push(make_pair(p.fi,p.se));
                v[g[p.fi][p.se]] = 1;
                if(p.fi == M && p.se == N)
                    return 1;
            }
            if(p.se <= M && p.fi <= N && !v[g[p.se][p.fi]] || (p.se == M && p.fi == N)){
                if(p.se == M && p.fi == N)
                    return 1;
                q.push(make_pair(p.se,p.fi));
                v[g[p.se][p.fi]] = 1;

            }
        }
    }
    return 0;
}

int main(){

    s(M);
    s(N);

    for(int i = 1; i <= M;i++){
        for(int j = 1; j <= N;j++){
            s(g[i][j]);
        }
    }

    if(bfs())
        cout << "yes";
    else cout << "no";

    return 0;
}