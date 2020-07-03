#pragma once

class Rectangle
{
public:
    Rectangle(float width = 0.0f, float height = 0.0f);
    ~Rectangle();

    void setWidth(float width) noexcept;
    void setHeight(float height) noexcept;

    float getArea() const noexcept;

protected:
private:
    float m_fWidth;
    float m_fHeight;
};