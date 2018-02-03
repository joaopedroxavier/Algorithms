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

int ans, a, b, f, k, tank;

void cnt(int i, int s) {
  if(i == k) {
    if(s == 1 and tank < a-f) ans++;
    else if(s == -1 and tank < f) ans++;
    return;
  }
  if(s == 1) {
    if(tank < 2*(a-f)) {
      ans++, tank = b;
    }
    tank -= 2*(a-f);

    cnt(i+1, -1);
  }
  else {
    if(tank < 2*f) {
      ans++, tank = b;
    }
    tank -= 2*f;

    cnt(i+1, 1);
  }
}

int main(){
  scanf("%d %d %d %d", &a, &b, &f, &k);

  if(k == 1) {
    if(f > b or a-f > b) return printf("-1\n"), 0;
  }
  if(k == 2) {
    if(f > b or 2*(a-f) > b) return printf("-1\n"), 0;
  }
  if( k > 2 and (2*(a-f) > b or 2*f > b)) return printf("-1\n"), 0;

  tank = b - f;
  cnt(1, 1);

  printf("%d\n", ans);

	return 0;
}

