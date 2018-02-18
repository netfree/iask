#include <bits/stdc++.h>

using namespace std;

ifstream fin ("sortaret.in");
ofstream fout("sortaret.out");

const int N_MAX = 50000 + 5;
vector<int> vec[N_MAX];
int n, m, viz[N_MAX], ans, st[N_MAX];

void sortaret(int nod){
  viz[nod] = true;
  for(auto v : vec[nod])
    if(!viz[v])
      sortaret(v);
  st[++ans] = nod;
}

int main(){
  fin >> n >> m;
  while(m--){
    int a, b;
    fin >> a >> b;
    vec[a].push_back(b);
  }

  for(int i = 1; i<=n; ++i)
    if(!viz[i])
      sortaret(i);

  for(int i = n; i>=1; --i)
    fout << st[i] << " ";

  return 0;
}

//Andrei Muntean, 2018
