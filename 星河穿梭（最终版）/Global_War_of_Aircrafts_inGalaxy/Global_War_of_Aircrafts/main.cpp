#include "the_war_scenes.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    The_War_Scenes w;
    w.show();
    return a.exec();
}
