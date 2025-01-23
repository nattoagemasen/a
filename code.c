#include <stdio.h>

#define LEN_NAME 17
#define BOARD_W 3
#define BOARD_H 3

typedef struct {
    int num_play;           /* 対戦数 */
    int num_player1_win;    /* Player1の勝利数 */
    int num_player2_win;    /* Player2の勝利数 */
    int num_draw;           /* 引き分け数 */
    double ave_player1_win; /* Player1の勝率 */
    double ave_player2_win; /* Player2の勝率 */
    char player1[LEN_NAME]; /* Player1の名前 */
    char player2[LEN_NAME]; /* Player2の名前 */
} PLAYDATA;

void print_board(int board[BOARD_H][BOARD_W]);

int main(void) {
    PLAYDATA a;
    printf("Enter Player1's name (max. 16 chars): ");
    scanf("%s", a.player1);
    printf("Enter Player2's name (max. 16 chars): ");
    scanf("%s", a.player2);
    printf("\n%s vs %s\n", a.player1, a.player2);
    int board[BOARD_H][BOARD_W] = {{0, 1, -1}, {0, -1, 1}, {0, 0, 0}};
    print_board(board);
    return 0;
}

void print_board(int board[BOARD_H][BOARD_W]) {
    for (int h = 0; h < BOARD_H; ++h) {
        fputc('|', stdout);
        for (int w = 0; w < BOARD_W; ++w) {
            switch (board[h][w]) {
                case 0:
                    printf(" |");
                    break;
                case 1:
                    printf("o|");
                    break;
                case -1:
                    printf("x|");
                    break;
            }
        }
        fputc('\n', stdout);
    }
}
