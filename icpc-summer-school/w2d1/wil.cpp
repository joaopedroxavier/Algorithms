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
const int N=2e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll ps[N], v[N], n, p, d;

struct MaxQueue {
  deque<pll> maxqueue;

  void push(ll x) {
    pll p = {x, 1};
    while(!maxqueue.empty() and maxqueue.back().first <= x) {
      p.second += maxqueue.back().second;
      maxqueue.pop_back();
    }
    maxqueue.push_back(p);
  }

  void pop() {
    if(!maxqueue.empty()) {
      maxqueue.front().second--;
      if(maxqueue.front().second <= 0) maxqueue.pop_front();
    }
  }

  ll get_max() {
    return maxqueue.front().first;
  }
};

bool check(int m) {
  if(m <= d) return true;

  MaxQueue mq;

  mq.push(ps[d]);
  for(int i=1; i+d <= m; i++) {
    mq.push((ps[i+d] - ps[i]));
  }

  ll gains = mq.get_max();
  ll best  = ps[m] - gains;
  if(best <= p) return true;

  for(int i=1; i+m <= n; i++) {
    mq.pop();
    mq.push((ps[i+m] - ps[i+m-d]));
    ll gains = mq.get_max();
    ll best  = ps[i+m] - ps[i] - gains;
    if(best <= p) return true;
  }

  return false;
}

int main(){
  scanf("%lld %lld %lld", &n, &p, &d);
  for(int i=1; i<=n; i++) scanf("%lld", &v[i]);

  for(int i=1; i<=n; i++) ps[i] = ps[i-1] + v[i];

  int l=0, r=n;
  while(l < r) {
    int m = (l+r+1)/2;
    if(check(m)) l = m;
    else r = m-1;
  }

  printf("%d\n", l);

  return 0;
}

