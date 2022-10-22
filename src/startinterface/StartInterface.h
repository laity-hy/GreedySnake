//
// Created by HongYing on 2022/10/20.
//

#ifndef GREEDYSNAKE_STARTINTERFACE_H
#define GREEDYSNAKE_STARTINTERFACE_H

#include <deque>
#include <vector>
#include "../component/Point.h"

class StartInterface {
public:
    StartInterface();

    void PrintFirst();

    void PrintSecond();

    void PrintThird();

    void PrintText();

    void ClearText();

    void Action();

private:
    std::deque<Point> startsnake;
    std::vector<Point> textsnake;
    int speed;
};


#endif //GREEDYSNAKE_STARTINTERFACE_H
