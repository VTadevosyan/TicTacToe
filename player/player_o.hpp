/**
 * Tic Tac Toe
 */

#ifndef PLAYER_O_HPP
#define PLAYER_O_HPP

#include "player/player.hpp"
#include "items/item_o.hpp"

class item_o;

/**
 * @class player_o
 * @brief Player 'O' implementation
 */
class player_o : public player
{
public:
    /// @brief Get player 'O'
    static player_o* get_instance();

    /// @brief Destructor
    virtual ~player_o();

    /// @brief Take player 'O' turn
    virtual void do_step(const unsigned&) override;

    /// @brief Create 'O' item and assign to base class member
    virtual void create_item(const unsigned&) override;


protected:
    /// @brief Constructor
    player_o();

private:
    static player_o* m_instance;
};

#endif // PLAYER_O_HPP
