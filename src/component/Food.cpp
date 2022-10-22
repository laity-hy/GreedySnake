//
// Created by HongYing on 2022/10/19.
//

#include "Food.h"
#include "../utils/Tools.h"
#include <cstdlib>
#include <iostream>

Food::Food() {
    cnt = 0;
    flash_flag = false;
    big_flag = false;
    x = 0, y = 0;
    big_x = 0, big_y = 0;
    progress_bar = 0;
}

void Food::DrawFood(Snake &snake) {
    /*
     * ����rand������ȡ���꣬�����䷶Χ������2-29�ڣ����ڵ�ͼ�ڣ������ȡ�������������ص��������»�ȡ��ͬʱÿ5��ʳ��ͳ���һ����ʱʳ��
     */
    while (true) {
        int tmp_x = rand() % 30;
        int tmp_y = rand() % 30;
        if (tmp_x < 2) tmp_x += 2;
        if (tmp_y < 2) tmp_y += 2;
        bool flag = false;
        for (auto &point: snake.snake) {
            if ((point.getX() == tmp_x && point.getY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y)) {
                flag = true;
                break;
            }
        }
        if (flag)continue;
        x = tmp_x;
        y = tmp_y;
        SetCursorPosition(x, y);
        SetColor(13);
        std::cout << "��";
        ++cnt;
        cnt %= 5;
        if (cnt == 0) {
            DrawBigFood(snake);
        }
        break;
    }
}

void Food::DrawBigFood(Snake &snake) {
    SetCursorPosition(5, 0);
    SetColor(11);
    std::cout << "------------------------------------------";
    progress_bar = 42;
    while (true) {
        int tmp_x = rand() % 30;
        int tmp_y = rand() % 30;
        if (tmp_x < 2) tmp_x += 2;
        if (tmp_y < 2) tmp_y += 2;
        bool flag = false;
        for (auto &point: snake.snake) {
            if ((point.getX() == tmp_x && point.getY() == tmp_y) || (tmp_x == x && tmp_y == y)) {
                flag = true;
                break;
            }
        }
        if (flag)continue;
        big_x = tmp_x;
        big_y = tmp_y;
        SetCursorPosition(big_x, big_y);
        SetColor(18);
        std::cout << "��";
        big_flag = true;
        flash_flag = true;
        break;
    }
}

void Food::FlashBigFood() {
    SetCursorPosition(big_x, big_y);
    SetColor(18);
    if (flash_flag) {
        std::cout << "  ";
        flash_flag = false;
    } else {
        std::cout << "��";
        flash_flag = true;
    }
    SetCursorPosition(26, 0);
    SetColor(11);
    for (int i = 42; i >= progress_bar; --i) {
        std::cout << "\b \b";
    }
    --progress_bar;
    if (progress_bar == 0) {
        SetCursorPosition(big_x, big_y);
        std::cout << "  ";
        big_flag = false;
        big_x = 0;
        big_y = 0;
    }
}

bool Food::GetBigFlag() const {
    return big_flag;
}

int Food::GetProgressBar() const {
    return progress_bar;
}
