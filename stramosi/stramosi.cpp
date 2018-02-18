#include <bits/stdc++.h>

using namespace std;

ifstream fin ("stramosi.in");
ofstream fout("stramosi.out");

const int N_MAX = 250000 + 5, K_MAX = 20;

int n, m, dp[K_MAX][N_MAX], p, q;

int stramosi(int q, int p){
  for(int bit = 1; bit < 31; ++bit)
    if(p&(1<<bit))
      q = dp[bit][q];
  return q;
}

int main(){
  fin >> n >> m;
  for(int i = 1; i<=n; ++i)
    fin >> dp[0][i];

  for(int i = 1; (1<<i) <= n; ++i)
    for(int j = 1; j<=n; ++j)
      dp[i][j] = dp[i-1][dp[i-1][j]];

  while(m--){
    fin >> q >> p;
    fout << stramosi(q,p) << "\n";
  }
	return 0;
}

//Andrei Muntean, 2018
