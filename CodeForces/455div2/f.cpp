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

int n, v[N];
int p[N];

int main(){
  scanf("%d", &n);

  if(n&1) printf("NO\n");
  else {
    printf("YES\n");
    for(int i=1; i<=n; i++) v[i] = i;

    int p = 1;
    while(p <= n) p *= 2;
    p /= 2;
    int p1 = p-1, p2 = p, lim = n;
    while(p1 > 0) {
      while(p2 <= lim and p1 > 0) {
        swap(v[p1], v[p2]);
        p1--; p2++;
      }
      lim = p1;
      int q = 1;
      while(q <= lim) q *= 2;
      q /= 2;
      p1 = q-1; p2 = q;
    }
    for(int i=1; i<=n; i++) printf("%d ", v[i]);
    printf("\n");
  }

  if(n <= 5) printf("NO\n");
  else if(n == 6) {
    printf("YES\n3 6 2 5 1 4\n");
  }
  else if(n == 7) {
    printf("YES\n7 3 6 5 1 2 4\n");
  }
  else {
    for(int p=0; (1<<p) <= n; p++) if(n == (1<<p)) return printf("NO\n"), 0;
    for(int i=1; i<=n; i++) v[i] = i;

    vector<int> aux(n+1);
    aux[1] = 7, aux[2] = 3, aux[3] = 6, aux[4] = 5, aux[5] = 1;
    aux[6] = 2, aux[7] = 4;
    for(int p=3; (1<<p) <= n; p++) {
      int lim = min((1<<(p+1))-1, n);
      aux[(1<<p)] = v[lim];
      for(int i=(1<<p)+1; i<=lim; i++) {
        aux[i] = v[i-1];
      }
    }
    printf("YES\n");
    for(int i=1; i<=n; i++) printf("%d ", aux[i]);
    printf("\n");
  }

  return 0;
}

