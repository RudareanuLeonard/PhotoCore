#pragma once


#include <iostream>
#include <QPixmap>


class Image{

    private:
        int width, height;
        float zoom_factor;
        QPixmap original_representation;

    public:

    Image(int width, int height, float zoom_factor, QPixmap original_representation){
        this->width = width;
        this->height = height;
        this->zoom_factor = zoom_factor;
        this->original_representation = original_representation;
    }

    QPixmap get_original_representation(){
        return this->original_representation;
    }

    QPixmap getScaledPixmap();
    void zoomIn();
    void zoomOut();
    


};