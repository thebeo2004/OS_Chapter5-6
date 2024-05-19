#include <bits/stdc++.h>
#include "Optimal.h"
#include "FIFO.h"
#include "LRU.h"
#include "LFU.h"
#include "MFU.h"
#include "SecondChance.h"

using namespace std;

vector<int> seq_references;

void get_references() {
    int x;

    while(cin >> x) {
        seq_references.push_back(x);
    }
}

void Working_Set(vector<int> seq_references, int delta, int index) {
    
    index-= 1;

    set<int> storage;
    vector<int> v;

    ff(i, index - delta + 1, index) {
        
        int ref = seq_references[i];

        if (!storage.count(ref)) {
            storage.insert(ref);
            v.push_back(ref);
        }
    }

    sort(v.begin(), v.end());

    cout << "Working Set: ";

    for(auto i : v) {
        cout << i << " ";
    }
}

void solve() {

    get_references();

    //Number of frames
    int frames = 4;

    // Optimal_Algorithm(seq_references, frames);

    //First In First Out
    // FIFO_Algorithm(seq_references, frames);

    //Least Recently Used
    // LRU_Algorithm(seq_references, frames);

    //Least Frequently Used
    // LFU_Algorithm(seq_references, frames);

    //Most Frequently Used
    // MFU_Algorithm(seq_references, frames);

    //Second Chance Algorithm
    int pointer = 1;
    SecondChance_Algorithm(seq_references, frames, pointer);

    // int delta = 10;
    // int index = 20;
    // Working_Set(seq_references, delta, index);

}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0);

    freopen("References.inp", "r", stdin);
    freopen("Result.out", "w", stdout);

    solve();


    return 0;
}