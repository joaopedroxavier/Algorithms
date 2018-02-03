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

string transf(int n) {
  string ans;
  while(n) {
    ans.pb(n%10 + 'a');
    n /= 10;
  }
  return ans;
}

int num;

int main(){
  scanf("%d", &num);

  while(num%10 == 0) num /= 10;

  string s = transf(num);
  string t = s;
  reverse(t.begin(), t.end());
  printf("%s\n", t == s ? "YES" : "NO");

	return 0;
}

