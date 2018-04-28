#include <bits/stdc++.h>
using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int trie[N][30], trien = 1;
int n, sz[N];
bool terminal[N];

int addtrie(int u, int c) {
  sz[u]++; c -= 'a';

  if(!trie[u][c]) trie[u][c] = ++trien;
  return trie[u][c];
}

void mergesl(multiset<int> &m, multiset<int> &other) {
  for(auto it : other) {
    m.insert(it);
  }
}

multiset<int> solve(int u, int h) {
  multiset<int> ans;
  if(sz[u] == 1) {
    ans.insert(h);
    return ans;
  }

  int ma = 0, v = u;
  for(int i=0; i<26; i++) if(trie[u][i]){
    if(ma < sz[trie[u][i]]) {
      ma = sz[trie[u][i]];
      v = trie[u][i];
    }
  }

  ans = solve(v, h+1);
  for(int i=0; i<26; i++) if(trie[u][i] and trie[u][i] != v) {
    multiset<int> other = solve(trie[u][i], h+1);
    mergesl(ans, other);
  }
  ans.insert(h);
  if(!terminal[u]) ans.erase(prev(ans.end()));

  return ans;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for(int i=0; i<n; i++) {
    string s;
    cin >> s;
    int p = 1;
    for(char c : s) {
      p = addtrie(p, c);
    }
    terminal[p] = true;
    sz[p]++;
  }

  int ans = 0;
  for(int i=0; i<26; i++) if(trie[1][i]) {
    for(auto it : solve(trie[1][i], 1)) {
      ans += it;
    }
  }

  cout << ans << endl;

  return 0;
}

