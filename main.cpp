#include <bits/stdc++.h>
#include "Optimal.h"
#include "FIFO.h"
#include "LRU.h"
#include "LFU.h"

using namespace std;

vector<int> seq_references;

void get_references() {
    int x;

    while(cin >> x) {
        seq_references.push_back(x);
    }
}

void solve() {

    get_references();

    int frames = 3;

    // Optimal_Algorithm(seq_references, frames);
    // FIFO_Algorithm(seq_references, frames);
    // LRU_Algorithm(seq_references, frames);
    // LFU_Algorithm(seq_references, frames);

}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0);

    freopen("References.inp", "r", stdin);
    freopen("Result.out", "w", stdout);

    solve();


    return 0;
}