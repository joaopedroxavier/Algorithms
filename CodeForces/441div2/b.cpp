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

map<int, vector<int>> p;
int n, k, m;

int main(){
  scanf("%d %d %d", &n, &k, &m);

  for(int i=0; i<n; i++) {
    int u;
    scanf("%d", &u);
    p[u%m].pb(u);
  }

  for(auto q : p) if((int) q.second.size() >= k) {
    vector<int> v = q.second;
    printf("Yes\n");
    for(int i=0; i<k; i++) printf("%d ", v[i]);
    printf("\n");
    return 0;
  }

  printf("No\n");

	return 0;
}

