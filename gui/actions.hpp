/**
 * Tic Tac Toe
 */

#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include <QAction>
#include <QIcon>

class main_window;

/// @class base_action
/// @brief base class for game actions
class base_action : public QAction
{
public:
    /// @brief Constructor
    base_action(const QIcon&, const QString&, QObject* = 0);

    /// @brief Destructor
    virtual ~base_action();

    /// @brief Execute action(Pure virtual function)
    virtual void execute() const = 0;

protected:
    main_window* m_parent;
};

/// @class new_game_action
/// @brief New game action
class new_game_action : public base_action
{
public:
    /// @brief Constructor
    new_game_action(const QIcon&, const QString&, QObject* = 0, bool = false);

    /// @brief Execute new game action
    virtual void execute() const override;

private:
    bool m_is_multiple_game;
};

/// @class main_menu_action
/// @brief Show Main menu
class main_menu_action : public base_action
{
public:
    /// @brief Constructor
    main_menu_action(const QIcon&, const QString&, QObject* = 0);

    /// @brief Execute show main menu action
    virtual void execute() const override;
};

/// @class style_action
/// @brief Change Style action
class style_action : public base_action
{
public:
    /// @brief Constructor
    style_action(const QIcon&, const QString&, QObject* = 0);

    /// @brief Execute new game action
    virtual void execute() const override;
};

/// @class exit_action
/// @brief Exit Game action
class exit_action : public base_action
{
public:
    /// @brief Constructor
    exit_action(const QIcon&, const QString&, QObject* = 0);

    /// @brief Execute new game action
    virtual void execute() const override;
};

/// @class help_action
/// @brief Help
class help_action : public base_action
{
public:
    /// @brief Constructor
    help_action(const QIcon&, const QString&, QObject* = 0);

    /// @brief Execute new game action
    virtual void execute() const override;
};

/// @class about_action
/// @brief About action
class about_action : public base_action
{
public:
    /// @brief Constructor
    about_action(const QIcon&, const QString&, QObject* = 0);

    /// @brief Execute new game action
    virtual void execute() const override;
};

#endif // ACTIONS_HPP
