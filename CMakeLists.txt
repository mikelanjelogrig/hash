cmake_minimum_required(VERSION 2.8)
project( hash )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( hash hash.cpp )
target_link_libraries( hash ${OpenCV_LIBS} )
install(FILES "opencv2/opencv.hpp"
    DESTINATION ${OPENCV_INCLUDE_INSTALL_PATH}/opencv2
    COMPONENT dev)