#include "color.h"

namespace geom
{
    Color::Color(int red, int green, int blue, int alpha)
    {
        _red = (ChannelValue)red;
        _green = (ChannelValue)green;
        _blue = (ChannelValue)blue;
        _alpha = (ChannelValue)alpha;
    }

    Color::Color(int red, int green, int blue)
    {
        _red = (ChannelValue)red;
        _green = (ChannelValue)green;
        _blue = (ChannelValue)blue;
        _alpha = 0xff;
    }

    Color::Color(int hex)
    {
        if (hex >> 24)
        {
            _alpha = hex & 0xff;
            hex >>= 8;
        }
        _blue = hex & 0xff;
        hex >>= 8;
        _green = hex & 0xff;
        hex >>= 8;
        _red = hex & 0xff;
    }

    Color::~Color()
    {
    }
} // namespace geom
