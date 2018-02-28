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
typedef pair<ll, ll> pll;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int t;

int main(){
  scanf("%d", &t);

  while(t--) {
    vector<pll> prod; int n;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
      ll s, d;
      scanf("%lld %lld", &s, &d);
      prod.pb(mp(s, d));
    }

    sort(prod.begin(), prod.end());
    queue<pll> q; ll tm=0; int i=1;
    q.push(prod[0]); tm += prod[0].first; 

    while(!q.empty()) {
      tm += q.front().second; q.pop();

      while(i < n and prod[i].first <= tm) q.push(prod[i]), i++;

      if(q.empty() and i < n) {
        q.push(prod[i]);
        tm = prod[i].first;
        i++;
      }
    }

    printf("%lld\n", tm);
  }

	return 0;
}

