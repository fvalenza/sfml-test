cmake_minimum_required (VERSION 2.8.11)
project (SFML_TUTO)

set(CMAKE_CXX_FLAGS "-g -W -Wall -pedantic -std=c++11")

include_directories("include")
set(SHARED
  sfml-graphics
  sfml-window
  sfml-system
  sfml-audio
)
file(GLOB_RECURSE SRC src/*.cpp)

macro(ADD_APPLICATION MAINFILE EXEC )

  set(APP_${EXEC}
    app/${MAINFILE}.cpp
    ${SRC}
  )
  list(APPEND APP_${EXEC} ${SRC})
  add_executable(${EXEC} ${APP_${EXEC}})
  target_link_libraries(
    ${EXEC}
    ${SHARED}
  )
  message("${APP_${EXEC}}")
endmacro()

ADD_APPLICATION(main my_exe)
  