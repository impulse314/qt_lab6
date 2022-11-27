#include "gamemodel.h"

GameModel::GameModel(int n, int m, ItemType initPlayer) {
    player = initPlayer;

    model.resize(n);
    for (int i = 0; i < n; ++i) {
        model[i].resize(m);

        for (int j = 0; j < m; ++j) {
            model[i][j] = Empty;
        }
    }
}

GameModel::GameModel(vector<vector<ItemType>> model) {
    model = model;
}

ItemType GameModel::check_win() {
    auto winInHLine = check_win_hline();
    if (winInHLine != Empty) {
        return winInHLine;
    }

    auto winInVLine = check_win_vline();
    if (winInVLine != Empty) {
        return winInVLine;
    }

    return Empty;
}

ItemType GameModel::check_win_hline() {
    int count_item;

    for (int i = 0; i < model.size(); i++) {
        ItemType currentItem = model[i][0];
        for (int j = 1; j < model[i].size(); j++) {
            if (model[i][j] == Empty) {
                count_item = 0;
                currentItem = Empty;
                continue;
            }
            if (model[i][j] != currentItem) {
                currentItem = model[i][j];
                count_item = 1;
                continue;
            }
            count_item++;
            if (count_item >= 5)
                return currentItem;
        }
    }
    return Empty;
}

ItemType GameModel::check_win_vline() {
    int count_item;

    for (int j = 0; j < model[0].size(); j++) {
        ItemType currentItem = model[0][j];
        for (int i = 1; i < model.size(); i++) {
            if (model[i][j] == Empty) {
                count_item = 0;
                currentItem = Empty;
                continue;
            }
            if (model[i][j] != currentItem) {
                currentItem = model[i][j];
                count_item = 1;
                continue;
            }
            count_item++;
            if (count_item >= 5)
                return currentItem;
        }
    }
    return Empty;
}

void GameModel::change_player() {
    if (player == Cross) {
        player = Zero;
    }
    else {
        player = Cross;
    }
}

bool GameModel::step(int i, int j) {
    if (model[i][j] != Empty) {
        return false;
    }
    model[i][j] = player;
    change_player();
}
