#include <bits/stdc++.h>

using namespace std;

ifstream fin ("rmq.in");
ofstream fout("rmq.out");

const int maxk = 20, maxn = 100000 + 5;

int n, m;
int dp[maxk][maxn];



int main(){
  fin >> n >> m;
  for(int i = 1; i<=n; ++i)
    fin >> dp[0][i];

  init();

  while(m--){
    fin >> x >> y;
    fout << rmq(x, y);
  }
	return 0;
}

//Andrei Muntean, 2018
