/**
 * Tic Tac Toe
 */

#ifndef PLAYER_PLAYER_HPP
#define PLAYER_PLAYER_HPP

class abstract_item;
class QPointF;

/**
 * @class player
 * @brief The base class for Players
 */
class player
{
public:
    /// @brief Constructor
    player()
    {
    }

    /// @brief Destructor
    virtual ~player()
    {
    }

    /// @brief Take turn
    virtual void do_step(const unsigned&) = 0;

    /// @brief Create and draw 'X' or 'O' shape
    virtual void create_item(const unsigned&) = 0;

    /// @brief Get item for drawing
    virtual abstract_item* get_item()
    {
        return m_item;
    }

protected:
    abstract_item* m_item;
};


#endif //end of PLAYER_PLAYER_HPP
