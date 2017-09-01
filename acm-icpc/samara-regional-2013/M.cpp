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
const ll N=1e9;
const int MOD=1e9+7;
const ll N2=2e9;

map<int, int> bit;
ll n, m;

void add(ll p, ll v){
  p += N;
  while(p < N2) bit[p] += v, p += p&-p;
}

ll query(ll p){
  ll r = 0;
  p += N;
  while(p) r += bit[p], p -= p&-p;
  return r;
}

int main(){
  scanf("%lld", &n);
  for(int i=0;i<n;i++){
    ll a, b;
    scanf("%lld %lld", &a, &b);
    if(a == 1) add(b, 1);
    else add(-N+1, 1), add(-b+1, -1);
  }
  scanf("%lld", &m);
  for(int i=0;i<m;i++){
    ll u;
    scanf("%lld", &u);
    printf("%lld\n", query(u));
  }
	return 0;
}
