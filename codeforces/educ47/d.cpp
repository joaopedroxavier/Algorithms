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

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

vector<int> adj[N];
int n, m;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);
  if(m < n-1) return printf("Impossible\n"), 0;

  int amt = 0;
  for(int i=1; i<n; i++) {
    adj[i].push_back(i+1);
    amt++;
  }
  for(int i=1; i<=n; i++) {
    if(amt == m) break;
    for(int j=i+2; j<=n; j++) {
      if(__gcd(i, j) == 1) {
        adj[i].push_back(j);
        amt++;
        if(amt == m) break;
      }
    }
  }

  if(amt < m) return printf("Impossible\n"), 0;
  else {
    printf("Possible\n");
    for(int i=1; i<=n; i++) {
      for(int j : adj[i]) printf("%d %d\n", i, j);
    }
  }
	return 0;
}

