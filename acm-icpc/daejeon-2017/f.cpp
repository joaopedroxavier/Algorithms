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

void get_pos(int lth, int walks, int &x, int &y) {
  if(lth == 1) return;
  int l = lth/2;
  int sz = l*l;
  int quad = walks / sz;

  get_pos(l, walks - quad * sz, x, y);
  if(quad == 0) {
    swap(x, y);
  }
  if(quad == 1) {
    y += l;
  }
  if(quad == 2) {
    x += l; y += l;
  }
  if(quad == 3) {
    swap(x, y);
    x = l - x + 1;
    y = l - y + 1;
    x += l;
  }
}

int n, k;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &k);
  k--;

  int x = 1, y = 1; get_pos(n, k, x, y);
  printf("%d %d\n", x, y);
  return 0;
}

