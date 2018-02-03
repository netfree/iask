#include <bits/stdc++.h>

using namespace std;

ifstream fin ("royfloyd.in");
ofstream fout("royfloyd.out");

int n;
int dmin[105][105];

int main(){

  fin >> n;
  for(int i = 1; i<=n; ++i)
    for(int j = 1; j<=n; ++j)
      fin >> dmin[i][j];

      
for(int k = 1; k<=n; ++k)
  for(int i = 1; i<=n; ++i)
    for(int j = 1; j<=n; ++j)

        if(i != j and dmin[i][k] and dmin[k][j] and (!dmin[i][j] or dmin[i][k] + dmin[k][j] < dmin[i][j]))
           dmin[i][j] = dmin[i][k] + dmin[k][j];

           for(int i = 1; i<=n; ++i){
                   for(int j = 1 ; j<=n; ++j)
                       fout << dmin[i][j]<<" ";
                   fout << "\n";
               }

	return 0;
}

//Andrei Muntean, 2018
