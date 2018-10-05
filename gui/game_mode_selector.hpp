/**
 * Tic Tac Toe
 */

#ifndef GAME_MODE_SELECTOR_HPP
#define GAME_MODE_SELECTOR_HPP

#include <QWidget>
#include <QButtonGroup>

class QPushButton;

/**
 * @class game_mode_selector
 * @brief Game menu widget
 */
class game_mode_selector : public QWidget
{
    Q_OBJECT
public:
    /// @brief Constructor
    game_mode_selector(QWidget* parent = 0);

    /// @brief Get buttons group
    QButtonGroup* get_buttons_group() const;

private:
    /// @brief Construct widget
    void construct();

    /// @brief Setup widget layout
    void setup_layout();

    /// @brief Create font: Arial 30px bold
    void create_font();

    /// @brief Create singleplayer mode button
    void create_singleplayer_mode_button();

    /// @brief Create multiplayer mode button
    void create_multiplayer_mode_button();

    /// @brief Create Exit game button
    void create_exit_button();

    /// @brief Create button group for game mode selection
    void create_button_group();

private:
    QPushButton* m_single_mode;
    QPushButton* m_multiplayer_mode;
    QPushButton* m_exit_button;
    QWidget* m_parent;
    QFont* m_font;
    QButtonGroup* m_group;
    static const QSize m_minimum_size;
};

#endif // GAME_MODE_SELECTOR_HPP
