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

string s, t;
vi ans;
int mi = INF;

int main(){
	ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  cin >> s >> t;
  for(int i=0;i<=m-n;++i){
    int cont=0;
    vi swt;
    for(int j=0;j<n;++j){
      if(s[j] != t[i+j]) cont++, swt.pb(j+1);
    }
    if(cont < mi) mi = cont, ans = swt;
  }
  cout << mi << endl;
  for(int i : ans) cout << i << ' ';
  cout << endl;
	return 0;
}

