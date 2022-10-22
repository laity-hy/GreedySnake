//
// Created by HongYing on 2022/10/19.
//

#ifndef GREEDYSNAKE_POINT_H
#define GREEDYSNAKE_POINT_H


class Point {
public:
    Point();

    Point(int x, int y);

    void Print();//在x,y下打印正方形字符

    void PrintCircular();//在x,y下打印圆形字符

    void Clear();

    void ChangePosition(int x, int y);

    bool operator==(const Point &point);

    int getX() const;

    int getY() const;

private:
    int x, y;
};


#endif //GREEDYSNAKE_POINT_H
