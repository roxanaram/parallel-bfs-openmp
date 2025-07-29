# ⚙️ Parallel BFS in C++ with OpenMP

![C++](https://img.shields.io/badge/Language-C++-blue?logo=c%2B%2B)
![OpenMP](https://img.shields.io/badge/OpenMP-Multithreading-yellow)
![Status](https://img.shields.io/badge/Status-Finished-brightgreen)

## 📌 Overview
This project implements and benchmarks a parallelized Breadth-First Search (BFS) algorithm using OpenMP in C++. It compares performance against a sequential version on large graphs.

## 🛠 Tech Stack
- C++ (C++11 standard)
- OpenMP for parallelism
- Matplotlib-cpp for plotting

## 🚀 Features
- Generates random undirected graphs
- Performs BFS sequentially and in parallel
- Uses omp_get_wtime() for benchmarking
- Visualizes performance speedup

## 📂 Folder Structure
```
parallel-bfs-openmp/
├── bfs.cpp               # Main C++ code
├── report.pdf            # Detailed project write-up
├── Makefile              # Build automation
├── README.md             # This file
```

## ⚙️ Build & Run
```bash
# Compile with OpenMP
$ make

# Run the compiled executable
$ ./bfs
```

## 📊 Sample Output
- Average runtime (sequential vs parallel)
- Speedup graph
- Analysis of thread scalability

---

# 🧮 Scientific Calculator in Java

![Java](https://img.shields.io/badge/Language-Java-orange?logo=java)
![Swing](https://img.shields.io/badge/GUI-Swing-lightgrey)
![Status](https://img.shields.io/badge/Status-Finished-brightgreen)

## 📌 Overview
A fully functional scientific calculator built with Java and Swing. It supports both basic and advanced math operations with a user-friendly graphical interface.

## 🛠 Tech Stack
- Java SE
- Swing (GUI)
- OOP principles (MVC-inspired structure)

## 🔧 Features
- Basic arithmetic: +, -, ×, ÷
- Scientific: sin, cos, tan, log, ln, √, factorial, e^x
- Memory: M+, MR, MC
- Expression evaluator: parses nested expressions
- History panel for previous results

## 📂 Folder Structure
```
scientific-calculator-java/
├── src/
│   └── Calculator.java   # Main application class
├── README.md             # Project documentation
```

## ▶️ Usage
1. Compile and run from terminal:
```bash
$ javac src/Calculator.java
$ java -cp src Calculator
```

2. Or open in an IDE like IntelliJ / Eclipse and run `Calculator.java`

## 🖼 Sample UI
- Responsive grid layout with 36 buttons
- Real-time error handling and input validation
- Scrollable history view
