#pragma once

#include "Entities/ientity.h"
#include <QKeyEvent>

class Player : public IEntity, public QWidget
{
public:
    Player(Cell* cell);
    virtual void Draw(QPainter* painter) override;
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
private:
    Avatar _avatar;
    Cell* _cell;
};
