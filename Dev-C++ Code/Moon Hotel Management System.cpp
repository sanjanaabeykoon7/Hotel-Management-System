#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <chrono> // Include for std::chrono
#include <thread> // Include for std::this_thread
#include <cstdlib> // For system()

using namespace std;

// Define room structure
struct Room {
    string id;
    string type;
    bool isBooked;
    string guestName;
    double price;
};

// Function prototypes
void displayMenu();
void bookRooms(vector<Room>& rooms);
void viewRooms(const vector<Room>& rooms);
void availableRooms(const vector<Room>& rooms);
void viewBill(const vector<Room>& rooms);
void searchRoomByID(const vector<Room>& rooms);
void checkOut(vector<Room>& rooms);


int main() {
    // Define a map for username and password
    map<string, string> credentials = {{"moon", "hotel"}};
    
    // Define vector to store room information
    vector<Room> rooms = {
        {"101", "Single", false, "", 40.0},
        {"102", "Double", false, "", 60.0},
        {"103", "Twin", false, "", 70.0},
        {"104", "Family", false, "", 140.0},
        {"105", "Standard", false, "", 90.0},
        {"106", "Deluxe", false, "", 130.0}
    };

    std::string username, password;
    cout << ("Welcome to Moon Hotel\n");
    cout << ("Username: ");
    cin >> username;
    cout << ("Password: ");
    cin >> password;

    // Check if username and password are correct
    if (credentials.find(username) != credentials.end() && credentials[username] == password) {
        cout << "Login Successful!" << endl;
        int choice;
        do {
            displayMenu();
            cout << "Enter Your Choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    bookRooms(rooms);
                    break;
                case 2:
                    viewRooms(rooms);
                    break;
                case 3:
                    availableRooms(rooms);
                    break;
                case 4:
                    viewBill(rooms);
                    break;
                case 5:
                    searchRoomByID(rooms);
                    break;
                case 6:
                    checkOut(rooms);
                    break;
                case 7:
                    cout << "Exiting Program." << endl;
                    break;
                default:
                    cout << "Invalid Choice. Please enter a number from 1 to 8." << endl;
                    break;
            }
        } while (choice != 7);
    } else {
        cout << "Invalid Credentials!" << endl;
    }
    return 0;
}

// Function for displaying menu
void displayMenu() {
    cout << "Options:" << endl;
    cout << "1. Book Rooms" << endl;
    cout << "2. View Rooms" << endl;
    cout << "3. Available Rooms" << endl;
    cout << "4. View Bill" << endl;
    cout << "5. Room ID Search" << endl;
    cout << "6. Check-Out" << endl;
    cout << "7. Exit" << endl;
}

// Function to book rooms
void bookRooms(vector<Room>& rooms) {
    cout << "Available Rooms:" << endl;
    for (const auto& room : rooms) {
        if (!room.isBooked) {
            cout << "Room ID: " << room.id << ", Type: " << room.type << ", Price: Rs " << room.price * 250 << endl;
        }
    }
    int numOfRooms;
    cout << "Enter the number of rooms to book: ";
    cin >> numOfRooms;
    vector<string> bookedRooms;
    for (int i = 0; i < numOfRooms; ++i) {
        string bookID;
        cout << "Enter the Room ID to book (" << i + 1 << "): ";
        cin >> bookID;
        bool roomFound = false;
        for (auto& room : rooms) {
            if (room.id == bookID && !room.isBooked) {
                room.isBooked = true;
                cout << "Enter guest name for room " << bookID << ": ";
                cin >> room.guestName;
                bookedRooms.push_back(bookID);
                cout << "Room " << bookID << " has been booked successfully!" << endl;
                roomFound = true;
                break;
            }
        }
        if (!roomFound)
            cout << "Room not available or invalid Room ID!" << endl;
    }
    cout << "Rooms booked: ";
    for (const auto& roomID : bookedRooms) {
        cout << roomID << " ";
    }
    cout << endl;
}

// Function to view rooms
void viewRooms(const vector<Room>& rooms) {
    cout << "Room List:" << endl;
    for (const auto& room : rooms) {
        cout << "Room ID: " << room.id << ", Type: " << room.type << ", Price: Rs " << room.price * 250;
        if (room.isBooked)
            cout << " (Booked) - Guest: " << room.guestName;
        else
            cout << " (Available)";
        cout << endl;
    }
}

// Function to display available rooms
void availableRooms(const vector<Room>& rooms) {
    cout << "Available Rooms:" << endl;
    for (const auto& room : rooms) {
        if (!room.isBooked)
            cout << "Room ID: " << room.id << ", Type: " << room.type << ", Price: Rs " << room.price * 250 << endl;
    }
}

// Function to view bill
void viewBill(const vector<Room>& rooms) {
    double totalBill = 0.0;
    cout << "Bill:" << endl;
    for (const auto& room : rooms) {
        if (room.isBooked) {
            cout << "Room ID: " << room.id << ", Type: " << room.type << ", Price: Rs " << room.price * 250 << " - Guest: " << room.guestName << endl;
            totalBill += room.price;
        }
    }
    cout << "Total Bill: Rs " << totalBill * 250 << endl;
}

// Function to search room by ID
void searchRoomByID(const vector<Room>& rooms) {
    string searchID;
    cout << "Enter Room ID to search: ";
    cin >> searchID;
    bool found = false;
    for (const auto& room : rooms) {
        if (room.id == searchID) {
            cout << "Room found!" << endl;
            cout << "Room ID: " << room.id << ", Type: " << room.type << ", Price: Rs " << room.price * 250 << " - Guest: " << room.guestName;
            if (room.isBooked)
                cout << " (Booked)";
            else
                cout << " (Available)";
            cout << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Room not found!" << endl;
}

// Function to check out
void checkOut(vector<Room>& rooms) {
    string checkOutID;
    cout << "Enter Room ID to check-out: ";
    cin >> checkOutID;
    bool foundCheckOut = false;
    for (auto& room : rooms) {
        if (room.id == checkOutID && room.isBooked) {
            room.isBooked = false;
            room.guestName = "";
            cout << "Room " << checkOutID << " has been checked-out successfully!" << endl;
            foundCheckOut = true;
            break;
        }
    }
    if (!foundCheckOut)
        cout << "Room not booked or invalid Room ID!" << endl;
}
