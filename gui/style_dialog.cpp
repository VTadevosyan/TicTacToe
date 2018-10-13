/**
 * Tic Tac Toe
 */

#include "widgets.hpp"
#include "style_dialog.hpp"
#include "game/manager.hpp"

#include <QPushButton>


style_dialog::style_dialog(QWidget* p)
        : QDialog(p)
{
    initialize();
}

void style_dialog::initialize()
{
    setup_layout();
    setLayout(m_layout);
    setWindowTitle("Tic Tac Toe: Window Style Settings");
}

void style_dialog::setup_layout()
{
    m_selected_window_bg = new QLabel(this);
    m_selected_board_bg = new QLabel(this);
    m_selected_shapes = new QLabel(this);
    m_layout = new QVBoxLayout;
    button* save   = new button(QIcon(images::save), "Save",
                                this, QSize(), images::btn_size);
    button* cancel = new button(QIcon(images::cancel), "Cancel",
                                this, QSize(), images::btn_size);
    button* wimg1  = new button(QIcon(images::w_img1), images::btn_txt + "1",
                                this, images::ico_size, images::img_size);
    button* wimg2  = new button(QIcon(images::w_img2), images::btn_txt + "2",
                                this, images::ico_size, images::img_size);
    button* wimg3  = new button(QIcon(images::w_img3), images::btn_txt + "3",
                                this, images::ico_size, images::img_size);
    button* wimg4  = new button(QIcon(images::w_img4), images::btn_txt + "4",
                                this, images::ico_size, images::img_size);
    button* bimg1  = new button(QIcon(images::b_img1), images::btn_txt + "1",
                                this, images::ico_size, images::img_size);
    button* bimg2  = new button(QIcon(images::b_img2), images::btn_txt + "2",
                                this, images::ico_size, images::img_size);
    button* bimg3  = new button(QIcon(images::b_img3), images::btn_txt + "3",
                                this, images::ico_size, images::img_size);
    button* bimg4  = new button(QIcon(images::b_img4), images::btn_txt + "4",
                                this, images::ico_size, images::img_size);
    button* xoimg1 = new button(QIcon(images::xo_img1), images::btn_txt + "1",
                                this, images::ico_size, images::shp_size);
    button* xoimg2 = new button(QIcon(images::xo_img2), images::btn_txt + "2",
                                this, images::ico_size, images::shp_size);
    QHBoxLayout* l1 = new QHBoxLayout;
    l1->addStretch();
    l1->addWidget(new QLabel("Window Background Image"));
    l1->addStretch();
    m_layout->addStretch();
    m_layout->addLayout(l1);
    QHBoxLayout* l2 = new QHBoxLayout;
    l2->addStretch();
    l2->addWidget(wimg1);
    l2->addWidget(wimg2);
    l2->addWidget(wimg3);
    l2->addWidget(wimg4);
    l2->addStretch();
    m_layout->addLayout(l2);
    QHBoxLayout* l3 = new QHBoxLayout;
    l3->addStretch();
    l3->addWidget(new QLabel("Board Background Image"));
    l3->addStretch();
    m_layout->addStretch();
    m_layout->addLayout(l3);
    QHBoxLayout* l4 = new QHBoxLayout;
    l4->addStretch();
    l4->addWidget(bimg1);
    l4->addWidget(bimg2);
    l4->addWidget(bimg3);
    l4->addWidget(bimg4);
    l4->addStretch();
    m_layout->addLayout(l4);
    m_layout->addStretch();
    QHBoxLayout* l5 = new QHBoxLayout;
    l5->addStretch();
    l5->addWidget(new QLabel("'X'-'O' Shapes"));
    l5->addStretch();
    m_layout->addStretch();
    m_layout->addLayout(l5);
    QHBoxLayout* l6 = new QHBoxLayout;
    l6->addStretch();
    l6->addWidget(xoimg1);
    l6->addWidget(xoimg2);
    l6->addStretch();
    m_layout->addLayout(l6);
    m_layout->addStretch();
    QHBoxLayout* l7 = new QHBoxLayout;
    l7->addWidget(new QLabel("Window Background Image: "));
    l7->addWidget(m_selected_window_bg);
    l7->addStretch();
    m_layout->addLayout(l7);
    QHBoxLayout* l8 = new QHBoxLayout;
    l8->addWidget(new QLabel("Board Background Image: "));
    l8->addWidget(m_selected_board_bg);
    l8->addStretch();
    m_layout->addLayout(l8);
    m_layout->addStretch();
    QHBoxLayout* l9 = new QHBoxLayout;
    l9->addWidget(new QLabel("'X'-'O' Shapes Image: "));
    l9->addWidget(m_selected_shapes);
    l9->addStretch();
    m_layout->addLayout(l9);
    m_layout->addStretch();

    QHBoxLayout* l10 = new QHBoxLayout;
    l10->addStretch();
    l10->addWidget(cancel);
    l10->addWidget(save);
    m_layout->addLayout(l10);

    connect(wimg1,  SIGNAL(released()), SLOT(set_window_bg_1()));
    connect(wimg2,  SIGNAL(released()), SLOT(set_window_bg_2()));
    connect(wimg3,  SIGNAL(released()), SLOT(set_window_bg_3()));
    connect(wimg4,  SIGNAL(released()), SLOT(set_window_bg_4()));
    connect(bimg1,  SIGNAL(released()), SLOT(set_board_bg_1()));
    connect(bimg2,  SIGNAL(released()), SLOT(set_board_bg_2()));
    connect(bimg3,  SIGNAL(released()), SLOT(set_board_bg_3()));
    connect(bimg4,  SIGNAL(released()), SLOT(set_board_bg_4()));
    connect(xoimg1, SIGNAL(released()), SLOT(set_shapes_1()));
    connect(xoimg2, SIGNAL(released()), SLOT(set_shapes_2()));
    connect(save,   SIGNAL(released()), SLOT(accept()));
    connect(cancel, SIGNAL(released()), SLOT(reject()));
}

void style_dialog::set_window_bg(const QString& img, const QString& name)
{
    manager* m = manager::get_instance();
    Q_ASSERT(m != 0);
    m->set_window_bg_image_path(img);
    m_selected_window_bg->setText(name);
}

void style_dialog::set_board_bg(const QString& img, const QString& name)
{
    manager* m = manager::get_instance();
    Q_ASSERT(m != 0);
    m->set_board_bg_image_path(img);
    m_selected_board_bg->setText(name);
}

void style_dialog::set_shapes(const std::pair<QString, QString>& imgs,
        const QString& name)
{
    manager* m = manager::get_instance();
    Q_ASSERT(m != 0);
    m->set_item_image_path(imgs);
    m_selected_shapes->setText(name);
}

void style_dialog::set_window_bg_1()
{
    set_window_bg(images::w_img1, "Image 1");
}

void style_dialog::set_window_bg_2()
{
    set_window_bg(images::w_img2, "Image 2");
}

void style_dialog::set_window_bg_3()
{
    set_window_bg(images::w_img3, "Image 3");
}

void style_dialog::set_window_bg_4()
{
    set_window_bg(images::w_img4, "Image 4");
}

void style_dialog::set_board_bg_1()
{
    set_board_bg(images::b_img1, "Image 1");
}

void style_dialog::set_board_bg_2()
{
    set_board_bg(images::b_img2, "Image 2");
}

void style_dialog::set_board_bg_3()
{
    set_board_bg(images::b_img3, "Image 3");
}

void style_dialog::set_board_bg_4()
{
    set_board_bg(images::b_img4, "Image 4");
}

void style_dialog::set_shapes_1()
{
    set_shapes(std::make_pair(images::s_img1, images::s_img2), "Image 1");
}

void style_dialog::set_shapes_2()
{
    set_shapes(std::make_pair(images::s_img3, images::s_img4), "Image 2");
}
