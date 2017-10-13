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
const int N=2e3+5;
const int T=1e7+5;
const int MOD=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll n, s, t, v[N], next_sack[T], num[N];
ll ansmin = INF, ansmax, ansavg;

ll gcd(ll a, ll b){ return b ? gcd(b, a%b) : a; }

ll query(int i){
  map<ll, ll> not_taken; ll ans = 0;

  for(int i=1;i<=n;i++) not_taken[v[i]]++;
 
  //for(auto p : not_taken) printf("%lld : %lld\n", p.first, p.second);

  ll p = v[i];
  while(!not_taken.empty()){
    not_taken[p]--;
    if(!not_taken[p]) not_taken.erase(p);
    ll comeback = (p + t) % s;
    ll next = (not_taken.lower_bound(next_sack[comeback]) == not_taken.end()) ? not_taken.begin() -> first : not_taken.lower_bound(next_sack[comeback]) -> first;
    ans += t;
    if(not_taken.empty()) break;
    if(next >= comeback) ans += next - comeback;
    else ans += s - comeback + next;
    p = next;
  }

  return ans;
}

int main(){
  scanf("%lld %lld %lld", &n, &s, &t);

  for(int i=1;i<=n;i++) scanf("%lld", &v[i]);

  sort(v, v+n+1);

  num[1] = v[1] + s - v[n];
  for(int i=2;i<=n;i++) num[i] = v[i] - v[i-1];

  for(int j=0;j<=v[1];j++) next_sack[j] = v[1];
  for(int i=2;i<=n;i++){
    for(int j=v[i-1]+1;j<=v[i];j++) next_sack[j] = v[i];
  }
  for(int i=v[n]+1;i<s;i++) next_sack[i] = v[1];

  for(int i=1;i<=n;i++){
    ll qry = query(i);
    ansmin = min(ansmin, qry), ansmax = max(ansmax, qry + num[i] - 1);
    ansavg += qry * num[i] + (num[i] * (num[i] - 1)) / 2;
  }

  printf("%lld\n%lld\n%lld/%lld\n", ansmin, ansmax, ansavg/gcd(ansavg, s), s/gcd(ansavg, s));

  return 0;
}

