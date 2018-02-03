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
const int N=2e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

map<int, int> counter;
int n, k;
int a[N], b[N], dp[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin >> k >> n;
  for(int i=0;i<k;++i) cin >> a[i];
  for(int i=0;i<n;++i) cin >> b[i];

  for(int i=k-1;i>=0;--i) dp[i] = a[i] + dp[i+1];
  for(int i=0;i<n;++i){
    map<int, int> vis;
    for(int j=1;j<=k;++j){
      int sum = b[i]+dp[j];
      if(!vis[sum]){
        if(counter[sum] == i) counter[sum]++, vis[sum]=1;
        else counter.erase(sum);
      }
    }
  }

  int ans = 0;
  for(auto it : counter) if(it.second == n){
    ans++;
  }

  cout << ans << endl;
  return 0;
}

