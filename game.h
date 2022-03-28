#ifndef GAME_H
#define GAME_H

#include<vector>
class Game
{
public:
    Game();
    void Startgame();
    bool collectibility();
    bool isFinished();
    int GetValue(int colomn, int line);
    void RestartGame();
    void Move(int colomn, int line);
private:
    int table[4][4];
    int copytable[4][4];
    int nullcoloumn;
    int nullline;
    int copynullline;
    int copynullcoloumn;
    std::vector<int> ValueInTable[15];

};

#endif // GAME_H
