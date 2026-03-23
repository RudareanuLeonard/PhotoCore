#include "MainScreen.h"

QWidget* MainScreen::createMainScreen() {
    QWidget* window = new QWidget();

    window->setFixedSize(this->width, this->height);
    window->setWindowTitle(this->title);

     // Create the button
    QPushButton* load_photo_button = new QPushButton("Load Photo");
    load_photo_button->setFixedSize(120, 40);

    QString file_url;

    QVBoxLayout* layout = new QVBoxLayout();
    QLabel *image_label = new QLabel();

    image_label->setAlignment(Qt::AlignCenter);

    layout->addStretch();
    layout->addWidget(image_label, 0, Qt::AlignCenter);  // fixed position in center
    layout->addStretch();
    layout->addWidget(load_photo_button, 0, Qt::AlignHCenter);  // button at bottom


    QObject::connect(load_photo_button, &QPushButton::clicked, [window, layout, image_label]() { //$file_url <- capture by reference so it can be modified
        std::cout << "Load photo button pressed\n";

        QString fileName = QFileDialog::getOpenFileName(nullptr, "Open Image", "/home/", "Image Files (*.png *.jpg *.bmp)");

        std::cout << "fileName = " << fileName.toStdString() << "\n";
        
        QPixmap image(fileName);
        QPixmap scaled_image = image.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        image_label->setPixmap(scaled_image);
        
        
        // layout->update();

        // window->update();

    });



 
    // layout->addStretch();

    // layout->addWidget(load_photo_button, 0, Qt::AlignHCenter);

    window->setLayout(layout);


    return window;
}


