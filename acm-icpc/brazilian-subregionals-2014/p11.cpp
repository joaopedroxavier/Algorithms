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

int az[N];

int main(){
  ios_base::sync_with_stdio(false);
  int c, n;
  cin >> c >> n;

  for(int i=0;i<n;++i){
    int a;
    cin >> a;
    az[a+1] = 1;
  }

  for(int i=1;i<=c;++i) az[i] += az[i-1];

  int slice = c/n;
  bool ans = false;
  for(int i=1;i<=slice;++i){
    bool can = true;
    for(int j=0;j<n-1;++j) {
      int s1 = az[i+(j+1)*slice-1];
      int s2 = az[i+(j)*slice-1];
      if(s1 - s2 != 1) can = false;
    }
    if(can) ans = true;
  }

  cout << ((ans) ? "S" : "N") << endl;
  return 0;
}

