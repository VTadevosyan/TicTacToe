/**
 * Tic Tac Toe
 */

#ifndef ITEM_O_HPP
#define ITEM_O_HPP

#include "items/abstract_item.hpp"

#include <map>

/**
 * @class item_o
 * @brief 'O' item implementation
 */
class item_o : public abstract_item
{
public:
    /// @brief Constructor
    item_o();

    /// @brief Destructor
    virtual ~item_o();

    /// @brief Return O item bounding rectangle
    virtual QRectF boundingRect() const override;

    /// @brief Paint O item
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

    /// @brief Set item section
    virtual void set_section(const unsigned&, bool t = false) override;

private:
    unsigned m_section;
    std::map<unsigned, QPoint> m_pos;
    bool m_is_victorious;
};

#endif // ITEM_O_HPP
