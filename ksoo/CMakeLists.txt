# 요구 CMake 최소 버전
CMAKE_MINIMUM_REQUIRED ( VERSION 2.8 )
 
# 프로젝트 이름 및 버전
PROJECT ( "chap1" )
SET ( PROJECT_VERSION_MAJOR 0 )
SET ( PROJECT_VERSION_MINOR 1 )
 
# 빌드 형상(Configuration) 및 주절주절 Makefile 생성 여부
SET ( CMAKE_BUILD_TYPE Release )
SET ( CMAKE_VERBOSE_MAKEFILE true ) 
SET ( CMAKE_CXX_FLAGS "-std=c++11 -w")
 
SET ( CMAKE_C_FLAGS_RELEASE "" )
SET ( CMAKE_EXE_LINKER_FLAGS_RELEASE "-DRELEASE -DLINKER_FLAGS " )
 


ADD_COMPILE_OPTIONS ( -g -Wall -fno-aggressive-loop-optimizations -Wall -fpermissive -fexceptions)

SET ( CMAKE_EXE_LINKER_FLAGS " ")
 
#ADD_EXECUTABLE( chap1 chap1.cpp )
#ADD_EXECUTABLE( chap2 chap2.cpp )
#ADD_EXECUTABLE( chap2_2 chap2_2.cpp )
#ADD_EXECUTABLE( chap3 chap3.cpp )
#ADD_EXECUTABLE( chrono chrono.cpp )
#ADD_EXECUTABLE( thread thread.cpp )
#ADD_EXECUTABLE( mutex mutex.cpp )
#ADD_EXECUTABLE( atomic1 atomic_01.cpp )
#ADD_EXECUTABLE( atomic2 atomic_02.cpp )
#ADD_EXECUTABLE( atomic3 atomic_03.cpp )
#ADD_EXECUTABLE( atomic4 atomic_04.cpp )
ADD_EXECUTABLE( async1 async_future_01.cpp )
ADD_EXECUTABLE( promise1 promise_01.cpp )
ADD_EXECUTABLE( pack packaged_task_01.cpp )
ADD_EXECUTABLE( future-test future-test.cpp )
#ADD_EXECUTABLE( atomic5 atomic_05.cpp )

#target_link_libraries(thread pthread)
#target_link_libraries(mutex pthread)
target_link_libraries(async1 pthread)
target_link_libraries(promise1 pthread)
target_link_libraries(pack pthread)
target_link_libraries(future-test pthread)

 
