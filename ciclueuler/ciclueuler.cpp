#define pii pair<int, int>
#define x first
#define y second
#include <bits/stdc++.h>

using namespace std;

ifstream fin ("ciclueuler.in");
ofstream fout("ciclueuler.out");

const int N_MAX = 100000 + 5;
const int M_MAX = 500000 + 5;

bitset<N_MAX> viz;
bitset<M_MAX> used;
vector<pii> vec[N_MAX];
stack<int> st;
int g[N_MAX];
vector<int> ans;
int n, m;

void dfs(int nod){
  viz[nod] = true;
  for(auto v : vec[nod])
    if(!viz[v.x])
      dfs(v.x);
}

int main(){
  fin >> n >> m;
  for(int i = 1, a, b; i<=m; ++i){
    fin >> a >> b;
    vec[a].push_back({b,i});
    vec[b].push_back({a,i});
    g[a]++; g[b]++;
  }
  dfs(1);
  for(int i = 1; i<=n; ++i)
    if(!viz[i] or g[i] % 2 != 0){
      fout << -1;
      return 0;
    }
  st.push(1);
  while(st.size()){
    int nod = st.top();
    if(g[nod] == 0){
      ans.push_back(nod);
      st.pop();
    } else {
      while(used[vec[nod].back().y])
        vec[nod].pop_back();
      int new_nod = vec[nod].back().x;
      g[nod] --; g[new_nod] --;
      used[vec[nod].back().y] = true;
      vec[nod].pop_back();
      st.push(new_nod);
    }
  }
  for(int i = ans.size()-1; i>=1; --i)
    fout << ans[i] << " ";
	return 0;
}

//Andrei Muntean, 2018
