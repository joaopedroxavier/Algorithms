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

char shift(char c){ return (c == 'a') ? 'z' : c-1; }

int main(){
	ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();

  for(int i=0;i<n;i++){
    if(s[i] > shift(s[i])){
      while(s[i] > shift(s[i]) and i < n) s[i] = shift(s[i]), i++;
      break;
    }
    if(i == n-1) s[i] = shift(s[i]);
  }

  cout << s << endl;
	return 0;
}

