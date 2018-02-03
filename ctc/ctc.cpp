#include <bits/stdc++.h>

using namespace std;

ifstream fin ("ctc.in");
ofstream fout("ctc.out");

const int N_MAX = 100000 + 5;
int n, m, a, b;
vector<int> vec[N_MAX], rev[N_MAX];
bitset<N_MAX> stviz, viz;

stack<int> st;

void stdfs(int nod){
  stviz[nod] = true;
  for(auto v : vec[nod])
    if(!stviz[v])
      stdfs(v);
  st.push(nod);
}

vector<int> temp;
vector<vector<int> > ans;

void dfs(int nod){
  viz[nod] = true;
  temp.push_back(nod);
  for(auto v : rev[nod])
    if(!viz[v])
      dfs(v);
}

int main(){
  fin >> n >> m;
  while(m--){
    fin >> a >> b;
    vec[a].push_back(b);
    rev[b].push_back(a);
  }

  for(int i = 1; i<=n; ++i)
    if(!stviz[i])
      stdfs(i);

  while(!st.empty()){
    temp.clear();
    if(!viz[st.top()])
      dfs(st.top());
    st.pop();
    if(temp.size())
      ans.push_back(temp);
  }

  fout << ans.size() << "\n";
  for(auto temp : ans){
    for (auto i : temp)
      fout << i << " ";
    fout << "\n";
  }


	return 0;
}

//Andrei Muntean, 2018
