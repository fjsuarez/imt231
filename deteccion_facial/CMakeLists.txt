cmake_minimum_required(VERSION 3.29)
project(face_course LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Bring in third-party libs
include(cmake/FetchLibTorch.cmake)   # sets TORCH_LIBRARIES & TORCH_INCLUDE_DIRS
include(cmake/FetchOpenCV.cmake)     # sets OpenCV_LIBS & OpenCV_INCLUDE_DIRS

# Our sources
file(GLOB_RECURSE SRC CONFIGURE_DEPENDS src/*.cpp include/*.hpp)

add_executable(hello_image ${SRC})
target_include_directories(hello_image PRIVATE ${TORCH_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS} include)
target_link_libraries    (hello_image PRIVATE ${TORCH_LIBRARIES}     ${OpenCV_LIBS})

# Windows DLL copy helper
if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET hello_image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${TORCH_DLLS} $<TARGET_FILE_DIR:hello_image>)
endif()
