//
// Created by Jack Duval on 11/3/24.
//

#pragma once

#include <string>
#include <unordered_map>

namespace string_utils {

bool contains(const std::string &str, const std::string &substr);

} // namespace string_utils

namespace collection_utils {

template<typename T>
bool map_all_true(std::unordered_map<T, bool> &m) {
  for (auto &kv_pair : m) {
    if (kv_pair.second == false) { return false; }
  }

  return true;
}

}