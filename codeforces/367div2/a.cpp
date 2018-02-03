#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ld x, y;
int n;
set<ld> s;

ld dist(ld x, ld y){ return sqrt(x*x + y*y); }

int main(){
  scanf("%Lf %Lf", &x, &y);
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    ld xn, yn, v;
    scanf("%Lf %Lf %Lf", &xn, &yn, &v);
    s.insert(dist(x-xn,y-yn) / v);
  }

  printf("%.12Lf\n", *s.begin());

	return 0;
}

