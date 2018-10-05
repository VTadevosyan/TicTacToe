/**
 * Tic Tac Toe
 */

#ifndef PLAYER_X_HPP
#define PLAYER_X_HPP

#include "player/player.hpp"
#include "items/item_x.hpp"

class QPointF;

/**
 * @class player_x
 * @brief Player 'X' implementation
 */
class player_x : public player
{
public:
    /// @brief Get player 'X'
    static player_x* get_instance();

    /// @brief Destructor
    virtual ~player_x();

    /// @brief Take player 'X' turn
    virtual void do_step(const unsigned&) override;

    /// @brief Create 'X' item and assign to base class member
    virtual void create_item(const unsigned&) override;

private:
    /// @brief Constructor
    player_x();

private:
    static player_x* m_instance;
};

#endif // PLAYER_X_HPP
