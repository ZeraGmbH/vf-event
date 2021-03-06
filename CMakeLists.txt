cmake_minimum_required(VERSION 3.1)

#set project name and language
project(vf-event LANGUAGES CXX)

#Automoc and RCC ON. Needed in QT projects
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#C++ 11 Flag
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Set project Version
set(VfEvent_VERSION_MAJOR "0")
set(VfEvent_VERSION_MINOR "0")
set(VfEvent_VERSION_PATCH "1")

set(PROJECT_VERSION "${VfEvent_VERSION_MAJOR}.${VfEvent_VERSION_MINOR}.${VfEvent_VERSION_PATCH}")

#Adding cmake functions like feature_summary()
include(FeatureSummary)
include(GNUInstallDirs)

#Find dependecies
find_package(Qt5 COMPONENTS Core CONFIG REQUIRED)
find_package(VfHelpers REQUIRED)


#sum up project Files 
file(GLOB SOURCES 
    ${PROJECT_SOURCE_DIR}/*.cpp
    )

file(GLOB HEADER
    ${PROJECT_SOURCE_DIR}/*.h
    )

file(GLOB RESOURCES 
    ${PROJECT_SOURCE_DIR}/*.qrc
    )

#create library 
add_library(VfEvent SHARED
    ${SOURCES}
    ${HEADER}
    ${RESOURCES}
    )


#link dependencies
target_link_libraries(VfEvent 
    PRIVATE
    Qt5::Core
    VeinMeta::VfHelpers
    )

#set target Version
set_target_properties(VfEvent PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(VfEvent PROPERTIES SOVERSION ${VfEvent_VERSION_MAJOR})

#generate export header
include(GenerateExportHeader)
generate_export_header(VfEvent)



#install export header
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/vfevent_export.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/VfEvent
    )

# announce headers - target perspective
target_include_directories(VfEvent
    PUBLIC
    $<INSTALL_INTERFACE:include/VfEvent>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

# install library
install(TARGETS VfEvent
    EXPORT VfEventExport
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

# configure *ConfigVersion.cmake
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    VfEventConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY SameMinorVersion
    )

# configure *Config.cmake
configure_file(VfEventConfig.cmake.in VfEventConfig.cmake @ONLY)

# install *Config(Version).cmake
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/VfEventConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/VfEventConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/VfEvent
    )

# install targets cmake-files
install(EXPORT VfEventExport
    FILE VfEventTargets.cmake
    NAMESPACE VeinMeta::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/VfEvent
    )

# install public headers
install(
    FILES ${HEADER}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/VfEvent
    )

# spawn out some info on configuration
feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)



