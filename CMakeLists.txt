cmake_minimum_required(VERSION 3.10)
project(SimpleHttpServer)

set(CMAKE_CXX_STANDARD 17)

# 실행 파일 설정
add_executable(main src/main.cpp)

# Windows 소켓 라이브러리 추가
if(WIN32)
    target_link_libraries(main ws2_32)
endif()
