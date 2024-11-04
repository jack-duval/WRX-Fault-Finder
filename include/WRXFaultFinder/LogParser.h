//
// Created by Jack Duval on 11/3/24.
//

#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "csv.hpp"
#include "LogEntry.h"
#include "Utils.h"

namespace WRXFaultFinder {

enum class FAILURE_REASON {
  kSuccess = 0,
  kFileNotExist = 1,
  kFileEmpty = 2,
  kNotWRX = 3,
  kMissingFaultCriteria = 4,
  kMissingRelevantData = 5
};

/**
 * @brief overload ostream operator to write correct failure reason.
 *
 * @param os some ostream
 * @param f some failure reason
 */
std::ostream &operator<<(std::ostream &os, const FAILURE_REASON &f);

/**
 * @brief Parse a csv datalog from a Cobb Accessport (AP) and create a
 * collection of LogEntry objects.
 */
class LogParser {
 public:
  /**
   * @brief Constructor that accepts a filename for a log. If the filename is a
   * datalog from a WRX and using an AP, we will store this filename.
   *
   * If it is not a "real log," we will exit. (cerr)
   *
   * @param filename String filename - some filename, that we'll confirm is
   * valid
   */
  explicit LogParser(const std::string &filename);

  /**
   * @brief Determine whether or not this file exists, is an AP log, and has
   * the data we will be analyzing.
   *
   * Return an int that represents success or failure reason. 0 is success.
   * Failure Reasons can be found below.
   *
   * @param filename String filename to a csv
   */
  static WRXFaultFinder::FAILURE_REASON valid_datalog(const std::string &filename);

  /**
   * @brief Return a collection of LogEntry objects in a vector. Right now,
   * this could be large. TODO manage lifecycle of this vector, since it may
   * have timestamps we don't need to worry about...
   */
  static std::vector<LogEntry> parse();

 protected:
  std::string m_filename;

  std::unordered_map<std::string, bool> target_vars{
      {"AC Compressor Sw (on/off)", false},
      {"AF Correction 1 (%)", false},
      {"AF Correction 3 (%)", false},
      {"AF Learning 1 (%)", false},
      {"AF Learning 3 (%)", false},
      {"AF Sens 1 Ratio (AFR)", false},
      {"Accel Position (%)", false},
      {"Boost (psi)", false},
      {"Boost Extended (psi)", false},
      {"Coolant Temp (F)", false},
      {"Dyn Adv Mult (DAM)", false},
      {"Fuel Pressure (psi)", false},
      {"Fuel Pressure Target (psi)", false},
      {"Gear Position (gear)", false},
      {"Ignition Timing (deg)", false},
      {"Inj Duty Cycle (%)", false},
      {"Inj Timing H SOI (deg)", false},
      {"Intake Temp (F)", false},
      {"Intake Temp Manifold (F)", false},
      {"MAF Corr Final (g/s)", false},
      {"MAF Volts (V)", false},
      {"Oil Temp (F)", false},
      {"RPM (RPM)", false},
      {"Throttle Pos (%)", false},
      {"Vehicle Speed (mph)", false}
  };
};
} // namespace WRXFaultFinder
