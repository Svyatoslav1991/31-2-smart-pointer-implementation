# CMakeList.txt : CMake project for 31-1-using-smart-pointer, include source and define
# project specific logic here.
#

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Add source to this project's executable.
add_executable (31-2-smart-pointer-implementation "main.cpp"  ${MY_INCLUDE_DIR}/dog.h "dog.cpp" ${MY_INCLUDE_DIR}/shared_ptr_toy.h "shared_ptr_toy.cpp" ${MY_INCLUDE_DIR}/functions.h "functions.cpp")

target_include_directories(31-2-smart-pointer-implementation PUBLIC ${CMAKE_SOURCE_DIR}/include)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 31-2-smart-pointer-implementation PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.