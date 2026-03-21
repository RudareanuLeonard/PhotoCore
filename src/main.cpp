#include <QApplication>
#include "ui/WelcomeScreen/WelcomeScreen.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    WelcomeScreen welcome_screen;
    QWidget* welcome_window = welcome_screen.createWelcomeScreen();

    welcome_window->show();

    int result = app.exec();
    delete welcome_window;
    return result;
}
