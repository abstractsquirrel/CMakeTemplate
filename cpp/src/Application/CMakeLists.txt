# Copyright 2019 James McIntosh
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#         http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

include(sources.cmake)

add_executable(Application
    ${SOURCE_LIST}
    )

target_compile_definitions(Application PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<BOOL:$ENV{CLION_IDE}>:CLION>
    )

target_include_directories(Application PRIVATE
    ${CMAKE_SOURCE_DIR}/src/Logger
    ${CMAKE_SOURCE_DIR}/src/Util
    )

target_compile_options(Application PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX /Za>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -Werror>
    )

target_link_options(Application PRIVATE
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-static>
    )

set_target_properties(Application PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/${CMAKE_BUILD_TYPE}
    )

get_filename_component(BIN_DIR_NAME ${CMAKE_BINARY_DIR} NAME)

add_custom_command(TARGET Application
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/out/${BIN_DIR_NAME}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/out ${CMAKE_SOURCE_DIR}/out/${BIN_DIR_NAME}
    )

target_link_libraries(Application Util Logger)
