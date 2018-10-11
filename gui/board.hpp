/**
 * Tic Tac Toe
 */

#ifndef BOARD_HPP
#define BOARD_HPP


#include <QGraphicsView>
#include <QMouseEvent>

#include <vector>

#include <iostream>


/// forward declarations
class QGraphicsScene;
class manager;
class abstract_item;
class item_o;
class item_x;

/**
 * @class board
 * @brief Board class declaration
 */
class board : public QGraphicsView
{
    Q_OBJECT
public:
    /// @brief Constructor
    board(QWidget* parent = 0);

    /// @brief Destructor
    ///virtual ~board();

    /// @brief Board sections enumeration
    enum section
    {
        section_1 = 1, section_2, section_3,
        section_4, section_5, section_6,
        section_7, section_8, section_9
    };

    /// @brief Mouse move event: Highligth specified sections
    virtual void mouseMoveEvent(QMouseEvent*) override;

    /// @brief Mouse press event
    virtual void mousePressEvent(QMouseEvent*) override;

    /// @brief Mouse leave event: Clear board highligthing
    virtual void leaveEvent(QEvent*) override;

    /// @brief Find mouse pressed section on board
    static section find_section(const QPointF&);

    /// @brief return false if section empty, false otherwise
    static bool check_section(const unsigned&);

    /// @brief create sections vector and initialize with 0
    static std::vector<bool> crate_sections_vector();

    /// @brief Set Board background style
    void set_background_image(const QString&);

    /// @brief Clear board
    void clear();

signals:
    void game_status_changed(const unsigned&);

private:
    /// @brief Initialize board
    void initialize();

    /// @brief Create scene
    void create_scene();

    /// @brief Draw empty board 3x3
    void draw_empty_board();

    /// @brief Add item to board and update data
    void update_board_data(abstract_item*, const unsigned&);

    /// @brief Return true if board full, false otherwise
    bool is_full() const;

    /// @brief Draw victorius line, when the game is over
    ///        Green if player 'X' win, red otherwise
    /// @param[in] gs game status
    /// @param[in] sv sections vector
    void draw_victorious_line(const unsigned& gs,
            const std::vector<unsigned>& v);

    /// @brief Draw victorious green line for 'X' player
    void draw_victorious_x_line(const std::vector<unsigned>& v);

    /// @brief Draw victorious red line for 'O' player
    void draw_victorious_o_line(const std::vector<unsigned>& v);

    /// @brief Finish game if game status changed
    void finish_game(const unsigned&);

    /// @brief Clear board highlitgthing
    void clear_highligthing();

    /// @brief Retrieve active section from mouse position
    void get_active_section(section);

private:
    QGraphicsScene* m_scene;
    QGraphicsRectItem* m_active_section;
    static const QRect m_scene_rect;
    static const QSize m_board_size;
    static std::vector<bool> m_section;
    static unsigned m_board_shapes_count;
};

#endif // BOARD_HPP
