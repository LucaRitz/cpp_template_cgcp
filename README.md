# C++ Template for computer perception and computer graphics

This is a template project which contains the configuration of
the following external libraries:
- opencv (https://github.com/opencv/opencv.git)
- opencv_contrib (https://github.com/opencv/opencv_contrib.git)
- opengl
- fltk (https://github.com/fltk/fltk)
- glad (https://github.com/Dav1dde/glad)
- glm (https://github.com/g-truc/glm)

Additional for testing:
- googletest (https://github.com/google/googletest.git)
- nlohmann_json (https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent)

The project consists of a main application, a template library and its test application.
You just have to create your own project out of this template, import it in your IDE and start the cmake configuration
process. Then you're able to run your application.
There is no need to install or build the external libs separately.

## Note
Opencv will build at cmake-configuration time and it will take a while. For more information
have a look at https://github.com/LukasSeglias/CMake-OpenCV-from-sources and/or
[OpenCV + Visual Studio + CMake = Adventure time](http://www.graymatterdeveloper.com/2019/12/25/opencv-and-cmake-in-cpp/)

## In detail
This template is especially for computer graphics and computer perception/vision projects.
Naturally, the template can be adapted for other projects also.<br>
The layout explained in detail:
```
.
├── cmake                   # Custom cmake files
├── ext                     # External libraries
├── lib                     # Custom libraries
    .
    └── custom_lib          # A library
        .
        ├── include         # Public header files
        ├── src             # Source files
├── main                    # Main project
    .
    └── src                 # Source files
└── test                    # Automated tests
    .
    ├── ext                 # External test libraries
    └── custom_lib          # Test project for "custom_lib"
        .
        ├── resources       # Contains resources for tests (eg. description of inputs)
        ├── src             # Source files
```
There are three targets interesting:
- template_lib (The template library)
- template_lib_test (The test target for the template library)
- main_exe (The main application which uses the target template_lib)

## Platforms and build
The libraries are intent to be shared-build, there is no static build available right now.
The libs are moved to the correct place automatically after each build.

The project runs on the following platforms:
- Windows 10

Tested IDEs:
- CLion
- Visual Studio 2019

## Additional
I tried to follow the latest cmake recommendations. If there is any potential for improvement
(eg. testing and fixing for linux platforms), feel free to contribute.