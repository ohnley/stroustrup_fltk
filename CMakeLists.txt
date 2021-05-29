cmake_minimum_required(VERSION 3.01)

project(
    DummyCMakeTest
    VERSION 2.0.0
    DESCRIPTION "A dummy project made with CMAKE"
)

# if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

#     set(CMAKE_CXX_EXTENSIONS OFF)
    
#     include(CTest)


# endif()
# include(FetchContent)

# find external packages
set(FLTK_DIR "F:/my_dev/extern_libs/fltk136/build")
find_package(FLTK REQUIRED CONFIG)


# this allows us to grab outside libraries that use CMake and pull them 
# into this project -- not sure if this does a static or dynamic link
# FetchContent_Declare(
#     fmtlib
#     GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#     GIT_TAG 7.1.3
# )

# FetchContent_Declare( FLTK
#     GIT_REPOSITORY      https://github.com/fltk/fltk
#     GIT_TAG             "branch-1.1"
# )
# we still need to link this to the executable in the application CMAKE
# FetchContent_MakeAvailable(fmtlib)
# FetchContent_MakeAvailable(FLTK)

add_subdirectory(src)
add_subdirectory(applicachun)