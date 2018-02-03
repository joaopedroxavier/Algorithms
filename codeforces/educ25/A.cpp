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

bool isUp(char a){ return a <='Z' and a >= 'A'; }

int volume(string s){
  int v = 0;
  for(char c : s) if(isUp(c)) v++;
  return v;
}

int ans = 0;

int main(){
	ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  while(1){
    string text;
    cin >> text;
    if(cin.eof()){
      cout << ans << endl;
      break;
    }
    ans = max(ans, volume(text));
  }
	return 0;
}

