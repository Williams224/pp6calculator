cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(pp6calculator)

include(CheckCXXCompilerFlag)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU1Clang")
    check_cxx_compiler_flag(-std=c++11 HAS_GNUSTYLE_CPP11)
    if(HAS_GNUSTYLE_CPP11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")
	endif()
			
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors -Wall -Wextra -Werror -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-nonansi-builtins -fno-gnu-keywords -fstrict-aliasing")
endif()

include_directories(PP6Lib)

add_subdirectory(PP6Lib)

add_executable(Input Input.cpp PP6Lib/Particle.hpp PP6Lib/Particle.cpp PP6Lib/ThreeVector.cpp PP6Lib/ThreeVector.hpp PP6Lib/FourVector.hpp PP6Lib/FourVector.cpp PP6Lib/Week3.hpp PP6Lib/Week3.cpp PP6Lib/FileReader.cpp PP6Lib/FileReader.hpp PP6Lib/Week2.hpp PP6Lib/Week2.cpp PP6Lib/Week1.hpp PP6Lib/Week1.cpp PP6Lib/Math.cpp PP6Lib/Math.hpp)


target_link_libraries(Input pp6lib)

install(TARGETS Input DESTINATION bin)

include(CPack)
