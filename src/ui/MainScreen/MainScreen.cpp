#include "MainScreen.h"

QWidget* MainScreen::createMainScreen() {
    QWidget* window = new QWidget();

    window->setFixedSize(this->width, this->height);
    window->setWindowTitle(this->title);

    QPushButton* load_photo_button = new QPushButton("Load Photo");
    load_photo_button->setFixedSize(120, 40);

    QPushButton* rotate_left_button = new QPushButton("↺ Rotate Left");
    rotate_left_button->setFixedSize(120, 40);
    rotate_left_button->setEnabled(false);

    QPushButton* rotate_right_button = new QPushButton("↻ Rotate Right");
    rotate_right_button->setFixedSize(120, 40);
    rotate_right_button->setEnabled(false);

    QVBoxLayout* layout = new QVBoxLayout();
    QLabel* image_label = new QLabel();
    image_label->setAlignment(Qt::AlignCenter);

    // Rotation buttons side by side above Load Photo
    QHBoxLayout* rotate_layout = new QHBoxLayout();
    rotate_layout->addStretch();
    rotate_layout->addWidget(rotate_left_button);
    rotate_layout->addWidget(rotate_right_button);
    rotate_layout->addStretch();

    layout->addStretch();
    layout->addWidget(image_label, 0, Qt::AlignCenter);
    layout->addStretch();
    layout->addLayout(rotate_layout);
    layout->addSpacing(8);
    layout->addWidget(load_photo_button, 0, Qt::AlignHCenter);

    // Store the current pixmap so rotation always applies to the displayed image
    QPixmap* current_pixmap = new QPixmap();

    QObject::connect(load_photo_button, &QPushButton::clicked,
        [image_label, rotate_left_button, rotate_right_button, current_pixmap]() {
            QString fileName = QFileDialog::getOpenFileName(nullptr, "Open Image", "/home/", "Image Files (*.png *.jpg *.bmp)");
            if (fileName.isEmpty()) return;

            QPixmap image(fileName);
            *current_pixmap = image.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            image_label->setPixmap(*current_pixmap);

            rotate_left_button->setEnabled(true);
            rotate_right_button->setEnabled(true);
        });

    QObject::connect(rotate_left_button, &QPushButton::clicked,
        [image_label, current_pixmap]() {
            QTransform transform;
            transform.rotate(-90);
            *current_pixmap = current_pixmap->transformed(transform, Qt::SmoothTransformation);
            image_label->setPixmap(*current_pixmap);
        });

    QObject::connect(rotate_right_button, &QPushButton::clicked,
        [image_label, current_pixmap]() {
            QTransform transform;
            transform.rotate(90);
            *current_pixmap = current_pixmap->transformed(transform, Qt::SmoothTransformation);
            image_label->setPixmap(*current_pixmap);
        });

    window->setLayout(layout);
    return window;
}