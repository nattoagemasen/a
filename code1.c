#include <stdio.h>  //三目並べ（○×ゲーム）

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
void mark_board(int board[3][3],
                int turn);  // 対戦者に基づいてマスへ入力を行なう関数
void print_board(
    int board[BOARD_H]
             [BOARD_W]);  // boardに格納されている盤の状態を表示する関数

int main(void) {
    PLAYDATA a;
    int i;
    printf("Enter Player1's name (max. 16 chars): ");//プレイヤー名の入力と出力
    scanf("%s", a.player1);
    printf("Enter Player2's name (max. 16 chars): ");
    scanf("%s", a.player2);
    printf("\n%s vs %s\n\n", a.player1, a.player2);
    int board[BOARD_H][BOARD_W] = {0}, turn;

    for (i = 0; i < 9; i++) {  // 9試合する
        turn = i % 2 == 0 ? 1 : -1;
        mark_board(board, turn);
        print_board(board);
    }
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
void mark_board(int board[3][3], int turn) {
    int v, h;
    printf("Player%c's turn (%c)\n", turn == 1 ? '1' : '2',
           turn == 1 ? 'o' : 'x');
    while (1) {
        printf("What is the vertical position? ");
        scanf("%d", &v);
        printf("What is the horizontal position? ");
        scanf("%d", &h);
        if (v >= 0 && v <= 2 && h >= 0 && h <= 2) {
            if (board[v][h] == 0) break;
        }
        printf("Cannot put there\n");
    }
    board[v][h] = turn;
}
