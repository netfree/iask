#define pii pair<int, int>
#define x first
#define y second
#include <bits/stdc++.h>

using namespace std;

ifstream fin ("bellmanford.in");
ofstream fout("bellmanford.out");

const int N_MAX = 50000 + 5;
const int inf = 0x3f3f3f3f;

vector<pii> vec[N_MAX];
int viz[N_MAX], dist[N_MAX];
int n, m;

queue<int> q;

void bellmanford(){
  for(int i = 2; i<=n; ++i)
    dist[i] = inf;
  q.push(1);
  while(!q.empty()){
    int nod = q.front();
    viz[nod] ++;
    q.pop();

    if(viz[nod] > n + 1){
      fout << "Ciclu negativ!";
      exit(0);
    }


    for(auto v : vec[nod])
      if(dist[nod] + v.y < dist[v.x]){
        dist[v.x] = v.y + dist[nod];
        q.push(v.x);
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
  bellmanford();
  for(int i = 2; i<=n; ++i)
    if(dist[i] >= inf)
      fout << "0 ";
    else
      fout << dist[i] << " ";
	return 0;
}

//Andrei Muntean, 2018
