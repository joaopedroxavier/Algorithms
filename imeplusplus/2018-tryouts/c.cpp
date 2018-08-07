//
// 내가 나인 게 싫은 날
// 영영 사라지고 싶은 날
// 문을 하나 만들자 너의 맘 속에다
// 그 문을 열고 들어가면
// 이 곳이 기다릴 거야
// 믿어도 괜찮아 널 위로해줄 magic shop
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 50;
const int M = 6;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, v[N], sum[N], cnt[N];
int grid[M][M], ans[M][M];
bitset<7> hor[M], ver[M], block[M], region[N];

bool go(int i, int j, int k) {
  if(hor[i][k] or ver[j][k]) return false;

  int blk = (i / 2) * 2 + (j >= 3);
  int reg = grid[i][j];

  if(region[reg][k] or block[blk][k]) return false;

  if(sum[reg] + k > v[reg]) return false;
  if(cnt[reg] == 1 and sum[reg] + k != v[reg]) return false;

  ans[i][j] = k; sum[reg] += k;
  hor[i][k] = 1; ver[j][k] = 1;
  region[reg][k] = 1; block[blk][k] = 1;
  cnt[reg]--;

  if(i == 5 and j == 5) return true;

  if(j == 5) {
    for(int l=1; l<=6; l++) {
      if(go(i+1, 0, l)) return true;
    }
  }
  else {
    for(int l=1; l<=6; l++) {
      if(go(i, j+1, l)) return true;
    }
  }

  ans[i][j] = 0; sum[reg] -= k;
  hor[i][k] = 0; ver[j][k] = 0;
  region[reg][k] = 0; block[blk][k] = 0;
  cnt[reg]++;

  return false;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &v[i]);

  for(int i=0; i<6; i++) for(int j=0; j<6; j++) scanf("%d", &grid[i][j]);

  for(int i=1; i<=6; i++) if(go(0, 0, i)) break;

  for(int i=0; i<6; i++) {
    for(int j=0; j<6; j++) printf("%d ", ans[i][j]);
    printf("\n");
  }

	return 0;
}

