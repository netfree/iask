#include <bits/stdc++.h>

using namespace std;

ifstream fin ("stramosi.in");
ofstream fout("stramosi.out");

const int N_MAX = 250000 + 5;

int n, m, x, y, lui, x;
int dp[20][N_MAX];
int ans;

int main(){
  fin >> n >> m;
  for(int i = 1; i<=n; ++i)
    fin >> dp[0][i];

    for(int i = 1; i<=log2(n); ++i)
      for(int j = 1; j<=n; ++i)
        dp[i][j] = dp[i-1][ dp[i-1][j] ];

    while(m--){
      fin >> q >> p;
      ans = 0;
      for(bit = 1; bit < ; bit = (bit << 1))
    }

  return 0;
}

//Andrei Muntean, 2018
