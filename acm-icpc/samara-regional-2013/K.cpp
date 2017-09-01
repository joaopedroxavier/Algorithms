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

ll n, tgt;
ll p[N];

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> tgt;
  int l = 1, r = n;
  for(int i=n;i>0;i--){
    if(i-1 <= tgt) p[i] = l, l++, tgt -= i-1;
    else p[i] = r, r--;
  }
  for(int i=1;i<=n;i++) printf("%lld ", p[i]);
  printf("\n");
	return 0;
}
