//
//	(A - Interview with Oleg)
//	Codeforces Round #380 Div.2 (Based on Technocup 2017 - Elimination Round 2)
//	source:	http://codeforces.com/contest/738/problem/A
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e6;

int main(){
	string speech, ans, filler = "ogo";
	int n;
	cin >> n;
	cin >> speech;
	int p=0;
	while(strlen(speech.c_str())){
		if(speech.find(filler)){
			ans = ans + speech[0];
			speech.erase(0,1);
		}
		else{
			ans = ans + "***";
			p+=1;
			while(!speech.find(filler)){
				filler=filler+"go";
				p+=2;
			}
			speech.erase(0,p);
			p=0;
			filler="ogo";
		}
	}
	cout << ans << endl;
	return 0;
}

