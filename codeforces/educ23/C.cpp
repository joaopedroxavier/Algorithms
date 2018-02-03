//
//
//
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

ll digitsum(ll n){
  ll sum = 0;
  while(n){
    sum += n%10;
    n /= 10;
  }
  return sum;
}

ll get_ans(ll n, ll s){
  ll l=0, r=n, ans=0;
  while(l <= r){
    ll m = (l+r)/2;
    if(m - digitsum(m) >= s) ans = m, r = m-1;
    else l = m+1;
  }
  return ((ans == 0) ? 0 : n-ans+1);
}

int main(){
	ios_base::sync_with_stdio(false);
  ll n, s;
  cin >> n >> s;
  cout << get_ans(n, s) << endl;
	return 0;
}

