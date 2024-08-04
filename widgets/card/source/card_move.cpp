#include "card_move.h"
#include "../../../source/singleton.h"


void Card_move::stackButtonClicked()
{
    Singleton& singleton = Singleton::getInstance();
    std::rotate(singleton.cards[7].begin() , singleton.cards[7].begin() + 1 , singleton.cards[7].end());
    std::rotate(singleton.cards[7].begin() , singleton.cards[7].begin() + 1 , singleton.cards[7].end());
    std::rotate(singleton.cards[7].begin() , singleton.cards[7].begin() + 1 , singleton.cards[7].end());

    singleton.cards[7][0]->flipCard(false);
    singleton.cards[7][1]->flipCard(false);
    singleton.cards[7][2]->flipCard(false);
    singleton.cards[7][3]->flipCard(true);

    singleton.cards[7][0]->raise();
    singleton.cards[7][1]->raise();
    singleton.cards[7][2]->raise();
    singleton.cards[7][3]->raise();
}

