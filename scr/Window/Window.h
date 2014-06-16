/*

Programmer: Heihachi

*/

#ifndef WINDOW_
#define WINDOW_

#include <ncurses.h>
#include <ctime>
#include <cstdio>

using namespace std;

class Curses
{
    public:
        Curses() { startProcess(); }
        ~Curses() { }
        bool startProcess();
        bool drawBorders(WINDOW*);

};

#endif
