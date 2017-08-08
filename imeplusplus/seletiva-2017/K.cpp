#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define f first
#define s second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii, ii> sofa;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int l[N], r[N], u[N], d[N];
sofa room[N], back[N];
int s, n, m;
int cntl, cntr, cntt, cntb;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> s;
  cin >> n >> m;
  for(int i=0;i<s;++i){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ii p1 = mp(x1, y1), p2 = mp(x2, y2);
    if(p2 < p1) swap(p2, p1);
    room[i] = mp(p1, p2);
    back[i] = mp(p1, p2);
  }

  cin >> cntl >> cntr >> cntt >> cntb;

  sort(room, room+s, [](sofa a, sofa b){ return a.f.f < b.f.f; });

  for(int i=0;i<s;++i) l[room[i].f.f + 1]++;
  for(int i=1;i<=n+1;++i) l[i] = l[i-1] + l[i];

  for(int i=s-1;i>=0;--i) r[room[i].s.f - 1]++;
  for(int i=n;i>=0;--i) r[i] = r[i+1] + r[i];

  sort(room, room+s, [](sofa a, sofa b){ return a.f.s < b.f.s; });
  for(int i=0;i<s;++i) d[room[i].f.s + 1]++;
  for(int i=1;i<=m+1;++i) d[i] = d[i-1] + d[i];

  for(int i=s-1;i>=0;--i) u[room[i].s.s - 1]++;
  for(int i=m;i>=0;--i) u[i] = u[i+1] + u[i];

  for(int i=0;i<s;++i){
    int cl = l[back[i].s.f], cr = r[back[i].f.f], ct = d[back[i].s.s], cb = u[back[i].f.s];
    if(back[i].f.s == back[i].s.s) cl--, cr--;
    else ct--, cb--;
    if(cntl == cl and cntr == cr and cntt == ct and cntb == cb){
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
	return 0;
}

