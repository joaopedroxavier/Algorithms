#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e6+5;
const int K=26;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

string s;
int sl[2*N], len[2*N], sz, last;
ll cnt[2*N], d[2*N];
map<int, int> adj[2*N];
set<int> vtx;
int lastvtx;

void add(int c) {
  int u = sz++;
  len[u] = len[last] + 1;

  int p = last;
  while(p != -1 and !adj[p][c])
    adj[p][c] = u, p = sl[p];

  if(p == -1) sl[u] = 0;
  else {
    int q = adj[p][c];
    if(len[p] + 1 == len[q]) sl[u] = q;
    else {
      int r = sz++;
      len[r] = len[p] + 1;
      sl[r] = sl[q];
      adj[r] = adj[q];
      while(p != -1 and adj[p][c] == q)
        adj[p][c] = r, p = sl[p];
      sl[q] = sl[u] = r;
    }
  }

  last = u;
}

void clear(){
  for(int i=0; i <= sz; i++) adj[i].clear();
  last = 0;
  sz = 1;
  sl[0] = -1;
}

void build(string s) {
  clear();
  int num = s.size();
  for(int i=0; i < num; i++) {
    add(s[i]);
  }
}

ll n, m;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  build(s);

  for(int i=0; i<2*N; i++) if(!adj[i].empty()) {
    for(auto p : adj[i]) {
      vtx.insert(i), vtx.insert(p.second);
    }
    m += adj[i].size();
  }
  cout << vtx.size() << " " << m << endl;

  for(int i=0; i<2*N; i++) if(!adj[i].empty()) {
    for(auto p : adj[i]) {
      cout << i+1 << " " << p.second+1 << " " << (char) p.first << endl;
    }
  }

  int p = 0;
  for(int i=0; i<2*N; i++) if(len[i] > len[p]) p = i;

  vector<int> terminates;
  while(p != -1) terminates.pb(p), p = sl[p];

  cout << terminates.size() << endl;
  for(auto i : terminates) cout << i+1 << " ";
  cout << endl;


	return 0;
}

