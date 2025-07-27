#include "tile.h"
#include <QDebug>
#include <QMouseEvent>




Tile::Tile(QWidget * parent): QPushButton(parent)
{
    this->setEnabled(true);
    this->Bomb = false;
    this->state = Hidden;
    this->adjacentMines = 0;//rand() % (8 + 1);
    this->setStyleSheet(
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
        "}"
        );
}

void Tile::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        switch(state)
        {
        case Hidden: {QIcon Flag_icon(":images/Flag_icon.png"); setIcon(Flag_icon); this->state = Flagged; emit rightClick(true); break;}
        case Flagged: setIcon(QIcon()); state = Hidden; break;
        case Revealed:
        case Exploded:   //qDebug() << "Exploded";
        default:
            break;
        }
        //if(state != Exploded)
            //emit rightClick(state);
    }

    if(event->button() == Qt::LeftButton)
    {
        switch(this->state)
        {
        case Hidden:
            if(this->Bomb == false)
            {
                switch(this->adjacentMines)
                {
                case 0: {setIcon(QIcon()); break;}
                case 1:
                {
                    QIcon Number_icon;
                    Number_icon.addPixmap(QPixmap(":images/one_icon.png"  ), QIcon::Disabled, QIcon::Off);
                    setIcon(Number_icon);
                    break;
                }
                case 2: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/two_icon.png"  ), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
                case 3: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/three_icon.png"), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
                case 4: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/four_icon.png" ), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
                case 5: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/five_icon.png" ), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
                case 6: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/six_icon.png"  ), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
                case 7: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/seven_icon.png"), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
                case 8: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/eight_icon.png"), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
                default:
                    break;
                }
                this->setEnabled(false);
                this->state = Revealed;
                // call open field algorithm
            }
            else
            {
                QIcon Bomb_icon;
                Bomb_icon.addPixmap(QPixmap(":images/bomb_icon.png"), QIcon::Disabled, QIcon::Off);
                setIcon(Bomb_icon);
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
                emit exploded();
                // call end game function
            }
            break;
        case Flagged:
        case Revealed:
        case Exploded:
        default:
            break;
        }
    }
    QPushButton::mousePressEvent(event);
}

void Tile::plotBombs()
{
    QIcon Bomb_icon;
    Bomb_icon.addPixmap(QPixmap(":images/bomb_icon.png"), QIcon::Disabled, QIcon::Off);
    setIcon(Bomb_icon);
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
void Tile::setTile()
{
    this->state = Hidden;
    this->setEnabled(true);
    this->setIcon(QIcon());
    this->adjacentMines = rand() % (8 + 1);
    this->Bomb = false;
    this->setEnabled(true);
    this->setStyleSheet(
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
        "}"
        );
}

Tile_State Tile::getState()           { return this->state;  }
bool Tile::getBomb()                  { return this->Bomb;   }
void Tile::setState(Tile_State state) { this->state = state; }
void Tile::setBomb()                  { this->Bomb = true;   }

