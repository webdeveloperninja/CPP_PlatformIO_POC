#include "rectangle.h"

Rectangle::Rectangle(float const width, float const height)
    : m_fWidth{width},
      m_fHeight{height}
{
}

Rectangle::~Rectangle()
{
}

float Rectangle::getArea() const noexcept
{
    return m_fWidth * m_fHeight;
}

void Rectangle::setWidth(float const width) noexcept
{
    m_fWidth = width;
}

void Rectangle::setHeight(float const height) noexcept
{
    m_fHeight = height;
}