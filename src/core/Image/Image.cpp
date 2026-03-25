#include "Image.h"

 QPixmap Image::getScaledPixmap(){

    QPixmap initial_image = this->get_original_representation();

    int width = initial_image.width();
    int height = initial_image.height();

    QPixmap rescaled_image = initial_image.scaled(width * this->zoom_factor, height * this->zoom_factor, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    return rescaled_image;

 }

//  void Image::zoomIn(){

//  }