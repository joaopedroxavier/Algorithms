#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

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

map<string, ld> m;
char s[20], t[20];
int n;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);

  m["pink"] = 0;

  for(int i=0; i<n; i++) {
    ld r;
    scanf(" %s %s %Lf", s, t, &r);
    string ss = s, tt = t;

    if(!m.count(ss)) m[ss] = -100000;
    if(!m.count(tt)) m[tt] = -100000;

    m[ss] = max(m[ss], log(r) + m[tt]);
  }

  printf("%.12Lf\n", exp(min(log(10.0L), m.count("blue") ? m["blue"] : -100000)));
	return 0;
}

