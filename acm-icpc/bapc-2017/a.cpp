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

ld m, n;
ld r;

int mm, nn;

ld ax, ay, bx, by;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %Lf", &mm, &nn, &r);
  scanf("%Lf %Lf %Lf %Lf", &ax, &ay, &bx, &by);

  m = (ld) mm; n = (ld) nn;

  ld theta = PI / m;
  ld segm = r / n;

  ld mi = 1e9;
  for(int i=0; i<=nn; i++) {
    ld d1 = abs(((ld) i) * segm - ay * segm);
    ld d2 = abs(((ld) i) * segm - by * segm);
    ld d3 = abs((ax - bx) * theta * ((ld) i) * segm);

    mi = min(mi, d1 + d2 + d3);
  }

  printf("%.15Lf\n", mi);

	return 0;
}

