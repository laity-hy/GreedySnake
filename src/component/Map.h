//
// Created by HongYing on 2022/10/19.
//

#ifndef GREEDYSNAKE_MAP_H
#define GREEDYSNAKE_MAP_H

#include <vector>
#include "Point.h"

class Map {
public:
    Map();

    void PrintInitMap();

private:
    std::vector<Point> initMap;
};


#endif //GREEDYSNAKE_MAP_H
