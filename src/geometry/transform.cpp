#include "transform.hpp"

namespace geom
{

    Transform::Transform()
        : _position()
    {
        _matrix[0][0] = 1;
        _matrix[0][1] = 0;
        _matrix[1][0] = 0;
        _matrix[1][1] = 1;
    }

    Transform::Transform(const vector &position)
        : Transform()
    {
        _position = position;
    }

    vector Transform::scale() const
    {
        return vector(
            hypot(_matrix[0][0], _matrix[0][1]),
            hypot(_matrix[1][0], _matrix[1][1]));
    }

    void Transform::setScale(const vector &scale)
    {
        if (scale.x <= 0 || scale.y <= 0)
        {
            throw std::invalid_argument("Scale must be a positive number");
        }
        vector current_scale = this->scale();
        _matrix[0][0] *= scale.x / current_scale.x;
        _matrix[0][1] *= scale.x / current_scale.x;
        _matrix[1][0] *= scale.y / current_scale.y;
        _matrix[1][1] *= scale.y / current_scale.y;
    }

    double Transform::rotation() const
    {
        return atan2(_matrix[0][1], _matrix[0][0]);
    }

    void Transform::setRotation(double angle)
    {
        vector current_scale = this->scale();
        double _sin = sin(angle);
        double _cos = cos(angle);
        _matrix[0][0] = _cos * current_scale.x;
        _matrix[0][1] = _sin * current_scale.x;
        _matrix[1][0] = -_sin * current_scale.y;
        _matrix[1][1] = _cos * current_scale.y;
    }

    void Transform::translate(const vector &translation)
    {
        _position = _position + translation;
    }

    void Transform::rotate(double angle)
    {
        double _sin = sin(angle);
        double _cos = cos(angle);
        int tmp[2][2];
        tmp[0][0] = _matrix[0][0] * _cos + _matrix[1][0] * _sin;
        tmp[1][0] = -_matrix[0][0] * _sin + _matrix[1][0] * _cos;
        tmp[0][1] = _matrix[0][1] * _cos + _matrix[1][1] * _sin;
        tmp[1][1] = -_matrix[0][1] * _sin + _matrix[1][1] * _cos;
        _matrix[0][0] = tmp[0][0];
        _matrix[0][1] = tmp[0][1];
        _matrix[1][0] = tmp[1][0];
        _matrix[1][1] = tmp[1][1];
    }

    void Transform::rescale(const vector &scale)
    {
        if (scale.x <= 0 || scale.y <= 0)
        {
            throw std::invalid_argument("Scale must be a positive number");
        }
        _matrix[0][0] *= scale.x;
        _matrix[0][1] *= scale.x;
        _matrix[1][0] *= scale.y;
        _matrix[1][1] *= scale.y;
    }

}