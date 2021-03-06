/*
Copyright 2017 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS-IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "lullaby/util/file.h"

namespace lull {

bool EndsWith(const std::string& filename, const std::string& suffix) {
  return filename.size() >= suffix.size() &&
         filename.compare(
             filename.size() - suffix.size(), suffix.size(), suffix) == 0;
}

const std::string GetBasenameFromFilename(const std::string& filename) {
  std::string::size_type index = filename.find_last_of("/\\");
  if (index == std::string::npos) {
    return filename;
  }
  if (index - 1 == filename.length()) {
    return "";
  }
  return filename.substr(index + 1);
}

const std::string GetExtensionFromFilename(const std::string& filename) {
  std::string::size_type index = filename.rfind('.');
  if (index == std::string::npos) {
    return "";
  }
  return filename.substr(index);
}

}  // namespace lull
