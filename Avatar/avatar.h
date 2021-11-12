#pragma once

#include <QWidget>
#include <QImage>
#include <QPainter>

class GraphicCell;

class Avatar : public QWidget
{
public:
    Avatar(const GraphicCell* graphicCell, const QString filename, QWidget* parent = 0);
    ~Avatar();

    void Draw(const GraphicCell* graphicCell, QPainter* painter);
    void UpdatePicture(QString filename);

    QString GetFilename() const;
private:
    int _width;
    int _height;

    QImage _image;
    QString _filename;
};

