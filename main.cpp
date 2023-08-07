#include <QApplication>
#include "VstManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    VstManager window;
    window.show();

    return app.exec();
}
