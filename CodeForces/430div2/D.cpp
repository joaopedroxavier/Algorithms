#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=3e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

unsigned trie[N][2], sz[N], trien = 1, v[N];
int n, m;

int add(int u, int c){
  if(trie[u][c]) return trie[u][c];
  return trie[u][c] = ++trien;
}

int mex(int query){
  int u = 1;
  unsigned p = (1<<31), m = query;
  while(p){
    if(p & query){
      int v = trie[u][1], w = trie[u][0];
      if(!v) return m ^ query;
      if(sz[v] == p){
        m ^= p;
        if(!w) return m ^ query;
        else u = w;
      }
      else u = v;
    }
    else{
      int v = trie[u][0], w = trie[u][1];
      if(!v) return m ^ query;
      if(sz[v] == p){
        m ^= p;
        if(!w) return m ^ query;
        else u = w;
      }
      else u = v;
    }
    p = (p >> 1);
  }
  return m ^ query;
}

set<int> has;

int main(){
  scanf("%d %d", &n, &m);

  for(int i=0;i<n;i++){
    scanf("%d", &v[i]);
    unsigned u = 1, p = (1<<31);
    if(has.count(v[i])) continue;
    sz[u]++;
    while(p){
      if(v[i] & p) u = add(u, 1);
      else u = add(u, 0);
      sz[u]++;
      p = (p >> 1);
    }
    has.insert(v[i]);
  }

  int qry = 0;
  for(int i=0;i<m;i++){
    int c;
    scanf("%d", &c);
    qry ^= c;
    printf("%d\n", mex(qry));
  }
  return 0;
}
