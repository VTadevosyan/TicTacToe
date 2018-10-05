/**
 * Tic Tac Toe
 */

#include "gui/actions.hpp"
#include "gui/main_window.hpp"
#include "gui/menu.hpp"
#include "gui/game_mode_selector.hpp"
#include "game/manager.hpp"

#include <QCloseEvent>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QPalette>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <list>

#include <iostream>

namespace main_window_options {

static const QString window_title = "Tic Tac Toe";

} // main_window_options

const QSize main_window::m_minimum_size = QSize(800, 620);

main_window::main_window(QWidget *parent)
    : QMainWindow(parent)
{
    construct();
    m_menu = new menu(menuBar(), this);
    m_menu->initialize();
    connect(m_menu->game_action_group(), SIGNAL(triggered(QAction*)), this, SLOT(actionEvent(QAction*)));
    connect(m_menu->info_action_group(), SIGNAL(triggered(QAction*)), this, SLOT(actionEvent(QAction*)));
}

main_window::~main_window()
{
    deleteLater();
}

void main_window::construct()
{
    create_game_selector();
    setup_window();
}

void main_window::create_board()
{
    m_board = new board(this);
    QHBoxLayout* lh = new QHBoxLayout;
    lh->addStretch();
    lh->addWidget(m_board);
    lh->addStretch();
    QVBoxLayout* lv = new QVBoxLayout;
    lv->addStretch();
    lv->addLayout(lh);
    lv->addStretch();
    QWidget* w = new QWidget(this);
    w->setLayout(lv);
    setCentralWidget(w);
    connect(m_board, SIGNAL(game_status_changed(uint)), SLOT(end_game(uint)));
    connect(m_board, SIGNAL(game_status_changed(uint)), SLOT(show_game_mode_selector()));
}

void main_window::create_game_selector()
{
    m_selector = new game_mode_selector(this);
    setCentralWidget(m_selector);
    setMinimumSize(m_minimum_size);
    connect(m_selector->get_buttons_group(), SIGNAL(buttonClicked(int)), this, SLOT(set_game_mode(int)));
}

void main_window::start_game(bool mode)
{
    set_game_mode(mode);
}

void main_window::set_game_mode(int mode)
{
    m_manager = manager::get_instance(mode);
    Q_ASSERT(m_manager != 0);
    m_manager->set_game_mode(mode);
    m_manager->start();
    create_board();
}

void main_window::setup_window()
{
    manager* m = manager::get_instance();
    set_background_image(m->get_window_bg_image_path());
    setMinimumSize(m_minimum_size);
    setWindowTitle(main_window_options::window_title);
    setWindowIcon(QIcon("img/tic_tac_toe.png"));
}

void main_window::end_game(const unsigned& s)
{
    QMessageBox m(this);
    m.setFixedSize(QSize(300, 190));
    m.setStyleSheet("font: 30px;");
    switch(s) {
    case manager::win:
        m.setText("YOU WIN!");
        m.exec();
        break;
    case manager::lose:
        m.setText("YOU LOSE!");
        m.exec();
        break;
    case manager::draw:
        m.setText("DRAW!");
        m.exec();
    }
    m_board->clear();
    m_manager->game_finished();
}

void main_window::show_game_mode_selector()
{
    create_game_selector();
}

void main_window::return_main_menu()
{
    Q_ASSERT(m_manager != 0);
    if (m_manager->check_game_status() == manager::in_the_game) {
        const QString msg = "Show Main Menu. The game will be lost\nAre You Sure?";
        QMessageBox::StandardButton btn = QMessageBox::warning(this, main_window_options::window_title,
                                                               msg, QMessageBox::Ok | QMessageBox::Cancel);
        if (btn == QMessageBox::Ok) {
            show_game_mode_selector();
        }
    }
}

void main_window::closeEvent(QCloseEvent* e)
{
    Q_ASSERT(m_manager != 0);
    const QString msg = (m_manager->check_game_status() == manager::in_the_game)
                ? "If You close window now, the game will be lost!"
                : "Are You Sure?";
    QMessageBox::StandardButton btn = QMessageBox::warning(this, main_window_options::window_title,
                                                           msg, QMessageBox::Ok | QMessageBox::Cancel);
    btn == QMessageBox::Ok ? e->accept() : e->ignore();
}

void main_window::actionEvent(QAction* e)
{
    std::list<base_action*> al = m_menu->actions();
    auto it = al.begin();
    for(; it != al.end(); ++it) {
        if(e == *it) {
            (*it)->execute();
            return;
        }
    }
    Q_ASSERT(it != al.end());
}

void main_window::set_styles()
{
    manager* m = manager::get_instance();
    Q_ASSERT(m != 0);
    set_background_image(m->get_window_bg_image_path());
    if (m->check_game_status() == manager::in_the_game) {
        m_board->set_background_image(m->get_board_bg_image_path());
    }
}

void main_window::set_background_image(const QString& s)
{
    QPalette p;
    QPixmap bg(s);
    p.setBrush(QPalette::Background, bg);
    setPalette(p);
}

