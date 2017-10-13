#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
const int N = 1e5+5;

int grid[26][26];
string vis[26];
string cic, ans;
int vis2[26], par[26];

string dfs(int v){
  if(vis[v].size()) return vis[v];
  string greater, tmp;
  for(int i = 0; i < 26; i++){
    if(grid[v][i] && (tmp = dfs(i)).size() > greater.size())
      greater = tmp;
  }
  vis[v].push_back('a' + v);
  return vis[v] = vis[v] + greater;
}

void cycle(int v, int u, int root){
  if(vis2[v]){
    if(v != root) return;
    else{ par[v] = u; return; }
  }
  par[v] = u;
  vis2[v] = 1;
  for(int i=0;i<26;i++)
    if(grid[v][i]) cycle(i, v, root);
}


int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    for(int i=0;i<26;i++) vis[i].clear();
    cic.clear();
    ans.clear();
    for(int i=0;i<26;i++) for(int j=0;j<26;j++) grid[i][j] = 1;

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
      char a, b;
      scanf(" %c%c", &a, &b);
      grid[a - 'a'][b - 'a'] = 0;
    }

    for(int i=0;i<26;i++){
      memset(par, -1, sizeof par);
      memset(vis2, 0, sizeof vis2);

      cycle(i, -1, i);
      if(~par[i]){
        int v = par[i];
        while(v != i){
          cic.push_back(v + 'a');
          v = par[v];
        }
        cic.push_back(i + 'a');
        reverse(cic.begin(), cic.end());
        break;
      }
    }

    if(!cic.empty()){
      int n = (int)cic.size();
      for(int i=0;i<20;i++){
        for(int j=0;j<20;j++) printf("%c", cic[(i+j)%n]);
        printf("\n");
      }
    }

    if(cic.empty()){
      for(int i=0;i<26;i++){
        if(ans.size() < dfs(i).size()) ans = dfs(i);
      }
      int n = (int)ans.size();
      for(int i=0;i<(n+1)/2;i++){
        for(int j=0;j<(n+1)/2;j++) printf("%c", ans[(i+j)%n]);
        printf("\n");
      }
      if(ans.empty()) printf("a\n");
    }
  }

  return 0;
}
