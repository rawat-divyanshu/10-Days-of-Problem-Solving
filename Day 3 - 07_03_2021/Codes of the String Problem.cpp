// Take as input str, a string. Assume that value of a=1, b=2, c=3, d=4, …. z=26. Write a recursive function (return type Arraylist) to print all possible codes for the string. E.g. for “1123” possible codes are aabc, kbc, alc, aaw, kw.

// Input Format
// Enter a number

// Constraints
// None

// Output Format
// Display all the possible codes

#include<bits/stdc++.h>
using namespace std;

vector<string> res;

void generateStringCodes(string str, string out, int i, int n) {
	// Base Case
	if(i > n) return;
	if(i == n) {
		res.push_back(out);
	}

	// Recursive Case
	if((int)str[i] != 0) {
		char ch1 = (int)str[i] + 48;
		generateStringCodes(str,out+ch1,i+1,n);
	}
	if(i < n-1 && stoi(str.substr(i,2)) <= 26) {
		char ch2 = stoi(str.substr(i,2)) + 96;
		generateStringCodes(str,out+ch2,i+2,n);
	}
}

int main() {
	string str;
	cin >> str;
	generateStringCodes(str,"",0,str.length());
	int n = res.size();
	for(int i = 0; i < n; i++) {
        cout << res[i] << " ";
	}
	return 0;
}