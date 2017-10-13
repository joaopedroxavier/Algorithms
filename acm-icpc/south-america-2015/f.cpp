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
typedef pair<ii, int> iii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const ll INF=1e9;

int p, v;
ll ans;
int xp[N], yp[N];
int xv[N], yv[N], type[N];

map<ll, int> bit;
map<ii, int> idx;

void add(ll p, int v){
  p += INF;
  p += 2;
  while(p <= 2*INF) bit[p] += v, p += (p&-p);
}

int query(ll p){
  p += INF;
  int r = 0; p += 2;
  while(p) r += bit[p], p -= (p&-p); 
  return r;
}


int main(){
  scanf("%d %d", &p, &v);

  for(int i=1; i<=p; i++) scanf("%d %d", &xp[i], &yp[i]), idx[mp(xp[i], yp[i])] = i;

  scanf("%d %d", &xv[1], &yv[1]);
  for(int i=2; i<=v; i++){
    scanf("%d %d", &xv[i], &yv[i]);

    if(xv[i] == xv[i-1]){
      if(yv[i] > yv[i-1]) type[i] = -1, type[i-1] = +1;
      else type[i] = +1, type[i-1] = -1;
    }
  }
  if(xv[v] == xv[1]){
    if(yv[1] > yv[v]) type[1] = -1, type[v] = +1;
    else type[1] = +1, type[v] = -1;
  }

  vector<iii> pts;
  for(int i=1; i<=v; i++) pts.pb(mp(mp(xv[i], yv[i]), type[i]));

  for(int i=1; i<=p; i++) pts.pb(mp(mp(xp[i], yp[i]), 0));

  sort(pts.begin(), pts.end());

  for(iii point : pts){
    int x = point.first.first;
    int y = point.first.second;
    int t = point.second;
    if(t == 0){
      if(query(y) % 2 == 0) ans += idx[mp(x, y)];
    }
    else add(y, t);
  }

  printf("%lld\n", ans);

  return 0;
}

