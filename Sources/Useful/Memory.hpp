#pragma once

#include <memory>

namespace uf {

    template<class T>
    using uptr = std::unique_ptr<T>;

}