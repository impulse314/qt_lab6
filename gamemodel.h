#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include<vector>
using namespace std;

enum ItemType {
    Empty, Cross, Zero
};

struct GameModel {
    vector<vector<ItemType>> model;

    ItemType player;

    GameModel(int n, int m, ItemType initPlayer = Cross);
    GameModel(vector<vector<ItemType>> model);

    void change_player();
    bool step(int i, int j);

    ItemType check_win();
    ItemType check_win_hline();
    ItemType check_win_vline();
};

#endif // GAMEMODEL_H
