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

int n, a, b;

int check(int x, int y) {
  int aa = a, bb = b;
  vector<int> v(x), w(y);

  while(aa) for(int i=0; i<x and aa; i++) {
    aa--;
    v[i]++;
  }

  while(bb) for(int i=0; i<y and bb; i++) {
    bb--;
    w[i]++;
  }

  int mi = INF;
  for(int i : v) mi = min(mi, i);
  for(int i : w) mi = min(mi, i);

  return mi;
}

int main(){
  scanf("%d %d %d", &n, &a, &b);

  int ans = 0;
  for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(i+j == n){
    ans = max(ans, check(i,j));
  }

  printf("%d\n", ans);

	return 0;
}

