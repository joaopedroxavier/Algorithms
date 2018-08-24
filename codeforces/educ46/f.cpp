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

const int N = 5e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int SQR;

struct qry {
  int l, r, id, ans;
};

bool cmp(const qry &lhs, const qry &rhs) {
  if(lhs.l / SQR == rhs.l / SQR) {
    return ((lhs.l / SQR) & 1) ? lhs.r > rhs.r : lhs.r < rhs.r;
  }
  return lhs.l < rhs.l;
}

bool cmpid(const qry &lhs, const qry &rhs) {
  return lhs.id < rhs.id;
}

qry queries[N];
int n, q, a[N], ans[N], fr[N];
bool put[N];
vector<int> unq;

inline void add(int u) {
  fr[a[u]]++;
  if(fr[a[u]] == 1 and !put[a[u]]) {
    unq.push_back(a[u]);
    put[a[u]] = true;
  }
}

inline void rem(int u) {
  fr[a[u]]--;
  if(fr[a[u]] == 1 and !put[a[u]]) {
    unq.push_back(a[u]);
    put[a[u]] = true;
  }
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);

  scanf("%d", &q);

  SQR = sqrt(n+q);
  for(int i=0; i<q; i++) {
    int l, r; scanf("%d %d", &l, &r);
    queries[i] = {l, r, i, 0};
  }
  sort(queries, queries+q, cmp);

  int pl = 1, pr = 1;
  fr[a[1]] = 1;
  unq.push_back(a[1]);

  for(int i=0; i<q; i++) {
    int l = queries[i].l, r = queries[i].r;

    while(pl > l) { pl--; add(pl); }
    while(pl < l) { rem(pl); pl++; }

    while(pr < r) { pr++; add(pr); }
    while(pr > r) { rem(pr); pr--; }

    while(!unq.empty() and fr[unq.back()] != 1) {
      put[unq.back()] = false;
      unq.pop_back();
    }
    if(!unq.empty()) queries[i].ans = unq.back();
  }
  sort(queries, queries+q, cmpid);
  for(int i=0; i<q; i++) printf("%d\n", queries[i].ans);

  return 0;
}

