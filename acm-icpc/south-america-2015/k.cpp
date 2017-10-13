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

int n, m;
int e[N], limit[N];
vi s[N], c[N];

int main(){
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++) s[i].pb(0), c[i].pb(INF);

  for(int i=1; i<=n; i++) scanf("%d", &e[i]);

  for(int i=0; i<m; i++) {
    int l, st, ct;

    scanf("%d %d %d", &l, &st, &ct);
    s[l].pb(st), c[l].pb(ct);
  }


	return 0;
}

