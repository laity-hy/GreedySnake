//
// Created by HongYing on 2022/10/19.
//


#ifndef GREEDYSNAKE_SNAKE_H
#define GREEDYSNAKE_SNAKE_H

#include <deque>
#include "Point.h"
#include "Food.h"

class Food;

class Snake {
public:
    enum Direction {
        UP, DOWN, LEFT, RIGHT
    };

    Snake();

    void InitSnake();

    void Move();

    void NormalMove();

    bool OverEdge();

    bool HitItself();

    bool ChangeDirection();

    bool GetFood(const Food &food);

    bool GetBigFood(Food &food);

private:
    std::deque<Point> snake;
    Direction direction;

    friend class Food;
};


#endif //GREEDYSNAKE_SNAKE_H
