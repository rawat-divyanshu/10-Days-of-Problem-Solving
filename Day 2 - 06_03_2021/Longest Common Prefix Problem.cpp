// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(int n, vector<string> words) {
    if(n == 0) return "";

    string prefix = words[0];

    for(int i = 1; i < n; i++) {
        string tempPrefix = "";
        for(int j = 0; j < min(prefix.length(),words[i].length()); j++) {
            if(prefix[j] == words[i][j]) {
                tempPrefix += prefix[j];
                continue;
            }
            break;
        }
        prefix = tempPrefix;
        if(prefix == "") return prefix;

    }
    return prefix;
}

int main() {
    int n;
    cin >> n;
    vector<string> words;

    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }
    
    cout << longestCommonPrefix(n,words) << endl;
    return 0;
}