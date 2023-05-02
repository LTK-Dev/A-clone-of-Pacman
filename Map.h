#pragma once
#include <iostream>
#include <fstream>
#include <iostream>
#include <algorithm>

class Map {
    private:
        static const int MAP_WIDTH = 28;
        static const int MAP_HEIGHT = 31;
        const std::string mapFile = "Map.txt";

       

        int tile[MAP_HEIGHT][MAP_WIDTH];
        // Mang 3 chieu i j k luu tru khoang cach ngan nhat di tu i den j voi k la up right down left tu 0 den 3
        // Biến dist được sử dụng để tính toán khoảng cách nhỏ nhất giữa các điểm trên bản đồ
        int dist[MAP_WIDTH * MAP_HEIGHT][MAP_WIDTH * MAP_HEIGHT][4];
        // lưu trữ vị trí tiếp theo của điểm chuyển hướng (góc) khi đi từ vị trí (i, j) với hướng k.
        // được sử dụng để lưu trữ vị trí của các góc trên đường đi,
        std::pair<int, int> nextCrossID[MAP_HEIGHT][MAP_WIDTH][4];
        // được đánh dấu là true nếu vị trí (i, j) với hướng k là một góc
        // được sử dụng để đánh dấu các vị trí của các góc trên bản đồ.
        bool markCross[MAP_HEIGHT][MAP_WIDTH][4];

        void findingCrossRoad();

        void calculateDistance();

        void NextCrossTileID();
    public:
        static const int UP = 0;
        static const int RIGHT = 1;
        static const int DOWN = 2;
        static const int LEFT = 3;

        Map();

        ~Map() {}

        int getTileID(int x, int y);

        std::pair<int, int> getnextCrossID(int x, int y, int dir);

        bool isWall(std::pair<int, int> tileID);

        bool iscrossRoad(int y, int x);

        bool canChangeDir(int x, int y, int newDir);

        bool besideCrossIsWall(std::pair<int, int> Cross, int newDir);

        int eatCoins(const int &pacmanTileX, const int &pacmanTileY);

        int getDist(std::pair<int, int> start, std::pair<int, int> end, int startDir);

        void reset();
};


