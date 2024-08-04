    #ifndef CARD_H
    #define CARD_H

    #include <QWidget>
    #include <QPixmap>
    #include <QPainter>

    class Card : public QWidget {
        Q_OBJECT

    private:
        QWidget* parent;
        int cardColor;
        int cardNumber;
        int stack;
        bool isBackVisible;
        bool draging;
        bool top;
        QPoint dragStartPosition;

        QPixmap image;

        void generatePath();
        static void moveCard(int oldPositionX , int newPositionX , bool);
        bool checkForWin();

    public:
        explicit Card(int number, int color, QWidget *parent = nullptr);
        
        void showCard(int positionX, int positionY);
        void flipCard(bool showBack);

        void setPosition(int posiX, int posiY );
        void setColor(bool isRed);
        int getCardColor();
        void setStack(int number);
        void setTop(bool t);
        void setDragging(bool drag);

    protected:
        void paintEvent(QPaintEvent* event) override;
        void mousePressEvent(QMouseEvent* event) override;
        void mouseMoveEvent(QMouseEvent* event) override;
        void mouseReleaseEvent(QMouseEvent* event) override;

        int positionX;
        int positionY;
        bool isRed;
    };

    #endif // CARD_H
