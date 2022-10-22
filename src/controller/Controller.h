//
// Created by HongYing on 2022/10/20.
//

#ifndef GREEDYSNAKE_CONTROLLER_H
#define GREEDYSNAKE_CONTROLLER_H


class Controller {
public:
    Controller();

    static void Start();

    void Select();

    void DrawGame() const;

    int PlayGame();

    void UpdateScore(const int &tmp);

    void RewriteScore() const;

    static int Menu();

    void Game();

    int GameOver() const;

private:
    int speed;
    int key;
    int score;
};


#endif //GREEDYSNAKE_CONTROLLER_H
