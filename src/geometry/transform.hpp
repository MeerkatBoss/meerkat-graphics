#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <geometry/vector.hpp>
#include <cmath>
#include <stdexcept>

namespace geom
{
    /**
     * @brief Class used for storing object's rotation, position and scale
     */
    class Transform
    {
    private:
        vector _position;
        double _matrix[2][2];

    public:
        Transform();
        explicit Transform(const vector &position);
        ~Transform() {}

        /**
         * @brief Retrieve position of object's origin
         *
         * @return Vector from (0, 0) to origin
         */
        vector position() const { return _position; }

        /**
         * @brief Set the position of object's origin
         *
         * @param position new position of object's origin
         */
        void setPosition(const vector &position) { _position = position; }

        /**
         * @brief Retrieve scale of the object
         *
         * @return Vector representation of scale. X-coordinate corresponds
         * to scale along x-axis, y-coordinate corresponds to scale along y-axis
         */
        vector scale() const;

        /**
         * @brief Set the scale of object
         *
         * @param scale new scale vector. Coordinates must be positive
         * @throws std::invalid_argument - provided scale had
         *                                  non-positive coordinates
         */
        void setScale(const vector &scale);

        /**
         * @brief Retrive object's rotation around the origin in radians
         *
         * @return Rotation angle in radians
         */
        double rotation() const;

        /**
         * @brief Set the rotation angle around object's origin
         *
         * @param angle - angle of rotation in radians
         */
        void setRotation(double angle);

        /**
         * @brief Apply translation to object's origin
         *
         * @param translation translation vector
         */
        void translate(const vector &translation);

        /**
         * @brief Rotate object around its origin
         *
         * @param angle rotation angle in radians
         */
        void rotate(double angle);

        /**
         * @brief Apply scale to object
         *
         * @param scale scale factors along x and y axes
         * @throws std::invalid_argument - scale vector had
         *                                  non-positive coordinates
         */
        void rescale(const vector &scale);
    };

} // namespace geom

#endif // TRANSFORM_HPP
