#include<string>
#include<iostream>
using namespace std;

// Custom Signup exception handler
class SignUpException {
private:
    string message;

public:
    // Constructor to initialize the error message
    SignUpException(const string &msg) : message(msg) {}

    // Method to retrieve the error message
    const char *what() const 
    {
        return message.c_str();
    }
};

//login exception handler
class LoginException {
private:
    string message;

public:
    // Constructor to initialize error message
    LoginException(const string &msg) : message(msg) {}

    // Method to retrieve the error message
    const char *what() const {
        return message.c_str();
    }
};