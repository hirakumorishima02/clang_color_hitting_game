#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void discard_inputs();
char get_trial_char(void);
void chg_display_title(void);
void chg_make_question(char qx[]);
int chg_play_turn(char qx[]);
int chg_check_result(int);
void color_hitting_game(void);

const char color_array[] = {'R','G','B','Y','M','C'};
const int color_num = sizeof(color_array) / sizeof(color_array[0]);
const int q_size = 4;

int main(void){
    color_hitting_game();
    return 0;
}

// 不要な文字を捨てる関数
void discard_inputs() {
    for(;;){
        if(getchar()=='\n') break;
    }
    return;
}

// 選択肢以外の文字を入力したら入力処理を繰り返す関数
char get_trial_char(void) {
    char ch;
    int i;

    for(;;) {
        ch = getchar();
        for(i=0;i<color_num;i++){
            if(ch == color_array[i]) return ch;
        }
    }
}

void chg_display_title(void) {
    printf("【色当てゲーム】\n");
    printf("ゲームを始めてください。\n");
    return;
}

void chg_make_question(char qx[]) {
    int i;

    srand((unsigned)time(NULL));
    for(i=0;i<q_size;i++){
        char color_num = rand()%6;
        qx[i] = color_array[color_num];
    }
    printf("コンピュータが問題を出題しました。\n");
    for(i=0;i<q_size;i++){
        printf("%c", qx[i]);
    }
    puts("");
    return;
}

int chg_play_turn(char qx[]) {
    char t1,t2,t3,t4;
    char tx[] = {t1,t2,t3,t4};
    int i, matched=0;

    for(i=0;i<q_size;i++){
        tx[i] = get_trial_char();
    }

    discard_inputs();

    for(i=0;i<q_size;i++){
        if(qx[i] == tx[i]) matched++;
    }

    return matched;
}

int chg_check_result(int matched) {
    int result = 0;
    if(matched==q_size) {
        result = 1;
    }
    return result;
}

void color_hitting_game(void) {
    char q1,q2,q3,q4;
    char qx[] = {q1,q2,q3,q4};
    int turn;
    const int max_turn = 10;

    chg_display_title();
    chg_make_question(qx);

    for(turn=1;turn<=max_turn;turn++){
        printf("予想を入力してください。(%d回目)\n", turn);
        int matched = chg_play_turn(qx);

        if(chg_check_result(matched)) {
            puts("全問正解です。");
            break;
        }
        printf("%d個正解です。\n",matched);
        if(turn==10) {puts("ゲーム終了です。"); printf("答えは%C%C%C%Cでした。\n", qx[0],qx[1],qx[2],qx[3]);};
    }

    return;
}