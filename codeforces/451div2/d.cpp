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
const int N=2e5+5;
const int M=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, k;
int t[M];

int main(){
  scanf("%d %d %d", &n, &m, &k);

  for(int i=0; i<n; i++) {
    int u;
    scanf("%d", &u);
    t[u]++;
  }

  int c = 0;
  int ans = 0;

  for(int i=0; i<m; i++) {
    c += t[i];
    if(c >= k) {
      c--;
      t[i] = 0;
      ans++;
    }
  }

  for(int i=m; i<M; i++) {
    c += t[i];
    c -= t[i-m];
    if(c >= k) {
      c--;
      t[i] = 0;
      ans++;
    }
  }

  printf("%d\n", ans);

	return 0;
}

