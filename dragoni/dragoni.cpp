#include <bits/stdc++.h>

using namespace std;

ifstream fin ("dragoni.in");
ofstream fout("dragoni.out");

const int N_MAX = 800 + 5;
const int inf = 0x3f3f3f3f;

int dmax[N_MAX], cst[N_MAX];
bitset<N_MAX> viz;
struct eee {
  int nod, cost;
};
vector<eee> vec[N_MAX];

int p, n, m;

queue<int> qa;

void cerinta_a(){
  int dist_max = dmax[1];
  qa.push(1);
  int ans = -inf;
  while(!qa.empty()){
    int nod = qa.front();
    qa.pop();
    viz[nod] = true;
    ans = max(ans, dmax[nod]);
    for(auto v : vec[nod])
      if(!viz[v.nod] and v.cost <= dist_max)
        qa.push(v.nod);
  }
  fout << ans;
}

struct eeee{
  int cost, dragon_max, nod;
  bool operator <(eeee a) const {
    if(cost < a.cost) return false;
    if(dragon_max < a.dragon_max) return false;
    return true;
  };
};

int dp[N_MAX][N_MAX];

struct e{
  int nod, drago;
};

queue<e> q;

void cerinta_b(){
  for(int i = 1; i<=n; ++i)
    for(int j = 1; j<=n; ++j)
      dp[i][j] = inf;
  dp[1][1] = 0;
  q.push({1, 1});
  while(!q.empty()){
    int nod = q.front().nod;
    int drago = q.front().drago;
    //cout << nod << " " << drago << "\n";
    q.pop();

    if(nod == n)
      continue;

    for(auto v : vec[nod])
      if(v.cost <= dmax[drago]){
        int new_drago;
        if(dmax[drago] > dmax[v.nod])
          new_drago = drago;
        else new_drago = v.nod;
        if(dp[v.nod][new_drago] > dp[nod][drago] + v.cost){
          dp[v.nod][new_drago] = dp[nod][drago] + v.cost;
          q.push({v.nod, new_drago});
        }
      }
  }

  int minn = inf;
  for(int i = 1; i<=n; ++i)
    minn = min(minn, dp[n][i]);
  fout << minn;
}


int main(){

  fin >> p;
  fin >> n >> m;
  for(int i = 1; i<=n; ++i)
    fin >> dmax[i];
  while(m--){
    int a, b, d;
    fin >> a >> b >> d;
    vec[a].push_back({b, d});
    vec[b].push_back({a, d});
  }

  if(p == 1)
    cerinta_a();
  else
    cerinta_b();

	return 0;
}

//Andrei Muntean, 2018
