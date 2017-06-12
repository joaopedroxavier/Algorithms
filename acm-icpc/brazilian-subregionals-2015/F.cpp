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

int f[N], n, ans;
void factorials(){
  f[0] = 1;
  for(int i=1;i<10;++i) f[i] = i*f[i-1];
}

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n;
  factorials();

  for(int i=9;i>=0;--i){
    if(f[i] > n) continue;
    else ans += n/f[i], n = n%f[i];
  }

  cout << ans << endl;
	return 0;
}

