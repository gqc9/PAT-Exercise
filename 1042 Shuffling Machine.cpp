/*
 * 模拟洗牌
 *  */

#include <cstdio>

struct Card {
    char c;
    int num;
};

int main() {
    freopen("1.txt","r",stdin);
    const int cardnum = 55;
    int time;
    scanf("%d", &time);
    Card* cards[cardnum];
    for (int i=1, tmp=0; i<cardnum; i++) {
        cards[i] = new Card;
        if (tmp==0) cards[i]->c = 'S';
        else if (tmp==1) cards[i]->c = 'H';
        else if (tmp==2) cards[i]->c = 'C';
        else if (tmp==3) cards[i]->c = 'D';
        else cards[i]->c = 'J';

        cards[i]->num = (i-1) % 13 + 1;
        if (cards[i]->num == 13) tmp++;
    }
    int init[cardnum];
    for (int i=1; i<cardnum; i++) {
        init[i] = i;
    }
    int input[cardnum];
    for (int i=1; i<cardnum; i++) {
        scanf("%d", &input[i]);
    }

    for (int i=0; i<time; i++) {
        int after[cardnum];
        for (int j=1; j<cardnum; j++) {
            after[input[j]] = init[j];
        }

        for (int k=1; k<cardnum; k++) {
            init[k] = after[k];
        }
    }

    for (int k=1; k<cardnum; k++) {
        printf("%c%d", cards[init[k]]->c, cards[init[k]]->num);
        if (k!=cardnum-1) printf(" ");
    }

    return 0;
}