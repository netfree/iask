#include <bits/stdc++.h>

using namespace std;

ifstream fin ("hamilton.in");
ofstream fout("hamilton.out");

const int N_MAX = 18 + 5;
const int inf = 0x3f3f3f3f;
int cost[N_MAX][N_MAX], dp[(1<<18) + 5][N_MAX], n, m, a, b, c, ans = inf;

int isbit(int a, int poz){
  return (a & (1<<poz));
}

int main(){
  fin >> n >> m;
  memset(cost, inf, sizeof(cost));
  while(m--){
    fin >> a >> b >> c;
    cost[a][b] = c;
  }
  memset(dp, inf, sizeof(dp));
  dp[1][0] = 0;
  for(int config = 1; config <= (1<<n) - 1; ++config)
    for(int i = 0; i < n; ++i)
      if(isbit(config, i))
        for(int j = 0; j < n; ++j)
          if(not isbit(config, j))
            dp[config + (1<<j)][j] = min(dp[config][i] + cost[i][j] , dp[config + (1<<j)][j]);

  for(int i = 1; i < n; ++i)
    ans = min(ans, dp[(1<<n)-1][i] + cost[i][0]);

  if(ans >= inf)
    fout << "Nu exista solutie";
  else
    fout << ans;

	return 0;
}

//Andrei Muntean, 2018
