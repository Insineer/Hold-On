#include "Geometry.hpp"

#include "Useful/Math.hpp"

namespace uf {
    float HalfDiag(const Rectangle &Rect) {
        return std::sqrt(Rect.GetSize().x * Rect.GetSize().x + Rect.GetSize().y * Rect.GetSize().y) / 2;
    }

    vec2f Rotation(float x, float y, float angle) {
        return vec2f(x * std::cos(angle) + y * std::sin(angle), y * std::cos(angle) - x * std::sin(angle));
    }

    std::pair<vec2f, vec2f> GetSegm1(const Rectangle &Rect) {
        return std::make_pair(Rotation(Rect.GetPosition().x - Rect.GetSize().x / 2,
                                       Rect.GetPosition().y - Rect.GetSize().y / 2, Rect.GetRotation()),
                              Rotation(Rect.GetPosition().x + Rect.GetSize().x / 2,
                                       Rect.GetPosition().y - Rect.GetSize().y / 2, Rect.GetRotation()));
    };

    std::pair<vec2f, vec2f> GetSegm2(const Rectangle &Rect) {
        return std::make_pair(Rotation(Rect.GetPosition().x + Rect.GetSize().x / 2,
                                       Rect.GetPosition().y - Rect.GetSize().y / 2, Rect.GetRotation()),
                              Rotation(Rect.GetPosition().x + Rect.GetSize().x / 2,
                                       Rect.GetPosition().y + Rect.GetSize().y / 2, Rect.GetRotation()));
    };

    std::pair<vec2f, vec2f> GetSegm3(const Rectangle &Rect) {
        return std::make_pair(Rotation(Rect.GetPosition().x - Rect.GetSize().x / 2,
                                       Rect.GetPosition().y + Rect.GetSize().y / 2, Rect.GetRotation()),
                              Rotation(Rect.GetPosition().x + Rect.GetSize().x / 2,
                                       Rect.GetPosition().y + Rect.GetSize().y / 2, Rect.GetRotation()));
    };

    std::pair<vec2f, vec2f> GetSegm4(const Rectangle &Rect) {
        return std::make_pair(Rotation(Rect.GetPosition().x - Rect.GetSize().x / 2,
                                       Rect.GetPosition().y - Rect.GetSize().y / 2, Rect.GetRotation()),
                              Rotation(Rect.GetPosition().x - Rect.GetSize().x / 2,
                                       Rect.GetPosition().y + Rect.GetSize().y / 2, Rect.GetRotation()));
    };

    float TriangleArea(vec2f a, vec2f b, vec2f c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    bool Intersect(float a, float b, float c, float d) {
        if (a > b) std::swap(a, b);
        if (c > d) std::swap(c, d);
        return std::max(a, c) <= std::min(b, d);
    }

    bool Intersect(const vec2f &a, const vec2f &b, const vec2f &c, const vec2f &d) {
        return Intersect(a.x, b.x, c.x, d.x)
               && Intersect(a.y, b.y, c.y, d.y)
               && uf::sgn(TriangleArea(a, b, c)) * uf::sgn(TriangleArea(a, b, d)) <= 0
               && uf::sgn(TriangleArea(c, d, a)) * uf::sgn(TriangleArea(c, d, b)) <= 0;
    }

    bool Intersect(const vec2f &point1, const vec2f &point2, const Circle &Circle) {
        vec2f c = Circle.GetPosition();
        float diffX = point2.x - point1.x,
                diffY = point2.y - point1.y;
        float x = (diffX * diffY * (c.y - point1.y) + point1.x * diffY * diffY + c.x * diffX * diffX)
                  / (diffY * diffY + diffX * diffX),
                y = diffY * (x - point1.x) / diffX + point1.y;
        vec2f diff = vec2f(x, y) - c;
        if (Circle.GetRadius() < length(diff))
            return false;
        return true;
    }

    bool Intersect(const Circle &Circle1, const Circle &Circle2) {
        auto diff = vec2f(Circle1.GetPosition()) - vec2f(Circle2.GetPosition());
        if (Circle1.GetRadius() + Circle2.GetRadius() < length(diff))
            return false;
        return true;
    }

    bool Intersect(const Rectangle &Rect1, const Rectangle &Rect2) {
        auto diff = vec2f(Rect1.GetPosition()) - vec2f(Rect2.GetPosition());

        if (HalfDiag(Rect1) + HalfDiag(Rect2) < length(diff))
            return false;

        std::pair<vec2f, vec2f> Rect1Segm1 = GetSegm1(Rect1),
                Rect2Segm1 = GetSegm1(Rect2),
                Rect1Segm2 = GetSegm2(Rect1),
                Rect2Segm2 = GetSegm2(Rect2),
                Rect1Segm3 = GetSegm3(Rect1),
                Rect2Segm3 = GetSegm3(Rect2),
                Rect1Segm4 = GetSegm4(Rect1),
                Rect2Segm4 = GetSegm4(Rect2);
        if (Intersect(Rect1Segm1.first, Rect1Segm1.second, Rect2Segm1.first, Rect2Segm1.second)
            || Intersect(Rect1Segm1.first, Rect1Segm1.second, Rect2Segm2.first, Rect2Segm2.second)
            || Intersect(Rect1Segm1.first, Rect1Segm1.second, Rect2Segm3.first, Rect2Segm3.second)
            || Intersect(Rect1Segm1.first, Rect1Segm1.second, Rect2Segm4.first, Rect2Segm4.second)
            || Intersect(Rect1Segm2.first, Rect1Segm2.second, Rect2Segm1.first, Rect2Segm1.second)
            || Intersect(Rect1Segm2.first, Rect1Segm2.second, Rect2Segm2.first, Rect2Segm2.second)
            || Intersect(Rect1Segm2.first, Rect1Segm2.second, Rect2Segm3.first, Rect2Segm3.second)
            || Intersect(Rect1Segm2.first, Rect1Segm2.second, Rect2Segm4.first, Rect2Segm4.second)
            || Intersect(Rect1Segm3.first, Rect1Segm3.second, Rect2Segm1.first, Rect2Segm1.second)
            || Intersect(Rect1Segm3.first, Rect1Segm3.second, Rect2Segm2.first, Rect2Segm2.second)
            || Intersect(Rect1Segm3.first, Rect1Segm3.second, Rect2Segm3.first, Rect2Segm3.second)
            || Intersect(Rect1Segm3.first, Rect1Segm3.second, Rect2Segm4.first, Rect2Segm4.second)
            || Intersect(Rect1Segm4.first, Rect1Segm4.second, Rect2Segm1.first, Rect2Segm1.second)
            || Intersect(Rect1Segm4.first, Rect1Segm4.second, Rect2Segm2.first, Rect2Segm2.second)
            || Intersect(Rect1Segm4.first, Rect1Segm4.second, Rect2Segm3.first, Rect2Segm3.second)
            || Intersect(Rect1Segm4.first, Rect1Segm4.second, Rect2Segm4.first, Rect2Segm4.second))
            return true;
        return false;
    }

    bool Intersect(const Circle &Circle, const Rectangle &Rect) {
        std::pair<vec2f, vec2f> Segm1 = GetSegm1(Rect),
                Segm2 = GetSegm2(Rect),
                Segm3 = GetSegm3(Rect),
                Segm4 = GetSegm4(Rect);
        if (Intersect(Segm1.first, Segm1.second, Circle)
            || Intersect(Segm2.first, Segm2.second, Circle)
            || Intersect(Segm3.first, Segm3.second, Circle)
            || Intersect(Segm4.first, Segm4.second, Circle))
            return true;
        return false;
    }

    bool Intersect(const Rectangle &Rect, const Circle &Circle) { return Intersect(Circle, Rect); }
}