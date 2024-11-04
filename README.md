# WRX Fault Finder

This is an executable that will analyze logs from Cobb Accessports. It will identify knock events, and analyze context related to them. 

The analyzer will make some determintations based on context surrounding knock events, _if_ it's deterministic. 

For example, on FA20 subaru WRXs, it's expected that engine knock may be detected when the AC compressor switches on.

# Project Structure
```
├── CMakeLists.txt
├── LICENSE
├── README.md
├── cmake-build-debug/
├── include/
│   └── WRXFaultFinder
│       ├── FaultEntry.h
│       ├── LogAnalyzer.h
│       ├── LogEntry.h
│       └── LogParser.h
├── main.cpp
├── src/
│   ├── FaultEntry.cpp
│   ├── LogAnalyzer.cpp
│   ├── LogEntry.cpp
│   └── LogParser.cpp
├── test/
│   ├── FaultEntry_test.cpp
│   ├── LogAnalyzer_test.cpp
│   ├── LogParser_test.cpp
│   └── data/
│       ├── datalog1.csv
│       ├── datalog2.csv
│       ├── datalog3.csv
│       ├── datalog4.csv
│       └── datalog5.csv
├── third_party/
│   └── googletest/
└── utils/
    ├── Utils.cpp
    └── Utils.h
```
