#define pii pair<int, int>
#define x first
#define y second
#include <bits/stdc++.h>

using namespace std;

ifstream fin ("dijkstra.in");
ofstream fout("dijkstra.out");

const int N_MAX = 50000 + 5;
const int inf = 0x3f3f3f3f;

vector<pii> vec[N_MAX];
int dist[N_MAX];
int n, m;

priority_queue<pii, vector<pii>, greater<pii> > q;

void dijkstra(){
  for(int i = 2; i<=n; ++i)
    dist[i] = inf;
  q.push({0, 1});
  while(q.size()){
    int cost = q.top().x;
    int nod = q.top().y;
    q.pop();

    if(dist[nod] != cost)
      continue;

    for(auto v : vec[nod])
      if(dist[nod] + v.y < dist[v.x]){
        dist[v.x] = dist[nod] + v.y;
        q.push({dist[v.x], v.x});
      }
  }
}

int main(){
  fin >> n >> m;
  while(m--){
    int a, b, c;
    fin >> a >> b >> c;
    vec[a].push_back({b,c});
  }
  dijkstra();
  for(int i = 2; i<=n; ++i)
    if(dist[i] >= inf)
      fout << "0 ";
    else
      fout << dist[i] << ' ';
	return 0;
}

//Andrei Muntean, 2018
