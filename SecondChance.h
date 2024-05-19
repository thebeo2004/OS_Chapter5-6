#pragma once

#include "CommonFunc.h"

vector<int> bit;

void find_victim(int &pointer) {

    int length = bit.size();

    while(true) {
        if (bit[pointer] == 0) {
            break;
        } else {
            bit[pointer] = 0;
            pointer = (pointer + 1) % length;
        }
    }
}

void SecondChance_Algorithm(vector<int> seq_references, int frames, int pointer) {
    int page_fault = 0;
    pointer -= 1;

    vector<int> MEM, page_faults;

    cout << "Page Replacement: ";

    ff(i, 0, int(seq_references.size()) - 1) {
        int ref = seq_references[i];

        if (check_existence(MEM, ref) != -1) {
            bit[check_existence(MEM, ref)] = 1;
        } else {
            page_fault += 1;
            page_faults.push_back(ref);

            if (MEM.size() < frames) {
                MEM.push_back(ref);
                bit.push_back(0);
            } else {

                find_victim(pointer);
                
                cout << MEM[pointer] << " ";

                MEM[pointer] = ref;
            }
        }
    }

    pagefaults_display(page_faults);
    cout << "Page Faults: " << page_fault;
    cout << "\nHits: " << seq_references.size() - page_fault;
}