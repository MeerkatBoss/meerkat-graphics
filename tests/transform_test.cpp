#include <gtest/gtest.h>
#include <geometry/transform.hpp>
TEST(TransformTest, emptyTransformTest)
{
    geom::Transform *transform = new geom::Transform();
    ASSERT_EQ(transform->position(), geom::vector(0, 0));
    ASSERT_EQ(transform->scale(), geom::vector(1, 1));
    ASSERT_TRUE(abs(transform->rotation()) < 1e-9);
}

TEST(TransformTest, setPositionTest)
{
    geom::vector new_pos = geom::vector(2.1, 3.4);
    geom::Transform *transform = new geom::Transform();
    transform->setPosition(new_pos);
    ASSERT_EQ(transform->position(), new_pos);
}