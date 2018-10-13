/**
 * Tic Tac Toe
 */

#include "logging.hpp"
#include "manager.hpp"

#include <iostream>
#include <cassert>
#include <ctime>
#include <time.h>


logging::log logging::m_log = log();

namespace {

static std::string get_time()
{
    std::time_t time = std::time(0);
    return std::string(std::ctime(&time));
}

}

void logging::initialize()
{
    assert(m_log.empty());
    m_log.push_back("Starting game 'Tic Tac Toe'  #" + get_time());
    std::cout << m_log.back() << std::endl;
}

void logging::uninitialize()
{
    m_log.push_back("Exiting game 'Tic Tac Toe'  #" + get_time());
    std::cout << m_log.back() << std::endl;
    m_log.clear();
}

void logging::log_turn(unsigned s, bool p)
{
    std::string msg = std::string("Player ") + (p ? "'X'" : "'O'") +
            "' take turn on section " + std::to_string(s) + "  #";
    m_log.push_back(msg + get_time());
    std::cout << m_log.back() << std::endl;
}

void logging::log_action(manager::status s, bool n, bool e)
{
    std::string msg;
    if (n) {
        assert(s == manager::not_started && e == false);
        msg = "New game at " + get_time();
        m_log.push_back(msg);
        std::cout << m_log.back() << std::endl;
    } else {
        msg = "Game finished. ";
        if (e) {
            msg += "User exits game. ";
        }
        switch(s) {
            case manager::win:
                msg += "Player 'X' win the game!  #";
                break;
            case manager::draw:
                msg += "Draw  #";
                break;
            case manager::lose:
                msg += "Player 'O' win the game!  #";
                break;
            default:
                assert("Unexpected type" != 0);
        }
        msg += get_time();
        m_log.push_back(msg);
        std::cout << m_log.back() << std::endl;
    }
}
