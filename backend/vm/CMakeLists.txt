project(NightLangVM)
set(PRJ_NAME "night_vm")

file(GLOB PRJ_SOURCES
src/test.cpp
)

set(PRJ_DEFINITIONS)

if(WIN32)
    list(APPEND PRJ_DEFINITIONS NIGHT_WIN)
endif()

add_library(${PRJ_NAME} SHARED ${PRJ_SOURCES})

target_include_directories(${PRJ_NAME}
PUBLIC include/
)

target_compile_definitions(${PRJ_NAME}
PUBLIC ${PRJ_DEFINITIONS}
PRIVATE NIGHT_VM_BUILD
)