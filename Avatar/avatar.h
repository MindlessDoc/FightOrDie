#pragma once

#include <QWidget>
#include <QImage>
#include <QPainter>

class GraphicCell;

class Avatar : public QWidget
{
public:
    //Avatar(const Cell* cell = nullptr, const QString filename = "", QWidget* parent = 0);
    Avatar(const GraphicCell* graphicCell, const QString filename, QWidget* parent = 0);
    ~Avatar();

    void Draw(const GraphicCell* graphicCell, QPainter* painter);

    QString GetFilename() const;
private:
    QImage _image;
    QString _filename;
};

