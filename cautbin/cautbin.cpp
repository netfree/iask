#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cautbin.in");
ofstream fout("cautbin.out");

const int N_MAX = 100000 + 5;

int a[N_MAX], n, m;

int lower_bound(int x){
  int lo = 0, hi = n + 1;
  while(lo < hi){
    int mid = (lo + hi) / 2;
    if(x <= a[mid])
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}

int upper_bound(int x){
  int lo = 0, hi = n + 1;
  while(lo < hi){
    int mid = (lo + hi) / 2;
    if(x < a[mid])
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}

bool binary_search(int x){
  return (a[lower_bound(x)] == x);
}

int main(){
  fin >> n;
  for(int i = 1; i<=n; ++i)
      fin >> a[i];
  fin >> m;
  while(m--){
    int type, x;
    fin >> type >> x;
    if(type == 0)
      if(binary_search(x))
        fout << upper_bound(x) - 1 << "\n";
      else
        fout << "-1\n";
    else if(type == 1)
      fout << upper_bound(x) - 1 << "\n";
    else
      fout << lower_bound(x) << "\n";
  }
	return 0;
}

//Andrei Muntean, 2018
