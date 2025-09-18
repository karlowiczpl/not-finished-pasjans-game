#include "tackle.h"
#include "../widgets/board.h"
#include <vector>
#include <algorithm>
#include <random>
#include <memory>
#include <QDebug>
#include "singleton.h"

Tackle::Tackle(Board* b1) {
    generate(b1);
}

void Tackle::generate(Board* b1) {
    qDebug() << "test";
    std::vector<int> colors;
    std::vector<int> numbers;

    for (int i = 1; i < 14; i++) {
        for (int j = 0; j < 4; j++) {
            colors.push_back(j);
            numbers.push_back(i);
        }
    }
    schuffle(&numbers, &colors);
    assign(numbers, colors, b1);
}

void Tackle::schuffle(std::vector<int> *numbers, std::vector<int> *colors) {
    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(numbers->begin(), numbers->end(), generator);
    std::shuffle(colors->begin(), colors->end(), generator);
}

void Tackle::assign(std::vector<int> numbers, std::vector<int> colors, Board* b1) {
    Singleton& singleton = Singleton::getInstance();
    singleton.cards.resize(8);
    singleton.tackle = this;
    int counter = 0;

    singleton.cards[0].push_back(std::make_unique<Card>(numbers[counter], colors[counter], b1));
    counter++;

    for (int i = 1; i < 7; i++) {
        for (int j = 0; j <= i; j++) {
            singleton.cards[i].push_back(std::make_unique<Card>(numbers[counter], colors[counter], b1));
            singleton.cards[i][j]->setPosition(i, j);
            if (singleton.cards[i][j]->getCardColor() == 1 || singleton.cards[i][j]->getCardColor() == 0) {
                singleton.cards[i][j]->setColor(true);
            } else {
                singleton.cards[i][j]->setColor(false);
            }
            singleton.cards[i][j]->setParent(b1);
            counter++;
        }
    }

    while (counter < static_cast<int>(numbers.size())) {
        singleton.cards[7].push_back(std::make_unique<Card>(numbers[counter], colors[counter], b1));
        int j = singleton.cards[7].size() - 1;
        singleton.cards[7][j]->setPosition(7, j);
        if (singleton.cards[7][j]->getCardColor() == 1 || singleton.cards[7][j]->getCardColor() == 0) {
            singleton.cards[7][j]->setColor(true);
        } else {
            singleton.cards[7][j]->setColor(false);
        }
        singleton.cards[7][j]->setParent(b1);
        counter++;
    }

    flipCards();
}

void Tackle::flipCards() const {
    Singleton& singleton = Singleton::getInstance();
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < static_cast<int>(singleton.cards[i].size()); j++) {
            if (j != static_cast<int>(singleton.cards[i].size()) - 1) {
                singleton.cards[i][j]->flipCard(true);
            }
        }
    }
}

void Tackle::show() {
    Singleton& singleton = Singleton::getInstance();
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < static_cast<int>(singleton.cards[i].size()); j++) {
            if(j == singleton.cards[i].size() - 1)
            {
              singleton.cards[i][j]->setTop(true);
            }else
            {
              singleton.cards[i][j]->setTop(false);
            }
            singleton.cards[i][j]->showCard(START_POS_X + 105 * i, START_POS_Y + 50 * j);
        }
    }

    int counter = 0;
    while (counter < static_cast<int>(singleton.cards[7].size())) {
        if(counter == 0) {
            singleton.cards[7][0]->flipCard(false);
            singleton.cards[7][0]->showCard(770 , START_POS_Y);
            singleton.cards[7][0]->setStack(1);
            singleton.cards[7][0]->setPosition(0 , 0);
        }else if(counter == 1) {
            singleton.cards[7][1]->flipCard(false);
            singleton.cards[7][1]->showCard(800 , START_POS_Y);
            singleton.cards[7][1]->setStack(1);
            singleton.cards[7][1]->setPosition(0 , 1);
        }else if(counter == 2) {
            singleton.cards[7][2]->flipCard(false);
            singleton.cards[7][2]->showCard(830 , START_POS_Y);
            singleton.cards[7][2]->setStack(1);
            singleton.cards[7][2]->setPosition(0 , 2);
        }else if(counter == 3){
            singleton.cards[7][3]->flipCard(true);
            singleton.cards[7][3]->showCard(860 , START_POS_Y);
            singleton.cards[7][3]->setStack(2);
            singleton.cards[7][3]->setPosition(0 , 3);
        }else {
            singleton.cards[7][counter]->flipCard(true);
            singleton.cards[7][counter]->showCard(1200 , START_POS_Y);
            singleton.cards[7][counter]->setStack(3);
            singleton.cards[7][counter]->setPosition(0 , 4);
        }
        counter++;
    }
}
