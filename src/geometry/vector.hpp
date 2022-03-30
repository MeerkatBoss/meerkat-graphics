#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>

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

        inline bool operator==(vector other) const
        {
            const double eps = 1e-9;
            return abs(x - other.x) < eps && abs(y - other.y) < eps;
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

#endif // VECTOR_HPP
