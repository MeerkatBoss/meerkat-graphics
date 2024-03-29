#ifndef VERTEX_ITERATOR_HPP
#define VERTEX_ITERATOR_HPP

#include <geometry/vector.hpp>
namespace geom
{
    class VertexIterator
    {
    protected:
        VertexIterator();

    public:
        virtual bool hasNext() = 0;
        virtual vector getCurrent() = 0;
        virtual void next() = 0;
        ~VertexIterator();
    };

} // namespace geom

#endif // VERTEX_ITERATOR_HPP
