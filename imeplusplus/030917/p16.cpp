//
//	P16 - Letter Frequency
//	Judge: URI
//	source: https://www.urionlinejudge.com.br/judge/pt/problems/view/1255
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

const int N=1e2;

int freq[N];
int main(){
	int n, m=0;
	char a[26];
	char c;
	scanf("%d ", &n);
	for(char m='a';m<='z';++m) a[(int)m-'a'] = m;
	for(int i=0;i<n;++i){
		while(~scanf("%c", &c)){
			if((int)c <= (int)'z' and (int)c >= (int)'a'){
				freq[(int)c-(int)'a']++;
				m = max(m,freq[(int)c-(int)'a']);
			}
			if((int)c <= (int)'Z' and (int)c >= (int)'A'){
				freq[(int)c-(int)'A']++;
				m = max(m,freq[(int)c-(int)'A']);
			}
			if(c=='\n'){
				for(int j=0;j<26;++j) if(freq[j] == m) cout << a[j];
				cout << endl;
				m=0;
				for(int j=0;j<26;++j) freq[j]=0;
			}
		}
	}
	return 0;
}

