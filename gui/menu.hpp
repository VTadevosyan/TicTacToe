/**
 * Tic Tac Toe
 */

#ifndef MENU_HPP
#define MENU_HPP

#include <QWidget>
#include <QMenuBar>

#include <list>

class QAction;
class QActionGroup;
class QMenu;
class QWidget;

/**
 * @class menu_bar
 * @brief The menu bar class
 */
class menu_bar : public QMenuBar
{
public:
    /// @brief Constructor
    menu_bar(QWidget* const = 0);

    /// @brief Destructor
    ~menu_bar();

    /// @brief Initialize menu
    void initialize();

    /// @brief Get parent widget
    virtual QWidget* parent() const;

    /// @brief Get game action group
    QActionGroup* game_action_group() const;

    /// @brief Get info action group
    QActionGroup* info_action_group() const;

    /// @brief Get actions list
    std::list<base_action*> actions() const;

private:
    /// @brief Create and setup menu
    void setup_menu();

    /// @brief Fill actions data
    void fill_actions_data();

    /// @brief Create action groups
    void create_action_groups();

    /// @brief Create menus and add actions
    void create_menus();

private:
    QWidget* m_parent;
    std::list<base_action*> m_actions;
    QActionGroup* m_game_action_group;
    QActionGroup* m_info_action_group;
    /// Menus
    QMenu* m_game_menu;
    QMenu* m_info_menu;
};

#endif // MENU_HPP
