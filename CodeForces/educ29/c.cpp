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
const int N=15;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int bob[N][N], ali[N][N], vis[N][N];
int a, b;
ll pbob, pali, clen, r;
ll ansbob, ansali;

void dfs(int i, int j) {
  if(vis[i][j]) return;
  vis[i][j] = 1;

  clen++;
  pali += (i == (j+1)%3);
  pbob += (j == (i+1)%3);

  dfs(ali[i][j], bob[i][j]);
}

ii cycle(int i, int j, int di, int dj, bool fl) {
  if(i == di and j == dj and fl) return {i, j};

  int mi = ali[di][dj], mj = bob[di][dj];
  return cycle(ali[i][j], bob[i][j], ali[mi][mj], bob[mi][mj], true);
}

void dfsf(int i, int j, int k) {
  if(!k) return;

  ansali += (i == (j+1)%3);
  ansbob += (j == (i+1)%3);

  dfsf(ali[i][j], bob[i][j], k-1);
}

int main(){
  scanf("%lld %d %d", &r, &a, &b);

  a--, b--;
  for(int i=0; i<3; i++) for(int j=0; j<3; j++) scanf("%d", &ali[i][j]);
  for(int i=0; i<3; i++) for(int j=0; j<3; j++) scanf("%d", &bob[i][j]);

  for(int i=0; i<3; i++) for(int j=0; j<3; j++) ali[i][j]--, bob[i][j]--;
  ii pp = cycle(a, b, a, b, false);

  while(mp(a, b) != pp and r) {
    r--;

    ansali += (a == (b+1)%3);
    ansbob += (b == (a+1)%3);

    int nb = bob[a][b], na = ali[a][b];

    b = nb, a = na;
  }

  dfs(a,b);

  ansbob += pbob * (r/clen);
  ansali += pali * (r/clen);

  dfsf(a, b, r % clen);

  printf("%lld %lld\n", ansali, ansbob);

	return 0;
}

