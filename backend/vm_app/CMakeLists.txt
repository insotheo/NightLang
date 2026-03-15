project(NightLangApp)
set(PRJ_NAME "night")

file(GLOB PRJ_SOURCES
src/main.cpp
)

add_executable(${PRJ_NAME} ${PRJ_SOURCES})

target_link_libraries(${PRJ_NAME} PRIVATE "night_vm")