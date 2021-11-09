#include "virus.h"

Virus::Virus(GraphicField* gameField, GraphicCell* graphicCell)
    : Enemy(gameField, graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Enemy.png", 1000)
{
    //Think how to reduce
    _directionCount = 4;
    _direction.resize(_directionCount);
    for(int i = 0; i < _directionCount; i++)
    {
        _direction[i].resize(2);
    }

    _direction[0][0] = -1; _direction[0][1] = 0;
    _direction[1][0] = 1; _direction[1][1] = 0;
    _direction[2][0] = 0; _direction[2][1] = -1;
    _direction[3][0] = 0; _direction[3][1] = 1;
}
