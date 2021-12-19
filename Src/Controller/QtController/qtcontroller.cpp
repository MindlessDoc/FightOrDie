#include "qtcontroller.h"
#include "Src/Application/mediator.h"

QtController::QtController(Mediator* mediator, int keyForwardDirection, int keyBackDirection, int keyRightDirection,
                           int keyLeftDirection)
    : Controller(keyForwardDirection, keyBackDirection, keyRightDirection, keyLeftDirection, mediator)
{

}

void QtController::KeyIsPressed(int pressedKey)
{
    if(pressedKey == _keyForwardDirection)
    {
        Action(_forwardDiraction);
    }
    else if(pressedKey == _keyBackDirection)
    {
        Action(_backDiraction);
    }
    else if(pressedKey == _keyRightDirection)
    {
        Action(_rightDiraction);
    }
    else if(pressedKey == _keyLeftDirection)
    {
        Action(_leftDiraction);
    }
}

void QtController::Action(std::pair<int, int> vector)
{
    _mediator->notifyPlayerMove(vector.first, vector.second);
}
