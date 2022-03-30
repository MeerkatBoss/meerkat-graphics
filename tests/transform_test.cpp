#include <gtest/gtest.h>
#include <geometry/transform.hpp>
TEST(TransformTest, emptyTransformTest)
{
    geom::Transform *transform = new geom::Transform();
    ASSERT_EQ(transform->position(), geom::vector(0, 0));
    ASSERT_EQ(transform->scale(), geom::vector(1, 1));
    ASSERT_LT(abs(transform->rotation()), 1e-9);
}

TEST(TransformTest, transformFromPositionTest)
{
    geom::vector pos = geom::vector(7.4, 3.2);
    geom::Transform *transform = new geom::Transform(pos);
    ASSERT_EQ(transform->position(), pos);
    ASSERT_EQ(transform->scale(), geom::vector(1, 1));
    ASSERT_LT(abs(transform->rotation()), 1e-9);
    pos.x = -8.21;
    ASSERT_NE(transform->position(), pos);
}

TEST(TransformTest, setPositionTest)
{
    geom::vector new_pos = geom::vector(2.1, 3.4);
    geom::Transform *transform = new geom::Transform();
    transform->setPosition(new_pos);
    ASSERT_EQ(transform->position(), new_pos);
    new_pos.y = 6.23;
    ASSERT_NE(transform->position(), new_pos);
}

TEST(TransformTest, translateTest)
{
    geom::vector pos = geom::vector(4.3, -5.34);
    geom::Transform *transform = new geom::Transform(pos);
    geom::vector translation = geom::vector(1.3, 3.6);
    transform->translate(translation);
    ASSERT_EQ(transform->position(), pos + translation);
}

TEST(TransformTest, setRotationTest)
{
    double angle = M_PI / 3;
    geom::Transform *transform = new geom::Transform();
    transform->setRotation(angle);
    ASSERT_LT(abs(transform->rotation() - angle), 1e-9);
}

TEST(TransformTest, rotateTest)
{
    double angle = M_PI / 6;
    double rotation = M_PI / 4;
    geom::Transform *transform = new geom::Transform();
    transform->setRotation(angle);
    transform->rotate(rotation);
    ASSERT_LT(abs(transform->rotation() - angle - rotation), 1e-9);
}

TEST(TransformTest, setScaleTest)
{
    geom::vector scale = geom::vector(4.2, 2.3);
    geom::Transform *transform = new geom::Transform();
    transform->setScale(scale);
    ASSERT_EQ(transform->scale(), scale);
    scale.y = 3.2;
    ASSERT_NE(transform->scale(), scale);
}

TEST(TransformTest, rescaleTest)
{
    geom::vector scale = geom::vector(2.1, 3.2);
    geom::vector rescale = geom::vector(4.3, 2.7);
    geom::vector new_scale = geom::vector(
        scale.x * rescale.x,
        scale.y * rescale.y);
    geom::Transform *transform = new geom::Transform();
    transform->setScale(scale);
    transform->rescale(rescale);
    ASSERT_EQ(transform->scale(), new_scale);
}

TEST(TransformTest, rescaleAndRotateTest)
{
    geom::vector scale = geom::vector(2.1, 3.2);
    geom::vector rescale = geom::vector(0.3, 4.2);
    geom::vector new_scale = geom::vector(
        scale.x * rescale.x,
        scale.y * rescale.y);
    double angle = M_PI / 6;
    double rotation = M_PI / 4;
    double new_angle = angle + rotation;
    geom::Transform *transform = new geom::Transform();
    transform->setScale(scale);
    transform->setRotation(angle);
    ASSERT_EQ(transform->scale(), scale);
    ASSERT_LT(abs(transform->rotation() - angle), 1e-9);
    transform->rescale(rescale);
    transform->rotate(rotation);
    ASSERT_EQ(transform->scale(), new_scale);
    ASSERT_LT(abs(transform->rotation() - new_angle), 1e-9);
}

TEST(TransformTest, invalidSetScaleTest)
{
    geom::vector scale = geom::vector(-1.3, 3.2);
    geom::Transform *transform = new geom::Transform();
    ASSERT_THROW(transform->setScale(scale), std::invalid_argument);
}

TEST(TransformTest, invalidRescaleTest)
{
    geom::vector scale = geom::vector(2.3, 2.1);
    geom::vector rescale = geom::vector(3.3, -0.8);
    geom::Transform *transform = new geom::Transform();
    transform->setScale(scale);
    ASSERT_THROW(transform->rescale(rescale), std::invalid_argument);
}