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

ll n, a[N];
ll m[3];
ll mi, cont;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i=0;i<n;++i) cin >> a[i];
  sort(a, a+n);
  mi = a[0];
  for(int i=0;i<n;++i){
    if(a[i] != mi) cont++;
    if(cont > 2) break;
    m[cont]++;
    mi = a[i];
  }
  if(m[0] == 3) cout << 1 << endl;
  else if(m[0] > 3) cout << m[0]*(m[0]-1)*(m[0]-2)/6 << endl;
  else if(m[0] + m[1] == 3) cout << 1 << endl;
  else if(m[0] + m[1] > 3) cout << m[0]*m[1] << endl;
  else cout << m[0] * m[1] * m[2] << endl;
	return 0;
}

