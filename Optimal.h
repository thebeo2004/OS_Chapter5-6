#pragma once

#include "CommonFunc.h"

int find_victim(vector<int> seq_references, vector<int> MEM, int id) {

        int frames = MEM.size();

        if (frames == 1) {
            return MEM[0];
        }

        vector<bool> flag(frames, 0);

        ff(i, id + 1, int(seq_references.size()) - 1) {

            int ref = seq_references[i];

            int x = check_existence(MEM, ref);

            if (x > -1 && !flag[x]) {
                flag[x] = true;
                frames--;
            }

            if (frames == 1) {
                break;
            }
        }

        ff(i, 0, int(MEM.size()) - 1) {
            if (!flag[i]) {
                return i;
            }
        }

        return -1;
    }

void Optimal_Algorithm(vector<int> seq_references, int frames) {

        int page_fault = 0;

        vector<int> MEM, page_replacement;

        cout << "Page Replacement: ";

        ff(i, 0, int(seq_references.size()) - 1) {

            // cout << i << "-th interaction: \n";

            int ref = seq_references[i];

            if (check_existence(MEM, ref) != -1) {
                // continue;
            } else {
                page_fault += 1;

                if (MEM.size() < frames) {
                    MEM.push_back(ref);
                } else {
                    int victim = find_victim(seq_references, MEM, i);

                    // cout << "victim: " << MEM[victim] << "\n";
                    cout << MEM[victim] << " ";

                    MEM.erase(MEM.begin() + victim);

                    MEM.push_back(ref);
                }
            }

            // cout << "MEM: ";
            // for (auto k : MEM) {
            //     cout << k << " ";
            // }
            // cout << "\n";
        }

        cout << "\nPage Faults: " << page_fault;
        cout << "\nHits: " << seq_references.size() - page_fault;
}
