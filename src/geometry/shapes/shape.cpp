#include "shape.hpp"
namespace geom
{
  Shape::Shape(Color *border_color, Color *fill_color)
      : _border_color(border_color),
        _fill_color(fill_color) {}
} // namespace geom
