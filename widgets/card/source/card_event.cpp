#include "../../../source/singleton.h"
#include "../card.h"
#include "card_move.h"
#include <QDebug>
#include <QMouseEvent>

#define SAMPLE_COLORS isRed != singleton.cards[pos][singleton.cards[pos].size() - 1]->isRed
#define SAMPLE_POSITION pos != positionX
#define VISIBLE isBackVisible == false
#define OUT_OF_RANGE positionX < 7
#define GOOD_DOWN_CARD cardNumber == singleton.cards[pos][singleton.cards[pos].size() - 1]->cardNumber - 1
#define GOOD_POSITION pos >= 0 && pos < 7

void Card::mousePressEvent(QMouseEvent *event)
{
  Singleton& singleton = Singleton::getInstance();
  if (event->button() == Qt::LeftButton)
  {
    if(!top)
    {
      for (int i = positionY + 1; i < singleton.cards[positionX].size(); i++)
      {
        singleton.cards[positionX][i]->raise();
      }
    }
    if (stack == 2)
    {
      Card_move::stackButtonClicked();
      Tackle::show();
    }
    else if (!isBackVisible && (stack == 0 || stack == 1))
    {
      draging = true;
      dragStartPosition = event->pos();
      raise();
    }
  }
  QWidget::mousePressEvent(event);
}

void Card::mouseMoveEvent(QMouseEvent *event) {
  Singleton &singleton = Singleton::getInstance();
  QPoint newPos = mapToParent(event->pos() - dragStartPosition);
  if (draging && top) {
    move(newPos);
  } else if (!isBackVisible && !top) {
    move(newPos);
    int counter = 1;
    for (int i = positionY + 1; i < singleton.cards[positionX].size(); i++)
    {
      newPos = mapToParent(event->pos() - dragStartPosition) + QPoint(0 , 50 * counter);
      singleton.cards[positionX][i]->move(newPos);
      singleton.cards[positionX][i]->raise();
      counter++;
    }
  }

}
void Card::mouseReleaseEvent(QMouseEvent *event)
{
  Singleton& singleton = Singleton::getInstance();
  QPoint posInParent = mapToParent(pos());
  int pos = ((posInParent.x() - 20) / 105) / 2;

  if (event->button() == Qt::LeftButton)
  {
    draging = false;
    if (stack == 0)
    {
      if (SAMPLE_POSITION && OUT_OF_RANGE && VISIBLE && SAMPLE_COLORS && GOOD_DOWN_CARD)
      {
        moveCard(positionY, pos, false);
      }
      else
      {
        singleton.tackle->show();
      }
    }
    else if (stack == 1)
    {
      if (SAMPLE_POSITION && VISIBLE && SAMPLE_COLORS && GOOD_DOWN_CARD)
      {
        moveCard(positionY, pos, true);
      }
      else
      {
        singleton.tackle->show();
      }
    }
  }
  QWidget::mouseReleaseEvent(event);
}
