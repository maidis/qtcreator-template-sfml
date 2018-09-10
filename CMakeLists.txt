project(%{ProjectName})

cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -O0")
set(CMAKE_MODULE_PATH "${CMAKE_ROOT}/Modules/"  "/usr/share/SFML/cmake/Modules/")


set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/%{CppFileName}


)
set(HEADERS
   ${HEADERS}


)

find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
endif()


add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
