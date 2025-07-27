#include "minecounter.h"


MineCounter::MineCounter(int bombs)
{
    _bombs = bombs;
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
    _bombs++;
    display(_bombs);
}

void MineCounter::dec()
{
    //if(_bombs > 0)
        _bombs--;
    display(_bombs);
}

int MineCounter::value()
{
    return _bombs;
}


