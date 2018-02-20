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
int ans[N];
char s[N];

bool check(int k) {
  memset(v, 0, sizeof v);

  for(int i=1; i<=n; i++) {
    if(s[i-1] == 'P') v[i%k] = 1;
  }

  for(int i=0; i<k; i++) if(!v[i]) return true;
  return false;
}

int main(){
  
  while(scanf("%s", s) != EOF) {
    memset(ans, 0, sizeof ans);
    n = (int) strlen(s);

    bool trv = true;
    for(int i=0; i<n; i++) trv = trv and (s[i] == 'R');
    if(trv) printf("%d\n", n-1);
    else {
      for(ll i=1; i < n; i++) if(n%i == 0 and check(i)) {
        ans[i] = 1;
        for(ll j=2*i; j < n; j+=i) ans[j] = 1;
      }
      int cnt = 0;
      for(int i=0; i<n; i++) {
        cnt += ans[i];
      }
      printf("%d\n", cnt);
    }
  }

	return 0;
}

