# 🏫 IIT ISM Dhanbad Campus Shortest Path Finder

This project calculates the **shortest path** between any two locations within the **IIT ISM Dhanbad campus** using **Dijkstra’s Algorithm** combined with the **Haversine formula** for real-world geographical distance calculations.

---

## 📌 Description

A C++-based console application that models the campus as a **graph**, where nodes represent various locations and edges represent paths between them. It calculates the **shortest real-world route** between two points based on geographical coordinates (latitude & longitude).

---

## 🚀 Features

- Calculates shortest path using **Dijkstra’s Algorithm**
- Uses the **Haversine formula** for real distance between latitude-longitude coordinates
- Accurate for real-world use within the IIT ISM Dhanbad campus
- Clear output of total distance and optimal route
- Fully written in **C++**

---

## 📌 Example

### ▶️ Input:
- **Source:** Ruby Hostel  
- **Destination:** NLHC

### 🧭 Shortest Path Computed:Ruby Hostel → 
Ruby Garden →Applied Geophysics Annexure Building →Department of Geophysics →Old Library →Opal Hostel →Diamond Hostel →International EDC →NLHC
**0.765502 km**  
*(Approximately 765.5 meters of walking distance across the campus)*

## ⚙️ How It Works

1. GPS coordinates are stored for each campus location.
2. Connections are defined between nearby locations.
3. The **Haversine formula** calculates real distances between them.
4. **Dijkstra’s Algorithm** computes the shortest total distance path.
5. Output includes the path and total walking distance.
---

## 🧠 Algorithms Used

### ✅ Dijkstra’s Algorithm
Used for finding the shortest path from a source node to all other nodes in a weighted graph.

### ✅ Haversine Formula
Used to calculate the great-circle distance between two points on the Earth’s surface based on latitude and longitude.

---

## 🛠️ Technologies Used

- **Language**: C++
- **Algorithm**: Dijkstra's Algorithm
- **Math**: Haversine Formula
- **Data Input**: Manually entered graph with real coordinates

---
## Campus Graph
<img width="767" alt="Graph" src="https://github.com/user-attachments/assets/50189b6c-e326-4ead-8517-e98456bec20d" />

## Example 
<img width="1408" alt="Example" src="https://github.com/user-attachments/assets/87310687-dbda-4f0b-bf94-88fbbcc1b7ef" />
<img width="1408" alt="Example2" src="https://github.com/user-attachments/assets/b64d75b5-9391-4270-9b72-949e6dfd6c52" />


