#pragma once
#include<string>
#include<exception>
using namespace std;

class InvalidNameException:public exception {
    string message;
public:
    InvalidNameException(const string& message="This field cannot be empty!\n"):message(message){}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidNumber: public exception {
    string message;
public:
    InvalidNumber(const string& message="Enter a positive number\n"):message(message){}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class MyInvalidArgument:public exception {
    string message;
public:
    MyInvalidArgument(const string& message="Enter the required argument\n"):message(message){}
    const char* what() const noexcept override {
        return message.c_str();
    }
};