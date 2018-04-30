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

ll n, k;
vector<ll> v;

int solve(int p){
  if(p == 0) for(ll i : v) if(i >= k) return p;
  if(v[n-1] >= k) return p;
  for(int i=1;i<n;i++) v[i] = min(k, v[i] + v[i-1]);
  return solve(p+1);
}

vector<ll> prod(vector<vector<ll>> a, vector<ll> t, ll s){
  vector<ll> ans(s);
  for(int i=0;i<s;i++){
    for(int j=0;j<s;j++){
      if((double)ans[i] + (double)a[i][j]*(double)t[j] >= (double)k) ans[i] = k;
      else ans[i] = min(k, ans[i] + a[i][j]*t[j]);
    }
  }
  return ans;
}

vector<vector<ll>> mult(vector<vector<ll>> a, vector<vector<ll>> b, ll s){
  vector<ll> v(s);
  vector<vector<ll>> ans(s,v);
  for(int i=0;i<s;i++){
    for(int j=0;j<s;j++){
      for(int l=0;l<s;l++){
        if((double)ans[i][j] + (double)a[i][l]*(double)b[l][j] >= (double)k) ans[i][j] = k;
        else ans[i][j] = min(k, ans[i][j] + a[i][l]*b[l][j]);
      }
    }
  }
  return ans;
}

vector<vector<ll>> fastexp(vector<vector<ll>> mat, ll s, ll exp){
  vector<ll> t(s);
  vector<vector<ll>> ans(s,t);
  for(int i=0;i<s;i++) ans[i][i] = 1;
  while(exp){
    if(exp&1) ans = mult(mat, ans, s);
    mat = mult(mat, mat, s);
    exp /= 2;
  }
  return ans;
}

bool check(vector<ll> t, ll s){ return t[s-1] >= k; }

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for(int i=0;i<n;i++){
    ll u;
    cin >> u;
    if(u) v.pb(u);
  }
  n = v.size();
  if(n > 10){
    cout << solve(0) << endl;
    return 0;
  }
  vector<ll> t(n);
  vector<vector<ll> > m(n, t);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      m[i][j] = (i >= j);
    }
  }
  ll l = 0, r = k;
  while(l <= r){
    ll med = (l+r)/2;
    if(l == r) break;
    vector<vector<ll>> aux = fastexp(m, n, med);
    if(check(prod(aux, v, n), n)) r = med;
    else l = med+1;
  }
  cout << r << endl;
	return 0;
}

