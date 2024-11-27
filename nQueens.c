#include <stdio.h>

int row[8], s = 0; 

int safe(int x, int y) {
    for (int i = 0; i < y; i++) {
        if (row[i] == x || row[i] == x - (y - i) || row[i] == x + (y - i)) {
            return 0;
        }
    }
    return 1; 
}

void putBoard() {
    printf("\nSolution #%d", ++s);
    printf("\n -----------------------\n");
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (row[y] == x) {
                printf("| Q");
            } else {
                printf("|  ");
            }
        }
        printf("|\n -----------------------\n");
    }
}

void queen(int y) {
      if (y == 8) { 
        putBoard();
        return;
    }
    for (int x = 0; x < 8; x++) {
        if (safe(x, y)) { 
            row[y] = x;
            queen(y + 1);
        }
    }
}

int main() {
    queen(0);
    return 0;
}
