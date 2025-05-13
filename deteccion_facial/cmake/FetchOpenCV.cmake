find_package(OpenCV REQUIRED COMPONENTS core imgproc videoio objdetect face highgui)

if(NOT OpenCV_FOUND)
  message(FATAL_ERROR "OpenCV not found. Please install OpenCV or check your installation.")
endif()

message(STATUS "Found OpenCV: ${OpenCV_VERSION}")
message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")