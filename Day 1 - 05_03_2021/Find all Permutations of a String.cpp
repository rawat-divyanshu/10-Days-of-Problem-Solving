#include <bits/stdc++.h>
using namespace std;

void permute(char str[100], int i) {
    // Base Case
    if(str[i] == '\0') {
        cout << str << endl;
        return;
    }

    // Recursive Case
    for(int j = i; str[j] != '\0'; j++) {
        swap(str[i],str[j]);
        permute(str,i+1);
        swap(str[i],str[j]);
    }
}

int main() {
    char str[100];
    cin >> str;
    permute(str,0);
    return 0;
}
