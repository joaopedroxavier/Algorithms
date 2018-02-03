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

bool isvowel(char c){ return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'; }

int main(){
	ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  vector<bool> typo(s.size());

  int cont = 0;
  set<char> streak;
  for(int i=0; i<(int)s.size(); i++){
    if(!isvowel(s[i])) cont++, streak.insert(s[i]);
    else cont = 0, streak.clear();
    if(cont >= 3 and streak.size() > 1){
      typo[i] = true, cont = 1;
      streak.clear();
      streak.insert(s[i]);
    }
  }

  for(int i=0; i<(int)s.size(); i++){
    if(typo[i]) printf(" ");
    printf("%c", s[i]);
  }
  printf("\n");

	return 0;
}

