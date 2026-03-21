#include "MainScreen.h"

QWidget* MainScreen::createMainScreen() {
    QWidget* window = new QWidget();

    window->setFixedSize(this->width, this->height);
    window->setWindowTitle(this->title);

    return window;
}

