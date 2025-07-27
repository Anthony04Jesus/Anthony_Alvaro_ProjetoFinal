#ifndef MINECOUNTER_H
#define MINECOUNTER_H

#include <QLCDNumber>

class MineCounter : public QLCDNumber
{
public:
    MineCounter(int bombs);

    void inc();
    void dec();
    int  value();
    void resetBombs();

private:
    int _bombs;
    int _bombCounter;
};

#endif // MINECOUNTER_H
