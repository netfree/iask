#include <bits/stdc++.h>

using namespace std;

ifstream fin ("dictree.in");
ofstream fout("dictree.out");

const int N_MAX = 25000 + 5;

string cuvvv[N_MAX];
int n, j, ans;

int main(){

  fin >> n;
  for(int i = 1; i<=n; ++i)
    fin >> cuvvv[i];

  sort(cuvvv + 1, cuvvv + n + 1);

  ans += cuvvv[1].size();

  for(int i = 2; i<=n; ++i){
    for( j = 0; j < min( cuvvv[i].size() , cuvvv[i-1].size() ) and cuvvv[i][j]==cuvvv[i-1][j]; ++j);
        ans += cuvvv[i].size() - j;
  }

  fout << ans + 1;

	return 0;
}

//Andrei Muntean, 2018
