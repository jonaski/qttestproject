set(SOURCES mainwindow.cpp logging.cpp iconloader.cpp aboutdialog.cpp)
set(HEADERS mainwindow.h logging.h aboutdialog.h)
set(UI mainwindow.ui aboutdialog.ui)
set(RESOURCES ../data/data.qrc ../data/icons.qrc)

qt6_wrap_cpp(MOC ${HEADERS})
qt6_wrap_ui(UIC ${UI})
qt6_add_resources(QRC ${RESOURCES})

add_library(qttestproject_lib STATIC ${SOURCES} ${MOC} ${UIC} ${QRC})

target_include_directories(qttestproject_lib PRIVATE
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(qttestproject_lib SYSTEM PRIVATE
  ${GLIB_INCLUDE_DIRS}
)

target_link_directories(qttestproject_lib PRIVATE
  ${GLIB_LIBRARY_DIRS}
)

target_link_libraries(qttestproject_lib PRIVATE
  ${GLIB_LIBRARIES}
  ${QT_LIBRARIES}
)

set(EXECUTABLE_OUTPUT_PATH ..)
set(QTTESTPROJECT-WIN32-FLAG WIN32)

add_executable(qttestproject ${QTTESTPROJECT-WIN32-FLAG} ${QTTESTPROJECT-WIN32-RESOURCES} main.cpp)
target_link_libraries(qttestproject PRIVATE qttestproject_lib Qt6::Core Qt6::Gui Qt6::Widgets)
