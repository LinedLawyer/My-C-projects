#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int tower1[5] = {1, 2, 3, 4, 5};
int tower2[5] = {0, 0, 0, 0, 0};
int tower3[5] = {0, 0, 0, 0, 0};

void printASCIIboard() {
    int i;
    for (i = 0; i < 5; i++) {
        switch (tower1[i]) {
            case 0:
                printf("     |0|     \t");
                break;
            case 1:
                printf("    @|1|@    \t");
                break;             
            case 2:
                printf("   @@|2|@@   \t");
                break;
            case 3:
                printf("  @@@|3|@@@  \t");
                break;
            case 4:
                printf(" @@@@|4|@@@@ \t");
                break;
            case 5:
                printf("@@@@@|5|@@@@@\t");
                break;
        }
        switch (tower2[i]) {
            case 0:
                printf("     |0|     \t");
                break;
            case 1:
                printf("    @|1|@    \t");
                break;             
            case 2:
                printf("   @@|2|@@   \t");
                break;
            case 3:
                printf("  @@@|3|@@@  \t");
                break;
            case 4:
                printf(" @@@@|4|@@@@ \t");
                break;
            case 5:
                printf("@@@@@|5|@@@@@\t");
                break;
        }
        switch (tower3[i]) {
            case 0:
                printf("     |0|     \t");
                break;
            case 1:
                printf("    @|1|@    \t");
                break;             
            case 2:
                printf("   @@|2|@@   \t");
                break;
            case 3:
                printf("  @@@|3|@@@  \t");
                break;
            case 4:
                printf(" @@@@|4|@@@@ \t");
                break;
            case 5:
                printf("@@@@@|5|@@@@@\t");
                break;
        }
        printf("\n");
    }
        printf("      A      \t      B      \t      C\n");
}

int search(int tower[]) {
    int i;
    for (i = 0; i < 5; i++) {
        if (tower[i] != 0) {
            return i;
        }
    }
    return -1;
}

int Move(char *move) {
    int i;
    int index, tindex;
    switch (move[0]) {
        case 'A':
            index = search(tower1);
            switch (move[1]) {
                case 'B':
                    tindex = search(tower2);
                    
                    if (tindex == -1) {
                        tower2[4] = tower1[index];
                        tower1[index] = 0;
                        return 1;                        
                    } else {
                        if (tower2[tindex] < tower1[index]) {
                            printf("Can only place smaller disks on disks.\n");
                            return 0;
                        }
                        tower2[tindex-1] = tower1[index];
                        tower1[index] = 0;
                        return 1;                        
                    }
                case 'C':
                    tindex = search(tower3);
                    if (tindex == -1) {
                        tower3[4] = tower1[index];
                        tower1[index] = 0;
                        return 1;                        
                    } else {
                        if (tower3[tindex] < tower1[index]) {
                            printf("Can only place smaller disks on disks.\n");
                            return 0;
                        }
                        tower3[tindex-1] = tower1[index];
                        tower1[index] = 0;
                        return 1;                        
                    }   
                default:
                    return 0;
            }
        case 'B':
            index = search(tower2);
            switch (move[1]) {
                case 'A':
                    tindex = search(tower1);
                    if (tindex == -1) {
                        tower1[4] = tower2[index];
                        tower2[index] = 0;
                        return 1;                        
                    } else {
                        if (tower1[tindex] < tower2[index]) {
                            printf("Can only place smaller disks on disks.\n");
                            return 0;
                        }
                        tower1[tindex-1] = tower2[index];
                        tower2[index] = 0;
                        return 1;                        
                    }
                case 'C':
                    tindex = search(tower3);
                    if (tindex == -1) {
                        tower3[4] = tower2[index];
                        tower2[index] = 0;
                        return 1;                        
                    } else {
                        if (tower3[tindex] < tower2[index]) {
                            printf("Can only place smaller disks on disks.\n");
                            return 0;
                        }
                        tower3[tindex-1] = tower2[index];
                        tower2[index] = 0;
                        return 1;                        
                    }   
                default:
                    return 0;
            }
        case 'C':
            index = search(tower3);
            switch (move[1]) {
                case 'A':
                    tindex = search(tower1);
                    if (tindex == -1) {
                        tower1[4] = tower3[index];
                        tower3[index] = 0;
                        return 1;                        
                    } else {
                        if (tower1[tindex] < tower3[index]) {
                            printf("Can only place smaller disks on disks.\n");
                            return 0;
                        }
                        tower1[tindex-1] = tower3[index];
                        tower3[index] = 0;
                        return 1;                        
                    }
                case 'B':
                    tindex = search(tower2);
                    if (tindex == -1) {
                        tower2[4] = tower3[index];
                        tower3[index] = 0;
                        return 1;                        
                    } else {
                        if (tower2[tindex] < tower3[index]) {
                            printf("Can only place smaller disks on disks.\n");
                            return 0;
                        }
                        tower2[tindex-1] = tower3[index];
                        tower3[index] = 0;
                        return 1;                        
                    }   
                default:
                    return 0;
            }
        default:
            return 0;
    }
}

int getMove() {
    char move[1000];
    gets(move);
    if (move[0] == 'Q') {
        printf("Thanks for playing!");
        exit(1);
    }
    if (!Move(move)) {
        printf("Try again. Valid moves are: AB, AC, BA, BC, CA, CB. Case Sensitive\n");
        return 0;
    }
    return 1;
}

int main (int arc,char *argv[]) {
    bool gameEnd = false;
    int i = 0;
    int comp = 0;
    int moves = 0;
    printf("Welcome to Towers Of Hanoi by Galen Heinze\nTo play, enter the letter of the 'from' tower, and the 'to' tower.\nYou cannot stack a smaller disk on a larger disk.\nTo win stack all the disks in order from smallest to largest, top to bottom, in tower 'C'. Enter 'Q' to quit. ENJOY!\n\n");
    while (gameEnd == false) {
        printASCIIboard();
        if(getMove()) {
            moves++;
        }
        for (i = 0; i < 5; i++) {
            if (tower3[i] == i + 1) {
                comp++;
            }
        }
        if (comp == 5) {
            printASCIIboard();
            printf("Good job! You figured it out in %d moves!", moves);
            exit(1);
        }
        comp = 0;
    }
}
