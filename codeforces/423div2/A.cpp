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

int n, ans;
int a, b, c;

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n >> a >> b;
  for(int i=0;i<n;++i){
    int u;
    cin >> u;
    if(u == 1){
      if(a) a--;
      else if(b) b--, c++;
      else if(c) c--;
      else ans += 1;
    }
    if(u == 2){
      if(b) b--;
      else ans += 2;
    }
  }

  cout << ans << endl;

  return 0;
}

