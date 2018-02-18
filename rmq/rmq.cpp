#include <bits/stdc++.h>

using namespace std;

ifstream fin ("rmq.in");
ofstream fout("rmq.out");

const int N_MAX = 100000 + 5;

int dp[30][N_MAX], val[N_MAX];
int n, m;

void init_rmq(){
  for(int power = 1; (1<<power) <= n; ++power)
    for(int i = 1; i + (1<<power) - 1 <=n; ++i)
      if(val[dp[power-1][i]] < val[dp[power-1][i + (1<<(power-1))]])
        dp[power][i] = dp[power-1][i];
      else
        dp[power][i] = dp[power-1][i + (1<<(power-1))];
}

int query(int lo, int hi){
  int power = log2(hi-lo+1);
  return(min(val[dp[power][lo]], val[dp[power][hi - (1 << power) + 1]]));
}

int main(){
  fin >> n >> m;
  for(int i = 1; i<=n; ++i){
    dp[0][i] = i;
    fin >> val[i];
  }

  init_rmq();

  while(m--){
    int a, b;
    fin >> a >> b;
    fout << query(a, b) << "\n";
  }
	return 0;
}

//Andrei Muntean, 2018
