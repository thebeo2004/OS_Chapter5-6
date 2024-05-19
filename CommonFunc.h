#pragma once

#include <bits/stdc++.h>

using namespace std;

#define ff(i, a, b) for(int i = a; i <= int(b); i++)
#define Rep(i,a, b) for(int i = a; i >= int(b); i--)

const int INF = 1e9 + 7;

int check_existence(vector<int> v, int value) {

    ff(i, 0, int(v.size()) - 1) {
        if (value == v[i]) {
            return i;
        }
    }

    return -1;
}

void pagefaults_display(vector<int> v) {
    cout << "\nPage Faults: ";

    for (auto i : v) {
        cout << i << " ";
    }
    cout << "\n";
}