/**
 * Tic Tac Toe
 */

#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <QSize>
#include <QString>


namespace images {

static const QString w_img1 = "img/xo_window_background_1.jpg";
static const QString w_img2 = "img/xo_window_background_2.jpg";
static const QString w_img3 = "img/xo_window_background_3.jpg";
static const QString w_img4 = "img/xo_window_background_4.jpg";

static const QString b_img1 = "img/xo_board_background_1.jpg";
static const QString b_img2 = "img/xo_board_background_2.jpg";
static const QString b_img3 = "img/xo_board_background_3.png";
static const QString b_img4 = "img/xo_board_background_4.png";

static const QString xo_img1 = "img/xo.png";
static const QString xo_img2 = "img/xo_2.png";

static const QString s_img1 = "img/x_1.png";
static const QString s_img2 = "img/o_1.png";
static const QString s_img3 = "img/x_2.png";
static const QString s_img4 = "img/o_2.png";

static const QString save = "img/save.png";
static const QString cancel = "img/cancel.png";

static const QString btn_txt = "  I\nm\n a\n g\n e\n ";

static const QSize btn_size(100, 40);
static const QSize img_size(170, 145);
static const QSize shp_size(180, 120);
static const QSize ico_size(120, 120);

} // images

/**
 * @class options
 * @brief Game options
 */
class options
{
public:
    /// @brief Constructor
    /// @param[in] wi Window background image
    /// @param[in] bi Board background image
    /// @param[in] si Shape images: first - 'X', second - 'O'
    options(const QString& wi = images::w_img1, const QString& bi = images::b_img1,
            const std::pair<QString, QString>& si = std::make_pair(images::s_img1, images::s_img2));

    /// @brief Destructor
    ~options();

private:
    QString m_window_bg_img;
    QString m_board_bg_img;
    std::pair<QString, QString> m_shapes_img;
};

#endif // OPTIONS_HPP
