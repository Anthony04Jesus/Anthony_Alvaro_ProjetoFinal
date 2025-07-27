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

private:
    int _bombs;
};

#endif // MINECOUNTER_H
