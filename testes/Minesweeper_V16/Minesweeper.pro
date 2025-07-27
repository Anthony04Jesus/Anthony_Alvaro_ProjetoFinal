QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += windows
# CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutwindow.cpp \
    field.cpp \
    game.cpp \
    main.cpp \
    resultwindow.cpp \
    tile.cpp

HEADERS += \
    aboutwindow.h \
    field.h \
    game.h \
    resultwindow.h \
    tile.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS +=

RESOURCES += \
    images.qrc


