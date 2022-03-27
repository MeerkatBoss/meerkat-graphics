#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "vector.h"

namespace geom
{
    class Transform
    {
    private:
        vector _position;
        int _matrix[2][2];

    public:
        Transform(/* args */);
        ~Transform();

        vector position() const { return _position; }
        void setPosition(const vector &position) { _position = position; }
    };

} // namespace geom

#endif // TRANSFORM_H
