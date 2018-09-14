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

bool cp(ll a, ll b, ll c, ll d) {
  return a*d < b*c;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  int t; scanf("%d", &t);

  while(t--) {
    int n; scanf("%d", &n);

    vector<ll> a;
    map<ll, ll> freq;
    for(int i=0; i<n; i++) {
      ll u; scanf("%lld", &u);
      freq[u]++;
      if(freq[u] % 2 == 0) a.push_back(u);
    }

    sort(a.begin(), a.end());

    bool fd = false;
    ll l1, l2, p, ar;
    n = a.size();
    for(int i=0; i<n-1; i++) {
      ll l = a[i], r = a[i+1];
      ll per = 2*(l+r);
      ll are = l*r;
      if(!fd) {
        l1 = l, l2 = r;
        p = per, ar = are;
        fd = true;
      }
      else if(cp(per*per, are, p*p, ar)) {
        l1 = l, l2 = r;
        p = per, ar = are;
      }
    }
    printf("%lld %lld %lld %lld\n", l1, l1, l2, l2);
  }

	return 0;
}

