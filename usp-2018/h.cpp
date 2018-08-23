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
typedef pair<int, ii> iii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 3e4+5;
const int SQR = 200;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, q;
vector<iii> queries;

bool cmp(iii lhs, iii rhs) {
  int bl = lhs.nd.st / SQR;
  int br = rhs.nd.st / SQR;

  if(bl != br) return bl < br;

  return lhs.nd.nd < rhs.nd.nd;
}

set<int> good;
map<int, int> rep;
int qt[N], v[N], ans[N], ma;

void add(int i) {
  int r = ++rep[v[i]];
  qt[r]++;
  if(qt[r] >= r) {
    ma = max(ma, r);
  }
}

void rem(int i) {
  int r = rep[v[i]]--;
  if(qt[r] == r) {
    ma--;
  }
  qt[r]--;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &q);

  for(int i=1; i<=n; i++) scanf("%d", &v[i]);
  for(int i=0; i<q; i++) {
    int l, r; scanf("%d %d", &l, &r);
    queries.push_back({i, {l, r}});
  }
  sort(queries.begin(), queries.end(), cmp);

  int pl = 1, pr = 1;
  add(1);
  for(iii q : queries) {
    int i = q.st;
    int l = q.nd.st, r = q.nd.nd;

    while(pl < l) { rem(pl); pl++; }
    while(pl > l) { pl--; add(pl); }
    while(pr < r) { pr++; add(pr); }
    while(pr > r) { rem(pr); pr--; }

    ans[i] = ma;
  }

  for(int i=0; i<q; i++) printf("%d\n", ans[i]);

	return 0;
}

