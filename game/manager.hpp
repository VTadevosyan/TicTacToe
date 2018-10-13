/**
 * Tic Tac Toe
 */

#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include "options.hpp"

#include <QObject>
#include <vector>

/// Forward declarations
class abstract_item;
class player;
class player_x;
class player_o;
class QPointF;
class abstract_item;

/**
 * @class manager
 * @brief The Game manager
 */
class manager : public QObject
{
public:

    /// @brief Game status
    enum status {
        in_the_game = 0, win, lose, draw, not_started
    };

    /// @brief Get game manager instance
    static manager* get_instance(bool = false);

    /// @brief Get 'X' or 'O' item to draw
    abstract_item* get_item();

    /// @brief Destructor
    virtual ~manager();

    /// @brief Start game
    void start();

    /// @brief Set game options
    void set_options(const options&);

    /// @brief Set game status
    void set_game_status(const status&);

    /// @brief Set main window background image path
    void set_window_bg_image_path(const QString&);

    /// @brief Get main window background image path
    QString get_window_bg_image_path() const;

    /// @brief Set board background image path
    void set_board_bg_image_path(const QString&);

    /// @brief Get board background image path
    QString get_board_bg_image_path() const;

    /// @brief Set 'X' & 'O' shapes path
    void set_item_image_path(const std::pair<QString, QString>&);

    /// @brief Get 'X' & 'O' shapes path
    std::pair<QString, QString> get_item_image_path() const;

    /// @brief Take player 'X' turn
    /// @param[in] section index
    void take_turn(const unsigned&);

    /// @brief Set game mode: Multiple if true, single otherwise
    void set_game_mode(bool t);

    /// @brief Return true if multiple game, false otherwise
    bool is_multiple_game() const;

    /// @brief Return true, if 'X' player turn, false otherwise
    bool is_x_player_turn() const;

    /// @brief Return true, if specified section is empty
    bool is_section_empty(const unsigned&);

    /// @brief Check and get game status
    status check_game_status();

    /// @brief Retrieve drawing victorious line sections
    void get_victorious_line(std::vector<unsigned>&);

    /// @brief Do CPU turn
    void do_player_cpu_turn(unsigned&);

signals:
    void game_status_changed(status);

public slots:
    /// @brief Finish game
    void finish_game(bool = false);

private:
    /// @brief Constructor
    /// @param[in] t true if multiple game, false otherwise
    manager(bool t = false);

    /// @brief Create game options and initialize
    void initialize_game_options();

    /// @brief Create board data and initialize
    void initialize_board_data();

    /// @brief Set victorious line
    void set_victorious_line(const unsigned&,
            const unsigned&, const unsigned&);

    /// @brief Do player 'X' turn
    void do_player_x_turn(const unsigned&);

    /// @brief Do player 'O' turn
    void do_player_o_turn(const unsigned&);

    /**
     * @brief Do CPU steps and get section
     */
    /// STEP 1
    void do_cpu_step_1(unsigned&);

    /// STEP 2
    void do_cpu_step_2(unsigned&);

    /// STEP 3
    void do_cpu_step_3(unsigned&);

    /// STEP 4
    void do_cpu_step_4(unsigned&);

    /// @brief Check, if CPU can take victorious turn, do it!
    ///        Check, if opponent can win game and abort it!
    void check_and_take_turn(const char&, unsigned&);

    /// @brief Do CPU random step, when can do any turn
    void do_cpu_random_step(unsigned&);

private:
    static manager* m_instance;
    static const char m_empty_symbol;
    static const char m_x_symbol;
    static const char m_o_symbol;

private:
    std::vector<char> m_board_data;
    std::vector<unsigned> m_victorious_line;
    options m_game_options;
    status m_game_status;
    abstract_item* m_item;
    player_x* m_player_x;
    player_o* m_player_o;
    unsigned m_cpu_steps;
    bool m_is_multiple_game;
    bool m_is_player_x_turn;
};

#endif // GAME_MANAGER_HPP
