#include <cmath>
#include <QApplication>
#include <QPushButton>
#include <QObject>

#include "widgets/board.h"
#include "widgets/card/card.h"

#include "source/singleton.h"
#include "source/tackle.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    Singleton& singleton = Singleton::getInstance();
    static Board b1;
    Tackle t1(&b1);
    Tackle::show();

    return QApplication::exec();
}
