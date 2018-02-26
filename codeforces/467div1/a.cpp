#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll k, d, t;

int main(){
  scanf("%lld %lld %lld", &k, &d, &t);

  if(k % d == 0) {
    printf("%lld\n", t);
    return 0;
  }
  if(k <= d) {
    ll walk = ((d - k)*1 + (k)*2);
    ll cycles = (2*t) / walk;
    ll timepassed = cycles*d;

    ll r = (2*t) % (walk);

    bool half;
    if(r <= k*2) {
      timepassed += r / 2;
      half = r&1;
    }
    else {
      timepassed += k + (r - 2*k);
      half = false;
    }

    printf("%lld%s\n", timepassed, half ? ".5" : "");
  }
  else {
    ll big = ((k/d)+1)*d;
    ll walk = (big - k)*1 + (k)*2;
    ll cycles = (2*t) / walk;
    ll timepassed = cycles * big;

    ll r = (2*t) % walk;
    bool half;
    if(r <= k*2) {
      timepassed += r / 2;
      half = r&1;
    }
    else {
      timepassed += k + (r - 2*k);
      half = false;
    }

    printf("%lld%s\n", timepassed, half ? ".5" : "");
  }

	return 0;
}

