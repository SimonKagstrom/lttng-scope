cmake_minimum_required (VERSION 2.6)


# ====================================
# project name and version
# ====================================
project (lttng-scope)
set (PROJECT_VERSION_MAJOR  1)
set (PROJECT_VERSION_MINOR  0)
set (PROJECT_VERSION_PATCH  0)
set (PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")


# WX package
find_package(wxWidgets COMPONENTS core base REQUIRED)
 
 
# wxWidgets include (this will do all the magic to configure everything)
include( ${wxWidgets_USE_FILE} )

set (lttng-scope_SRCS
    src/main.cpp)

include_directories (${GLIB2_INCLUDE_DIRS})
include_directories (src/include/)
include_directories (/usr/include/wx-2.8/)

add_executable (${PROJECT_NAME} ${lttng-scope_SRCS})


target_link_libraries(lttng-scope ${wxWidgets_LIBRARIES})
