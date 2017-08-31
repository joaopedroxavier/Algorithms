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

ll cubic_root(ll n){
  ll l=0, r=1e6;
  while(l<=r){
    ll m = (l+r)/2;
    if(m*m*m >  n) r = m-1;
    else if(m*m*m == n) return m;
    else l = m+1;
  }
  return 0;
}

int main(){
  int q;
  scanf("%d", &q);

  while(q--){
    ll a, b;
    scanf("%lld %lld", &a, &b);
    ll cube = cubic_root(a*b);
    if(cube){
      if((a%cube == 0) and (b%cube == 0)) printf("Yes\n");
      else printf("No\n");
    }
    else{
      printf("No\n");
    }
  }

	return 0;
}

