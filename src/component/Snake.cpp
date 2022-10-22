//
// Created by HongYing on 2022/10/19.
//

#include "Snake.h"
#include "../utils/Tools.h"
#include <conio.h>
#include <iostream>

Snake::Snake() {
    snake.emplace_back(14, 8);
    snake.emplace_back(15, 8);
    snake.emplace_back(16, 8);
    direction = Direction::DOWN;
}

void Snake::InitSnake() {
    for (auto &point: snake) {
        point.PrintCircular();
    }
}

void Snake::Move() {
    switch (direction) {
        case Direction::UP:
            snake.emplace_back(Point(snake.back().getX(), snake.back().getY() - 1));
            break;
        case Direction::DOWN:
            snake.emplace_back(Point(snake.back().getX(), snake.back().getY() + 1));
            break;
        case Direction::LEFT:
            snake.emplace_back(Point(snake.back().getX() - 1, snake.back().getY()));
            break;
        case Direction::RIGHT:
            snake.emplace_back(Point(snake.back().getX() + 1, snake.back().getY()));
            break;
        default:
            break;
    }
    SetColor(14);
    snake.back().PrintCircular();
}

void Snake::NormalMove() {
    Move();
    snake.front().Clear();
    snake.pop_front();
}

bool Snake::OverEdge() {//超出边界则返回true没有超出则返回false
    return !(snake.back().getX() < 30 && snake.back().getY() < 30 && snake.back().getX() > 1 &&
             snake.back().getY() > 1);
}

bool Snake::HitItself() {//咬到自己则返回true没有则返回false
    std::deque<Point>::size_type cnt = 1;
    auto *head = new Point(snake.back().getX(), snake.back().getY());
    for (auto &point: snake) {
        if (!(point == *head)) {
            ++cnt;
        } else {
            break;
        }
    }
    delete head;
    if (cnt == snake.size()) {
        return false;
    } else {
        return true;
    }
}

bool Snake::ChangeDirection() {
    int ch;
    if (_kbhit()) {
        ch = _getch();
        switch (ch) {
            case 224:
                ch = _getch();
                switch (ch) {
                    case 72:
                        if (direction != Direction::DOWN)//如果方向与当前运动方向相反，无效
                            direction = Direction::UP;
                        break;
                    case 80:
                        if (direction != Direction::UP)
                            direction = Direction::DOWN;
                        break;
                    case 75:
                        if (direction != Direction::RIGHT)
                            direction = Direction::LEFT;
                        break;
                    case 77:
                        if (direction != Direction::LEFT)
                            direction = Direction::RIGHT;
                        break;
                    default:
                        break;
                }
                return true;
            case 27:
                return false;
            default:
                return true;
        }
    }
    return true;
}

bool Snake::GetFood(const Food &food) {
    if (snake.back().getX() == food.x && snake.back().getY() == food.y) {
        return true;
    } else {
        return false;
    }
}

bool Snake::GetBigFood(Food &food) {
    if (snake.back().getX() == food.big_x && snake.back().getY() == food.big_y) {
        food.big_flag = false;
        food.big_x = 0;
        food.big_y = 0;
        SetCursorPosition(1, 0);
        std::cout << "                                                            ";
        return true;
    } else {
        return false;
    }
}


