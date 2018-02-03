#define pii pair<int, int>
#define x first
#define y second
#include <bits/stdc++.h>

using namespace std;

ifstream fin ("bellmanford.in");
ofstream fout("bellmanford.out");

const int inf = 0x3f3f3f3f;
const int N_MAX = 50000 + 5;

vector<pii> vec[N_MAX];
int viz[N_MAX];
int dist[N_MAX];
queue<int> q;

int n, m, a, b, c;

void bellmanford(){
  q.push(1);
  for(int i = 2; i<=n; ++i)
    dist[i] = inf;

  while(!q.empty()){
    int nod = q.front();

    if(viz[nod] > n + 1){
      fout << "Ciclu negativ!";
      exit(0);
    }

    viz[nod] ++;
    q.pop();
    for(auto v : vec[nod]){
      int new_nod = v.first;
      int muchie_cost = v.second;
      if(dist[new_nod] > dist[nod] + muchie_cost){
        dist[new_nod] = dist[nod] + muchie_cost;
        q.push(new_nod);
      }
    }
  }

}

int main(){

  fin >> n >> m;
  while(m--){
    fin >> a >> b >> c;
    vec[a].push_back({b,c});
  }

  bellmanford();

  for(int i = 2; i<=n; ++i)
    fout << dist[i] << " ";

	return 0;
}

//Andrei Muntean, 2018
