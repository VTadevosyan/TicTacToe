/**
 * Tic Tac Toe
 */

#include "player_x.hpp"
#include "gui/board.hpp"
#include "items/item_x.hpp"


player_x* player_x::m_instance = 0;


player_x::player_x()
{
}

player_x::~player_x()
{
}

player_x* player_x::get_instance()
{
    if(m_instance == 0){
        m_instance = new player_x;
    }
    return m_instance;
}

void player_x::do_step(const unsigned& s)
{
    create_item(s);
    log_turn(s, true);
}

void player_x::create_item(const unsigned& s)
{
    m_item = new item_x;
    m_item->set_section(s);
}

