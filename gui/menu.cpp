/**
  * Tic Tac Toe
  */

#include "gui/actions.hpp"
#include "gui/menu.hpp"
#include "game/manager.hpp"

#include <QMessageBox>

#include <iostream>

menu::menu(QMenuBar* mb, QWidget* p)
        : m_parent(p)
        , m_menu_bar(mb)
        , m_game_action_group(0)
        , m_info_action_group(0)
        , m_game_menu(0)
        , m_info_menu(0)
{
    Q_ASSERT(m_menu_bar != 0);
}

menu::~menu()
{
}

void menu::initialize()
{
    setup_menu();
    fill_actions_data();
}

QWidget* menu::parent() const
{
    return m_parent;
}

QActionGroup* menu::game_action_group() const
{
    return m_game_action_group;
}

QActionGroup* menu::info_action_group() const
{
    return m_info_action_group;
}

std::list<base_action*> menu::actions() const
{
    return m_actions;
}

void menu::setup_menu()
{
    Q_ASSERT(m_menu_bar != 0);
    create_action_groups();
    create_menus();
}

void menu::create_action_groups()
{
    manager* m = manager::get_instance();
    Q_ASSERT(m != 0);
    try {
        m_game_action_group = new QActionGroup(m_menu_bar);
        m_info_action_group = new QActionGroup(m_menu_bar);
        m_game_action_group->addAction(
                    new main_menu_action(QIcon("img/main_menu.png"), "Main Menu", m_parent));
        m_game_action_group->addAction(
                    new new_game_action(QIcon("img/blue.ico"), "New Game", m_parent, m->is_multiple_game()));
        m_game_action_group->addAction(
                    new style_action(QIcon("img/style.png"), "Style", m_parent));
        m_game_action_group->addAction(
                    new exit_action(QIcon("img/quit.png"), "Quit", m_parent));
        m_info_action_group->addAction(
                    new help_action(QIcon("img/help.svg"), "Help", m_parent));
        m_info_action_group->addAction(
                    new about_action(QIcon("img/info.png"), "About", m_parent));
    } catch(const std::bad_alloc&) {
        QMessageBox msg;
        msg.setText("Can not allocate memory!");
        msg.exec();
        m_parent->close();
    }
}

void menu::create_menus()
{
    m_game_menu = new QMenu(QString("&Game"));
    m_info_menu = new QMenu(QString("&About"));
    m_game_menu->addActions(m_game_action_group->actions());
    m_info_menu->addActions(m_info_action_group->actions());
    m_menu_bar->addMenu(m_game_menu);
    m_menu_bar->addMenu(m_info_menu);
}

void menu::fill_actions_data()
{
    Q_ASSERT(m_game_action_group != 0);
    Q_ASSERT(m_info_action_group != 0);
    auto end_it = m_game_action_group->actions().end();
    for(auto it = m_game_action_group->actions().begin(); it != end_it; ++it) {
        m_actions.push_back(static_cast<base_action*>(*it));
    }
    end_it = m_info_action_group->actions().end();
    for(auto it = m_info_action_group->actions().begin(); it != end_it; ++it) {
        m_actions.push_back(static_cast<base_action*>(*it));
    }
}
