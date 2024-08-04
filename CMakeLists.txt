cmake_minimum_required(VERSION 3.28)
project(pasjns)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
        widgets/card/card.h
    widgets/board.h
)
set(SOURCE
        widgets/card/card.cpp
    widgets/board.cpp
        source/tackle.cpp
        source/tackle.h
        source/singleton.h
        widgets/card/source/card_apperance.cpp
        widgets/card/source/card_event.cpp
        widgets/card/source/card_move.cpp
        widgets/card/source/card_move.h
)
set(OTHER
    main.cpp
    resources.qrc
)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS} ${OTHER})

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

