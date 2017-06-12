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

ll n, b, s, ans;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> b;
  ll l=0, r=n/2;

  while(l <= r){
    ll m = (l+r)/2;
    if(b > 4*m*(n-m)) s=m, l=m+1;
    else r=m-1;
  }

  b -= 4*s*(n-s);
  ll x = s, y = s-1;

  if(b < n-2*s) y += b; // going right

  else if(b <= 2*(n-2*s-1)) y += (n-2*s), x += (b-(n-2*s)); // reached right, going down

  else if(b <= 3*(n-2*s-1)){ // reached bottom-right, going left
    y += (n-2*s), x += (n-2*s-1);
    y -= (b-2*(n-2*s-1)-1);
  }

  else{ // reached bottom-left, going up
    y = s;
    x += (n-2*s-1);
    x -= (b-3*(n-2*s-1)-1);
  }

  cout << x+1 _ y+1 << endl;

	return 0;
}
