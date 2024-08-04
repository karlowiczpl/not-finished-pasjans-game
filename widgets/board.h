#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>


class Board : public QMainWindow {

Q_OBJECT

private:
    void setApperance();

public:
    explicit Board(QWidget *parent = nullptr);

};


#endif //BOARD_H
