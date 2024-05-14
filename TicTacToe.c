#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char empty = ' ',
cross = 'X',
circle = 'O';

void create_board(char*** pboard) {
    char** tmp = (char**)malloc(sizeof(char*) * 3);
    for (int i = 0; i < 3; i++) {
        tmp[i] = (char*)malloc(sizeof(char) * 3);
    }
    *pboard = tmp;
}

void free_board(char*** pboard) {
    for (int i = 0; i < 3; i++) {
        free((*pboard)[i]);
        (*pboard)[i] = NULL;
    }
    free(*pboard);
    *pboard = NULL;
}

void reset_board(char*** pboard) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            (*pboard)[i][j] = empty;
        }
    }
}

void display_board(char*** pboard) {
    printf("      A     B     C\n");
    for (int row = 0; row < 3; row++) {
        printf("   -------------------\n");
        printf("%d ", row + 1);
        for (int col = 0; col < 3; col++) {
            printf(" | ");
            printf(" %c ", (*pboard)[row][col]);
        }
        printf(" |\n");
    }
    printf("   -------------------\n");
}

char check_winner(char*** pboard) {
    char symbol = empty;

    for (int i = 0; i < 3; i++) {
        if ((*pboard)[i][0] == (*pboard)[i][1] && (*pboard)[i][1] == (*pboard)[i][2] && (*pboard)[i][0] != empty) {
            symbol = (*pboard)[i][0];
            if (symbol != empty) return symbol;
        } else 
            if ((*pboard)[0][i] == (*pboard)[1][i] && (*pboard)[1][i] == (*pboard)[2][i] && (*pboard)[0][i] != empty){
                symbol = (*pboard)[0][i];
                if (symbol != empty) return symbol;
            }
    }

    if ((*pboard)[0][0] == (*pboard)[1][1] && (*pboard)[1][1] == (*pboard)[2][2] && (*pboard)[0][0] != empty) {
        symbol = (*pboard)[0][0];
        if (symbol != empty) return symbol;
    } else 
    if ((*pboard)[0][2] == (*pboard)[1][1] && (*pboard)[1][1] == (*pboard)[2][0] && (*pboard)[0][2] != empty) {
        symbol = (*pboard)[0][2];
        if (symbol != empty) return symbol;
    }

    /*if (winner_found) {
        printf("Player %c won. Congratulations!\n", winner_symbol);
    }
    else {
        printf("Draw! No winner found\n");
    }*/
    return symbol;
}

void scan_choice(int* prow, int* pcol, char*** pboard) {
    char tmp[3];
    printf("Choose a cell (ex. A1)\n");
    scanf_s("%s", tmp,3);
    getchar();
    printf("You chose %s\n", tmp);
    *prow = atoi(&tmp[1]) - 1;
    *pcol = (int)tmp[0] - 65;
    if ((*pboard)[*prow][*pcol] != empty) {
        printf("This cell already has a symbol. Try again\n");
        printf("Press [Enter]\n");
        getchar();
        scan_choice(prow, pcol, pboard);
    }
    if (*pcol >= 0 && *pcol < 3 && *prow >= 0 && *prow < 3) {
        //printf("scan_choice()\ncolumn: %d\nrow: %d\n", *pcol, *prow);
    }
    else {
        printf("You chose wrong cell. Try again\n");
        printf("Press [Enter]\n");
        getchar();
        scan_choice(prow, pcol, pboard);
    }
}

void match(char*** pboard) {
    int row = 0;
    int col = 0;
    int step = 0;
    
    while (step < 9) {
        system("cls");
        display_board(pboard);
        if (step % 2 == 0) {
            printf("Time for X\n");
        }
        else {
            printf("Time for O\n");
        }
        scan_choice(&row, &col, pboard);
        //printf("match()\nRow: %d\nColumn: %d\n", row, col);
        if (step % 2 == 0) {
            if ((*pboard)[row][col] == empty)
                (*pboard)[row][col] = cross;
        }
        else {
            if ((*pboard)[row][col] == empty)
                (*pboard)[row][col] = circle;
        }
        if (step >= 4) {
            char symbol = check_winner(pboard);
            if (symbol != empty) {
                system("cls");
                display_board(pboard);
                printf("Player %c won. Congratulations!\n", symbol);
                printf("Press [Enter] to continue\n");
                getchar();
                return;
            }
        }
        system("cls");
        display_board(pboard);
        if (step < 8) {
            printf("Press [Enter] for next step\n");
        }
        else {
            printf("Press [Enter] to finish\n");
        }
        getchar();
        step++;
    }
    char symbol = check_winner(pboard);
    if (symbol == empty) {
        printf("Draw! No winner found\n");
    }
    else {
        printf("Player %c won. Congratulations!\n", symbol);
    }
}

int main() {
    char** board = NULL;
    create_board(&board);
    
    bool play = true;
    int player_choice;
    while (play) {
        system("cls");
        reset_board(&board);
        printf("Tic Tac Toe\n");
        printf("1. Play with other player\n");
        printf("0. Exit\n");
        scanf_s("%d", &player_choice);

        switch (player_choice) {
        case 1:
            match(&board);
            break;
        case 0:
            printf("Closing the program\n");
            return 0;
            break;
        default:
            printf("You chose wrong number\n");
            getchar();
            getchar();
            break;

        }
    }


    display_board(&board);

    free_board(&board);
    return 0;
}