// Copyright 2019 James McIntosh
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//         http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#ifdef LOGGER_DLL
#define LOGGER_EXPORT __declspec(dllexport)
#else
#define LOGGER_EXPORT __declspec(dllimport)
#endif

#ifdef DEBUG
#define INFO(msg) CMakeTemplate::Logger::info(msg);
#define WARN(msg) CMakeTemplate::Logger::warn(msg);
#define ERR(msg) CMakeTemplate::Logger::err(msg);
#else
#define INFO(msg)
#define WARN(msg)
#define ERR(msg)
#endif

#include <iostream>
#include <string>

namespace CMakeTemplate::Logger {

    // public:
    LOGGER_EXPORT void info(const std::string& msg);

    LOGGER_EXPORT void warn(const std::string& msg);

    LOGGER_EXPORT void err(const std::string& msg);

    LOGGER_EXPORT void log(const std::string& msg = "", const std::string& prefix = "");
}

