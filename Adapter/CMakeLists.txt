set(pattern adapter)

file(GLOB file_list test_*.cpp)

foreach(fname IN LISTS file_list)
  get_filename_component(bname ${fname} NAME_WE)
  add_executable(${pattern}_${bname} ${fname})
endforeach()
