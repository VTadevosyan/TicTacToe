/**
 * Tic Tac Toe
 */

#include "gui/board.hpp"
#include "game/manager.hpp"
#include "player/player_x.hpp"
#include "player/player_o.hpp"
#include "items/item_o.hpp"
#include "items/item_x.hpp"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <cmath>

const QRect board::m_scene_rect = QRect(0, 0, 600, 600);
const QSize board::m_board_size = QSize(606, 606);
std::vector<bool> board::m_section = crate_sections_vector();
unsigned board::m_board_shapes_count = 0;


board::board(QWidget* p)
        : QGraphicsView(p)
        , m_active_section(0)
{
    initialize();
    setMouseTracking(true);
    m_board_shapes_count = 0;
}

/*board::~board()
{
    deleteLater();
}*/

void board::initialize()
{
    create_scene();
    draw_empty_board();
    crate_sections_vector();
    manager* m = manager::get_instance();
    Q_ASSERT(m != 0);
    setStyleSheet("background-image: url(" + m->get_board_bg_image_path() + ");");
}

void board::create_scene()
{
    m_scene = new QGraphicsScene();
    Q_ASSERT(m_scene != 0);
    m_scene->setSceneRect(QRectF(m_scene_rect));
    setScene(m_scene);
    setFixedSize(m_board_size);
}

void board::draw_empty_board()
{
    QGraphicsLineItem* l1 = new QGraphicsLineItem(200, 0, 200, m_scene_rect.height());
    QGraphicsLineItem* l2 = new QGraphicsLineItem(400, 0, 400, m_scene_rect.height());
    QGraphicsLineItem* l3 = new QGraphicsLineItem(0, 200, m_scene_rect.width(), 200);
    QGraphicsLineItem* l4 = new QGraphicsLineItem(0, 400, m_scene_rect.width(), 400);
    QGraphicsRectItem* br = new QGraphicsRectItem(m_scene_rect);
    l1->setPen(QPen(Qt::darkRed, 4, Qt::DashLine));
    l2->setPen(QPen(Qt::darkRed, 4, Qt::DashLine));
    l3->setPen(QPen(Qt::darkRed, 4, Qt::DashLine));
    l4->setPen(QPen(Qt::darkRed, 4, Qt::DashLine));
    br->setPen(QPen(Qt::black, 4));
    m_scene->addItem(l1);
    m_scene->addItem(l2);
    m_scene->addItem(l3);
    m_scene->addItem(l4);
    m_scene->addItem(br);
}

std::vector<bool> board::crate_sections_vector()
{
    m_section.resize(10);
    for(std::vector<bool>::iterator it = m_section.begin(); it != m_section.end(); ++it){
        *it = false;
    }
    return m_section;
}

void board::mouseMoveEvent(QMouseEvent* e)
{
    clear_highligthing();
    QPointF p = QPointF(mapToScene(e->pos()));
    section s = find_section(p);
    Q_ASSERT(s >= section_1 && s <= section_9);
    get_active_section(s);
    m_active_section->setPen(QPen(!check_section(s) ? Qt::yellow : Qt::red, 4, Qt::SolidLine));
    m_scene->addItem(m_active_section);
    m_scene->update();
}

void board::get_active_section(section s)
{
    Q_ASSERT(m_active_section == 0);
    static const QRect r(0, 0, 200, 200);
    switch (s) {
        case section_1: {
                m_active_section = new QGraphicsRectItem(r);
            } break;
        case section_2: {
                m_active_section = new QGraphicsRectItem(
                            r.topLeft().x() + 200, r.topLeft().y(),
                            r.bottomRight().x(), r.bottomRight().y());
            } break;
        case section_3: {
                m_active_section = new QGraphicsRectItem(
                            r.topLeft().x() + 400, r.topLeft().x(),
                            r.bottomRight().x(), r.bottomRight().y());
            } break;
        case section_4: {
                m_active_section = new QGraphicsRectItem(
                            r.topLeft().x(), r.topLeft().y() + 200,
                            r.bottomRight().x(), r.bottomRight().y());
            } break;
        case section_5: {
                m_active_section = new QGraphicsRectItem(
                            r.topLeft().x() + 200, r.topLeft().y() + 200,
                            r.bottomRight().x(), r.bottomRight().y());
            } break;
        case section_6: {
                m_active_section = new QGraphicsRectItem(
                            r.topLeft().x() + 400, r.topLeft().y() + 200,
                            r.bottomRight().x(), r.bottomRight().y());
            } break;
        case section_7: {
                m_active_section = new QGraphicsRectItem(
                            r.topLeft().x(), r.topLeft().y() + 400,
                            r.bottomRight().x(), r.bottomRight().y());
            } break;
        case section_8: {
                m_active_section = new QGraphicsRectItem(
                            r.topLeft().x() + 200, r.topLeft().y() + 400,
                            r.bottomRight().x(), r.bottomRight().y());
            } break;
        case section_9: {
                m_active_section = new QGraphicsRectItem(
                            r.topLeft().x() + 400, r.topLeft().y() + 400,
                            r.bottomRight().x(), r.bottomRight().y());
            } break;
        default:
            Q_ASSERT("Unexpected section" != 0);
    }
}

void board::leaveEvent(QEvent*)
{
    clear_highligthing();
}

void board::mousePressEvent(QMouseEvent* e)
{
    if (e->button() != Qt::LeftButton) {
        return;
    }
    QPointF p = QPointF(mapToScene(e->pos()));
    const unsigned s = find_section(p);
    manager* m = manager::get_instance();
    Q_ASSERT(m != 0);
    if(is_full() || check_section(s)){      
        return;
    }
    m->take_turn(s);
    update_board_data(m->get_item(), s);
    if(unsigned gs = m->check_game_status()){
        finish_game(gs);
        return;
    }
    if(!m->is_multiple_game()){
        unsigned cs = 0;
        m->do_player_cpu_turn(cs);
        Q_ASSERT(cs != 0);
        update_board_data(m->get_item(), cs);
        if(unsigned gs = m->check_game_status()){
            finish_game(gs);
        }
    }
}

board::section board::find_section(const QPointF& p)
{
    if(p.y() < 200) {
        if(p.x() < 200) {
            return section_1;
        } else if (p.x() < 400) {
            return section_2;
        }
        return section_3;
    } else if(p.y() < 400) {
        if(p.x() < 200) {
            return section_4;
        } else if (p.x() < 400) {
            return section_5;
        }
        return section_6;
    } else {
        if(p.x() < 200) {
            return section_7;
        } else if (p.x() < 400) {
            return section_8;
        }
        return section_9;
    }
}

bool board::check_section(const unsigned& s)
{
    Q_ASSERT(s != 0);
    return m_section[s];
}

bool board::is_full() const
{
    return m_board_shapes_count == board::section_9;
}

void board::update_board_data(abstract_item* i, const unsigned& s)
{
    Q_ASSERT(i != 0);
    m_scene->addItem(i);
    m_scene->update();
    ++m_board_shapes_count;
    m_section[s] = true;
}

void board::draw_victorious_line(const unsigned& s,
        const std::vector<unsigned>& v)
{
    switch(s) {
    case manager::draw:
        return;
    case manager::win:
        draw_victorious_x_line(v);
        return;
    case manager::lose:
        draw_victorious_o_line(v);
        return;
    }
}

void board::draw_victorious_o_line(const std::vector<unsigned>& v)
{
    for(size_t i = 0; i < v.size(); ++i){
        item_o* it = new item_o;
        it->set_section(v[i], true);
        m_scene->addItem(it);
    }
}

void board::draw_victorious_x_line(const std::vector<unsigned>& v)
{
    for(size_t i = 0; i < v.size(); ++i){
        item_x* it = new item_x;
        it->set_section(v[i], true);
        m_scene->addItem(it);
    }
}

void board::finish_game(const unsigned& s)
{
    std::vector<unsigned> v;
    manager* m = manager::get_instance();
    Q_ASSERT(m != 0);
    if(s == manager::win || s == manager::lose){
        m->get_victorious_line(v);
        draw_victorious_line(s, v);
    }
    emit game_status_changed(s);
}

void board::set_background_image(const QString& s)
{
    setStyleSheet("background-image: url(" + s + ");");
    m_scene->update();
}

void board::clear()
{
    m_scene->clear();
    m_board_shapes_count = 0;
    size_t n = m_section.size();
    for(size_t i = 0; i < n; ++i){
        m_section[i] = false;
    }
    draw_empty_board();
    m_scene->update();
}

void board::clear_highligthing()
{
    if (m_active_section) {
        m_scene->removeItem(m_active_section);
        delete m_active_section;
        m_active_section = 0;
        m_scene->update();
    }
}

