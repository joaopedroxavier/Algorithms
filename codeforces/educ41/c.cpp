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

const int N = 1e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n;
char a[N][N][4], aux[N][N][4];

char cmpl(char c) { return (c == '1') ? '0' : '1'; }

int cnt(vector<int> v) {
  int tl = v[0], tr = v[1], bl = v[2], br = v[3];
  int ans = 0;
  for(int i=0; i<n; i++) {
    if(i > 0 and aux[i][0][tl] == aux[i-1][0][tl]) ans++, aux[i][0][tl] = cmpl(aux[i][0][tl]);
    for(int j=1; j<n; j++) {
      if(aux[i][j][tl] == aux[i][j-1][tl]) ans++, aux[i][j][tl] = cmpl(aux[i][j][tl]);
    }
    if(aux[i][0][tr] == aux[i][n-1][tl]) ans++, aux[i][0][tr] = cmpl(aux[i][0][tr]);
    for(int j=1; j<n; j++) {
      if(aux[i][j][tr] == aux[i][j-1][tr]) ans++, aux[i][j][tr] = cmpl(aux[i][j][tr]);
    }
  }

  if(aux[0][0][bl] == aux[n-1][0][tl]) ans++, aux[0][0][bl] = cmpl(aux[0][0][bl]);
  for(int i=0; i<n; i++) {
    if(i > 0 and aux[i][0][bl] == aux[i-1][0][bl]) ans++, aux[i][0][bl] = cmpl(aux[i][0][bl]);
    for(int j=1; j<n; j++) {
      if(aux[i][j][bl] == aux[i][j-1][bl]) ans++, aux[i][j][bl] = cmpl(aux[i][j][bl]);
    }
    if(aux[i][0][br] == aux[i][n-1][bl]) ans++, aux[i][0][br] = cmpl(aux[i][0][br]);
    for(int j=1; j<n; j++) {
      if(aux[i][j][br] == aux[i][j-1][br]) ans++, aux[i][j][br] = cmpl(aux[i][j][br]);
    }
  }
  return ans;
}

void cpy() {
  for(int i=0; i<n; i++) 
    for(int j=0; j<n; j++) 
      for(int k=0; k<4; k++) 
        aux[i][j][k] = a[i][j][k];
}

int test(vector<int> v) {
  int tl = v[0];
  cpy();
  int cnt1 = cnt(v);
  cpy(); aux[0][0][tl] = cmpl(aux[0][0][tl]);
  int cnt2 = 1 + cnt(v);

  return min(cnt1, cnt2);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      scanf(" %c", &a[i][j][0]);
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      scanf(" %c", &a[i][j][1]);
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      scanf(" %c", &a[i][j][2]);
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      scanf(" %c", &a[i][j][3]);
    }
  }

  vector<int> v = {0, 1, 2, 3};
  int ans = INF;
  do {
    ans = min(ans, test(v));
  } while(next_permutation(v.begin(), v.end()));
  
  printf("%d\n", ans);

	return 0;
}

