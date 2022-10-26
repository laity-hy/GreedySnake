//
// Created by HongYing on 2022/10/19.
//

#include <cstdio>
#include <windows.h>

void SetWindowSize(int cols, int lines) {
    /*system("title laity");
    char cmd[30];
    sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);
    system(cmd);*/
    COORD coord;
    coord.X = cols * 2;
    coord.Y = lines;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetCursorPosition(const int x, const int y) {
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}

void SetCursorNoVisible() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO consoleCursorInfo;
    GetConsoleCursorInfo(handle, &consoleCursorInfo);
    consoleCursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &consoleCursorInfo);
}