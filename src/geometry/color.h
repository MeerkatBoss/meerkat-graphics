#ifndef COLOR_H
#define COLOR_H

namespace geom
{
    using ChannelValue = unsigned char;

    class Color
    {
    private:
        ChannelValue _red;
        ChannelValue _green;
        ChannelValue _blue;
        ChannelValue _alpha;

    public:
        Color(int red, int green, int blue, int alpha);
        Color(int red, int green, int blue);
        Color(int hex);
        ~Color();

        ChannelValue red() const { return _red; }

        ChannelValue green() const { return _green; }

        ChannelValue blue() const { return _blue; }

        ChannelValue alpha() const { return _alpha; }
    };
} // namespace geom

#endif // COLOR_H
