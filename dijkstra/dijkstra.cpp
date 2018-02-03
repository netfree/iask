#define pii pair<int, int>
#define x first
#define y second
#include <bits/stdc++.h>

using namespace std;

ifstream fin ("dijkstra.in");
ofstream fout("dijkstra.out");

const int inf = 0x3f3f3f3f;
const int N_MAX = 50000 + 5;

vector<pii> vec[N_MAX];
int viz[N_MAX];
int dist[N_MAX];
priority_queue<pii, vector<pii>, greater<pii> > q;

int n, m, a, b, c;

void dijkstra(){
  q.push({0,1});
  for(int i = 2; i<=n; ++i)
    dist[i] = inf;

  while(!q.empty()){
    int nod = q.top().y;
    int cost = q.top().x;

    q.pop();

    if(cost != dist[nod])
      continue;

    for(auto v : vec[nod]){
      int new_nod = v.first;
      int muchie_cost = v.second;
      if(dist[new_nod] > dist[nod] + muchie_cost){
        dist[new_nod] = dist[nod] + muchie_cost;
        q.push({dist[new_nod], new_nod});
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

  dijkstra();

  for(int i = 2; i<=n; ++i)
    if(dist[i] != inf)
      fout << dist[i] << " ";
    else fout << "0 ";

	return 0;
}

//Andrei Muntean, 2018
