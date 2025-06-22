# SimplePerformanceMonitor


Simple C++ project to monitor server metrics like CPU usage and request rate using a sliding window average.  
Alerts are triggered when the average exceeds a defined threshold.

## project idea;
- Monitors metrics like `RequestRate` and `CPUUsage`
- Tracks averages over a fixed window
- Alerts when a metric is overloaded
- Reads data from a CSV file (`data.csv`)
- Computes the **moving average** over a fixed-size time window
- Triggers an alert when a metric exceeds its defined threshold


├── interface/             
│   ├── SlidingWindow.h
│   ├── ServerMetric.h
│   ├── AlertManager.h
│   └── ServerMonitor.h
│
├── src/                   
│   ├── SlidingWindow.cpp
│   ├── ServerMetric.cpp
│   ├── AlertManager.cpp
│   └── ServerMonitor.cpp
│
├── main.cpp               
├── data.csv             
├── CMakeLists.txt        
└── README.md             

