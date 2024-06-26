#pragma once

#include "CommonFunc.h"

int MFU_find_victim(vector<int> count) {

    int MAX = -INF;

    for (auto i : count) {
        MAX = max(i, MAX);
    }

    ff(i, 0, int(count.size()) - 1) {
        if (count[i] == MAX) {
            return i;
        }
    }

    return -1;
}

void MFU_Algorithm(vector<int> seq_references, int frames) {
    int page_fault = 0;

    vector<int> MEM, count, page_faults;

    cout << "Page Replacement: ";

    ff(i, 0, int(seq_references.size()) - 1) {

        int ref = seq_references[i];

        if (check_existence(MEM, ref) != -1) {
            count[check_existence(MEM, ref)] += 1;
        } else {
            page_fault += 1;
            page_faults.push_back(ref);

            if (MEM.size() < frames) {
                MEM.push_back(ref);
                count.push_back(1);
            } else {
                int victim = MFU_find_victim(count);

                cout << MEM[victim] << " ";

                MEM.erase(MEM.begin() + victim);
                count.erase(count.begin() + victim);

                MEM.push_back(ref);
                count.push_back(1);
            }
        }
    }

    pagefaults_display(page_faults);
    cout << "Page Faults: " << page_fault;
    cout << "\nHits: " << seq_references.size() - page_fault;
}