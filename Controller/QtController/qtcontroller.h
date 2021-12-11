#pragma once
#include "Controller/controller.h"
#include <QKeyEvent>

class QtController : public Controller
{
public:
    QtController(Mediator* mediator, int keyForwardDirection = Qt::Key_W, int keyBackDirection = Qt::Key_S,
                 int keyRightDirection = Qt::Key_A, int keyLeftDirection = Qt::Key_D);
    virtual ~QtController() = default;

    virtual void KeyIsPressed(int pressedKey) override;
    virtual void Action(std::pair<int, int> vector) override;
};
