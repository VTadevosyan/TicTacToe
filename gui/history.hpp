/**
 * Tic Tac Toe
 */

#ifndef HISTORY_HPP
#define HISTORY_HPP

#include <QDockWidget>

class history : public QDockWidget
{
    Q_OBJECT
public:
    /// @brief Constructor
    history(QWidget* = nullptr);

};

#endif // HISTORY_HPP
