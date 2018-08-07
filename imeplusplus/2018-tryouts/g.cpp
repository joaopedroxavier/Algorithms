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

const int N = 5e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int sieve[N];
int n, t, cnt[N], id[N], has[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  for(int i=2; i<N; i++) if(!sieve[i]) {
    sieve[i] = i;
    for(int j=2*i; j<N; j+=i) sieve[j] = i;
  }

  scanf("%d %d", &n, &t);
  for(int i=1; i<=n; i++) scanf("%d", &id[i]);

  ll ans = 0, n_swords = 0;
  for(int i=0; i<t; i++) {
    int q; scanf("%d", &q);
    int swd = id[q];
    int cpy = swd;

    vector<int> primes;
    while(cpy > 1) {
      primes.push_back(sieve[cpy]);
      while(sieve[cpy] == primes.back()) cpy /= sieve[cpy];
    }

    int not_coprimes = 0;
    for(int i=1; i < (1 << primes.size()); i++) {
      int prod = 1, part = 0;
      for(int j=0; j < (int) primes.size(); j++) {
        if(i & (1 << j)) {
          prod *= primes[j];
          part++;
        }
      }
      if(part & 1) not_coprimes += cnt[prod];
      else not_coprimes -= cnt[prod];

      if(has[q]) cnt[prod]--;
      else cnt[prod]++;
    }

    if(has[q]) {
      if(swd == 1) ans -= n_swords - 1;
      else ans -= n_swords - not_coprimes;
      n_swords--;
    }
    else {
      ans += n_swords - not_coprimes;
      n_swords++;
    }
    has[q] = !has[q];

    printf("%lld\n", ans);
  }
	return 0;
}

