/**
 * Tic Tac Toe
 */

#include "gui/actions.hpp"
#include "gui/main_window.hpp"
#include "gui/style_dialog.hpp"
#include "game/logging.hpp"
#include "game/manager.hpp"
#include "game/options.hpp"

#include <iostream>

/// Base action
base_action::base_action(const QIcon& i, const QString& t, QObject* p)
        : QAction(i, t, p)
        , m_parent(static_cast<main_window*>(p))
{
}

base_action::~base_action()
{
    deleteLater();
}

/// New game action
new_game_action::new_game_action(const QIcon& i, const QString& t, QObject* p, bool mltp)
        : base_action(i, t, p)
        , m_is_multiple_game(mltp)
{
}

void new_game_action::execute() const
{
    manager* m = manager::get_instance();
    Q_ASSERT(m != 0);
    if (m->check_game_status() == manager::in_the_game) {
        m->set_game_status(manager::lose);
        m->finish_game(true);
        m_parent->start_game(m->is_multiple_game());
    }
}

/// Main menu action
main_menu_action::main_menu_action(const QIcon& i, const QString& t, QObject* p)
        : base_action(i, t, p)
{
}

void main_menu_action::execute() const
{
    manager* m = manager::get_instance();
    Q_ASSERT(m != 0);
    if (m->check_game_status() == manager::in_the_game) {
        Q_ASSERT(m_parent != 0);
        m_parent->return_main_menu();
    }
}

/// Style action
style_action::style_action(const QIcon& i, const QString& t, QObject* p)
        : base_action(i, t, p)
{
}

void style_action::execute() const
{
    manager* m = manager::get_instance();
    Q_ASSERT(m != 0);
    options o(m->get_window_bg_image_path(),
              m->get_board_bg_image_path(),
              m->get_item_image_path());
    style_dialog d;
    d.setModal(true);
    d.exec();
    if (d.result() == QDialog::Accepted) {
        m_parent->set_styles();
    } else {
        m->set_options(o);
    }
}

/// Help action
help_action::help_action(const QIcon& i, const QString& t, QObject* p)
        : base_action(i, t, p)
{
}

void help_action::execute() const
{
}

/// About action
about_action::about_action(const QIcon& i, const QString& t, QObject* p)
        : base_action(i, t, p)
{
}

void about_action::execute() const
{
}

/// Exit Game action
exit_action::exit_action(const QIcon& i, const QString& t, QObject* p)
        : base_action(i, t, p)
{
}

void exit_action::execute() const
{
    Q_ASSERT(m_parent != 0);
    m_parent->close();
}
