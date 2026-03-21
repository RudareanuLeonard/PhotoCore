#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QtWidgets>
#include <cstring>
#include <iostream>
#include <QObject>

#pragma once

#include "../Screen/Screen.h"

class MainScreen : public Screen{

    public:
    // std::QString title;
    QString title;
    int width, height;

    MainScreen(QString title="Main Screen", int width = 1000, int height = 1000) : Screen(width, height), title(title), width(width), height(height){
    }

    QWidget* createMainScreen();
};