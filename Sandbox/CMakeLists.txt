project(sandbox)

add_executable("${PROJECT_NAME}" main.cpp)

target_link_libraries("${PROJECT_NAME}" engine)
target_include_directories("${PROJECT_NAME}" PUBLIC  ../Engine/include)