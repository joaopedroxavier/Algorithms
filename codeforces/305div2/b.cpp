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
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, q;
int ans[N];
int bear[N][N];

int main(){
  scanf("%d %d %d", &n, &m, &q);
  for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) scanf("%d", &bear[i][j]);

  for(int i=1; i<=n; i++) {
    int cur = 0;
    for(int j=1; j<=m; j++) {
      if(bear[i][j] == 1) cur++;
      else ans[i] = max(ans[i], cur), cur = 0;
    }
    ans[i] = max(ans[i], cur);
  }

  for(int t=0; t<q; t++) {
    int r, c;
    scanf("%d %d", &r, &c);

    bear[r][c] ^= 1, ans[r] = 0;

    int cur = 0;
    for(int j=1; j<=m; j++) {
      if(bear[r][j] == 1) cur++;
      else ans[r] = max(ans[r], cur), cur = 0;
    }
    ans[r] = max(ans[r], cur);

    int p = 0;
    for(int i=1; i<=n; i++) p = max(p, ans[i]);
    printf("%d\n", p);
  }

	return 0;
}

