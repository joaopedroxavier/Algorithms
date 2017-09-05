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
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

vector<ll> in, primes;
int n, sieve[N];
map<int, int> gn;
map<int, int> cases;

vector<ii> factorize(int n){
  vector<ii> ans;
  for(int i : primes){
    ii p;
    p.first = i;
    while(!(n%p.first)) p.second++, n /= p.first;
    if(p.second) ans.pb(p);
  }
  if(n != 1) ans.pb(mp(n,1));
  return ans;
}

ll grundy(int v, int m){
  if(v <= 1) return 0;
  if(v == 2) return gn[v] = 1;
  if(gn.count(v)) return gn[v];

  set<int> play;
  for(int i=1;i<=m;i++){
    int move = 0, ma = 0;
    for(int j=1;j<32;j++) if((1<<j) & v){
      if(j > i){
        move = move | (1<<(j-i));
        ma = max(ma, j-i);
      }
      else if(j < i){
        move = move | (1<<j);
        ma = max(ma, j);
      }
    }    play.insert(grundy(move, ma));
  }

  int mex = 0;
  while(play.count(mex)) mex++;
  return gn[v] = mex;
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    ll u;
    scanf("%lld", &u);
    in.pb(u);
  }

  for(int i=2;i*i<N;i++) if(!sieve[i]){
    for(int j=2*i;j<N;j+=i){
      sieve[j] = 1;
    }
  }
  for(int i=2;i<N;i++) if(!sieve[i]){
    primes.pb(i);
  }

  for(int i : in){
    vector<ii> pf = factorize(i);
    for(ii p : pf){
      cases[p.first] = cases[p.first] | (1<<p.second);
    }
  }

  ll ans = 0;
  for(auto i : cases){
    int j = 0, ma = 0;
    while(j<32){
      if((1<<j) & i.second) ma = max(ma, j);
      j++;
    }
    ans ^= grundy(i.second, ma);
  }
  printf("%s\n", ans ? "Mojtaba" : "Arpa");
}

