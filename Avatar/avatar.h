#pragma once

#include <QWidget>
#include <QImage>
#include <QPainter>

class Cell;

class Avatar : public QWidget
{
public:
    //Avatar(const Cell* cell = nullptr, const QString filename = "", QWidget* parent = 0);
    Avatar(const Cell* cell, const QString filename, QWidget* parent = 0);
    ~Avatar();

    void Draw(const Cell* cell, QPainter* painter);
private:
    QImage _image;
};

