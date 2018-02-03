#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 2000000 + 5;

ifstream fin ("strmatch.in");
ofstream fout("strmatch.out");

char T[N_MAX], P[N_MAX]; int key[N_MAX];
vector<int> ans;

void build_key(){
  int k = 0, m = strlen(P+1);
  for(int i = 2; i<=m; ++i){
    while(P[i] != P[k+1] and k > 0)
      k = key[k];
    if(P[i] ==P[k+1])
      k++;
    key[i] = k;
  }
}

void kmp(){
  build_key();
  int k = 0, n = strlen(T+1), m = strlen(P+1);
  for(int i = 1; i<=n; ++i){
    while(T[i] != P[k+1] and k > 0)
      k = key[k];
    if(T[i] == P[k+1])
      k++;
    if(k == m){
      ans.push_back(i-m);
      k = key[k];
    }
  }
}

int main()
{
    fin >> (P+1);
    fin >> (T+1);
    kmp();
    fout << ans.size() << "\n";
    for(int i = 0; i < min(1000, (int)ans.size()); ++i)
        fout << ans[i] << " ";
    return 0;
}

//Andrei Muntean, 2018
