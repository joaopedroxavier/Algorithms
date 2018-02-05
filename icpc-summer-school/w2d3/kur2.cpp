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
const int N=5e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, v[N];
map<int, vector<int>> s;

bool test(int l, int r, int x) {
  int ans = upper_bound(s[x].begin(), s[x].end(), r) - lower_bound(s[x].begin(), s[x].end(), l);
  return ans > (r-l+1)/2;
}

int main(){
  srand(time(0));
  scanf("%d %d", &n, &m);

  for(int i=1; i<=n; i++) {
    scanf("%d", v+i);
    s[v[i]].pb(i);
  }

  for(int i=0; i<m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);

    bool found = false;
    for(int i=0; i<50; i++) {
      int guess = l + rand()%(r-l+1);
      if(test(l, r, v[guess])) {
        found = true;
        printf("%d\n", v[guess]);
        break;
      }
    }
    if(!found) printf("0\n");
  }

	return 0;
}

