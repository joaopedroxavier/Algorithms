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
const int T=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ii sack[N][T];
ll ep[N][T], et[N][T], ps[N][T];
ll p[N], t[N], ord[N];
int n, tmax;

int main(){
  scanf("%d %d", &n, &tmax);

  for(int i=0; i<n; i++) scanf("%lld %lld", &t[i], &p[i]), ord[i] = i;

  sort(ord, ord+n, [](int a, int b) { return p[b] * t[a] < p[a] * t[b]; });

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=tmax; j++) {
      ll tt = t[ord[i-1]], pp = p[ord[i-1]];

      if(j >= tt) {
        ll p1 = ep[i-1][j];
        ll p2 = ep[i-1][j-tt] + pp;
        ll t1 = et[i-1][j];
        ll t2 = et[i-1][j-tt] + j * pp;

        if(p1 > p2 or (p1 == p2 and t1 < t2)) {
          sack[i][j] = {i-1, j};
          
          et[i][j] = t1; ep[i][j] = p1;
        }
        else {
          sack[i][j] = {i-1, j-tt};

          et[i][j] = t2; ep[i][j] = p2;
        }
      }
      else {
        sack[i][j] = {i-1, j};

        ep[i][j] = ep[i-1][j];
        et[i][j] = et[i-1][j];
      }
    }
  }

  vector<int> ans;
  ii p = {n, 0}; 
  for(int i=0; i<=tmax; i++) {
    if(ep[n][i] > ep[n][p.second] or (ep[n][i] == ep[n][p.second] and et[n][i] < et[n][p.second])) {
      p = {n, i};
    }
  }

  while(p.first > 0) {
    if(p.second != sack[p.first][p.second].second) ans.pb(ord[p.first-1]);
    
    p = sack[p.first][p.second];
  }

  reverse(ans.begin(), ans.end());

  printf("%d\n", (int) ans.size());
  for(auto i : ans) printf("%d ", i+1);
  printf("\n");

  return 0;
}

