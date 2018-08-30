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

const int N = 2e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

map<int, set<pair<ll, int>>> shirtsf, shirtsb;
ll a[N];
int n, m;
int f[N], b[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%lld", &a[i]);
  }
  for(int i=0; i<n; i++) {
    int c; scanf("%d", &c);
    shirtsf[c].insert({a[i], i});
    f[i] = c;
  }
  for(int i=0; i<n; i++) {
    int c; scanf("%d", &c);
    shirtsb[c].insert({a[i], i});
    b[i] = c;
  }
  scanf("%d", &m);
  for(int i=0; i<m; i++) {
    int c; scanf("%d", &c);
    int idx1 = shirtsf[c].empty() ? INF : (*(shirtsf[c]).begin()).nd;
    int idx2 = shirtsb[c].empty() ? INF : (*(shirtsb[c].begin())).nd;

    if(idx1 == INF and idx2 == INF) printf("-1 ");
    else {
      if(idx1 == INF) {
        printf("%lld ", a[idx2]);
        shirtsf[f[idx2]].erase({a[idx2], idx2});
        shirtsb[b[idx2]].erase({a[idx2], idx2});
      }
      else if(idx2 == INF) {
        printf("%lld ", a[idx1]);
        shirtsf[f[idx1]].erase({a[idx1], idx1});
        shirtsb[b[idx1]].erase({a[idx1], idx1});
      }
      else {
        if(a[idx1] < a[idx2]) {
          printf("%lld ", a[idx1]);
          shirtsf[f[idx1]].erase({a[idx1], idx1});
          shirtsb[b[idx1]].erase({a[idx1], idx1});
        }
        else {
          printf("%lld ", a[idx2]);
          shirtsf[f[idx2]].erase({a[idx2], idx2});
          shirtsb[b[idx2]].erase({a[idx2], idx2});
        }
      }
    }
  }
  printf("\n");
  return 0;
}

