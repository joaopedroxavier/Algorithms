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

vector<int> a, b;
int n, m;
int ans1 = INF, ans2 = INF;
int hasa[N], hasb[N];

int main(){
  scanf("%d %d", &n, &m);
  
  for(int u, i=0; i<n; i++) {
    scanf("%d", &u);
    a.pb(u);
    ans1 = min(ans1, u);
    hasa[u] = 1;
  }
  for(int u, i=0; i<m; i++) {
    scanf("%d", &u);
    b.pb(u);
    ans2 = min(ans2, u);
    hasb[u] = 1;
  }

  for(int i=1; i<=9; i++) if(hasa[i] and hasb[i]) return printf("%d\n", i), 0;

  printf("%d%d\n", min(ans1,ans2), max(ans1,ans2));

	return 0;
}

