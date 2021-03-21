#include <bits/stdc++.h>

using namespace std;

#ifdef Sia
#define deb(...)    do{fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);_out(__VA_ARGS__);}while(0);
template<typename T>                 void _out(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S>  void _out(T &&x, S &&...y){cerr<<x<<", ";_out(y...);}
template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename It>            ostream& _out_it(ostream &os, It ita, It itb) {
	os << "{"; for(It it = ita; it != itb; ++it) os << (it == ita ? "" : ", ") << *it; os << "}";
	return os; }
template<typename T, typename S> ostream& operator << (ostream &os, map<T, S> &m){return _out_it(os, m.begin(), m.end());}
template<typename T>             ostream& operator << (ostream &os, set<T>    &s){return _out_it(os, s.begin(), s.end());}
template<typename T>             ostream& operator << (ostream &os, vector<T> &v){return _out_it(os, v.begin(), v.end());}
template<typename T>                 void debit(T a, T b){_out_it(cerr, a, b); cerr << endl;}
#define INITIO()    cout<<setprecision(numeric_limits<double>::max_digits10+1);
#else
#define deb(...)
#define debit(...)
#define endl        '\n'
#define INITIO()    ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<setprecision(numeric_limits<double>::max_digits10+1);
#endif
#define MEM(i,j) 	memset(i,j,sizeof i);
#define X           first
#define Y           second
#define pb          push_back
#define mp          make_pair
#define ALL(a)      a.begin(),a.end()
typedef				long long ll;
typedef				pair<ll,ll> pii;
const double Eps  = 1e-8;
const ll Inf      = 1e18+7;
const int Mod     = 1e9+7;
// -----------------------------------------------------------------------------------------------------------------------------------

const ll MAXN = 107;


string intToRoman(int num) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string result = "", romans[] = {"m", "cm", "d", "cd", "c", "xc", "l", "xl", "x", "ix", "v", "iv", "i"};
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            num -= values[i];
            result += romans[i];
        }
    }
    return result;
}


int main(){
	string readFileName,tmpFileName;
	
	cout<<"輸入需要複製的檔案的檔案名稱: ";
	cin>>readFileName;
	 
	cout<<"輸入欲產生的檔案的前綴名稱: ";
	cin>>tmpFileName;
	 
	int f,e;
	cout<<"需要輸出多少個檔案(?~?): ";
	cin>>f>>e;
	
	string s;
	cout<<"後綴字符(須包含檔名): ";
	cin>>s;
	
	for(int i=f;i<=e;i++){
		string writeFileName;
		
		writeFileName=tmpFileName;
		writeFileName+=intToRoman(i);
		writeFileName+=s;
		cout<<writeFileName<<endl;
		ifstream in(readFileName.c_str(),ios::binary);
		ofstream out(writeFileName.c_str(),ios::binary);
	
		out<<in.rdbuf();
	}
}

