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

int n, k;
set<int> b;
int a[N];
bool ans = false;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for(int i=0;i<n;++i) cin >> a[i];
  for(int i=0;i<k;++i){
    int u;
    cin >> u;
    b.insert(-u);
  }
  for(int i=0;i<n;++i) if(!a[i]){
    a[i] = -(*(b.begin()));
    b.erase(b.begin());
  }
  for(int i=0;i<n;++i) if(a[i] < a[i-1]) ans = true;
  
  cout << ((ans) ? "Yes" : "No") << endl;
	return 0;
}

