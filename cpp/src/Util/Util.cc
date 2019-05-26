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

#include "Util.h"

#include "Logger.h"

namespace CMakeTemplate {
  void Util::libraryFunction() {
    Logger::log();
    Logger::info("Enter Util::libraryFunction()");

    Logger::warn("Release warning");
    Logger::err("Release error");
    INFO("Debug info")
    WARN("Debug warning")
    ERR("Debug error")

    Logger::info("Exit Util::libraryFunction()");
    Logger::log();
  }
}
