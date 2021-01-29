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
have a look at<br>
https://github.com/LukasSeglias/CMake-OpenCV-from-sources and/or <br>
[OpenCV + Visual Studio + CMake = Adventure time](http://www.graymatterdeveloper.com/2019/12/25/opencv-and-cmake-in-cpp/)

## In detail
This template is especially for computer graphics and computer perception/vision projects.
Naturally, the template can be adapted for other projects also.<br>
The layout explained in detail:
```
.
├── app                     # Main project
    .
    └── src                 # Source files of the main project
├── cmake                   # Custom cmake files
├── ...                     # Not necessary for build purposes
├── ext                     # External libraries
├── lib                     # Custom libraries
    .
    └── custom_lib          # A library
        .
        ├── include         # Public header files of the library
        └── src             # Source files of the library
└── test                    # Automated tests
    .
    ├── ext                 # External libraries for test purposes only
    └── custom_lib          # Test project for "custom_lib"
        .
        ├── resources       # Contains resources for tests (eg. description of inputs)
        └── src             # Source files of the test application
```
There are three interesting targets:
- template_lib (The template library)
- template_lib_test (The test target for the template library)
- app (The main application which uses the target template_lib)

### Steps
1. Rename or remove the targets (there are TODOs in the corresponding CMake-Files "TODO: Rename")
2. Let CMake configure.
3. Run your main or test application
4. Add your own lib-targets and test-applications

### Doxygen
#### Prerequisites
- Docker

#### Build a document
Have a look at [lib/template_lib/](lib/template_lib). You will find a Doxyfile to describe the
documentation of that library. To create the documentation just build the target 'doxygen' or 
navigate in a console of your choice to the folder [doxygen](doxygen) and execute:
```
docker-compose up
```
The output will be stored in 'doxygen_output/<name-of-library>'.

#### Build another library
If you want to build the documentation of another library, just edit the environment
variable 'LIBRARY' [doxygen/.env](doxygen/.env) (this is the name of the folder of the library, eg. [template_lib](lib/template_lib)).
You can also change the language to generate there.

### The documentation
#### Prerequisites
- Docker

There is already a built in approach to generate a project documentation with
latex and docker. The necessary folders for this are "doc" and "doc_source".<br>
If you don't need a documentation pdf you can delete these two folders, don't forget to
remove the 'add_subdirectory' in [CMakeLists.txt](CMakeLists.txt), otherwise
read the next few lines.<br>

#### Build a document
You don't have to do much, just install docker on your system and navigate inside a console of your choice to
the folder [doc_source](doc_source) and execute:<br>
```
docker-compose up
```
or just use the target 'document' and build it.
This command generates and stores your pdf in [doc/document/en/document.pdf](doc/document/en/document.pdf).
If you wan't to change the language, just navigate to [doc_source/.env](doc_source/.env) and change the "LANGUAGE"
environment variable to "de" for example. Note that you must provide a language folder inside [doc_source/tex/document/](doc_source/tex/document)
where the language specific latex-files are stored. Inside this environment file, you can also change the document to
be created if you have more than one. The environment you have to change is "DOCUMENT". Just write the name of the
top-level folder there, at the moment this is [document](doc_source/tex/document).

#### Write content
There is an example layout provided, but you can change this as you want, just keep in mind
that there is a restriction with subdirectories. You can add just one subdirectory inside your language specific folder for
a chapter so you can't add another subdirectory in [doc_source/tex/document/en/chapter_01](doc_source/tex/document/en/chapter_01) for example
(however, a resource folder is allowed).<br><br>

#### I need more than one document
You can duplicate the directory [doc_source/tex/document/](doc_source/tex/document) and give it another name.
Then you can change the name inside the [doc_source/.env](doc_source/.env) file to build this document.
The resulting file will be stored inside "doc/<your-name>/<your-language>/<your-main-latex-file-name>.pdf".<br>
Note that there are much files generated, just copy and paste the [doc/document/.gitignore](doc/document/.gitignore)
file to your new directory "doc/<your-name>".

#### I have my own latex files which I need to provide
You are able to provide your own latex libraries, just put them directly inside [doc_source/tex/latex_files](doc_source/tex/latex_files).
Have a look at the text document there if you need some more info [a_latex_file.txt](doc_source/tex/latex_files/a_latex_file.txt).
During build-time, all the files will be copied to your directory where your main tex file is stored and will be automatically deleted from there after the build,
so don't worry if there appear and disappear some files magically.

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