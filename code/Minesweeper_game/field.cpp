#include "resultwindow.h"
#include "field.h"
#include "tile.h"

using namespace std;

const QString Field::pushButtonStyle =
    "QPushButton {"
    "   background-color: #D3D3D3; /* Light gray */"
    "   border: 5px solid #808080; /* Darker gray border */"
    "   border-top-color: #FFFFFF; /* Lighter top border for 3D effect */"
    "   border-left-color: #FFFFFF; /* Lighter left border for 3D effect */"
    "   border-right-color: #808080; /* Darker right border */"
    "   border-bottom-color: #808080; /* Darker bottom border */"
    "   border-radius: 0px; /* Ensure no rounded corners */"
    "   font: bold 12pt 'Segoe UI', 'Arial'; /* Example font */"
    "   color: #000000; /* Default text color */"
    "}"
    "QPushButton:hover {"
    "   background-color: #C0D7FF; /* Slightly lighter on hover */"
    "}"
    "QPushButton:pressed {"
    "   background-color: #B3B3B3; /* Slightly darker when pressed */"
    "   border: 5px solid #808080; /* Invert the 3D effect when pressed */"
    "   border-top-color: #808080;"
    "   border-left-color: #808080;"
    "   border-right-color: #A0A0A0;"
    "   border-bottom-color: #A0A0A0;"
    "}";

const QString Field::QLCDNumberStyle =
    "QLCDNumber {"
    "   background-color: black;"
    "   color: red; /* Color of the segments */"
    "   border: 2px inset gray;"
    "   border-radius: 5px;"
    "}";

void Field::loadTiles()
{
    _tile = new Tile[SIZE_LINE*SIZE_COLUM];
    for(int L = 0; L < SIZE_LINE; L++)
    {
        for(int C = 0; C < SIZE_COLUM; C++)
        {
            int i = L*SIZE_COLUM + C;
            _tile[i].setFixedSize(30, 30);
            _tile[i].setTile(L,C);
            connect(&(_tile[i]), SIGNAL(rightClick(bool)), this, SLOT(setFlag(bool)));
            connect(&(_tile[i]), SIGNAL(rightClick(bool)), this, SLOT(count_Right()));
            connect(&(_tile[i]), SIGNAL(leftClick(int,int)), this, SLOT(openTile(int,int)));
            connect(&(_tile[i]), SIGNAL(leftClick(int,int)), this, SLOT(count_Left()));
            _field->addWidget(&(_tile[i]), L, C);
        }
    }
}

Field::Field(int SIZE_LINEx, int SIZE_COLUMx, int SIZE_BOMBSx, QWidget *parent): QWidget{parent}
{
    this->SIZE_LINE  = SIZE_LINEx ;
    this->SIZE_COLUM = SIZE_COLUMx;
    this->SIZE_BOMBS = SIZE_BOMBSx;
    this->totalTiles = SIZE_LINE*SIZE_COLUM;

    //======================================================================================================================================
    // TILE
    _field = new QGridLayout();
    _field->setHorizontalSpacing(0);
    _field->setVerticalSpacing(0);
    loadTiles();

    //======================================================================================================================================
    // RESTART BUTTON
    QIcon Smiley_Face(":images/smiley_face.png");
    _restart = new QPushButton();
    _restart->setFixedSize(40, 40);
    _restart->setIcon(Smiley_Face);
    _restart->setStyleSheet(pushButtonStyle);
    connect(_restart, SIGNAL(clicked()), this, SLOT(resetField()));
    _restart->setShortcut(QKeySequence(Qt::Key_Space));

    //======================================================================================================================================
    // BOMB COUNTER
    _counter = new QLCDNumber();
    _counter->setSegmentStyle(QLCDNumber::Flat);
    _counter->setDigitCount(4);
    _counter->display(SIZE_BOMBS);
    _counter->setStyleSheet(QLCDNumberStyle);
    this->_flag_count = SIZE_BOMBS;

    //======================================================================================================================================
    // TIME COUNTER
    _timer = new QLCDNumber();
    _timer->setSegmentStyle(QLCDNumber::Flat);
    _timer->setDigitCount(4);
    _timer->display(0);
    _timer->setStyleSheet(QLCDNumberStyle);
    this->_time_count = 0;
    this->timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Field::updateTime);

    //======================================================================================================================================
    // LAYOUTS
    _UI_layout = new QHBoxLayout();
    _UI_layout->addWidget(_counter);
    _UI_layout->addStretch(1000);
    _UI_layout->addWidget(_restart);
    _UI_layout->addStretch(1000);
    _UI_layout->addWidget(_timer);

    _layout = new QVBoxLayout();
    _layout->addLayout(_UI_layout);
    _layout->addLayout(_field);
    setLayout(_layout);

    this->resetField();
}

//==========================================================================================================================================
// METHODS
void Field::loadBombs( int line , int colum)
{
    int totalBombs = 0;
    srand(time(0));
    while(totalBombs != SIZE_BOMBS)
    {
        int L = rand() % SIZE_LINE;
        int C = rand() % SIZE_COLUM;

        int i = L*SIZE_LINE + C;

        if(_tile[i].getBomb() == false and L != line and C != colum)
        {
            _tile[i].setBomb();
            totalBombs++;
        }
    }
}

void Field::mostraResult()
{
    ResultWindow *dialog = new ResultWindow(result, clique_direito, clique_esquerdo, _time_count-1);
    dialog->exec();
    delete dialog;
    clique_direito = 0; // Zera contagem pro próximo jogo;
    clique_esquerdo = 0; // Zera contagem pro próximo jogo;
}

void Field::endGame()
{
    result = true;
    QIcon Win_Face(":images/win_face.png");
    _restart->setIcon(Win_Face);
    this->timer->stop();
    this->gameStarted = true;

    for(int L = 0; L < SIZE_LINE; L++)
    {
        for(int C = 0; C < SIZE_COLUM; C++)
        {
            int i = L*SIZE_LINE + C;
            _tile[i].lockButton();
            if(_tile[i].getBomb() == true)
            {
                _tile[i].plotFlag();
            }
        }
    }
    this->_flag_count = 0;
    this->_counter->display(_flag_count);
    mostraResult();
}
void Field::plotBombs()
{
    result = false;
    QIcon Dead_Face(":images/dead_face.png");
    _restart->setIcon(Dead_Face);
    this->timer->stop();

    for(int L = 0; L < SIZE_LINE; L++)
    {
        for(int C = 0; C < SIZE_COLUM; C++)
        {
            int i = L*SIZE_COLUM + C;
            if(_tile[i].getBomb() == true and _tile[i].getState() != Exploded)
                _tile[i].plotBomb();
            _tile[i].lockButton();
        }
    }
    mostraResult();
}
void Field::reloadField(int SIZE_LINEx, int SIZE_COLUMx, int SIZE_BOMBSx)
{
    delete[] _tile;

    this->SIZE_LINE  = SIZE_LINEx ;
    this->SIZE_COLUM = SIZE_COLUMx;
    this->SIZE_BOMBS = SIZE_BOMBSx;
    this->totalTiles = SIZE_LINE*SIZE_COLUM;

    loadTiles();

    this->resetField();
    QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
}
//======================================================================================================================================
// SIGNALS

void Field::openTile(int line , int colum)
{
    if(this->gameStarted == false)
    {
        timer->start(1000);            // Inicia o timer com intervalo de 1 segundo (1000 ms)
        this->loadBombs(line, colum);
        this->gameStarted = true;
    }

    int i = line*SIZE_LINE + colum;

    if(_tile[i].getBomb() == true)
    {
        this->plotBombs();
    }
    else
    {
        int adjacentBombs = 0;


        for (int dr = -1; dr <= 1; ++dr)
        {
            for (int dc = -1; dc <= 1; ++dc)
            {
                if (dr == 0 && dc == 0) {
                    continue;
                }
                int checkLine = line + dr;
                int checkColum = colum + dc;

                if (checkLine >= 0 and checkLine < SIZE_LINE &&
                    checkColum >= 0 and checkColum < SIZE_COLUM)
                {
                    int adjacentIndex = checkLine * SIZE_COLUM + checkColum;

                    if (_tile[adjacentIndex].getBomb())
                    {
                        adjacentBombs++;
                    }
                }
            }
        }

        _tile[i].setAdjacentBombs(adjacentBombs);
        this->totalTiles--;

        if(adjacentBombs == 0){
            this->openField(line,colum);
        }
    }
    if(this->totalTiles == SIZE_BOMBS)
    {
        this->endGame();
    }
}

void Field::openField(int line , int colum)
{
    for (int dr = -1; dr <= 1; ++dr)
    {
        for (int dc = -1; dc <= 1; ++dc)
        {
            if (dr == 0 && dc == 0) {
                continue;
            }
            int checkLine = line + dr;
            int checkColum = colum + dc;

            if (checkLine >= 0 and checkLine < SIZE_LINE &&
                checkColum >= 0 and checkColum < SIZE_COLUM)
            {
                int adjacentIndex = checkLine * SIZE_COLUM + checkColum;

                if (_tile[adjacentIndex].getState() == Hidden or _tile[adjacentIndex].getState() == Flagged)
                {
                    this->openTile(checkLine,checkColum);
                }
            }
        }
    }
}

void Field::resetField()
{
    this->_time_count = 0;
    this->_flag_count = SIZE_BOMBS;
    this->totalTiles = SIZE_COLUM*SIZE_LINE;
    this->gameStarted = false;

    this->_timer->display(_time_count);
    this->timer->stop();
    this->_counter->display(_flag_count);

    for(int L = 0; L < SIZE_LINE; L++)
    {
        for(int C = 0; C < SIZE_COLUM; C++)
        {
            int i = L*SIZE_COLUM + C;
            _tile[i].setTile(L,C);
        }
    }
    QIcon Smiley_Face(":images/smiley_face.png");
    _restart->setIcon(Smiley_Face);
}
void Field::updateTime()
{
    _timer->display(this->_time_count++);
}
void Field::setFlag( bool count_action )
{
    if( count_action == false)
    {
        this->_flag_count++;
    }
    else
    {
        this->_flag_count--;
    }
    this->_counter->display(_flag_count);
}

//======================================================================================================================================
// CONTADORES DE CLIQUE

void Field::count_Right()
{
    clique_direito++;
}

void Field::count_Left()
{
    clique_esquerdo++;
}
