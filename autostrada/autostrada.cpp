#include <bits/stdc++.h>

using namespace std;

ifstream fin ("autostrada.in");
ofstream fout("autostrada.out");

vector<pair<int,int> > roads;

int n, m, x, y;
bool drum[105][105], dmin[105][105];
set<pair<int,int> > ans;

int main(){

  fin >> n >> m;
  while(m--){
    fin >> x >> y;
    roads.push_back({x,y});
    drum[x][y] = true;
    drum[y][x] = true;
  }

  for(int i = 1; i<=n; ++i)
  drum[i][i] = true;

  for(auto road:roads){
    for(int i = 1; i<=n; ++i)
      for(int j = 1; j<=n; ++j)
        dmin[i][j] = drum[i][j];

    dmin[road.first][road.second] = false;

    for(int k = 1; k<=n; ++k)
      for(int i = 1; i<=n; ++i)
        for(int j = 1; j<=n; ++j)
          if(i != j and dmin[i][k] and dmin[k][j])
            dmin[i][j] = true;

     for(int i = 1; i<=n; ++i)
       for(int j = 1; j<=n; ++j)
          if(dmin[i][j] == false)
            ans.insert(road);
  }

  fout << ans.size() << "\n";
  for(auto s : ans)
    fout << min(s.first, s.second) << " " << max(s.first, s.second)<< "\n";

	return 0;
}

//Andrei Muntean, 2018
