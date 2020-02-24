set(module_name builder)

FILE(GLOB file_list "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
set(library_file_list)
foreach(fname IN LISTS file_list)
  string(REGEX REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/test_.*\.cpp" "" out ${fname})
  list(APPEND library_file_list "${out}")
endforeach()

if (library_file_list)
  add_library(${module_name} ${library_file_list})
endif()

ADD_TEST(${library_file_list})
