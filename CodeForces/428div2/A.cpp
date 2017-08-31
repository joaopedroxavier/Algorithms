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

int arya = 0, bran = 0;
int day[N];
int n, k;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for(int i=0;i<n;++i){
    cin >> day[i];
    arya += day[i];
    bran += min(8, arya);
    arya -= min(8, arya);
    if(bran >= k){
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
	return 0;
}

