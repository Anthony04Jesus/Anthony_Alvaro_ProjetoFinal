#include "tile.h"


const QString Tile::pushButtonStyle =
        "QPushButton {"
        "   background-color: #D3D3D3; /* Light gray */"
        "   border: 3px solid #808080; /* Darker gray border */"
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
        "QPushButton:checked {"
        "   background-color: #D3D3D3; /* Light gray */"
        "   border: 3px solid #808080; /* Darker gray border */"
        "   border-top-color: #FFFFFF; /* Lighter top border for 3D effect */"
        "   border-left-color: #FFFFFF; /* Lighter left border for 3D effect */"
        "   border-right-color: #808080; /* Darker right border */"
        "   border-bottom-color: #808080; /* Darker bottom border */"
        "   border-radius: 0px; /* Ensure no rounded corners */"
        "   font: bold 12pt 'Segoe UI', 'Arial'; /* Example font */"
        "   color: #000000; /* Default text color */"
        "}"
        "QPushButton:disabled {"
        "   background-color: #B0B0B0; /* Slightly darker when pressed */"
        "   border: 1px solid #808080; /* Invert the 3D effect when pressed */"
        "   border-top-color: #808080;"
        "   border-left-color: #808080;"
        "   border-right-color: #808080;"
        "   border-bottom-color: #808080;"
        "   color: #FF0000; /* Default text color */"
        "}";

Tile::Tile(QWidget * parent): QPushButton(parent)
{

    this->setEnabled(true);
    this->Bomb = false;
    this->state = Hidden;
    this->setStyleSheet(pushButtonStyle);
    this->line = 0;
    this->colum = 0;
}

void Tile::bombExploded()
{
    this->state = Exploded;
    this->setEnabled(false);
    this->setStyleSheet(
        "QPushButton:disabled {"
        "   background-color: #DDB0B0; /* Slightly darker when pressed */"
        "   border: 1px solid #808080; /* Invert the 3D effect when pressed */"
        "   border-top-color: #808080;"
        "   border-left-color: #808080;"
        "   border-right-color: #808080;"
        "   border-bottom-color: #808080;"
        "   color: #FF0000; /* Default text color */"
        "}"
        );
}

void Tile::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        switch(this->state)
        {
        case Hidden:
        {
            QIcon Flag_icon;
            Flag_icon.addPixmap(QPixmap(":images/Flag_icon.png"), QIcon::Disabled, QIcon::Off);
            setIcon(Flag_icon);
            this->state = Flagged;
            emit rightClick(true);
            break;
        }
        case Flagged:
        {
            setIcon(QIcon());
            this->state = Hidden;
            emit rightClick(false);
            break;
        }
        default:
            break;
        }
    }
    if(event->button() == Qt::LeftButton && this->state != Flagged)
    {
        if(this->Bomb == true and this->state == Hidden)
        {
            QIcon Bomb_icon;
            Bomb_icon.addPixmap(QPixmap(":images/explosion_icon.png"), QIcon::Disabled, QIcon::Off);
            setIcon(Bomb_icon);
            bombExploded();
        }
        emit leftClick(this->getLine(), this->getColum()); // call open field algorithm
    }
    QPushButton::mousePressEvent(event);
}

void Tile::plotBomb()
{
    QIcon Bomb_icon;
    Bomb_icon.addPixmap(QPixmap(":images/bomb_icon.png"), QIcon::Disabled, QIcon::Off);
    setIcon(Bomb_icon);
    bombExploded();
}
void Tile::plotFlag()
{
    QIcon WinFlag_icon;
    WinFlag_icon.addPixmap(QPixmap(":images/WinFlag_icon.png"), QIcon::Disabled, QIcon::Off);
    setIcon(WinFlag_icon);
    this->state = Flagged;
}

void Tile::setTile(int line, int colum)
{
    //this->blockSignals(false);
    this->line = line;
    this->colum = colum;
    this->state = Hidden;
    this->setEnabled(true);
    this->setIcon(QIcon());
    this->Bomb = false;
    this->setStyleSheet(pushButtonStyle);
}
void Tile::setAdjacentBombs(int adjacentBombs)
{
    switch(adjacentBombs)
    {
        case 0: {setIcon(QIcon()); break;}
        case 1: {QIcon Number_icon;  Number_icon.addPixmap(QPixmap(":images/one_icon.png"  ), QIcon::Disabled, QIcon::Off);  setIcon(Number_icon);  break;}
        case 2: {QIcon Number_icon;  Number_icon.addPixmap(QPixmap(":images/two_icon.png"  ), QIcon::Disabled, QIcon::Off);  setIcon(Number_icon);  break;}
        case 3: {QIcon Number_icon;  Number_icon.addPixmap(QPixmap(":images/three_icon.png"), QIcon::Disabled, QIcon::Off);  setIcon(Number_icon);  break;}
        case 4: {QIcon Number_icon;  Number_icon.addPixmap(QPixmap(":images/four_icon.png" ), QIcon::Disabled, QIcon::Off);  setIcon(Number_icon);  break;}
        case 5: {QIcon Number_icon;  Number_icon.addPixmap(QPixmap(":images/five_icon.png" ), QIcon::Disabled, QIcon::Off);  setIcon(Number_icon);  break;}
        case 6: {QIcon Number_icon;  Number_icon.addPixmap(QPixmap(":images/six_icon.png"  ), QIcon::Disabled, QIcon::Off);  setIcon(Number_icon);  break;}
        case 7: {QIcon Number_icon;  Number_icon.addPixmap(QPixmap(":images/seven_icon.png"), QIcon::Disabled, QIcon::Off);  setIcon(Number_icon);  break;}
        case 8: {QIcon Number_icon;  Number_icon.addPixmap(QPixmap(":images/eight_icon.png"), QIcon::Disabled, QIcon::Off);  setIcon(Number_icon);  break;}
    default:
        break;
    }
    this->setEnabled(false);
    this->state = Revealed;
}

Tile_State Tile::getState()           { return this->state;  }
bool Tile::getBomb(void)              { return this->Bomb;   }
int Tile::getLine(void)               { return this->line;   }
int Tile::getColum(void)              { return this->colum;  }
int Tile::getAdjascentBombs(void)     { return this->adjascentBombs;}
void Tile::setBomb()                  { this->Bomb = true;   }
void Tile::lockButton(void)
{
    this->setEnabled(false);
    if(this->state == Hidden or this->state == Flagged)
    {
        this->setStyleSheet
        (
            "QPushButton {"
            "   background-color: #D3D3D3; /* Light gray */"
            "   border: 3px solid #808080; /* Darker gray border */"
            "   border-top-color: #FFFFFF; /* Lighter top border for 3D effect */"
            "   border-left-color: #FFFFFF; /* Lighter left border for 3D effect */"
            "   border-right-color: #808080; /* Darker right border */"
            "   border-bottom-color: #808080; /* Darker bottom border */"
            "   border-radius: 0px; /* Ensure no rounded corners */"
            "   font: bold 12pt 'Segoe UI', 'Arial'; /* Example font */"
            "   color: #000000; /* Default text color */"
            "}"
        );
    }
}
