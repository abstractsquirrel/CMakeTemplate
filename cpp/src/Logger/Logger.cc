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

#include "Logger.h"

#include <iostream>

namespace CMakeTemplate::Logger {

  static const std::string kInfoPrefix{"[ INFO ] "};
  static const std::string kWarnPrefix{"[ WARN ] "};
  static const std::string kErrorPrefix{"[ ERROR ] "};

  LOGGER_EXPORT void info(const std::string& msg) {
    log(msg, kInfoPrefix);
  }

  LOGGER_EXPORT void warn(const std::string& msg) {
    log(msg, kWarnPrefix);
  }

  LOGGER_EXPORT void err(const std::string& msg) {
    log(msg, kErrorPrefix);
  }

  LOGGER_EXPORT void log(const std::string& msg, const std::string& prefix) {
    std::cout << prefix << msg << std::endl;
  }
}

