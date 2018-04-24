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

const int N = 1e7+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, v[N];
bitset<30> a[N];
bitset<30> p[N];

int chars[N][2], keys[N][2], triec = 1, triek = 1;
int sizec[N], sizek[N];

int goc(int u, int c) {
  if(!chars[u][c]) chars[u][c] = ++triec;
  return chars[u][c];
}

int gok(int u, int c) {
  if(!keys[u][c]) keys[u][c] = ++triek;
  return keys[u][c];
}

void addchar(bitset<30> x) {
  int ps = 1;
  for(int i=29; i>=0; i--) {
    sizec[ps]++;
    ps = goc(ps, x[i]);
  }
  sizec[ps]++;
}

void addkey(bitset<30> x) {
  int ps = 1;
  for(int i=29; i>=0; i--) {
    sizek[ps]++;
    ps = gok(ps, x[i]);
  }
  sizek[ps]++;
}

int least(bitset<30> x) {
  int pc = 1, pk = 1;
  bitset<30> ans;
  for(int i=29; i>=0; i--) {
    //printf("sizes: %d %d\n", sizec[pc], sizek[pk]);
    sizec[pc]--; sizek[pk]--;
    int c = (int) x[i];

    //printf("%d ", c);
    if(c == 1) {
      pc = goc(pc, 1);
      int go = gok(pk, 1);
      if(sizek[go] > 0) {
        //printf("1\n");
        pk = gok(pk, 1), ans[i] = 1; 
      }
      else {
        //printf("0\n");
        pk = gok(pk, 0), ans[i] = 0;
      }
    }

    else {
      pc = goc(pc, 0);
      int go = gok(pk, 0);
      if(sizek[go] > 0) {
        //printf("0\n");
        pk = gok(pk, 0), ans[i] = 0;
      }
      else {
        //printf("1\n");
        pk = gok(pk, 1), ans[i] = 1;
      }
    }
  }
  sizec[pc]--; sizek[pk]--;

  int ret = 0;
  for(int i=29; i>=0; i--) {
    int c = x[i] ^ ans[i];
    ret += c << i;
  }
  return ret;
}

void printc(bitset<30> x) {
  int ps = 1;
  for(int i=29; i>=0; i--) {
    printf("%d ", ps);
    ps = goc(ps, x[i]);
  }
  printf("%d\n", ps);
}

void printk(bitset<30> x) {
  int ps = 1;
  for(int i=29; i>=0; i--) {
    printf("%d ", ps);
    ps = gok(ps, x[i]);
  }
  printf("%d\n", ps);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int u; scanf("%d", &u);
    a[i] = bitset<30>(u);
  }

  for(int i=0; i<n; i++) {
    int u; scanf("%d", &u);
    p[i] = bitset<30>(u);
  }

  for(int i=0; i<n; i++) {
    addchar(a[i]);
    addkey(p[i]);
  }

  for(int i=0; i<n; i++) {
    printf("%d ", least(a[i]));
  }
  printf("\n");

	return 0;
}

