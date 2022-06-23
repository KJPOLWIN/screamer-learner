cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(screamer-learner VERSION 0.2)

IF(WIN32)
  set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

find_package(SFML 2.5.1 REQUIRED network audio graphics window system)

add_executable(screamer-learner src/main.cpp src/mainmenu.cpp src/options.cpp 
                                src/quizselect.cpp src/textbutton.cpp src/quiz.cpp
                                src/question.cpp src/quizstate.cpp src/jumpscare.cpp)

target_compile_options(screamer-learner PUBLIC -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion)
target_include_directories(screamer-learner PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src ${SFML_INCLUDE_DIR})
target_link_libraries(screamer-learner PUBLIC ${SFML_LIBRARIES} sfml-audio sfml-graphics sfml-system sfml-window)

