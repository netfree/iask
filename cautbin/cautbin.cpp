#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cautbin.in");
ofstream fout("cautbin.out");

const int N_MAX = 100000 + 5;

int type, val, n, a[N_MAX], m;

bool cmp (int a, int b){
  return (a>b);
}

int main(){
  fin >> n;
  for(int i = 1; i<=n; ++i)
    fin >> a[i];
  fin >> m;
  while(m--){
    fin >> type >> val;
    if(type == 0)
      if(binary_search(a, a+n+1, val,cmp))
        fout << upper_bound(a+1, a+n+1, val,cmp) - a << "\n";
      else fout << "-1\n";
    if(type == 1)
      fout << upper_bound(a+1, a+n+1, val,cmp) - a << "\n";
    if(type == 2)
      fout << lower_bound(a+1, a+n+1, val,cmp) - a << "\n";
  }
	return 0;
}

//Andrei Muntean, 2018
