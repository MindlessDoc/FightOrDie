#include "trojan.h"
#include "Src/Cells/cell.h"
#include "Src/Fields/field.h"

Trojan::Trojan(Field* gameField, Cell* cell)
    : Enemy(gameField, cell, 3000)
{
    //Think how to reduce
    _directionCount = 8;
    _direction.resize(_directionCount);
    for(int i = 0; i < _directionCount; i++)
    {
        _direction[i].resize(2);
    }

    _direction[0][0] = -1; _direction[0][1] = -2;
    _direction[1][0] = 1; _direction[1][1] = -2;
    _direction[2][0] = -2; _direction[2][1] = -1;
    _direction[3][0] = -2; _direction[3][1] = 1;
    _direction[4][0] = -1; _direction[4][1] = 2;
    _direction[5][0] = 1; _direction[5][1] = 2;
    _direction[6][0] = 2; _direction[6][1] = -1;
    _direction[7][0] = 2; _direction[7][1] = 1;

    //SetNextStep();
}

Trojan::Trojan(Field* gameField, Cell* cell, Mediator* mediator)
    : Enemy(gameField, cell, 3000, mediator)
{
    //Think how to reduce
    _directionCount = 8;
    _direction.resize(_directionCount);
    for(int i = 0; i < _directionCount; i++)
    {
        _direction[i].resize(2);
    }

    _direction[0][0] = -1; _direction[0][1] = -2;
    _direction[1][0] = 1; _direction[1][1] = -2;
    _direction[2][0] = -2; _direction[2][1] = -1;
    _direction[3][0] = -2; _direction[3][1] = 1;
    _direction[4][0] = -1; _direction[4][1] = 2;
    _direction[5][0] = 1; _direction[5][1] = 2;
    _direction[6][0] = 2; _direction[6][1] = -1;
    _direction[7][0] = 2; _direction[7][1] = 1;

    //SetNextStep();
}

Trojan::~Trojan()
{
//    if(_nextStep)
//        _nextStep->UpdateAvatar("C:/QtProjects/OOP/FightOrDie/Src/Way.png");
}

//void Trojan::SetNextStep()
//{
//    _possibleDirection.resize(0);
//    for(int i = 0; i < _directionCount; i++)
//    {
//        int newColumn = _graphicCell->GetColumn() + _direction[i][0];
//        int newRow = _graphicCell->GetRow() + _direction[i][1];
//        if(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells()
//                && newRow < _gameField->GetWidthInCells()
//             && static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->CanMoveIn())
//        {
//            _possibleDirection.push_back(_direction[i]);
//        }
//    }

//    if(!_possibleDirection.empty())
//    {
//        int index = QRandomGenerator::global()->bounded(0, int(_possibleDirection.size()));
//        _nextStep = static_cast<GraphicCell*>(_gameField->GetCell(_graphicCell->GetColumn() + _possibleDirection[index][0],
//                                    _graphicCell->GetRow() + _possibleDirection[index][1]));
//        _nextStep->UpdateAvatar("C:/QtProjects/OOP/FightOrDie/Src/NextStepTrojan.png");
//    }
//    else
//    {
//        _nextStep = nullptr;
//    }
//}

void Trojan::Move(int variant)
{
    int newColumn = _cell->GetColumn() + _direction[variant][0];
    int newRow = _cell->GetRow() + _direction[variant][1];

    if(_gameField->CheckOnInclusion(newColumn, newRow))
    {
        if(((_gameField->GetCell(newColumn, newRow)->GetEntity() && typeid(*(_gameField->GetCell(newColumn, newRow)->GetEntity())) == typeid(Player))
                || (!_gameField->GetCell(newColumn, newRow)->GetEntity()))
                && _gameField->GetCell(newColumn, newRow)->CanMoveIn(_cell->GetEntity()))
        {
            if(_gameField->GetCell(newColumn, newRow)->GetEntity() && typeid(*(_gameField->GetCell(newColumn, newRow)->GetEntity())) == typeid(Player))
            {
                //CHEKING!!!
                delete _gameField->GetCell(newColumn, newRow)->GetEntity();
            }
            _gameField->GetCell(newColumn, newRow)->Moving(_cell);
            _cell = _gameField->GetCell(newColumn, newRow);
        }
    }
    notify();
}

std::string Trojan::LogOut() const
{
    return  "Trojan info:\nCoordinates: column = " + std::to_string(_cell->GetColumn())+
            " row = " + std::to_string(_cell->GetRow()) + "\n";
}

void Trojan::Serialize(std::ostream &os)
{
    os << typeid (Trojan).name() << std::endl;
}

