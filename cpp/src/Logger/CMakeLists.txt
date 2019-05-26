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

add_Library(Logger SHARED
    ${SOURCE_LIST}
    )

target_compile_definitions(Logger PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<BOOL:$ENV{CLION_IDE}>:CLION>
    LOGGER_DLL
    )

target_include_directories(Logger PRIVATE
    )

target_compile_options(Logger PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX /Za>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -Werror>
    )

target_link_options(Logger PRIVATE
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-static>
    )

set_target_properties(Logger PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/${CMAKE_BUILD_TYPE}
    )

get_filename_component(BIN_DIR_NAME ${CMAKE_BINARY_DIR} NAME)

add_custom_command(TARGET Logger
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/out/${BIN_DIR_NAME}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/out ${CMAKE_SOURCE_DIR}/out/${BIN_DIR_NAME}
    )
