//
// Created by Jack Duval on 11/3/24.
//

#include "LogParser.h"
namespace WRXFaultFinder {

std::ostream &operator<<(std::ostream &os, const FAILURE_REASON &f) {
  switch (f) {
    case FAILURE_REASON::kSuccess:os << "This is a valid datalog." << std::endl;
      return os;

    case FAILURE_REASON::kFileNotExist:
      os << "File not found. Please verify the path." << std::endl;
      return os;

    case FAILURE_REASON::kFileEmpty:
      os << "The file is empty. Please try with a non-empty file." << std::endl;
      return os;

    case FAILURE_REASON::kNotWRX:
      os << "This is not an AP log from a Subaru WRX" << std::endl;
      return os;

    case FAILURE_REASON::kMissingFaultCriteria:
      os << "This is an AP log from a WRX, but is missing data about knock."
         << std::endl;
      return os;

    case FAILURE_REASON::kMissingRelevantData:
      os
          << "This is an AP log from a WRX, but is missing data used to understand"
          << " context surrounding the fault." << std::endl;
      return os;

    default:os << "Unknown failure reason." << std::endl;

  }
}

LogParser::LogParser(const std::string &filename) {
  FAILURE_REASON is_valid_datalog = valid_datalog(filename);
  if (is_valid_datalog != FAILURE_REASON::kSuccess) {
    std::cerr << "This is not a valid log. Reason: " << is_valid_datalog
              << std::endl;
    return;
  }

  m_filename = filename;
}

FAILURE_REASON LogParser::valid_datalog(const std::string &filename) {
  /*
   * A log is valid (kSuccess) if the following is true:
   * - The file exists and can be loaded with csv::CSVReader (kFileNotExist)
   * - The file is not empty (kFileEmpty)
   * - The file is from a WRX (using last column) (kNotWRX)
   * - The file contains a column for knock variables (kMissingFaultCriteria)
   * - The file contains data we want to use for context (rpm, gear, boost, time)
   *   (kMissingRelevantData)
   */

  // Check if the file exists
  std::ifstream f(filename.c_str());
  if (!f.good()) { return FAILURE_REASON::kFileNotExist; }

  // Define some format basics for the csv
  // some units are weird on these (namely, degree symbols).

  // Maybe use the parse function to strip the units and write UTF-8 acceptable
  // ones?

//  csv::CSVFormat format;
//  format.delimiter(',');
//  format.header_row(0);
//
//  // instantiate a reader, r
//  csv::CSVReader r(filename, format);
//
//  // check if the file is empty
//  if (r.empty()) { return FAILURE_REASON::kFileEmpty; }
//
//
//  // Ensure we have the right columns in the log
//  std::vector<std::string> cols = r.get_col_names();
//  int l = cols.size();
//
//  if (!string_utils::contains(cols[l-1], "WRX")) {
//    return FAILURE_REASON::kNotWRX;
//  }

  // Check we have columns for Knock
  /*
   * Variables for knock:
   * "Feedback Knock (°)"
   * "Fine Knock Learn (°)"
   * We could probably enforce columns length, and just check indexed columns
   * to make sure the column names match some expected ones. However, in case
   * there is variation depending on which generation WRX someone has, I'm
   * wary of that.
   */

//  bool fbk_col_present = false;
//  bool fkl_col_present = false;
//
//  for (auto& name : cols) {
//    if (string_utils::contains(name, "Feedback Knock")) {
//      fbk_col_present = true;
//      continue;
//    }
//
//    if (string_utils::contains(name, "Fine Knock")) {
//      fkl_col_present = true;
//      continue;
//    }
//
//    if (fbk_col_present && fkl_col_present) {
//      break;
//    }
//  }
//
//  if (!fbk_col_present || !fkl_col_present) {
//    return FAILURE_REASON::kMissingFaultCriteria;
//  }

  // check for variables we want for context:
  // TODO maybe just do in one pass with the above check?
  // Going to throw these in a map <string, bool>, "find" them,
  // then AND the values of the map TODO something better?
  /*
   * Time (sec)
   * AC Compressor Sw (on/off)
   * AF Correction 1 (%)
   * AF Correction 3 (%)
   * AF Learning 1 (%)
   * AF Learning 3 (%)
   * AF Sens 1 Ratio (AFR)
   * Accel Position (%)
   * Boost (psi)
   * Boost Extended (psi)
   * Coolant Temp (F)
   * Dyn Adv Mult (DAM)
   * Fuel Pressure (psi)
   * Fuel Pressure Target (psi)
   * Gear Position (gear)
   * Ignition Timing (°)
   * Inj Duty Cycle (%)
   * Inj Timing H SOI (°)
   * Intake Temp (F)
   * Intake Temp Manifold (F)
   * MAF Corr Final (g/s)
   * MAF Volts (V)
   * Oil Temp (F)
   * RPM (RPM)
   * Throttle Pos (%)
   * Vehicle Speed (mph)
   */
//  for (auto& col_name : cols) {
//    if (target_vars.find(col_name) != target_vars.end()) {
//      target_vars[col_name] = true;
//    }
//  }
//
//  bool target_vars_present = collection_utils::map_all_true(target_vars);
//


  // Just return success for now
  return FAILURE_REASON::kSuccess;
}

std::vector<LogEntry> LogParser::parse() {
  /*
   * Use csv::CSVReader to save header rows, as well as individual rows as LogEntry
   * objects
   */
  return {};
}

} // namespace WRXFaultFinder
