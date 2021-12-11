#include "controller.h"
#include "Application/mediator.h"

Controller::Controller(int keyForwardDirection, int keyBackDirection, int keyRightDirection, int keyLeftDirection,
                       Mediator* mediator)
    : _keyForwardDirection(keyForwardDirection)
    , _keyBackDirection(keyBackDirection)
    , _keyRightDirection(keyRightDirection)
    , _keyLeftDirection(keyLeftDirection)
    , _mediator(mediator)
{

}
