#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define y1 skjgdfugesf

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll n, m, cl, ce, v, q;
vector<ll> stairs;
vector<ll> elevators;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld %lld %lld %lld", &n, &m, &cl, &ce, &v);

  for(int i=0; i<cl; i++) {
    ll u; scanf("%lld", &u);
    stairs.push_back(u);
  }

  for(int j=0; j<ce; j++) {
    ll u; scanf("%lld", &u);
    elevators.push_back(u);
  }

  scanf("%lld", &q);
  for(int i=0; i<q; i++) {
    ll x1, y1, x2, y2;
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    swap(x1, y1);
    swap(x2, y2);
    ll answer = INF;

    if(y1 == y2) {
      answer = abs(x1 - x2);
    }
    else {
      ll usingleftstair = upper_bound(stairs.begin(), stairs.end(), x1) - stairs.begin();
      if(usingleftstair) {
        usingleftstair--;
        answer = min(answer, abs(x1 - stairs[usingleftstair]) + abs(stairs[usingleftstair] - x2) + abs(y2 - y1));
      }

      ll usingrightstair = upper_bound(stairs.begin(), stairs.end(), x1) - stairs.begin();
      if(usingrightstair != cl) {
        answer = min(answer, abs(x1 - stairs[usingrightstair]) + abs(stairs[usingrightstair] - x2) + abs(y2 - y1));
      }

      ll usingleftel = upper_bound(elevators.begin(), elevators.end(), x1) - elevators.begin();
      if(usingleftel) {
        usingleftel--;
        answer = min(answer, abs(x1 - elevators[usingleftel]) + abs(elevators[usingleftel] - x2) + (abs(y2 - y1) + v - 1) / v);
      }

      ll usingrightel = upper_bound(elevators.begin(), elevators.end(), x1) - elevators.begin();
      if(usingrightel != ce) {
        answer = min(answer, abs(x1 - elevators[usingrightel]) + abs(elevators[usingrightel] - x2) + (abs(y2 - y1) + v - 1) / v);
      }
    }


    printf("%lld\n", answer);
  }

  return 0;
}

