//
// Elohim Essaim, Elohim Essaim, I implore you...
//
#include <bits/stdc++.h>

using namespace std;

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

int trie[N][30], sz[N], trien = 1;
bool terminal[N];

int add(int u, char cc) {
  int c = cc - '0';
  if(trie[u][c]) return trie[u][c];
  return trie[u][c] = ++trien;
}

void adds(string s) {
  int p = 1;
  for(char c : s) {
    sz[p]++;
    p = add(p, c);
  }
  sz[p]++;
  terminal[p] = true;
}

int t, n;
string numb[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> t;

  while(t--) {
    memset(trie, 0, sizeof trie);
    memset(sz, 0, sizeof sz);
    memset(terminal, 0, sizeof terminal);
    trien = 1;

    cin >> n;
    for(int i=0; i<n; i++) {
      cin >> numb[i];
      adds(numb[i]);
    }

    bool found = false;
    for(int i=0; i<n; i++) {
      int p = 1;
      for(char c : numb[i]) {
        p = add(p, c);
      }
      if(sz[p] > 1) found = true;
    }

    cout << ((found) ? "NO" : "YES") << endl;
  }

	return 0;
}


