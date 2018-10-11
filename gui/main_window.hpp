/**
 * Tic Tac Toe
 */

#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include "gui/board.hpp"

#include <QMainWindow>
#include <QSize>

class manager;
class menu_bar;
class game_mode_selector;
class QButtonGroup;
class QCloseEvent;

/**
 * @class main_window
 * @brief Tic Tac Toe game Main Window class implementation
 */
class main_window : public QMainWindow
{
    Q_OBJECT
public:
    /// @brief Constructor
    main_window(QWidget* parent = 0);

    /// @brief Destructor
    virtual ~main_window();

    /// @brief Close Event
    virtual void closeEvent(QCloseEvent*) override;

    /// @brief Start game single or multiple mode
    void start_game(bool = false);

    /// @brief Apply window and board styles
    void set_styles();

    /// @brief Abort game and return main menu
    void return_main_menu();

private:
    /// @brief Construct main window
    void construct();

     /// @brief setup main window options
     /// ex: size, icon, title and etc...
    void setup_window();

    /// @brief Setup central widget
    void create_board();

    /// @brief Create game selector widget
    void create_game_selector();

    /// @brief set Main window background image
    void set_background_image(const QString&);

private slots:
    /// @brief End game and show winner name
    void end_game(const unsigned&);

    /// @brief Set game mode
    void set_game_mode(int);

    /// @brief Action Event
    void actionEvent(QAction*);

    /// @brief Show game mode selector home widget
    void show_game_mode_selector();

private:
    manager* m_manager;
    menu_bar* m_menu_bar;
    board* m_board;
    game_mode_selector* m_selector;
    QButtonGroup* m_group;

    /// Main window minimum size
    static const QSize m_minimum_size;
};

#endif // MAIN_WINDOW_HPP
