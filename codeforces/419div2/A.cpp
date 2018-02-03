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

ii clk;
int ans;

ii next(ii t){
  int hh = t.first;
  int mm = t.second;
  if(++mm == 60){
    mm = 0;
    hh = (hh + 1) % 24;
  }
  return mp(hh,mm);
}

bool is_pal(ii t){
  int hh = t.first;
  int mm = t.second;
  int h1 = hh/10, h2 = hh%10;
  int m1 = mm/10, m2 = mm%10;
  return h1 == m2 and m1 == h2;
}

int main(){
	ios_base::sync_with_stdio(false);
  char c;
  cin >> clk.first >> c >> clk.second;
  while(!is_pal(clk)) ans++, clk = next(clk);
  cout << ans << endl;
	return 0;
}

