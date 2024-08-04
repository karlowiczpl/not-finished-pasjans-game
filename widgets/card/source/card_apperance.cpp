#include "../card.h"

void Card::showCard(int positionX, int positionY)
{
    setGeometry(positionX, positionY, 100, 150);
    show();
    update();
}
void Card::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    const QRect rect(0, 0, width(), height());
    painter.setPen(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing);

    if (isBackVisible)
    {
        QPixmap im;
        im.load(":/cardBacks/blue.svg");
        painter.drawPixmap(rect, im);
    }
    else
    {
        painter.drawPixmap(rect, image);
    }
}