#ifndef TACKLE_H
#define TACKLE_H

#include "../widgets/card/card.h"
#include "../widgets/board.h"

#include <vector>

#define START_POS_X 30
#define START_POS_Y 20

class Tackle
{

public:
    Tackle(Board* b1);
    static void show();

    Tackle& operator=(const Tackle& other)
    {
      if(this == &other)
      {
        return *this;
      }
    }

private:
    void generate(Board* b1);
    static void schuffle(std::vector<int>* numbers , std::vector<int>* colors);
    void assign(std::vector<int> numbers , std::vector<int> colors , Board* b1);
    void flipCards() const;
};



#endif //TACKLE_H
