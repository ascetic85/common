
#ifndef DD_SIZE_H
#define DD_SIZE_H

#include "common.h"

namespace DD
{

class Size
{
	DD_SYNTHESIZE(float, m_width, Width)
    DD_SYNTHESIZE(float, m_height, Height)
public:
	Size(void) : m_width(0), m_height(0) {}
	Size(float width, float height) : m_width(width), m_height(height) {}
	Size(const Size& v): m_width(v.getWidth()), m_height(v.getHeight()) {}

	bool operator==(const Size& other) const
    {
        return (m_width == other.getWidth() && m_width == other.getHeight);
    }

	bool operator!=(const Size& other) const
    {
        return !operator==(other);
    }

	Size operator*(float c) const
	{
		return Size(m_width * c, m_height * c);
	}

	Size operator+(const Size& s) const
	{
		return Size(m_width + s.getWidth(), m_height + s.getHeight());
	}
};

} // DD namespace
