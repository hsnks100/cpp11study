# 요구 CMake 최소 버전
CMAKE_MINIMUM_REQUIRED ( VERSION 2.8 )
 
# 프로젝트 이름 및 버전
PROJECT ( "chap1" )
SET ( PROJECT_VERSION_MAJOR 0 )
SET ( PROJECT_VERSION_MINOR 1 )
 
# 빌드 형상(Configuration) 및 주절주절 Makefile 생성 여부
SET ( CMAKE_BUILD_TYPE Release )
SET ( CMAKE_VERBOSE_MAKEFILE true ) 

ADD_COMPILE_OPTIONS ( -g -Wall -fno-aggressive-loop-optimizations -Wall -fpermissive -fexceptions)

SET ( CMAKE_EXE_LINKER_FLAGS " ")
 
ADD_EXECUTABLE( chap1 chap1.cpp )
ADD_EXECUTABLE( chap2 chap2.cpp )
ADD_EXECUTABLE( chap2_2 chap2_2.cpp )
ADD_EXECUTABLE( chap3 chap3.cpp )

 
SET ( CMAKE_CXX_FLAGS "-std=c++11 -w")
 
SET ( CMAKE_C_FLAGS_RELEASE "" )
SET ( CMAKE_EXE_LINKER_FLAGS_RELEASE "-DRELEASE -DLINKER_FLAGS " )
 

