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

int l, r, u, d;
int n;
string s;

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n >> s;
  for(char c : s) {
    if(c == 'L') l++;
    if(c == 'R') r++;
    if(c == 'U') u++;
    if(c == 'D') d++;
  }

  printf("%d\n", 2*(min(u,d) + min(l,r)));

	return 0;
}

