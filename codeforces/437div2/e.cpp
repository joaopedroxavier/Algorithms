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
const int N=3e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

priority_queue<ll> buy;
ll ans, n;

int main(){
  scanf("%lld", &n);
  for(int i=0; i<n; i++) {
    ll u;
    scanf("%lld", &u);

    buy.push(-u);
    if(u > -buy.top()) {
      ans += u + buy.top();
      buy.pop();
      buy.push(-u);
    }
  }

  printf("%lld\n", ans);

	return 0;
}

