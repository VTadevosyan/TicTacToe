/**
 * Tic Tac Toe
 */

#include "gui/main_window.hpp"

#include <QApplication>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    try {
        QApplication app(argc, argv);
        main_window* w = new main_window;
        w->show();
        return app.exec();
    } catch(...) {
        QMessageBox m;
        m.setText("Unknown Exception!");
        m.exec();
    }
}
