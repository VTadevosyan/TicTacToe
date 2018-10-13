/**
 * Tic Tac Toe
 */

#include "widgets.hpp"

button::button(const QIcon& i, const QString& t, QWidget* p,
               const QSize& is, const QSize& bs)
        : QPushButton(i, t, p)
{
    if (!is.isEmpty()) {
        setIconSize(is);
    }
    if (!bs.isEmpty()) {
        setFixedSize(bs);
    }
}
