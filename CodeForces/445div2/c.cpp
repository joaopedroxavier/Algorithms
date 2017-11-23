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
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n;
int t[N];
set<int> last;

int main(){
  scanf("%d", &n);

  last.insert(0);
  for(int i=1; i<=n; i++) {
    int u;
    scanf("%d", &u);
    if(last.count(u)) {
      last.erase(u);
    }
    last.insert(i);
  }
  
  printf("%d\n", (int) last.size());

	return 0;
}

