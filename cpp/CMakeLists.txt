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

cmake_minimum_required(VERSION 3.14)

project(CMakeTemplate)

set_directory_properties(PROPERTIES
    VS_STARTUP_PROJECT Application
    )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE off)
set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_subdirectory(src/Application)
add_subdirectory(src/Util)
add_subdirectory(src/Logger)
