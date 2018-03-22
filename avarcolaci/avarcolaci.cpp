#include <bits/stdc++.h>

using namespace std;

ifstream fin ("avarcolaci.in");
ofstream fout("avarcolaci.out");

const int TEST_MAX = 15 + 5;

int memo[TEST_MAX];
int nt;

int main(){
  fin >> nt;
  for(int t = 1; t <= nt; ++t){
    int n, ind, survives = 0;
    fin >> n;
    for(int i = 1; i<= 2*n; ++i){
      int x; fin >> x;
      if(i == 1)
        ind = x;
      if(x == ind)
        survives ++;
      else survives --;
      if(survives == 0){
        survives = 1;
        ind = x;
      }
    }
    memo[t] = ind;
  }
  fin.close();
  ifstream fin ("avarcolaci.in");
  fin >> nt;
  for(int t = 1; t <= nt; ++t){
    int count = 0, n;
    fin >> n;
    for(int i = 1; i<= 2*n; ++i){
        int x; fin >> x;
        if(x == memo[t])
          count ++;
    }
    if(count > n)
      fout << memo[t] << "\n";
    else fout << "Mozart\n";
  }
  fin.close();
  fout.close();
    return 0;
}

//Andrei Muntean, 2018
