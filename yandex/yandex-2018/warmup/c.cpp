#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define y1 aweiufoiugaesfiguo

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll ox, oy;
int n;

bool col(ll x1, ll y1, ll x2, ll y2) { return (x1-ox)*(y2-oy) == (x2-ox)*(y1-oy); }

ll x[N], y[N];

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int t;
    scanf("%d", &t);
    if(t == 0) {
      ll r;
      scanf("%lld %lld %lld", &r, &x[i], &y[i]);
      x[i] *= 4;
      y[i] *= 4;
    }
    else {
      ll x1, y1, x2, y2, x3, y3, x4, y4;
      scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
      x[i] = (x1 + x2 + x3 + x4);
      y[i] = (y1 + y2 + y3 + y4);
    }
  }

  ox = x[0], oy = y[0];

  bool found = true;
  for(int i=1; i<n-1; i++) found = found and col(x[i], y[i], x[i+1], y[i+1]);

  printf("%s\n", found ? "Yes" : "No");

	return 0;
}

