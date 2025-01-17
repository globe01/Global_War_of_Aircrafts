QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG +=resources_big

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bomb.cpp \
    bullet.cpp \
    fort.cpp \
    fort_reverse.cpp \
    golden_ball.cpp \
    golden_ball_reverse.cpp \
    gundam.cpp \
    gundam_reverse.cpp \
    heroguardians.cpp \
    hole.cpp \
    laser.cpp \
    main.cpp \
    the_war_scenes.cpp \
    ufo_aircraft.cpp \
    warmap.cpp

HEADERS += \
    bomb.h \
    bullet.h \
    config.h \
    fort.h \
    fort_reverse.h \
    golden_ball.h \
    golden_ball_reverse.h \
    gundam.h \
    gundam_reverse.h \
    heroguardians.h \
    hole.h \
    laser.h \
    the_war_scenes.h \
    ufo_aircraft.h \
    warmap.h

FORMS += \
    the_war_scenes.ui

TRANSLATIONS += \
    Global_War_of_Aircrafts_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
