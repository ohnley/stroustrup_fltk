add_executable(app app.cpp)
add_executable(ch14ex09 ch14ex09.cpp)
add_executable(ch15 ch15drill.cpp)

# connect this to private dummy library
# this works since in the project level CMakeLists file, we added the 
# src sub-directory before this applicachun subdirectory
target_link_libraries(app PUBLIC dummy_library memos_lib strostrup_gui)
target_link_libraries(ch14ex09 PUBLIC dummy_library memos_lib strostrup_gui)
target_link_libraries(ch15 PUBLIC dummy_library memos_lib strostrup_gui)
# target_link_libraries(app PRIVATE fltk)
# target_include_directories(app PRIVATE ${FLTK_INCLUDE_DIRS})
# fltk_forms fltk_gl fltk_images)
# target_link_libraries(app PRIVATE fmt::fmt)



