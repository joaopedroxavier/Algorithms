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

const int N = 3e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, x1, x2, c[N], ord[N];
vector<int> f1, f2, ans1, ans2;
vector<int> r1, r2;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d", &n, &x1, &x2);

  for(int i=0; i<n; i++) scanf("%d", &c[i]), ord[i] = i;
  sort(ord, ord+n, [](int i, int j) { return c[i] < c[j]; });
  sort(c, c+n);

  for(int i=1; i<=n; i++) {
    int num = (x1 + i - 1)/i;
    int it = lower_bound(c, c+n, num) - c;
    /*
    printf("1 there are %d numbers above %d\n", n-it, num);
    printf("1 but i need %d\n", i);
    */
    f1.push_back(it);

    if(i <= n-it) ans1.push_back(1);
    else ans1.push_back(0);
  }

  for(int i=1; i<=n; i++) {
    int num = (x2 + i - 1)/i;
    int it = lower_bound(c, c+n, num) - c;
    /*
    printf("2 there are %d numbers above %d\n", n-it, num);
    printf("2 but i need %d\n", i);
    */
    f2.push_back(it);

    if(i <= n-it) ans2.push_back(1);
    else ans2.push_back(0);
  }

  r1.resize(n);
  r2.resize(n);

  int last = -1;
  for(int i=0; i<n; i++) {
    if(ans1[i] == 1) last = i;
    r1[i] = last;
  }
  last = -1; 
  for(int i=0; i<n; i++) {
    if(ans2[i] == 1) last = i;
    r2[i] = last;
  }

  /*
  for(int i : r1) printf("%d ", i);
  printf("\n");
  for(int i : r2) printf("%d ", i);
  printf("\n");
  for(int i : ans1) printf("%d ", i);
  printf("\n");
  for(int i : ans2) printf("%d ", i);
  printf("\n");
  */

  for(int i=1; i<=n; i++) {
    int p = i-1;
    if(r1[p] == -1) continue;

    int f = f1[p] + i;
    //printf("%d %d %d\n", i, (x1+i-1)/i, f1[p] + i);
    if(f >= n) continue;
    else {
      //printf("my index is %d\n", f);
      //printf("checking if there's an answer below than %d\n", n-f);
      if(r2[n-f-1] != -1) {
        printf("Yes\n");
        printf("%d %d\n", i, r2[n-f-1]+1);

        for(int j=f1[p]; j<f1[p]+i; j++) {
          printf("%d ", ord[j]+1);
        }
        printf("\n");
        for(int j=n-r2[n-f-1]-1; j<n; j++) {
          printf("%d ", ord[j]+1);
        }
        printf("\n");
        return 0;
      }
    }
  }

  for(int i=1; i<=n; i++) {
    int p = i-1;
    if(r2[p] == -1) continue;

    int f = f2[p] + i;
    //printf("%d %d %d\n", i, (x1+i-1)/i, f2[p] + i);
    if(f >= n) continue;
    else {
      //printf("my index is %d\n", f);
      //printf("checking if there's an answer below than %d\n", n-f);
      if(r1[n-f-1] != -1) {
        printf("Yes\n");
        printf("%d %d\n", r1[n-f-1]+1, i);

        for(int j=n-r1[n-f-1]-1; j<n; j++) {
          printf("%d ", ord[j]+1);
        }
        printf("\n");

        for(int j=f2[p]; j<f2[p]+i; j++) {
          printf("%d ", ord[j]+1);
        }
        printf("\n");
        return 0;
      }
    }
  }

  printf("No\n");
  /*
  for(int i=0; i<n; i++) {
    int it = upper_bound(f1.begin(), f1.end(), c[i]) - f1.begin();
    if(it != s1) p1[it]--;

    int jt = upper_bound(f2.begin(), f2.end(), c[i]) - f2.begin();
    if(jt != s2) p2[jt]--;
  }

  p1[0] += n;
  p2[0] += n;

  for(int i=1; i<s1; i++) p1[i] += p1[i-1];
  for(int i=1; i<s2; i++) p2[i] += p2[i-1];
  */

	return 0;
}

