#include <stdio.h>
#include <stdlib.h>

void discard_inputs();
char get_trial_char(void);
void chg_display_title(void);
void chg_make_question(char qx[]);
int chg_play_turn(char qx[]);
int chg_check_result(int);
void color_hitting_game(void);


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

    for(;;) {
        ch = getchar();
        if(ch == 'R'||ch == 'G'||
           ch == 'B'||ch == 'Y'||
           ch == 'M'||ch == 'C')
            return ch;
        }
}

void chg_display_title(void) {
    printf("【色当てゲーム】\n");
    printf("ゲームを始めてください。\n");
    return;
}

void chg_make_question(char qx[]) {
    qx[0] = 'R';
    qx[1] = 'G';
    qx[2] = 'B';
    qx[3] = 'Y';
    printf("コンピュータが問題を出題しました。\n");
    return;
}

int chg_play_turn(char qx[]) {
    char t1 = get_trial_char();
    char t2 = get_trial_char();
    char t3 = get_trial_char();
    char t4 = get_trial_char();

    discard_inputs();

    int matched=0;

    if(qx[0] == t1) matched++;
    if(qx[1] == t2) matched++;
    if(qx[2] == t3) matched++;
    if(qx[3] == t4) matched++;

    return matched;
}

int chg_check_result(int matched) {
    int result = 0;
    if(matched==4) {
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
        if(turn==10) puts("ゲーム終了です。");
    }

    return;
}