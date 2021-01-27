target_sources(${PROJECT_NAME}
        PUBLIC
        ../include/template_lib/template_lib.hpp
        ../include/template_lib/type.hpp

        PRIVATE
        template_lib.cpp
        type.cpp)
