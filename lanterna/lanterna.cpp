#include <bits/stdc++.h>

using namespace std;

ifstream fin ("lanterna.in");
ofstream fout("lanterna.out");

const int N_MAX = 50 + 5, K_MAX = 1000 + 5;
const int inf = 0x3f3f3f3f;

struct eee{
  int nod, t, w;
};
int cost[N_MAX];
bool ally[N_MAX];
vector<eee> vec[N_MAX];
int n, k, m;

struct eeee{
  int c, w, nod;
  bool operator <(eeee a) const {
    if(c < a.c) return false;
    if(w < a.w) return false; // fara nici un sens
    return true;
  };
};

priority_queue<eeee> q;

int get_cost(int lanterna){
  for(int i = 1; i<=n; ++i)
    cost[i] = inf;
  cost[1] = 0;
  q.push({0, lanterna, 1});
  while(!q.empty()){
    int c = q.top().c;
    int w = q.top().w;
    int nod = q.top().nod;

    q.pop();

    if(c != cost[nod])
      continue;

    if(ally[nod])
      w = lanterna;

    for(auto v : vec[nod])
      if(v.w <= w)
        if(cost[nod] + v.t < cost[v.nod]){
          cost[v.nod] = cost[nod] + v.t;
          q.push({cost[v.nod], w - v.w, v.nod});
        }
  }
  return cost[n];
}

int main(){
  fin >> n >> k;
  for(int i = 1; i<=n; ++i)
    fin >> ally[i];
  fin >> m;
  while(m--){
    int a, b, t, w;
    fin >> a >> b >> t >> w;
    vec[a].push_back({b,t,w});
    vec[b].push_back({a,t,w});
  }

  int min = inf, poz_min = 0;
  for(int i = 1; i <= k; ++i){
    int cst = get_cost(i);
    if(cst < min){
      min = cst;
      poz_min = i;
    }
  }

  fout << min << " " << poz_min;

	return 0;
}

//Andrei Muntean, 2018
