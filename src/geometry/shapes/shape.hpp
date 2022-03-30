#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <geometry/color.hpp>
#include <geometry/iterators/vertex_iterator.hpp>
namespace geom
{
    class Shape
    {
    private:
        Color *_border_color;
        Color *_fill_color;

    protected:
        Shape(Color *border_color, Color *fill_color);

    public:
        ~Shape();

        Color *borderColor() const { return _border_color; }
        void setBorderColor(Color *border_color) { _border_color = border_color; }

        Color *fillColor() const { return _fill_color; }
        void setFillColor(Color *fill_color) { _fill_color = fill_color; }

        virtual VertexIterator getIterator(int maxDeviationPx) = 0;
    };
} // namespace geom

#endif // SHAPE_HPP
