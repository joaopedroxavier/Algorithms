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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll k, p;

vector<ll> transf(ll n) {
  vector<ll> ans;
  while(n) ans.pb(n%10), n/=10;
  return ans;
}

ll retransf(vector<ll> v) {
  ll ans = 0;
  for(ll i : v){ ans *= 10; ans += i; } 
  return ans;
}

ll nextzcy(ll n) {
  vector<ll> v = transf(n);
  int sz = v.size();

  bool nine = true;
  for(ll i : v) nine = nine and (i == 9);
  if(nine) {
    vector<ll> newn(sz+2);
    newn[0] = 1;
    newn[sz+1] = 1;
    for(int i=1; i<sz+1; i++) newn[i] = 0;
    return retransf(newn);
  }

  int p1 = sz/2 - 1, p2 = sz/2;
  while(p1 >= 0) { 
    bool cont = (v[p1] == 9);
    v[p1] = (v[p1] + 1) % 10; v[p2] = (v[p2] + 1) % 10; p1--; p2++;
    if(!cont) break;
  }
  return retransf(v);
}

int main(){
  scanf("%lld %lld", &k, &p);

  ll numb = 11;

  ll sum = 0;
  for(int i=0; i<k; i++) {
    sum = (sum + numb) % p;
    numb = nextzcy(numb);
  }

  printf("%lld\n", sum);

	return 0;
}

