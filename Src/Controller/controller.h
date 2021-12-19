#pragma once
#include <iostream>

class Mediator;

class Controller
{
public:
    Controller(int keyForwardDirection, int keyBackDirection, int keyRightDirection, int keyLeftDirection,
               Mediator* mediator);
    virtual ~Controller() = default;

    virtual void KeyIsPressed(int pressedKey) = 0;
    virtual void Action(std::pair<int, int> vector) = 0;

protected:
    const int _keyForwardDirection;
    const int _keyBackDirection;
    const int _keyRightDirection;
    const int _keyLeftDirection;

    const std::pair<int, int> _forwardDiraction = {0, -1};
    const std::pair<int, int> _backDiraction = {0, 1};
    const std::pair<int, int> _rightDiraction = {-1, 0};
    const std::pair<int, int> _leftDiraction = {1, 0};

    Mediator* _mediator;
};
