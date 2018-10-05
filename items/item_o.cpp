/**
 * Tic Tac Toe
 */

#include "items/item_o.hpp"
#include "game/manager.hpp"

#include <QPainter>
#include <QPixmap>


item_o::item_o() : m_section(0)
{
    m_pos[1] = QPoint(1, 1);
    m_pos[2] = QPoint(201, 1);
    m_pos[3] = QPoint(401, 1);
    m_pos[4] = QPoint(1, 201);
    m_pos[5] = QPoint(201, 201);
    m_pos[6] = QPoint(401, 201);
    m_pos[7] = QPoint(1, 401);
    m_pos[8] = QPoint(201, 401);
    m_pos[9] = QPoint(401, 401);
}

item_o::~item_o()
{
}

QRectF item_o::boundingRect() const
{
    return items::bounding_rect;
}

void item_o::paint(QPainter* p, const QStyleOptionGraphicsItem*, QWidget*)
{
    if(m_is_victorious){
        p->setPen(Qt::NoPen);
        p->setBrush(QBrush(Qt::red));
        p->drawRect(QRect(m_pos[m_section], QSize(197, 197)));
    }
    manager* m = manager::get_instance();
    Q_ASSERT(m != 0);
    p->drawPixmap(m_pos[m_section], QPixmap(m->get_item_image_path().second));
}

void item_o::set_section(const unsigned& s, bool t)
{
    Q_ASSERT(s != 0 || s > 10);
    m_section = s;
    m_is_victorious = t;
}
