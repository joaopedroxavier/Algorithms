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
const int M=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll bright[N][N][N];
int n, q, c;
int xstar[M], ystar[M];
vi b[M];

int main(){
  scanf("%d%d%d", &n, &q, &c);
  for(int i=0;i<n;++i){
    int x, y; ll s;
    scanf("%d%d%lld", &x, &y, &s);
    xstar[i] = x, ystar[i] = y;
    b[i].pb(s);
    for(int j=1;j<=c;++j){
      int last = b[i].back();
      b[i].pb((last+1)%(c+1));
    }
  }

  for(int i=0;i<n;++i){
    for(int j=0;j<=c;++j) bright[xstar[i]][ystar[i]][j] += b[i][j];
  }

  for(int k=0;k<=c;++k){
    for(int i=1;i<=100;++i){
      for(int j=1;j<=100;++j){
        bright[i][j][k] += (bright[i-1][j][k] + bright[i][j-1][k] - bright[i-1][j-1][k]);
      }
    }
  }

  for(int i=0;i<q;++i){
    int t, x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
    t = t%(c+1);
    ll ans = bright[x2][y2][t] - bright[x1-1][y2][t] - bright[x2][y1-1][t] + bright[x1-1][y1-1][t];
    printf("%lld\n", ans);
  }

  return 0;
}

