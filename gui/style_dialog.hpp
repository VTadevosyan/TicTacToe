/**
 * Tic Tac Toe
 */

#ifndef STYLE_DIALOG_HPP
#define STYLE_DIALOG_HPP

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

/**
 * @class style_dialog
 * @brief Game's style settings class implementation
 */
class style_dialog : public QDialog
{
    Q_OBJECT
public:
    /// @brief Constructor
    style_dialog(QWidget* = 0);

private:
    /// @brief Initialize dialog
    void initialize();

    /// @brief Setup dialog's layout
    void setup_layout();

private slots:
    void set_window_bg_1();
    void set_window_bg_2();
    void set_window_bg_3();
    void set_window_bg_4();
    void set_board_bg_1();
    void set_board_bg_2();
    void set_board_bg_3();
    void set_board_bg_4();
    void set_shapes_1();
    void set_shapes_2();

private:
    QVBoxLayout* m_layout;
    QLabel* m_selected_window_bg;
    QLabel* m_selected_board_bg;
    QLabel* m_selected_shapes;
    QString m_initial_window_img;
    QString m_initial_board_img;
    std::pair<QString, QString> m_initial_shapes_img;
};

#endif // STYLE_DIALOG_HPP
