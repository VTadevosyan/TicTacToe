/**
 * Tic Tac Toe
 */

#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <QIcon>
#include <QPushButton>

/// @class button
/// @brief Custom implementation for QPushButton widget
class button : public QPushButton
{
    Q_OBJECT
public:
    /// @brief Constructor
    /// @param[in] i  icon
    /// @param[in] t  text
    /// @param[in] p  parent widget
    /// @param[in] is icon size
    /// @param[in] bs button size
    button(const QIcon& i = QIcon(), const QString& t = QString(), QWidget* p = 0,
                const QSize& is = QSize(), const QSize& bs = QSize());
};


#endif // WIDGETS_HPP
