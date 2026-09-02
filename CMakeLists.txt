cmake_minimum_required(VERSION 3.15)

project(PankeyEngine_Utility_Log)

if(NOT TARGET ThePankeyEngine_Utility_Log)

    add_library(ThePankeyEngine_Utility_Log INTERFACE)

    target_include_directories(
        ThePankeyEngine_Utility_Log
          INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}
    )

endif()