set(GMOCK_DIR "../../third-party/gmock-1.7.0"
    CACHE PATH "The path to the GoogleMock test framework.")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # force this option to ON so that Google Test will use /MD instead of /MT
    # /MD is now the default for Visual Studio, so it should be our default, too
    option(gtest_force_shared_crt
           "Use shared (DLL) run-time lib even when Google Test is built as static lib."
           ON)
elseif (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE=1)
endif()
add_subdirectory(${GMOCK_DIR} ${CMAKE_BINARY_DIR}/gmock)
set_property(TARGET gtest APPEND_STRING PROPERTY COMPILE_FLAGS " -w")

set (Test_Dir "${CMAKE_CURRENT_SOURCE_DIR}")
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/parserTest.cpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/parserTest.cpp")

include_directories(SYSTEM ${GMOCK_DIR}/gtest/include
                           ${GMOCK_DIR}/include)


add_executable(ParserTest parserTest.cpp)
target_link_libraries(ParserTest ParserCore
                               gmock_main)

add_test(ParserTest ParserTest)

add_executable(TreeTest treeTest.cpp)
target_link_libraries(TreeTest ParserCore
			       gmock_main)
add_test(TreeTest TreeTest)
