/**
 * Tic Tac Toe
 */

#ifndef ABSTRACT_ITEM_HPP
#define ABSTRACT_ITEM_HPP

#include <QGraphicsItem>
#include <QRectF>


namespace items {

static const QRectF bounding_rect = QRectF(0, 0, 200, 200);

} // items

/**
 * @class abstract_item
 * @brief The base class for 'X' & 'O' items
 */
class abstract_item : public QGraphicsItem
{
public:
    /// @brief Constructor
    abstract_item()
    {
    }

    /// @brief Destructor
    virtual ~abstract_item()
    {
    }

    /// @brief Return item bounding rectangle
    virtual QRectF boundingRect() const = 0;

    /// @brief Paint item
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) = 0;

    /// @brief Set drawing item section
    virtual void set_section(const unsigned&, bool = false) = 0;

};

#endif // ABSTRACT_ITEM_HPP
