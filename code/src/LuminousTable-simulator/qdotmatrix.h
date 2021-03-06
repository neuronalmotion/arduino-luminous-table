#ifndef QDOTMATRIX_H
#define QDOTMATRIX_H

#include <QWidget>
#include <QGraphicsBlurEffect>

#include "FakeHardware.h"

class QDotMatrix : public QWidget
{
    Q_OBJECT
public:
    explicit QDotMatrix(QWidget *parent = 0, int rowsCount = 20, int colsCount = 10, QColor backgroundColor = Qt::black);

    void setColor(int x, int y, CRGB color);
    void setColor(int x, int y, QColor color);
    void setIntensity(int value);

protected:
    //override
    void paintEvent(QPaintEvent * pe);

    QGraphicsBlurEffect *mGraphicsEffect;
    int mRowsCount;
    int mColsCount;
    int mDotSize;
    QColor **mMatrix;

    QColor mBackgroundColor;
    float mIntensity;

signals:

public slots:

};

#endif // QDOTMATRIX_H
