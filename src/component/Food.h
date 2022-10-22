//
// Created by HongYing on 2022/10/19.
//


#ifndef GREEDYSNAKE_FOOD_H
#define GREEDYSNAKE_FOOD_H

#include "Snake.h"

class Snake;

class Food {
public:
    Food();

    void DrawFood(Snake &snake);

    void DrawBigFood(Snake &snake);

    void FlashBigFood();

    bool GetBigFlag() const;

    int GetProgressBar() const;

private:
    int cnt;
    bool flash_flag;
    bool big_flag;
    int x, y;
    int big_x, big_y;
    int progress_bar;

    friend class Snake;
};


#endif //GREEDYSNAKE_FOOD_H
