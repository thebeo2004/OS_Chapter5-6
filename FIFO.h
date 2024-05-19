#pragma once

#include "CommonFunc.h"

void FIFO_Algorithm(vector<int> seq_references, int frames) {

    int page_fault = 0;

    vector<int> MEM;

    cout << "Page Replacement: ";

    ff(i, 0, int(seq_references.size()) - 1) {

        int ref = seq_references[i];

        if (check_existence(MEM, ref) != -1) {
                // continue;
        } else {
            page_fault += 1;

            if (MEM.size() < frames) {
                MEM.push_back(ref);
            } else {
                
                int victim = 0;

                // cout << "victim: " << MEM[victim] << "\n";
                cout << MEM[victim] << " ";

                MEM.erase(MEM.begin() + victim);

                MEM.push_back(ref);

            }
        }
    }

    cout << "\nPage Faults: " << page_fault;
    cout << "\nHits: " << seq_references.size() - page_fault;
    
}