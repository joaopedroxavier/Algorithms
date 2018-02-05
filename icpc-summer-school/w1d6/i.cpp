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
bool built;

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

void build(char* s) {
  clear();
  int num = (int) strlen(s);
  for(int i=0; i < num; i++) {
    add(s[i]);
  }
}

bool check(char* s) {
  int u = 0;
  for(int i=0; i < (int) strlen(s); i++) {
    if(adj[u][s[i]]) u = adj[u][s[i]];
    else return false;
  }
  return true;
}

void add_word(char* s) {
  for(int i=0; i < (int) strlen(s); i++) {
    add(s[i]);
  }
}

ll n, m;
char q[N], t[N];

int main(){

  while(scanf("%s", q) != EOF) {
    scanf("%s", t);

    for(int i=0; i < (int)strlen(t); i++) {
      if(t[i] < 'a') t[i] += 32;
    }

    if(q[0] == '?') printf("%s\n", (check(t) ? "YES" : "NO"));
    else {
      if(!built) build(t), built = true;
      else add_word(t);
    }
  }

	return 0;
}

