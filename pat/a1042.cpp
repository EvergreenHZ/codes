#include "../include/common.h"
using namespace std;

const char table[55][4] = {"0", "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "J1", "J2"};

void print_cards(vector<int> &cards) {
        for (int i = 1; i <= 54; i++) {
                if (i == 54) {
                        printf("%s\n", table[cards[i]]);
                        return;
                }
                printf("%s ", table[cards[i]]);
        }
}

void shuffle_cards(vector<int> &cards, vector<int> &order) {
        vector<int> tmp = cards;
        for (int i = 1; i < cards.size(); i++) {
                cards[order[i]] = tmp[i];
        }
        //print_cards(cards);
        return ;
}

int main() {
        int repeat_times;
        vector<int> order;
        vector<int> initial_cards;
        order.push_back(-1);
        scanf("%d", &repeat_times);
        for (int i = 1; i <= 54; i++) {
                int t;
                scanf("%d", &t);
                order.push_back(t);
        }

        for (int i = 0; i <= 54; i++) {
                initial_cards.push_back(i);
        }

        for (int i = 1; i <= repeat_times; i++) {
                shuffle_cards(initial_cards, order);
        }
        print_cards(initial_cards);
        return 0;
}
