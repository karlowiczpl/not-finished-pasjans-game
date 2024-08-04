#include "board.h"

Board::Board(QWidget *parent) :
    QMainWindow(parent){
    setApperance();
    this->show();
}
void Board::setApperance()
{
    setMinimumHeight(600);
    setMinimumWidth(1000);

    QPalette windowPalette;
    windowPalette.setColor(QPalette::Window , 0x0d411c);

    this->setPalette(windowPalette);
}