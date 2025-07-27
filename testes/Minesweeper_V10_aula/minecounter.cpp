#include "minecounter.h"


MineCounter::MineCounter(int bombs)
{
    _bombs = bombs;
    _bombCounter = _bombs;
    setSegmentStyle(QLCDNumber::Flat);
    setDigitCount(4);
    display(_bombs);
    setStyleSheet(
        "QLCDNumber {"
        "   background-color: black;"
        "   color: red; /* Color of the segments */"
        "   border: 2px inset gray;" // Optional border
        "   border-radius: 5px;"
        "}"
        );
}

void MineCounter::inc()
{
    _bombCounter++;
    display(_bombCounter);
}

void MineCounter::dec()
{
    //if(_bombs > 0)
        _bombCounter--;
    display(_bombCounter);
}

int MineCounter::value()
{
    return _bombCounter;
}

void MineCounter::resetBombs()
{
    _bombCounter = _bombs;
    this->display(_bombs);
}



