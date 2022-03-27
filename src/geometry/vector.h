#ifndef PRIMITIVES_H
#define PRIMITIVES_H

namespace geom
{
    struct vector
    {
        double x;
        double y;
        vector() : x(0), y(0) {}
        vector(double _x, double _y) : x(_x), y(_y) {}

        inline vector operator+(const vector &other) const
        {
            return vector(x + other.x, y + other.y);
        }

        inline vector operator-(const vector &other) const
        {
            return vector(x - other.x, y - other.y);
        }

        inline vector operator*(const double k) const
        {
            return vector(x * k, y * k);
        }
    };

    inline vector operator*(double k, const vector &v)
    {
        return v * k;
    }

    inline double dot_product(const vector &a, const vector &b)
    {
        return a.x * b.x + a.y * b.y;
    }

    inline double cross_product(const vector &a, const vector &b)
    {
        return a.x * b.y - a.y * b.x;
    }

} // namespace geom

#endif // PRIMITIVES_H
