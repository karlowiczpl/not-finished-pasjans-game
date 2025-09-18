#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <algorithm>
#include <vector>

#include "card.h"
#include <cmath>
#include <csignal>

#include "../../source/singleton.h"
#include "../../source/tackle.h"

Card::Card(int number, int color, QWidget *par) :
    QWidget(par),
    isBackVisible(false),
    parent(par),
    cardColor(color),
    cardNumber(number),
    draging(false),
    stack(0)
{
    generatePath();
    if (parent != nullptr) {
        setParent(parent);
    }
}

void Card::generatePath()
{
    QString path;
    if (cardColor == 3) path = ":/cardFronts/clubs_";
    else if (cardColor == 0) path = ":/cardFronts/diamonds_";
    else if (cardColor == 1) path = ":/cardFronts/hearts_";
    else if (cardColor == 2) path = ":/cardFronts/spades_";

    image.load(path + QString::number(cardNumber) + ".svg");
}
void Card::setPosition(int posiX, int posiY)
{
    positionX = posiX;
    positionY = posiY;
}


void Card::moveCard(int oldPositionX, int newPositionX, bool onStack)
{
    Singleton& singleton = Singleton::getInstance();
    if (oldPositionX >= 0 && oldPositionX < 7 && newPositionX >= 0 && newPositionX < 7 && !onStack)
    {
        auto& oldStack = singleton.cards[oldPositionX];
        auto& newStack = singleton.cards[newPositionX];

        if (!oldStack.empty())
        {
            newStack.push_back(std::move(oldStack.back()));
            oldStack.pop_back();
        
            if (!oldStack.empty())
            {
                oldStack.back()->flipCard(false);
            }

            Tackle::show();

            newStack.back()->setPosition(newPositionX, newStack.size() - 1);
        }
    }
    else if (onStack && newPositionX >= 0 && newPositionX < 7)
    {
        auto& oldStack = singleton.cards.back();
        auto& newStack = singleton.cards[newPositionX];

        if (!oldStack.empty())
        {
            newStack.push_back(std::move(oldStack[oldPositionX]));
            oldStack.erase(oldStack.begin() + oldPositionX);

            if (!oldStack.empty())
            {
                oldStack.back()->flipCard(false);
            }
            Tackle::show();
            newStack.back()->setPosition(newPositionX, newStack.size() - 1);
        }
    }
}
bool Card::checkForWin()
{
  Singleton& singleton = Singleton::getInstance();
  for(int i = 0; i < 7; i++)
  {
  }
    return true;
}
void Card::setStack(int number)
{
    stack = number;
}
void Card::setColor(bool isRed)
{
    this->isRed = isRed;
}
int Card::getCardColor()
{
    return cardColor;
}
void Card::flipCard(bool showBack)
{
    isBackVisible = showBack;
    update();
}
void Card::setTop(bool t) {top = t;}
void Card::setDragging(bool drag) {draging = drag;}
