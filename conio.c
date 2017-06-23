#include "conio.h"

static struct termios old, new;
/**
	@file conio.c
*/
/**
	@brief Initialize new terminal i/o settings
	@param int echo
	@return void
 */
void initTermios(int echo) {
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    new = old; /* make new settings same as old settings */
    new.c_lflag &= ~ICANON; /* disable buffered i/o */
    new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
    tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/**
	@brief Restore old terminal i/o settings
	@return void
 */
void resetTermios(void) {
    tcsetattr(0, TCSANOW, &old);
}

/**
	@brief Read 1 character - echo defines echo mode
	@param int echo
	@return char ch
 */
char getch_(int echo) {
    char ch;
    initTermios(echo);
    ch = getchar();
    if(ch == '\x1b') {
        if(getchar()=='[') {
            switch(getchar()) {
            case 'A':
                ch = '8';
                break;
            case 'B':
                ch = '2';
                break;
            case 'C':
                ch = '6';
                break;
            case 'D':
                ch = '4';
                break;
            }
        }
    }
    resetTermios();
    return ch;
}

/**
	@brief Read 1 character without echo
	@return char getch_(0)
 */
char getch(void) {
    return getch_(0);
}

/**
	@brief Read 1 character with echo 
	@return char getch_(1)
*/
char getche(void) {
    return getch_(1);
}
