//
// Created by HongYing on 2022/10/19.
//

#include "Map.h"
#include <windows.h>

Map::Map() {
    initMap.emplace_back(Point(1, 1));
    initMap.emplace_back(Point(2, 1));
    initMap.emplace_back(Point(3, 1));
    initMap.emplace_back(Point(4, 1));
    initMap.emplace_back(Point(5, 1));
    initMap.emplace_back(Point(6, 1));
    initMap.emplace_back(Point(7, 1));
    initMap.emplace_back(Point(8, 1));
    initMap.emplace_back(Point(9, 1));
    initMap.emplace_back(Point(10, 1));
    initMap.emplace_back(Point(11, 1));
    initMap.emplace_back(Point(12, 1));
    initMap.emplace_back(Point(13, 1));
    initMap.emplace_back(Point(14, 1));
    initMap.emplace_back(Point(15, 1));
    initMap.emplace_back(Point(16, 1));
    initMap.emplace_back(Point(17, 1));
    initMap.emplace_back(Point(18, 1));
    initMap.emplace_back(Point(19, 1));
    initMap.emplace_back(Point(20, 1));
    initMap.emplace_back(Point(21, 1));
    initMap.emplace_back(Point(22, 1));
    initMap.emplace_back(Point(23, 1));
    initMap.emplace_back(Point(24, 1));
    initMap.emplace_back(Point(25, 1));
    initMap.emplace_back(Point(26, 1));
    initMap.emplace_back(Point(27, 1));
    initMap.emplace_back(Point(28, 1));
    initMap.emplace_back(Point(29, 1));
    initMap.emplace_back(Point(30, 1));
    initMap.emplace_back(Point(1, 2));
    initMap.emplace_back(Point(30, 2));
    initMap.emplace_back(Point(1, 3));
    initMap.emplace_back(Point(30, 3));
    initMap.emplace_back(Point(1, 4));
    initMap.emplace_back(Point(30, 4));
    initMap.emplace_back(Point(1, 5));
    initMap.emplace_back(Point(30, 5));
    initMap.emplace_back(Point(1, 6));
    initMap.emplace_back(Point(30, 6));
    initMap.emplace_back(Point(1, 7));
    initMap.emplace_back(Point(30, 7));
    initMap.emplace_back(Point(1, 8));
    initMap.emplace_back(Point(30, 8));
    initMap.emplace_back(Point(1, 9));
    initMap.emplace_back(Point(30, 9));
    initMap.emplace_back(Point(1, 10));
    initMap.emplace_back(Point(30, 10));
    initMap.emplace_back(Point(1, 11));
    initMap.emplace_back(Point(30, 11));
    initMap.emplace_back(Point(1, 12));
    initMap.emplace_back(Point(30, 12));
    initMap.emplace_back(Point(1, 13));
    initMap.emplace_back(Point(30, 13));
    initMap.emplace_back(Point(1, 14));
    initMap.emplace_back(Point(30, 14));
    initMap.emplace_back(Point(1, 15));
    initMap.emplace_back(Point(30, 15));
    initMap.emplace_back(Point(1, 16));
    initMap.emplace_back(Point(30, 16));
    initMap.emplace_back(Point(1, 17));
    initMap.emplace_back(Point(30, 17));
    initMap.emplace_back(Point(1, 18));
    initMap.emplace_back(Point(30, 18));
    initMap.emplace_back(Point(1, 19));
    initMap.emplace_back(Point(30, 19));
    initMap.emplace_back(Point(1, 20));
    initMap.emplace_back(Point(30, 20));
    initMap.emplace_back(Point(1, 21));
    initMap.emplace_back(Point(30, 21));
    initMap.emplace_back(Point(1, 22));
    initMap.emplace_back(Point(30, 22));
    initMap.emplace_back(Point(1, 23));
    initMap.emplace_back(Point(30, 23));
    initMap.emplace_back(Point(1, 24));
    initMap.emplace_back(Point(30, 24));
    initMap.emplace_back(Point(1, 25));
    initMap.emplace_back(Point(30, 25));
    initMap.emplace_back(Point(1, 26));
    initMap.emplace_back(Point(30, 26));
    initMap.emplace_back(Point(1, 27));
    initMap.emplace_back(Point(30, 27));
    initMap.emplace_back(Point(1, 28));
    initMap.emplace_back(Point(30, 28));
    initMap.emplace_back(Point(1, 29));
    initMap.emplace_back(Point(30, 29));
    initMap.emplace_back(Point(1, 30));
    initMap.emplace_back(Point(2, 30));
    initMap.emplace_back(Point(3, 30));
    initMap.emplace_back(Point(4, 30));
    initMap.emplace_back(Point(5, 30));
    initMap.emplace_back(Point(6, 30));
    initMap.emplace_back(Point(7, 30));
    initMap.emplace_back(Point(8, 30));
    initMap.emplace_back(Point(9, 30));
    initMap.emplace_back(Point(10, 30));
    initMap.emplace_back(Point(11, 30));
    initMap.emplace_back(Point(12, 30));
    initMap.emplace_back(Point(13, 30));
    initMap.emplace_back(Point(14, 30));
    initMap.emplace_back(Point(15, 30));
    initMap.emplace_back(Point(16, 30));
    initMap.emplace_back(Point(17, 30));
    initMap.emplace_back(Point(18, 30));
    initMap.emplace_back(Point(19, 30));
    initMap.emplace_back(Point(20, 30));
    initMap.emplace_back(Point(21, 30));
    initMap.emplace_back(Point(22, 30));
    initMap.emplace_back(Point(23, 30));
    initMap.emplace_back(Point(24, 30));
    initMap.emplace_back(Point(25, 30));
    initMap.emplace_back(Point(26, 30));
    initMap.emplace_back(Point(27, 30));
    initMap.emplace_back(Point(28, 30));
    initMap.emplace_back(Point(29, 30));
    initMap.emplace_back(Point(30, 30));
}

void Map::PrintInitMap() {
    for (auto &point: initMap) {
        point.Print();
        Sleep(10);
    }
}
