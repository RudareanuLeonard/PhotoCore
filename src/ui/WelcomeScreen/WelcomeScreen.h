#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <cstring>

#include "../Screen/Screen.h"

class WelcomeScreen : public Screen{

    public:
    // std::QString title;
    QString title;
    int width, height;

    WelcomeScreen(QString title="PhotoCore") : Screen(width, height){
        this->title = title;
    }

    void createWelcomeScreen();
};