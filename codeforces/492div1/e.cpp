//
// Elohim Essaim, Elohim Essaim, I implore you...
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll fexp(ll b, ll e, ll mod) {
  ll ans = 1;
  while(e) {
    if(e&1) ans = (ans*b) % mod;
    b = (b*b) % mod;
    e >>= 1;
  }
  return ans;
}

ll u, v, p;
ll cost;
vector<int> answer;

map<int, vector<int>> pathsu, pathsv;
set<int> ansu, ansv;

void process(ll x, ll p, ll who) {
  if((ll) answer.size() == cost) {
    if(who) {
      ansu.insert(x);
      pathsu[x] = answer;
    }
    else {
      ansv.insert(x);
      pathsv[x] = answer;
    }
    return;
  }

  int mv = rand() % 3;
  if(mv == 0) {
    answer.push_back(1);
    x = (x + 1) % p;
  }
  else if(mv == 1){
    answer.push_back(2);
    x = (x + p - 1) % p;
  }
  else {
    answer.push_back(3);
    x = fexp(x, p-2, p);
  }
  process(x, p, who);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  srand(time(0));

  scanf("%lld %lld %lld", &u, &v, &p);

  cost = 1;
  while(cost * cost <= p and cost < 100) cost++;
  printf("%lld\n", 2*cost);

  for(int i=0; i<100000; i++) {
    answer.clear();
    process(u, p, 1);
    answer.clear();
    process(v, p, 0);
  }

  for(int i : ansu) {
    if(ansv.count(i)) {
      vector<int> pt = pathsu[i];
      for(int j : pt) printf("%d ", j);
      pt = pathsv[i];
      reverse(pt.begin(), pt.end());
      for(int j : pt) {
        if(j == 1) printf("2 ");
        if(j == 2) printf("1 ");
        if(j == 3) printf("3 ");
      }
      printf("\n");
      return 0;
    }
  }

  return 0;
}

