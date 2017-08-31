#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ld r, d;
int n, ans;

ld dist(ld x, ld y){ return sqrt(x*x + y*y); }

bool check(ld x, ld y, ld z){
  return (dist(x,y) - z - (r - d)) > -EPS and (dist(x,y) + z - (r) < EPS);
}

int main(){
  scanf("%Lf %Lf", &r, &d);
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    ld x, y, z;
    scanf("%Lf %Lf %Lf", &x, &y, &z);
    if(check(x,y,z)) ans++;
  }
  cout << ans << endl;
	return 0;
}

