// #include <QApplication>
// #include <QLabel>


#include "WelcomeScreen.h"

void WelcomeScreen::createWelcomeScreen(){

    QWidget window;


    window.setFixedSize(this->width, this->height);
    window.setWindowTitle(this->title);

    window.show();


}

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);


    WelcomeScreen welcome_screen;

    welcome_screen.createWelcomeScreen();


}
