//
// Created by HongYing on 2022/10/19.
//

#ifndef GREEDYSNAKE_POINT_H
#define GREEDYSNAKE_POINT_H


class Point {
public:
    Point();

    Point(int x, int y);

    void Print();//��x,y�´�ӡ�������ַ�

    void PrintCircular();//��x,y�´�ӡԲ���ַ�

    void Clear();

    void ChangePosition(int x, int y);

    bool operator==(const Point &point);

    int getX() const;

    int getY() const;

private:
    int x, y;
};


#endif //GREEDYSNAKE_POINT_H
