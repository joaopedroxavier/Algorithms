#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define y1 sfdyoiphohiesf

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii, ii> rct;

const long double EPS = 1e-9;
const int N=3e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, q;
ll bit[N][N];
map<rct, ll> queries;

rct build(int r1, int c1, int r2, int c2) { return mp(mp(r1,c1),mp(r2,c2)); }

void add(int x, int y, ll v) {
  int a = x, b = y;
  while (a <= n) {
    while (b <= m) { bit[a][b] ^= v; b += b&-b; }
    a += a&-a; b = y;
  }
}

ll query(int x, int y) {
  ll ans = 0;
  int a = x, b = y;
  while(a) {
    while(b) { ans ^= bit[a][b]; b -= b&-b; }
    a -= a&-a; b = y;
  }
  return ans;
}

int main(){
  scanf("%d %d %d", &n, &m, &q);
  srand(time(0));

  for(int i=0; i<q; i++) {
    int t, r1, c1, r2, c2;
    scanf("%d %d %d %d %d", &t, &r1, &c1, &r2, &c2);
    if(t == 1){
      ll v = rand();
      v <<= 32;
      v = v | rand();
      queries[build(r1,c1,r2,c2)] = v;

      add(r1,c1,v);
      add(r1,c2+1,v);
      add(r2+1,c1,v);
      add(r2+1,c2+1,v);

    } else if (t == 2) {
      ll v = queries[build(r1,c1,r2,c2)];
      queries.erase(build(r1,c1,r2,c2));

      add(r1,c1,v);
      add(r1,c2+1,v);
      add(r2+1,c1,v);
      add(r2+1,c2+1,v);

    } else {
      ll v = query(r1,c1), w = query(r2,c2);
      printf("%s\n", v == w ? "Yes" : "No");
    }
  }
  return 0;
}

