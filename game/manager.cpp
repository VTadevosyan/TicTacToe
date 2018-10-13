/**
 * Tic Tac Toe
 */

#include "game/manager.hpp"
#include "player/player_o.hpp"
#include "player/player_x.hpp"

#include <QPointF>
#include <QMessageBox>
#include <iostream>
#include <ctime>


manager* manager::m_instance = 0;
const char manager::m_empty_symbol = '*';
const char manager::m_x_symbol = 'x';
const char manager::m_o_symbol = 'o';


manager::manager(bool t)
    : m_game_status(manager::not_started)
    , m_item(0)
    , m_player_x(0)
    , m_player_o(0)
    , m_cpu_steps(0)
    , m_is_multiple_game(t)
    , m_is_player_x_turn(true)
{
    initialize_game_options();
    initialize_board_data();
}

manager::~manager()
{
    if (m_player_x) { delete m_player_x; }
    if (m_player_o) { delete m_player_o; }
    if (m_item) { delete m_item; }
}

manager* manager::get_instance(bool t)
{
    if(m_instance == 0){
        m_instance = new manager(t);
    }
    return m_instance;
}

void manager::set_game_mode(bool t)
{
    m_is_multiple_game = t;
}

void manager::start()
{
    m_player_x = player_x::get_instance();
    m_player_o = player_o::get_instance();
    Q_ASSERT(m_player_x != 0);
    Q_ASSERT(m_player_o != 0);
    m_game_status = manager::in_the_game;
}

void manager::initialize_board_data()
{
    m_board_data.resize(9);
    for(size_t i = 0; i < 9; ++i) {
        m_board_data[i] = m_empty_symbol;
    }
}

void manager::initialize_game_options()
{
    m_game_options.set_window_background_image("img/xo_window_background_1.jpg");
    m_game_options.set_board_background_image("img/xo_board_background_1.jpg");
    m_game_options.set_shape_styles(std::make_pair("img/x_2.png", "img/o_2.png"));
}

void manager::set_options(const options& o)
{
    m_game_options = o;
}

void manager::set_window_bg_image_path(const QString& s)
{
    if (s != m_game_options.get_window_background_image()) {
        m_game_options.set_window_background_image(s);
    }
}

QString manager::get_window_bg_image_path() const
{
    return m_game_options.get_window_background_image();
}

void manager::set_board_bg_image_path(const QString& s)
{
    if (s != m_game_options.get_board_background_image()) {
        m_game_options.set_board_background_image(s);
    }
}

QString manager::get_board_bg_image_path() const
{
    return m_game_options.get_board_background_image();
}

void manager::set_item_image_path(const std::pair<QString, QString>& p)
{
    m_game_options.set_shape_styles(p);
}

std::pair<QString, QString> manager::get_item_image_path() const
{
    return m_game_options.get_shape_styles();
}

bool manager::is_multiple_game() const
{
    return m_is_multiple_game;
}

bool manager::is_x_player_turn() const
{
    return m_is_player_x_turn;
}

bool manager::is_section_empty(const unsigned& s)
{
    Q_ASSERT(s != 0 && s > 9);
    return m_board_data[s-1];
}

void manager::set_game_status(const status& s)
{
    m_game_status = s;
}

manager::status manager::check_game_status()
{
    if (m_game_status == manager::not_started) {
        return manager::not_started;
    }
    if ((m_board_data[0] == m_board_data[3]) && m_board_data[0] != m_empty_symbol){
        if(m_board_data[0] == m_board_data[6]){
            set_victorious_line(0, 3, 6);
            return m_board_data[0] == m_x_symbol ? manager::win : manager::lose;
        }
    }
    if ((m_board_data[1] == m_board_data[4]) && m_board_data[1] != m_empty_symbol){
        if(m_board_data[1] == m_board_data[7]){
            set_victorious_line(1, 4, 7);
            return m_board_data[1] == m_x_symbol ? manager::win : manager::lose;
        }
    }
    if ((m_board_data[2] == m_board_data[5]) && m_board_data[2] != m_empty_symbol){
        if(m_board_data[2] == m_board_data[8]){
            set_victorious_line(2, 5, 8);
            return m_board_data[2] == m_x_symbol ? manager::win : manager::lose;
        }
    }
    if ((m_board_data[0] == m_board_data[1]) && m_board_data[0] != m_empty_symbol){
        if(m_board_data[0] == m_board_data[2]){
            set_victorious_line(0, 1, 2);
            return m_board_data[0] == m_x_symbol ? manager::win : manager::lose;
        }
    }
    if ((m_board_data[3] == m_board_data[4]) && m_board_data[3] != m_empty_symbol){
        if(m_board_data[3] == m_board_data[5]){
            set_victorious_line(3, 4, 5);
            return m_board_data[3] == m_x_symbol ? manager::win : manager::lose;
        }
    }
    if ((m_board_data[6] == m_board_data[7]) && m_board_data[6] != m_empty_symbol){
        if(m_board_data[6] == m_board_data[8]){
            set_victorious_line(6, 7, 8);
            return m_board_data[6] == m_x_symbol ? manager::win : manager::lose;
        }
    }
    if ((m_board_data[0] == m_board_data[4]) && m_board_data[0] != m_empty_symbol){
        if(m_board_data[0] == m_board_data[8]){
            set_victorious_line(0, 4, 8);
            return m_board_data[0] == m_x_symbol ? manager::win : manager::lose;
        }
    }
    if ((m_board_data[2] == m_board_data[4]) && m_board_data[2] != m_empty_symbol){
        if(m_board_data[2] == m_board_data[6]){
            set_victorious_line(2, 4, 6);
            return m_board_data[2] == m_x_symbol ? manager::win : manager::lose;
        }
    }
    for(size_t i = 0; i < 9; ++i){
        if(m_board_data[i] == m_empty_symbol){
            return manager::in_the_game;
        }
    }
    m_victorious_line.clear();
    return manager::draw;
}

void manager::take_turn(const unsigned& s)
{
    Q_ASSERT(s != 0 && s < 10);
    if(!m_game_status){
        if(m_is_player_x_turn){
            do_player_x_turn(s);
        } else if(m_is_multiple_game) {
            do_player_o_turn(s);
        }
    }
}

void manager::do_player_x_turn(const unsigned& s)
{
    m_player_x->do_step(s);
    m_item = m_player_x->get_item();
    m_board_data[s-1] = m_x_symbol;
    m_is_player_x_turn = false;
}

void manager::do_player_o_turn(const unsigned& s)
{
    m_player_o->do_step(s);
    m_item = m_player_o->get_item();
    m_board_data[s-1] = m_o_symbol;
    m_is_player_x_turn = true;
}

void manager::do_player_cpu_turn(unsigned& s)
{
    switch(m_cpu_steps){
    case 0:
        do_cpu_step_1(s);
        break;
    case 1:
        do_cpu_step_2(s);
        break;
    case 2:
        do_cpu_step_3(s);
        break;
    case 3:
        do_cpu_step_4(s);
        break;
    }
    m_player_o->do_step(s);
    m_item = m_player_o->get_item();
    m_is_player_x_turn = true;
    m_board_data[s-1] = m_o_symbol;
}

void manager::do_cpu_random_step(unsigned& s)
{
    while(true) {
        s = rand() % 8 + 1;
        Q_ASSERT(s != 0 || s > 9);
        if(m_board_data[s-1] == m_empty_symbol){
            m_board_data[s-1] = m_o_symbol;
            ++m_cpu_steps;
            return;
        }
    }
}

void manager::do_cpu_step_1(unsigned& s)
{
    ++m_cpu_steps;
    if(m_board_data[4] == m_x_symbol){
        std::vector<unsigned> v = {1, 3, 7, 9};
        srand(time(0));
        s = v[rand() % 4];
        m_board_data[s-1] = m_o_symbol;
    } else {
        s = 5;
        m_board_data[s-1] = m_o_symbol;
    }
}

void manager::do_cpu_step_2(unsigned& s)
{
    ++m_cpu_steps;
    check_and_take_turn(m_x_symbol, s);
    if (s) {
        m_board_data[s-1] = m_o_symbol;
        return;
    }
    if (m_board_data[4] == m_x_symbol) {
        if (m_board_data[0] == m_x_symbol) {
            s = 9;
        } else if (m_board_data[1] == m_x_symbol) {
            s = 8;
        } else if (m_board_data[2] == m_x_symbol) {
            s = 7;
        } else if (m_board_data[3] == m_x_symbol) {
            s = 6;
        } else if (m_board_data[5] == m_x_symbol) {
            s = 4;
        } else if (m_board_data[6] == m_x_symbol) {
            s = 3;
        } else if (m_board_data[7] == m_x_symbol) {
            s = 2;
        } else {
            s = 1;
        }
        if (m_board_data[s-1] == m_empty_symbol) {
            m_board_data[s-1] = m_o_symbol;
            return;
        }
    } else if (m_board_data[4] == m_o_symbol) {
        if (m_board_data[0] == m_x_symbol && m_board_data[2] == m_x_symbol){
            s = 2;
        } else if (m_board_data[2] == m_x_symbol && m_board_data[8] == m_x_symbol) {
            s = 6;
        } else if (m_board_data[0] == m_x_symbol && m_board_data[6] == m_x_symbol) {
            s = 4;
        } else if (m_board_data[6] == m_x_symbol && m_board_data[8] == m_x_symbol) {
            s = 8;
        } else if ((m_board_data[0] == m_x_symbol && m_board_data[8] == m_x_symbol) ||
                   (m_board_data[2] == m_x_symbol && m_board_data[6] == m_x_symbol)) {
            for(size_t i = 1; i <= 7; i += 2) {
                if (m_board_data[i] == m_empty_symbol) {
                    s = i + 1;
                    break;
                }
            }
        }
        if(s && m_board_data[s-1] == m_empty_symbol) {
            m_board_data[s-1] = m_o_symbol;
            return;
        }
    }
    --m_cpu_steps;
    do_cpu_random_step(s);
}

void manager::do_cpu_step_3(unsigned& s)
{
    ++m_cpu_steps;
    check_and_take_turn(m_o_symbol, s);
    if(!s){
        check_and_take_turn(m_x_symbol, s);
    }
    if(s && m_board_data[s-1] == m_empty_symbol) {
        m_board_data[s-1] = m_o_symbol;
        return;
    }
    --m_cpu_steps;
    do_cpu_random_step(s);
}

void manager::do_cpu_step_4(unsigned& s)
{
    ++m_cpu_steps;
    check_and_take_turn(m_o_symbol, s);
    if(!s){
        check_and_take_turn(m_x_symbol, s);
    }
    if(s && m_board_data[s-1] == m_empty_symbol) {
        m_board_data[s-1] = m_o_symbol;
        return;
    }
    --m_cpu_steps;
    do_cpu_random_step(s);
}

void manager::check_and_take_turn(const char& c, unsigned& s)
{
    if((m_board_data[8] == m_empty_symbol) &&
           ((m_board_data[0] == c && m_board_data[4] == c) ||
            (m_board_data[2] == c && m_board_data[5] == c) ||
            (m_board_data[6] == c && m_board_data[7] == c) ||
            (m_board_data[5] == c && m_board_data[7] == c))) {
        s = 9;
    } else if((m_board_data[4] == m_empty_symbol) &&
             ((m_board_data[0] == c && m_board_data[8] == c) ||
              (m_board_data[2] == c && m_board_data[6] == c) ||
              (m_board_data[1] == c && m_board_data[7] == c) ||
              (m_board_data[3] == c && m_board_data[5] == c))) {
        s = 5;
    } else if((m_board_data[0] == m_empty_symbol) &&
             ((m_board_data[4] == c && m_board_data[8] == c) ||
              (m_board_data[1] == c && m_board_data[2] == c) ||
              (m_board_data[3] == c && m_board_data[6] == c) ||
              (m_board_data[1] == c && m_board_data[3] == c))) {
        s = 1;
    } else if((m_board_data[6] == m_empty_symbol) &&
             ((m_board_data[2] == c && m_board_data[4] == c) ||
              (m_board_data[0] == c && m_board_data[3] == c) ||
              (m_board_data[7] == c && m_board_data[8] == c) ||
              (m_board_data[3] == c && m_board_data[7] == c))) {
        s = 7;
    } else if((m_board_data[2] == m_empty_symbol) &&
             ((m_board_data[4] == c && m_board_data[6] == c) ||
              (m_board_data[0] == c && m_board_data[1] == c) ||
              (m_board_data[5] == c && m_board_data[8] == c) ||
              (m_board_data[1] == c && m_board_data[5] == c))) {
        s = 3;
    } else if((m_board_data[1] == m_empty_symbol) &&
             ((m_board_data[0] == c && m_board_data[2] == c) ||
              (m_board_data[4] == c && m_board_data[7] == c))) {
        s = 2;
    } else if((m_board_data[3] == m_empty_symbol) &&
             ((m_board_data[0] == c && m_board_data[6] == c) ||
              (m_board_data[4] == c && m_board_data[5] == c))) {
        s = 4;
    } else if((m_board_data[5] == m_empty_symbol) &&
             ((m_board_data[2] == c && m_board_data[8] == c) ||
              (m_board_data[3] == c && m_board_data[4] == c))) {
        s = 6;
    } else if((m_board_data[7] == m_empty_symbol) &&
             ((m_board_data[6] == c && m_board_data[8] == c) ||
              (m_board_data[1] == c && m_board_data[4] == c))) {
        s = 8;
    }
}

abstract_item* manager::get_item()
{
    return m_item;
}

void manager::finish_game(bool f)
{
    m_item = 0;
    m_cpu_steps = 0;
    m_is_player_x_turn = true;
    m_board_data.clear();
    m_board_data.resize(9);
    for(size_t i = 0; i < 9; ++i) {
        m_board_data[i] = m_empty_symbol;
    }
    logging::log_action(m_game_status, false, f);
    m_game_status = manager::not_started;
}

void manager::set_victorious_line(const unsigned& s1,
        const unsigned& s2, const unsigned& s3)
{
    m_victorious_line.clear();
    m_victorious_line.push_back(s1);
    m_victorious_line.push_back(s2);
    m_victorious_line.push_back(s3);
}

void manager::get_victorious_line(std::vector<unsigned>& v)
{
    v.clear();
    v.resize(3);
    for(size_t i = 0; i < 3; ++i){
        v[i] = m_victorious_line[i] + 1;
    }
}
