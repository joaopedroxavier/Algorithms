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
const int N=3e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll x[N], pot[N], n;
ll sum, ans;

void to_pos(){
  if(ans < 0) ans = ans + MOD;
  if(sum < 0) sum = sum + MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i=0;i<n;++i) cin >> x[i];

  pot[1]=1;
  for(int i=2;i<=n;++i) pot[i] = (pot[i-1]*2) % MOD;
  x[n] = 0;
  sort(x, x+n+1);
  sum += x[1];

  for(int i=2;i<=n;++i){
    ans = (ans + (((x[i] * pot[i]) % MOD) - sum) % MOD) % MOD;
    ans = (ans - x[i]) % MOD;
    sum = (sum * 2) % MOD;
    sum = (sum + x[i]) % MOD;
    to_pos();
  }

  cout << ans << endl;
	return 0;
}

