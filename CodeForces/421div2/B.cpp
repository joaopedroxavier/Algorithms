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
  int n, a;
  cin >> n >> a;
  int ans, dist = INF;
  for(int i=2;i<n;++i){
    int d = i-1;
//    cerr << (double)d*360/(double)n << endl;
//    cerr << d*360 - a*n << endl;
    if(abs(d*360-a*2*n) < dist) ans = i+1, dist = abs(d*360-a*2*n);
  }
  cout << 2 _ 1 _ ans << endl;
	return 0;
}

