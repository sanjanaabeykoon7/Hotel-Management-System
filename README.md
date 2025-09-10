# Moon Hotel Management System

## Overview

The Moon Hotel Management System is a console-based application developed in C++ for managing hotel room bookings, checkouts, and billing. It provides a simple interface for hotel staff to handle room reservations, view room availability, generate bills, and perform room searches. The system includes basic authentication and supports various room types with predefined pricing.

This project is designed as a beginner-friendly demonstration of C++ programming concepts, including data structures (vectors and maps), control flow, and modular functions. It was developed using the Dev-C++ IDE.

## Features

- **User Authentication**: Secure login with hardcoded credentials.
- **Room Booking**: Book multiple rooms by ID, assign guest names, and update room status.
- **View All Rooms**: Display a list of all rooms with their status (booked or available), type, price, and guest details if applicable.
- **Available Rooms**: List only unoccupied rooms with details.
- **Bill Generation**: Calculate and display the total bill for booked rooms, including individual room breakdowns.
- **Room Search**: Search for a specific room by ID to view its details.
- **Check-Out**: Release a booked room and clear guest information.
- **Predefined Rooms**: Includes six room types (Single, Double, Twin, Family, Standard, Deluxe) with sample pricing in USD (converted to local currency for display).

## Prerequisites

- C++ compiler (e.g., g++ via MinGW, as used in Dev-C++).
- Dev-C++ IDE (optional, for opening the project file directly).
- No external libraries are required beyond standard C++ headers.

## Installation

1. Clone the repository:
   ```
   git clone https://github.com/sanjanaabeykoon7/Hotel-Management-System.git
   ```
2. Navigate to the project directory:
   ```
   cd Hotel-Management-System/Dev-C++ Code
   ```
3. Compile the source code using g++:
   ```
   g++ "Moon Hotel Management System.cpp" -o "Moon Hotel Management System.exe" -std=gnu++11
   ```
   Alternatively, open `Moon Hotel Management System.dev` in Dev-C++ and build the project.

## Usage

1. Run the executable:
   ```
   "Moon Hotel Management System.exe"
   ```
2. Log in using the default credentials:
   - Username: `moon`
   - Password: `hotel`
3. Select options from the menu:
   - 1: Book Rooms – View available rooms and book by ID.
   - 2: View Rooms – List all rooms.
   - 3: Available Rooms – List unoccupied rooms.
   - 4: View Bill – Display bills for booked rooms.
   - 5: Room ID Search – Search by room ID.
   - 6: Check-Out – Release a room by ID.
   - 7: Exit – Quit the application.

**Note**: Prices are displayed in a local currency (multiplied by 250 for demonstration; actual USD prices are stored in the Room struct).

## Project Structure

- `Makefile.win`: Build configuration for Dev-C++.
- `Moon Hotel Management System.cpp`: Main source code file.
- `Moon Hotel Management System.dev`: Dev-C++ project file.
- `Moon Hotel Management System.layout`: Dev-C++ layout configuration.

## Limitations

- Hardcoded rooms and credentials; no persistent storage (e.g., database or file I/O).
- Basic error handling; assumes valid user inputs.
- No advanced features like date-based reservations or multi-user support.
---
