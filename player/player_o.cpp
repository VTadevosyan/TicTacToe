/**
 * Tic Tac Toe
 */

#include "player_o.hpp"
#include "gui/board.hpp"
#include "items/item_o.hpp"


player_o* player_o::m_instance = 0;


player_o::player_o()
{
}

player_o::~player_o()
{
}

player_o* player_o::get_instance()
{
    if(m_instance == 0){
        m_instance = new player_o;
    }
    return m_instance;
}

void player_o::do_step(const unsigned& s)
{
    create_item(s);
}

void player_o::create_item(const unsigned& s)
{
    m_item = new item_o;
    m_item->set_section(s);
}

