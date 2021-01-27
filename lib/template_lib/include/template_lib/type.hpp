#pragma once

#include "macro_definition.hpp"

namespace templatelib {
    struct EXPORT_TEMPLATE_LIB Type {
        explicit Type(int value = 0);

        int _value;
    };
}