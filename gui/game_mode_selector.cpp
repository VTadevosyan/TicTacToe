/**
 * Tic Tac Toe
 */

#include "gui/game_mode_selector.hpp"

#include <QButtonGroup>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>


namespace button {

static const QSize btn_size(190, 65);
static const QString stylesheet = "color: darkRed; padding: -100px;";

} // button

const QSize game_mode_selector::m_minimum_size = QSize(800, 620);


game_mode_selector::game_mode_selector(QWidget *parent)
        : QWidget(parent)
        , m_parent(parent)
{
    construct();
}

QButtonGroup* game_mode_selector::get_buttons_group() const
{
    return m_group;
}

void game_mode_selector::construct()
{
    create_font();
    create_singleplayer_mode_button();
    create_multiplayer_mode_button();
    create_exit_button();
    create_button_group();
    setup_layout();
    setMinimumSize(m_minimum_size);
}

void game_mode_selector::create_font()
{
    m_font = new QFont;
    m_font->setFamily("Arial");
    m_font->setPixelSize(30);
    m_font->setBold(true);
}

void game_mode_selector::create_singleplayer_mode_button()
{
    QFont f(*m_font);
    f.setPixelSize(20);
    m_single_mode = new QPushButton("Singleplayer", this);
    m_single_mode->setFixedSize(button::btn_size);
    m_single_mode->setFont(f);
    m_single_mode->setStyleSheet(button::stylesheet);
}

void game_mode_selector::create_multiplayer_mode_button()
{
    QFont f(*m_font);
    f.setPixelSize(20);
    m_multiplayer_mode = new QPushButton("Multiplayer", this);
    m_multiplayer_mode->setFixedSize(button::btn_size);
    m_multiplayer_mode->setFont(f);
    m_multiplayer_mode->setStyleSheet(button::stylesheet);
}
void game_mode_selector::create_exit_button()
{
    QFont f(*m_font);
    f.setPixelSize(20);
    m_exit_button = new QPushButton("Exit", this);
    m_exit_button->setFixedSize(button::btn_size);
    m_exit_button->setFont(f);
    m_exit_button->setStyleSheet(button::stylesheet);
    connect(m_exit_button, SIGNAL(released()), m_parent, SLOT(close()));
}

void game_mode_selector::create_button_group()
{
    m_group = new QButtonGroup;
    m_group->addButton(m_single_mode, 0);
    m_group->addButton(m_multiplayer_mode, 1);
}

void game_mode_selector::setup_layout()
{
    QLabel* txt = new QLabel;
    txt->setText(" Tic Tac Toe");
    txt->setFont(*m_font);
    txt->setStyleSheet("font-family: Verdana; font-size: 30 px; color: white;");
    QLabel* img = new QLabel;
    img->setPixmap(QPixmap("img/red.png"));
    img->setFixedSize(QSize(200, 200));
    QVBoxLayout* l = new QVBoxLayout;
    l->addStretch();
    l->addWidget(txt);
    l->addStretch();
    l->addWidget(img);
    l->addStretch();
    l->addWidget(m_single_mode);
    l->addWidget(m_multiplayer_mode);
    l->addWidget(m_exit_button);
    l->addStretch();
    QHBoxLayout* ml = new QHBoxLayout;
    ml->addStretch();
    ml->addLayout(l);
    ml->addStretch();
    setLayout(ml);
}
