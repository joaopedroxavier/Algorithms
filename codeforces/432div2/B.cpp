#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define f first
#define s second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll, ll> pll;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

pair<ll, ll> p[3];

ll dist(pll a, pll b){ return (a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s) ; }
set<ll> s;

ll area(pll a, pll b, pll c){
  return (a.f * b.s) + (b.f * c.s) + (c.f * a.s) - (a.s * b.f) - (b.s * c.f) - (c.s * a.f);
}

int main(){
  scanf("%lld %lld %lld %lld %lld %lld", &p[0].f, &p[0].s, &p[1].f, &p[1].s, &p[2].f, &p[2].s);

  if(area(p[0], p[1], p[2]) == 0) return printf("No\n"), 0;

  printf("%s\n", ((dist(p[0], p[1]) == dist(p[1], p[2])) ? "Yes" : "No"));
	return 0;
}

