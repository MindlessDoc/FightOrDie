#pragma once

#include "Src/Cells/cell.h"
#include "Src/Containers/vector.h"
#include "Src/Entities/Characters/Player/player.h"
#include "Src/Loggers/logger.h"

class Field : public Serializable
{
public:
    Field(int heightInCells, int widthInCells);
    virtual ~Field();

    void InitField(Player* player, Mediator* mediator);
    void InitCell(int column, int row, Cell* cell);

    Field(const Field& other);
    Field& operator=(const Field& other);

    Field(Field&& other);
    Field& operator=(Field&& other);

    int GetHeightInCells();
    int GetWidthInCells();

    Cell* GetCell(int column, int row);
    Player* GetPlayer();

    void InitMediator(Mediator* mediator);

    bool CheckOnInclusion(int column, int row);

    virtual void Serialize(std::ostream& os) override;

private:
    int _heightInCells;
    int _widthInCells;

    Vector<Vector<Cell*>> _cells;
};

