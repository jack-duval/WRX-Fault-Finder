//
// Created by Jack Duval on 11/3/24.
//

#include "Utils.h"

namespace string_utils {

bool contains(const std::string &str, const std::string &substr) {
  return str.find(substr) != std::string::npos;

}

} // namespace string_utils