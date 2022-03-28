#include "game.h"
#include <QRandomGenerator>
#include<algorithm>
#include<vector>
#include<QDebug>
Game::Game()
{
    Startgame();

}
void Game::Startgame()
{

    QRandomGenerator *rand = QRandomGenerator::global();



    bool check;
    int  value;
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {

                value = rand->bounded(1,17);
                if(std::find(ValueInTable->begin(),ValueInTable->end(),value) != ValueInTable->end())
                {
                    check = false;
                    while(!check)
                    {
                        value = rand->bounded(1,17);
                        if(std::find(ValueInTable->begin(),ValueInTable->end(),value) == ValueInTable->end())
                        {
                            check = true;
                            ValueInTable->push_back(value);
                        }
                        else
                        {
                            check = false;
                        }
                     }
                }
                if(value == 16)
                {
                    nullcoloumn = j;
                    nullline = i;
                    copynullcoloumn= nullcoloumn;
                    copynullline=nullline;
                }
                table[i][j] = value;
                copytable[i][j] = value;
                ValueInTable->push_back(value);
          }

        }
    ValueInTable->clear();
    for(int i = 0 ;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            ValueInTable->push_back(table[i][j]);
        }
    }


}


void Game::RestartGame()
{
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            table[i][j] = copytable[i][j];
        }
    }
    nullline = copynullline;
    nullcoloumn = copynullcoloumn;
    qDebug() << ValueInTable->size();
}


int Game::GetValue(int line, int column)
{
    return table[line][column];
}

bool Game::isFinished()
{
    int a = 1;
    for(int i = 0; i<4 ;i++)
    {
        for (int j = 0; j<4 ;j++)
        {
            if(table[i][j] != a)
            {
                return false;
            }
            a++;
        }
    }
    return true;
}


void Game::Move(int line, int coloumn)
{
    if((line == nullline) && (coloumn - nullcoloumn == 1 || coloumn - nullcoloumn == -1) || ((coloumn == nullcoloumn) && (line - nullline == 1 || line - nullline==-1)))
    {
       std::swap(table[line][coloumn], table[nullline][nullcoloumn]);
       nullline = line;
       nullcoloumn = coloumn;
    }
}


bool Game::collectibility()
{
    int inv = 0;
    for(int i = 0;  i < ValueInTable->size(); i++)
    {
        if(ValueInTable->at(i)!=16)
        {
            for(int j = 0; j < i;j++)
            {
                if(ValueInTable->at(j) > ValueInTable->at(i))
                {
                    inv++;
                }
            }

        }
    }
    inv+=nullline;
    inv+=1;
    return inv%2 ==0 ? true:false;
}

