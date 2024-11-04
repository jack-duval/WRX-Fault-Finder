//
// Created by Jack Duval on 11/3/24.
//

#pragma once

#include <vector>

#include "LogParser.h"
#include "LogEntry.h"
#include "FaultEntry.h"

namespace WRXFaultFinder {

/**
 * @brief responsible for finding faults in a collection of LogEntry objects.
 */
class LogAnalyzer {
 public:
  LogAnalyzer() = default;

 protected:
  std::vector<LogEntry> m_log_entries;
  std::vector<FaultEntry> m_fault_entries;
};

} // namespace WRXFaultFinder