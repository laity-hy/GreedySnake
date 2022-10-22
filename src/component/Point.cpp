//
// Created by HongYing on 2022/10/19.
//

#include "Point.h"
#include "../utils/Tools.h"
#include <iostream>

Point::Point() {}

Point::Point(int x, int y) : x(x), y(y) {}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::Print() {
    SetCursorPosition(x, y);
    std::cout << "¡ö";
}

void Point::PrintCircular() {
    SetCursorPosition(x, y);
    std::cout << "¡ñ";
}

void Point::Clear() {
    SetCursorPosition(x, y);
    std::cout << "  ";
}

void Point::ChangePosition(const int x, const int y) {
    this->x = x;
    this->y = y;
}

bool Point::operator==(const Point &point) {
    return (point.x == this->x) && (point.y == this->y);
}
