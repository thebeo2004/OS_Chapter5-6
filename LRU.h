#pragma once

#include "CommonFunc.h"

int find_victim(vector<int> timer, int offset) {

    int MIN = INF, ans = 0;

    ff(i, 0, int(timer.size()) - 1) {

        if (timer[i] < MIN) {
            MIN = timer[i];
            ans = i;
        }
    }

    return ans;
}

void LRU_Algorithm(vector<int> seq_references, int frames) {
    int page_fault = 0;

    vector<int> MEM, timer, page_faults;

    cout << "Page Replacement: ";

    ff(i, 0, int(seq_references.size()) - 1) {
        int ref = seq_references[i];

        if (check_existence(MEM, ref) != -1) {
            timer[check_existence(MEM, ref)] = i;
        } else {
            page_fault += 1;
            page_faults.push_back(ref);

            if (MEM.size() < frames) {
                MEM.push_back(ref);
                timer.push_back(i);
            } else {

                int victim = find_victim(timer, 2);

                cout << MEM[victim] << " ";

                MEM.erase(MEM.begin() + victim);
                timer.erase(timer.begin() + victim);

                MEM.push_back(ref);
                timer.push_back(i);
            }
        }
    }

    pagefaults_display(page_faults);
    cout << "Page Faults: " << page_fault;
    cout << "\nHits: " << seq_references.size() - page_fault;
}