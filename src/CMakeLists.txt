
set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/dummycmake/blinker.hpp"
                "${PROJECT_SOURCE_DIR}/include/dummycmake/sorter.hpp"
)

set(MEMO_HEADER "${PROJECT_SOURCE_DIR}/include/dummycmake/memostab.h"
)

set(STROUSTRUP_GUI_HEADER "${PROJECT_SOURCE_DIR}/include/dummycmake/fltk.h"
                          "${PROJECT_SOURCE_DIR}/include/dummycmake/Graph.h"
                          "${PROJECT_SOURCE_DIR}/include/dummycmake/Gui.h"
                          "${PROJECT_SOURCE_DIR}/include/dummycmake/Point.h"
                          "${PROJECT_SOURCE_DIR}/include/dummycmake/Simple_window.h"
                          "${PROJECT_SOURCE_DIR}/include/dummycmake/Window.h"
                          "${PROJECT_SOURCE_DIR}/include/dummycmake/std_lib_facilities.h"
)



# set up this projects libraries
add_library(dummy_library blinker.cpp sorter.cpp ${HEADER_LIST})
target_include_directories(dummy_library PUBLIC ../include)

add_library(memos_lib memostab.cpp  ${MEMO_HEADER})
target_include_directories(memos_lib PUBLIC ../include)

add_library(strostrup_gui Graph.cpp GUI.cpp Window.cpp Simple_window.cpp ${STROUSTRUP_GUI_HEADER})
target_include_directories(strostrup_gui PUBLIC ../include)

# link the stroustrup gui to the FLTK
target_include_directories(strostrup_gui PUBLIC ${FLTK_INCLUDE_DIRS})
target_link_libraries(strostrup_gui PUBLIC fltk_forms fltk_gl fltk_images)
# target_link_libraries(strostrup_gui PUBLIC  fltk_z)




# Debug ...

message(STATUS "BUILD_FLTK                  = ${BUILD_FLTK}")
message(STATUS "FLTK_DIR                    = ${FLTK_DIR}")
message(STATUS "FLTK_FOUND                  = ${FLTK_FOUND}")
message(STATUS "FLTK_COMMIT                 = '${FLTK_COMMIT}'")
message(STATUS "FLTK_INCLUDE_DIRS           = ${FLTK_INCLUDE_DIRS}")
message(STATUS "FLTK SOURCE DIRS            = ${fltk_SOURCE_DIR}")
message(STATUS "MSVCIDE PATH                = ${CMAKE_MSVCIDE_RUN_PATH}")
# source_group(
#     TREE "${PROJECT_SOURCE_DIR}/include"
#     PREFIX "Headerd Files"
#     FILES ${HEADER_LSIT} ${MEMO_HEADER}
# )