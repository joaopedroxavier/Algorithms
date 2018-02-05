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
const int N=1e2+5;
const int MOD=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll dist[N][N], c[N][N];
int n, m, v1, v2;

void fill() {
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      c[i][j] = dist[i][j];
    }
  }
}

ll maxt() {
  ll ans = 0;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      ans = max(ans, c[i][j]);
    }
  }

  return ans;
}

ll check(ll val) {
  fill();
  c[v1][v2] = c[v2][v1] = min(c[v1][v2], val);
  for(int p=1; p<=n; p++) {
    for(int q=1; q<=n; q++) {
      c[p][q] = min(c[p][q], c[p][v1] + c[v1][v2] + c[v2][q]);
      c[p][q] = min(c[p][q], c[p][v2] + c[v2][v1] + c[v1][q]);
    }
  }
  ll m = maxt();
  return m;
}

int main(){
  scanf("%d %d", &n, &m);

  memset(dist, 63, sizeof dist);
  for(int i=0; i<m; i++) {
    int u, v; ll w;
    scanf("%d %d %lld", &u, &v, &w);

    dist[u][v] = dist[v][u] = min(dist[u][v], w);
  }

  for(int i=1; i<=n; i++) dist[i][i] = 0;
  for(int k=1; k<=n; k++) {
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  ll maxtraveltime = INF; ll ans = INF;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      fill();
      c[i][j] = c[j][i] = 0;
      for(int p=1; p<=n; p++) {
        for(int q=1; q<=n; q++) {
          c[p][q] = min(c[p][q], c[p][i] + c[j][q]);
          c[p][q] = min(c[p][q], c[p][j] + c[i][q]);
        }
      }
      ll m = maxt();
      if(m <= maxtraveltime) {
          if(maxtraveltime > m) {
            ans = 0;
          }
          maxtraveltime = m;
          v1 = i, v2 = j;

          ll l = 0, r = INF;
          ll thresh = check(0);
          while(l < r) {
            ll m = (l+r+1)/2;
            ll tt = check(m);

            if(tt == thresh) l = m;
            else r = m-1;
          }

          ans = max(ans, l);
      }
    }
  }

  printf("%lld.000000 %lld.000000\n", maxtraveltime >= INF ? -1 : maxtraveltime, ans >= INF ? -1 : ans);

  return 0;
}

