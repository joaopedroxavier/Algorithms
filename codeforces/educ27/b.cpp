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

string s;
int sum1, sum2;
int v[6];

int main(){
  cin >> s;
  for(int i=0; i<3; i++) {
    sum1 += s[i] - '0';
    v[i] = s[i] - '0';
  }
  for(int i=3; i<6; i++) {
    sum2 += s[i] - '0';
    v[i] = s[i] - '0';
  }

  int ans = INF;
  for(int i=0; i<1000000; i++) {
    int s1 = 0, s2 = 0, n = i;
    int cost = 0;
    for(int j=0; j<6; j++) {
      int u = n%10;
      if(u != v[5-j]) cost++;

      if(j < 3) s2 += u;
      else s1 += u;

      n/=10;
    }
    if(s1 == s2) ans = min(ans, cost);
  }

  printf("%d\n", ans);

	return 0;
}

