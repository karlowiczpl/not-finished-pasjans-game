#ifndef SINGLETON_H
#define SINGLETON_H

#include "../widgets/card/card.h"
#include "../widgets/board.h"
#include "tackle.h"

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    std::vector<std::vector<std::unique_ptr<Card>>> cards;
    Tackle* tackle = nullptr;

private:
    Singleton() = default;
    ~Singleton() = default;
};

#endif // SINGLETON_H
