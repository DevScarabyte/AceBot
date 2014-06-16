
#include "Window.h"

bool Curses::startProcess()
{
    initscr();
    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    keypad(stdscr,TRUE);
//    srand(time(NULL));

    // Coloring the screen
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_RED); // border
    init_pair(2, COLOR_GREEN, COLOR_GREEN); // barrier
    init_pair(3, COLOR_GREEN, COLOR_BLACK); // player
    init_pair(4,   COLOR_RED, COLOR_BLACK); // boss

    int parent_x = 0, parent_y = 0, new_x = 0, new_y = 0, input_size = 3;
    // set up initial windows
    getmaxyx(stdscr, parent_y, parent_x);
    int temp1, temp2;
    //printf("X: %i Y: %i\n", parent_x, parent_y);
    WINDOW *output = newwin(parent_y - input_size, parent_x, 0, 0);
    //WINDOW *input = newwin(input_size, parent_x, parent_y - input_size, 0);
    int x=0,y=0,i=0;
    getmaxyx(output, y, x);

    for(i;i<x;x++)
    {
        wmove(stdscr, 0, i);
        waddch(stdscr, 'A');
    }
//    this->drawBorders(output);
//    drawBorders(input);
    while(1)
    {
       for(i;i<x;x++)
        {
            wmove(output, 0, i);
            waddch(output, 'A');
        }
    }
    return true;
}

bool Curses::drawBorders(WINDOW *screen)
{
    int x=0,y=0,i=0;
    getmaxyx(screen, y, x);
    printf("X: %i Y: %i", x, y);
    /*// corners
    wmove(screen, 0, 0);
    waddch(screen, '+' | COLOR_PAIR(1));
    wmove(screen, y-1, 0);
    waddch(screen, '+' | COLOR_PAIR(1));
    wmove(screen, 0, x-1);
    waddch(screen, '+' | COLOR_PAIR(1));
    wmove(screen, y-1, x-1);
    waddch(screen, '+' | COLOR_PAIR(1));

    // sides
    for (i = 1; i < (y - 1); i++)
    {
        wmove(screen, i, 0);
        waddch(screen, '|' | COLOR_PAIR(1));
        wmove(screen, i, x-1);
        waddch(screen, '|' | COLOR_PAIR(1));
    }

    // top and bottom
    for (i = 1; i < (x - 1); i++)
    {
        wmove(screen, 0, i);
        waddch(screen, '-' | COLOR_PAIR(1));
        wmove(screen, y-1, i);
        waddch(screen, '-' | COLOR_PAIR(1));
    }*/
}

