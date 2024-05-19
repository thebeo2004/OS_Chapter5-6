#pragma once

#include "CommonFunc.h"



int find_victim(vector<int> count) {

    int MIN = INF;

    for (auto i : count) {
        MIN = min(i, MIN);
    }

    ff(i, 0, int(count.size()) - 1) {
        if (count[i] == MIN) {
            return i;
        }
    }

    return -1;
}

void LFU_Algorithm(vector<int> seq_references, int frames) {
    int page_fault = 0;

    vector<int> MEM, count;

    cout << "Page Replacement: ";

    ff(i, 0, int(seq_references.size()) - 1) {

        int ref = seq_references[i];

        if (check_existence(MEM, ref) != -1) {
            count[check_existence(MEM, ref)] += 1;
        } else {
            page_fault += 1;

            if (MEM.size() < frames) {
                MEM.push_back(ref);
                count.push_back(1);
            } else {
                int victim = find_victim(count);

                cout << MEM[victim] << " ";

                MEM.erase(MEM.begin() + victim);
                count.erase(count.begin() + victim);

                MEM.push_back(ref);
                count.push_back(1);
            }
        }
    }

    cout << "\nPage Faults: " << page_fault;
    cout << "\nHits: " << seq_references.size() - page_fault;
}