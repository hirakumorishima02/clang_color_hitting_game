#include <stdio.h>
#include <stdlib.h>

void discard_inputs();
char get_trial_char(void);

int main(void){
    char q1 = 'R';
    char q2 = 'G';
    char q3 = 'B';
    char q4 = 'Y';

    printf("【色当てゲーム】\n");
    printf("ゲームを始めてください。\n");
    printf("コンピュータが問題を出題しました。\n");

    int i;

    for(i=0;i<10;i++){
        printf("予想を入力してください。\n");

        char t1 = get_trial_char();
        char t2 = get_trial_char();
        char t3 = get_trial_char();
        char t4 = get_trial_char();

        discard_inputs();

        int matched=0;

        if(q1 == t1) matched++;
        if(q2 == t2) matched++;
        if(q3 == t3) matched++;
        if(q4 == t4) matched++;

        if(matched==4) {
            puts("全問正解です。");
            break;
        }

        puts("結果は…");
        printf("%d個正解です。\n",matched);
    }

    if(i==10) puts("ゲーム終了です。");

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