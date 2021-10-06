#ifndef CELL_H
#define CELL_H


class Cell
{
public:
    Cell(bool state);
    static int GetHeight();
    static int GetWidth();
private:
    const static int _height = 50;
    const static int _width = 50;
    bool _state;
};

#endif // CELL_H
