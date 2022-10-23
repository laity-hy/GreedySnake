//
// Created by HongYing on 2022/10/20.
//

#include "StartInterface.h"
#include <windows.h>

StartInterface::StartInterface() {
    speed = 35;//设置动画速度
    startsnake.emplace_back(Point(0, 14));
    startsnake.emplace_back(Point(1, 14));
    startsnake.emplace_back(Point(2, 15));
    startsnake.emplace_back(Point(3, 16));
    startsnake.emplace_back(Point(4, 17));
    startsnake.emplace_back(Point(5, 18));
    startsnake.emplace_back(Point(6, 17));
    startsnake.emplace_back(Point(7, 16));
    startsnake.emplace_back(Point(8, 15));
    startsnake.emplace_back(Point(9, 14));

    textsnake.emplace_back(Point(-26, 14));//S
    textsnake.emplace_back(Point(-25, 14));
    textsnake.emplace_back(Point(-27, 15));
    textsnake.emplace_back(Point(-26, 16));
    textsnake.emplace_back(Point(-25, 17));
    textsnake.emplace_back(Point(-27, 18));
    textsnake.emplace_back(Point(-26, 18));

    textsnake.emplace_back(Point(-23, 14));//N
    textsnake.emplace_back(Point(-23, 15));
    textsnake.emplace_back(Point(-23, 16));
    textsnake.emplace_back(Point(-23, 17));
    textsnake.emplace_back(Point(-23, 18));
    textsnake.emplace_back(Point(-22, 15));
    textsnake.emplace_back(Point(-21, 16));
    textsnake.emplace_back(Point(-20, 17));
    textsnake.emplace_back(Point(-19, 14));
    textsnake.emplace_back(Point(-19, 15));
    textsnake.emplace_back(Point(-19, 16));
    textsnake.emplace_back(Point(-19, 17));
    textsnake.emplace_back(Point(-19, 18));

    textsnake.emplace_back(Point(-17, 18));//A
    textsnake.emplace_back(Point(-16, 17));
    textsnake.emplace_back(Point(-15, 16));
    textsnake.emplace_back(Point(-14, 15));
    textsnake.emplace_back(Point(-14, 16));
    textsnake.emplace_back(Point(-13, 14));
    textsnake.emplace_back(Point(-13, 16));
    textsnake.emplace_back(Point(-12, 15));
    textsnake.emplace_back(Point(-12, 16));
    textsnake.emplace_back(Point(-11, 16));
    textsnake.emplace_back(Point(-10, 17));
    textsnake.emplace_back(Point(-9, 18));

    textsnake.emplace_back(Point(-7, 14));//K
    textsnake.emplace_back(Point(-7, 15));
    textsnake.emplace_back(Point(-7, 16));
    textsnake.emplace_back(Point(-7, 17));
    textsnake.emplace_back(Point(-7, 18));
    textsnake.emplace_back(Point(-6, 16));
    textsnake.emplace_back(Point(-5, 15));
    textsnake.emplace_back(Point(-5, 17));
    textsnake.emplace_back(Point(-4, 14));
    textsnake.emplace_back(Point(-4, 18));

    textsnake.emplace_back(Point(-2, 14));//E
    textsnake.emplace_back(Point(-2, 15));
    textsnake.emplace_back(Point(-2, 16));
    textsnake.emplace_back(Point(-2, 17));
    textsnake.emplace_back(Point(-2, 18));
    textsnake.emplace_back(Point(-1, 14));
    textsnake.emplace_back(Point(-1, 16));
    textsnake.emplace_back(Point(-1, 18));
    textsnake.emplace_back(Point(0, 14));
    textsnake.emplace_back(Point(0, 16));
    textsnake.emplace_back(Point(0, 18));
}

void StartInterface::PrintFirst() {
    for (auto &point: startsnake) {
        point.Print();
        Sleep(speed);
    }
}

void StartInterface::PrintSecond() {
    for (int i = 10; i < 40; ++i) {
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
        startsnake.emplace_back(Point(i, j));
        startsnake.back().Print();
        startsnake.front().Clear();
        startsnake.pop_front();
        Sleep(speed);
    }

}

void StartInterface::PrintThird() {
    while (!startsnake.empty() || textsnake.back().getX() < 33) {//当蛇还没有消失或文字没移动到指定位置
        if (!startsnake.empty()) {
            startsnake.front().Clear();
            startsnake.pop_front();
        }
        ClearText();//清除已有的文字
        PrintText();//绘制更新位置后的文字
        Sleep(speed);
    }
}

void StartInterface::PrintText() {
    for (auto &point: textsnake) {
        if (point.getX() >= 0) {
            point.Print();
        }
    }
}

void StartInterface::ClearText() {
    for (auto &point: textsnake) {//清除的同时将文字整体右移动一格
        if (point.getX() >= 0) {
            point.Clear();
        }
        point.ChangePosition(point.getX() + 1, point.getY());
    }
}

void StartInterface::Action() {
    PrintFirst();
    PrintSecond();
    PrintThird();
}
