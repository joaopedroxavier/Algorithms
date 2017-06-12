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

struct pt{
  int x;
  int y;
};

int ans, bl, br, n;
pt p[N];

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i=0;i<n;++i) cin >> p[i].x >> p[i].y;
  sort(p, p+n, [](pt a, pt b){ return a.y > b.y; } );
  for(int i=0;i<n;++i){
    bl = -INF, br = INF;
    for(int j=i+1;j<n;++j){
      if(p[j].x < p[i].x and p[j].x > bl) ans++, bl = p[j].x;
      else if(p[j].x > p[i].x and p[j].x < br) ans++, br = p[j].x;
    }
  }

  cout << ans << endl;
  
	return 0;
}

