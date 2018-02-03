#include <bits/stdc++.h>

using namespace std;

ifstream fin ("sortaret.in");
ofstream fout("sortaret.out");

const int N_MAX = 50000 + 5;

int n, m, a, b;
bitset<N_MAX> viz;
vector<int> vec[N_MAX];
vector<int> ans;

void sortaret(int nod){
  if(viz[nod]) return;
  viz[nod] = true;
  for(auto v : vec[nod])
    sortaret(v);
  ans.push_back(nod);
}

int main(){
  fin >> n >> m;
  while(m--){
    fin >> a >> b;
    vec[a].push_back(b);
  }

  for(int i = 1; i<=n; ++i)
    sortaret(i);

  for(int i = ans.size()-1; i>=0; --i)
    fout << ans[i] << " ";
	return 0;
}

//Andrei Muntean, 2018
