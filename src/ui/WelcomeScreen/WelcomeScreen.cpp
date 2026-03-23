// #include <QApplication>
// #include <QLabel>


#include "WelcomeScreen.h"


QWidget* WelcomeScreen::createWelcomeScreen(){

    QWidget* window = new QWidget();


    window->setFixedSize(this->width, this->height);
    window->setWindowTitle(this->title);
    std::cout << "TEST\n";

    // Create the button
    QPushButton* start_button = new QPushButton("Start");
    start_button->setFixedSize(120, 40);


    QObject::connect(start_button, &QPushButton::clicked, [window]() {
    MainScreen main_screen;
    QWidget* main_window = main_screen.createMainScreen();
    main_window->show();
    window->close();
    });

    // Create a layout that centers its contents
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addStretch();           // pushes button down from top
    layout->addWidget(start_button, 0, Qt::AlignHCenter); // centers horizontally
    layout->addStretch();           // pushes button up from bottom

    window->setLayout(layout);
    
    return window;


}