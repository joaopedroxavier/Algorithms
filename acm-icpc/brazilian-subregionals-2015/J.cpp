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
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int pt[N], ans;

int main(){
	ios_base::sync_with_stdio(false);
  int j, r;
  cin >> j >> r;

  for(int i=0;i<j*r;++i){
    int p;
    cin >> p;
    pt[i%j]+=p;
  }
  
  for(int i=0;i<j;++i) if(pt[ans] <= pt[i]) ans = i;
  cout << ans+1 << endl;

	return 0;
}

