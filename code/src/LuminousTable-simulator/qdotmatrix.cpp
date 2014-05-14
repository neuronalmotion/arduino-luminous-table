#include "qdotmatrix.h"

#include <QPainter>

QDotMatrix::QDotMatrix(QWidget *parent, int rowsCount, int colsCount) :
    QWidget(parent)
{
    mRowsCount = rowsCount;
    mColsCount = colsCount;
    mDotSize = 32;

    // matrix memory allocation
    mMatrix = new QColor*[mRowsCount];
    for (int x = 0; x < mRowsCount; ++x) {
        mMatrix[x] = new QColor[mColsCount];
    }

    for (int x = 0; x < mRowsCount; ++x) {
        for (int y = 0; y < mColsCount; ++y) {
            int value = 0;
            mMatrix[x][y] = QColor::fromRgb(value, value, value);
        }
    }

    this->setFixedSize(rowsCount * mDotSize, colsCount * mDotSize);

    //add blur effect
    mGraphicsEffect = new QGraphicsBlurEffect();
    mGraphicsEffect->setBlurRadius(15);
    this->setGraphicsEffect(mGraphicsEffect);
}


void QDotMatrix::setColor(int x, int y, CRGB color)
{
   mMatrix[x][y] = QColor(color.r, color.g, color.b);
}

void QDotMatrix::setColor(int x, int y, QColor color)
{
    mMatrix[x][y] = color;
}

void QDotMatrix::paintEvent(QPaintEvent * pe)
{
    QPainter painter(this);

    for (int x = 0; x < mRowsCount; ++x) {
        for (int y = 0; y < mColsCount; ++y) {

            int startX = x * mDotSize;
            int startY = y * mDotSize;
            int endX = startX + mDotSize;
            int endY = startY + mDotSize;

            QColor color = mMatrix[x][y];
            color.setAlpha(255);
            painter.fillRect(QRect(startX, startY, endX, endY), color);

        }
    }

}