#include <bits/stdc++.h>

using namespace std;

ifstream fin ("strmatch.in");
ofstream fout("strmatch.out");

const int N_MAX = 2000000 + 5;

char P[N_MAX], T[N_MAX];
int elm_matched, key[N_MAX];
vector<int> ans;

void build_key(){
  int k = 0, m = strlen(P+1);
  for(int i = 2; i<=m; ++i){
    while(k > 0 and P[k+1] != P[i])
      k = key[k];
    if(P[k+1] == P[i])
      k ++;
    key[i] = k;
  }
}

void kmp(){
  int k = 0, n = strlen(T+1), m = strlen(P+1);
  for(int i = 1; i<=n; ++i){
    while(k > 0 and P[k+1] != T[i])
      k = key[k];
    if(P[k+1] == T[i])
      k ++;
    if(k == m){
      elm_matched ++;
      if(elm_matched <= 1000)
        ans.push_back(i-m);
      k = key[k];
    }
  }
}

int main(){
  fin >> (P+1);
  fin >> (T+1);
  build_key();
  kmp();
  fout << elm_matched << "\n";
  for(auto i : ans)
    fout << i << " ";
	return 0;
}

//Andrei Muntean, 2018
