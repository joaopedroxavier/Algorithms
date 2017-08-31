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

int main(){
	ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  cout << 2*((n-1)/k) + min(2, (n-1)%k) << endl;
  for(int i=2;i<=n;++i){
    if(i <= k+1) cout << 1 _ i << endl;
    else cout << i _ i-k << endl;
  }
	return 0;
}

