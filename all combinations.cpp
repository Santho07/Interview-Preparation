#include <iostream>
#include <algorithm>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n=5, r;

    vector<bool> v(5);
    string vowel = "aeiou";
    for(int k=1; k<=5; k++){
        fill(v.begin(), v.begin() + k, true);
        do {
            string s;
            for (int i = 0; i <5; ++i) {
                if (v[i]) {
                    s+=vowel[i];
                }
            }
            sort(s.begin(), s.end());
            std::cout <<s<<"\n";
        } while (std::prev_permutation(v.begin(), v.end()));

        fill(v.begin(), v.end(), false);
    }
    return 0;
}
