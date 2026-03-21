#include <QApplication>
#include <QLabel>

#pragma once

class Screen{
    public:
    int width;
    int height;

    Screen(int width=300, int height=300){
        this->width = width;
        this->height = height;
    }


};