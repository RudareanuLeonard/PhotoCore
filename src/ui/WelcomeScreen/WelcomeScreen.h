#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QtWidgets>
#include <cstring>
#include <iostream>

#include "../Screen/Screen.h"

class WelcomeScreen : public Screen{

    public:
    // std::QString title;
    QString title;
    int width, height;

    WelcomeScreen(QString title="PhotoCore", int width = 800, int height = 600) : Screen(width, height), title(title), width(width), height(height){
    }

    QWidget* createWelcomeScreen();
};