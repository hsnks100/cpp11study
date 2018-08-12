# 요구 CMake 최소 버전
CMAKE_MINIMUM_REQUIRED ( VERSION 2.8 )
 
# 프로젝트 이름 및 버전
PROJECT ( "chap1" )
SET ( PROJECT_VERSION_MAJOR 0 )
SET ( PROJECT_VERSION_MINOR 1 )
 
# 빌드 형상(Configuration) 및 주절주절 Makefile 생성 여부
SET ( CMAKE_BUILD_TYPE Release )
SET ( CMAKE_VERBOSE_MAKEFILE true )
 
# 빌드 대상 바이너리 파일명 및 소스 파일 목록
SET ( OUTPUT_ELF
        "${CMAKE_PROJECT_NAME}.out"
        )
SET ( SRC_FILES 
    chap1.cpp
    )



ADD_COMPILE_OPTIONS ( -g -Wall -fno-aggressive-loop-optimizations -Wall -fpermissive -fexceptions)

SET ( CMAKE_EXE_LINKER_FLAGS " ")
 
ADD_EXECUTABLE( ${OUTPUT_ELF} ${SRC_FILES} )

 
SET ( CMAKE_CXX_FLAGS "-std=c++11 -w")
 
SET ( CMAKE_C_FLAGS_RELEASE "" )
SET ( CMAKE_EXE_LINKER_FLAGS_RELEASE "-DRELEASE -DLINKER_FLAGS " )
 
