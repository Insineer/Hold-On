#include "Useful.hpp"

#include <SFML/Graphics.hpp>

#include "Useful/Vec2f.hpp"

int GetSign(float t) { return -(std::signbit(t) * 2 - 1); }

inline float Dist(const vec2f &vec) { return std::sqrt(vec.x * vec.x + vec.y * vec.y); }

inline float HalfDiag(const sf::RectangleShape &Rect) {
    return std::sqrt(Rect.getSize().x * Rect.getSize().x + Rect.getSize().y * Rect.getSize().y) / 2;
}

inline vec2f Rotation(float x, float y, float angle) {
    return vec2f(x * std::cos(angle) + y * std::sin(angle), y * std::cos(angle) - x * std::sin(angle));
}

inline std::pair<vec2f, vec2f> GetSegm1(const sf::RectangleShape &Rect) {
    return std::make_pair(Rotation(Rect.getPosition().x - Rect.getSize().x / 2,
                                   Rect.getPosition().y - Rect.getSize().y / 2, Rect.getRotation()),
                          Rotation(Rect.getPosition().x + Rect.getSize().x / 2,
                                   Rect.getPosition().y - Rect.getSize().y / 2, Rect.getRotation()));
};

inline std::pair<vec2f, vec2f> GetSegm2(const sf::RectangleShape &Rect) {
    return std::make_pair(Rotation(Rect.getPosition().x + Rect.getSize().x / 2,
                                   Rect.getPosition().y - Rect.getSize().y / 2, Rect.getRotation()),
                          Rotation(Rect.getPosition().x + Rect.getSize().x / 2,
                                   Rect.getPosition().y + Rect.getSize().y / 2, Rect.getRotation()));
};

inline std::pair<vec2f, vec2f> GetSegm3(const sf::RectangleShape &Rect) {
    return std::make_pair(Rotation(Rect.getPosition().x - Rect.getSize().x / 2,
                                   Rect.getPosition().y + Rect.getSize().y / 2, Rect.getRotation()),
                          Rotation(Rect.getPosition().x + Rect.getSize().x / 2,
                                   Rect.getPosition().y + Rect.getSize().y / 2, Rect.getRotation()));
};

inline std::pair<vec2f, vec2f> GetSegm4(const sf::RectangleShape &Rect) {
    return std::make_pair(Rotation(Rect.getPosition().x - Rect.getSize().x / 2,
                                   Rect.getPosition().y - Rect.getSize().y / 2, Rect.getRotation()),
                          Rotation(Rect.getPosition().x - Rect.getSize().x / 2,
                                   Rect.getPosition().y + Rect.getSize().y / 2, Rect.getRotation()));
};

inline float TriangleArea(vec2f a, vec2f b, vec2f c) { return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }

inline bool Intersect(float a, float b, float c, float d) {
    if (a > b) std::swap (a, b);
    if (c > d) std::swap (c, d);
    return std::max(a, c) <= std::min(b, d);
}

bool Intersect(vec2f a, vec2f b, vec2f c, vec2f d) {
    return Intersect(a.x, b.x, c.x, d.x)
           && Intersect(a.y, b.y, c.y, d.y)
           && GetSign(TriangleArea(a, b, c)) * GetSign(TriangleArea(a, b, d)) <= 0
           && GetSign(TriangleArea(c, d, a)) * GetSign(TriangleArea(c, d, b)) <= 0;
}

bool Intersect(vec2f &point1, vec2f &point2, const sf::CircleShape &Circle) {
    vec2f c = Circle.getPosition();
    float diffX = point2.x - point1.x,
          diffY = point2.y - point1.y;
    float x = (diffX * diffY * (c.y - point1.y) + point1.x * diffY * diffY + c.x * diffX * diffX)
            / (diffY * diffY + diffX * diffX),
          y = diffY * (x - point1.x) / diffX + point1.y;
    vec2f diff = vec2f(x, y) - c;
    if (Circle.getRadius() < Dist(diff))
        return false;
    return true;
}

bool Intersect(const sf::CircleShape &Circle1, const sf::CircleShape &Circle2) {
    auto diff = vec2f(Circle1.getPosition()) - vec2f(Circle2.getPosition());
    if (Circle1.getRadius() + Circle2.getRadius() < Dist(diff))
        return false;
    return true;
}

bool Intersect(const sf::RectangleShape &Rect1, const sf::RectangleShape &Rect2) {
    auto diff = vec2f(Rect1.getPosition()) - vec2f(Rect2.getPosition());

    if (HalfDiag(Rect1) + HalfDiag(Rect2) < Dist(diff))
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

bool Intersect(const sf::CircleShape &Circle, const sf::RectangleShape &Rect) {
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

bool Intersect(const sf::RectangleShape &Rect, const sf::CircleShape &Circle) { return Intersect(Circle, Rect); }