/**
 * Tic Tac Toe
 */

#ifndef ITEM_X_HPP
#define ITEM_X_HPP

#include "items/abstract_item.hpp"

#include <map>

/**
 * @class item_x
 * @brief 'X' item implementation
 */
class item_x : public abstract_item
{
public:
    /// @brief Constructor
    item_x();

    /// @brief Destructor
    virtual ~item_x();

    /// @brief Return X item bounding rectangle
    virtual QRectF boundingRect() const override;

    /// @brief Paint X item
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

    /// @brief Set item section
    virtual void set_section(const unsigned&, bool = false) override;

private:
    unsigned m_section;
    std::map<unsigned, QPoint> m_pos;
    bool m_is_victorious;
};

#endif // ITEM_X_HPP
