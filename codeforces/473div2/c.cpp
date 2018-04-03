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

int n;

void solvec() {
  for(int i=1; i<n; i++) {
    printf("%d %d\n", i, i+1);
  }
}

void solvei() {
  if(n < 6) printf("-1\n");
  else {
    printf("1 2\n");
    printf("1 3\n");
    printf("1 4\n");
    printf("4 5\n");
    printf("4 6\n");
    if(n > 6) {
      printf("4 7\n");
      for(int i=7; i<n; i++) printf("%d %d\n", i, i+1);
    }
  }
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  solvei();
  solvec();
	return 0;
}

