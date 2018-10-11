/**
 * Tic Tac Toe
 */

#include "options.hpp"

options::options(const QString &wi, const QString &bi,
                 const std::pair<QString, QString> &si)
        : m_window_bg_img(wi)
        , m_board_bg_img(bi)
        , m_shapes_img(si)
{
}

void options::set_window_background_image(const QString& s)
{
    if (m_window_bg_img != s) {
        m_window_bg_img = s;
    }
}

QString options::get_window_background_image() const
{
    return m_window_bg_img;
}

void options::set_board_background_image(const QString& s)
{
    if (m_board_bg_img != s) {
        m_board_bg_img = s;
    }
}

QString options::get_board_background_image() const
{
    return m_board_bg_img;
}

void options::set_shape_styles(const std::pair<QString, QString>& s)
{
    m_shapes_img.first  = s.first;
    m_shapes_img.second = s.second;
}

std::pair<QString, QString> options::get_shape_styles() const
{
    return m_shapes_img;
}
