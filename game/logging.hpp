/**
 * Tic Tac Toe
 */

#ifndef LOGGING_HPP
#define LOGGING_HPP

#include "manager.hpp"

#include <list>
#include <string>

class logging
{
public:
    typedef std::list<std::string> log;

    /// @brief Initialize logging
    static void initialize();

    /// @brief Uninitialize logging
    static void uninitialize();

    /// @brief Get log
    static void get(log&);

    /// @brief Log player turns
    /// @param[in] s Board section
    /// @param[in] p Player 'X' if p true, 'O' otherwise
    static void log_turn(unsigned s, bool p);

    /// @brief Log action: new or end game
    /// @param[in] s Game status
    /// @param[in] n True if new game action, false for end game
    /// @param[in] e True if Player closed game
    static void log_action(manager::status s, bool n = true, bool e = false);

private:
    static log m_log;

};

#endif // LOGGING_HPP
