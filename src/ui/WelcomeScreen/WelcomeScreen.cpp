// #include <QApplication>
// #include <QLabel>


#include "WelcomeScreen.h"


QWidget* WelcomeScreen::createWelcomeScreen(){

    QWidget* window = new QWidget();


    window->setFixedSize(this->width, this->height);
    window->setWindowTitle(this->title);
    std::cout << "TEST\n";
    
    return window;


}

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
