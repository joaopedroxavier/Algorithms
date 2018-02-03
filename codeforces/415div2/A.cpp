//
//
//
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

ll n, k, sum, ans;
double av;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> k;
  av = k-0.5;
  for(int i=0;i<n;++i){
    int u;
    cin >> u;
    sum += u;
  }
  while((double)sum/n < av){
    sum += k;
    n++;
    ans++;
  }
  cout << ans << endl;
	return 0;
}

