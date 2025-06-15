# Recipe App

A comprehensive C++ application for managing and exploring various Indian recipes with user authentication features.

## Overview

This Recipe App is an object-oriented application designed to store, categorize, and manage various types of Indian recipes. Users can sign up, log in, add their own recipes, view existing recipes, and perform various operations like searching and filtering recipes.

## Features

- **User Authentication System**
  - Sign up with username and password
  - Login validation
  - Exception handling for login/signup errors

- **Recipe Management**
  - Add new recipes with detailed information:
    - Recipe name
    - Ingredients and quantities
    - Cooking instructions
    - Preparation time
    - Additional attributes based on recipe type
  - Display all recipes
  - Search for specific recipes
  - Compare common ingredients between recipes
  - Sort or filter recipes based on likes/ratings
  - Get a random "Recipe of the Day"

- **Recipe Categories**
  - **North Indian Cuisine**
    - Snacks (with origin, preparation type, spice level, beverage pairing)
    - Desserts (with origin, sweetness level, freshness span, dry fruits)
    - Main Course (with oil content, ghee level, origin)
  
  - **South Indian Cuisine**
    - Snacks (with origin, preparation type, crispness level, chutney type)
    - Desserts (with origin, freshness span, texture type)
    - Main Course (with origin, coconut usage, ghee level)

## Object-Oriented Design

The project demonstrates advanced OOP concepts:

- **Inheritance**: Hierarchy of recipe types
- **Abstraction**: Abstract base class (Recipe) with derived specialized classes
- **Polymorphism**: Using virtual functions for displaying recipes
- **Encapsulation**: Private member variables with accessor methods
- **Operator Overloading**: Customized operators for comparing recipes and I/O operations
- **Templates**: Generic sorting algorithm for recipes
- **Exception Handling**: Custom exceptions for user authentication

## Class Structure

- **Recipe (Abstract Base Class)**
  - North Indian Recipe → North Indian Snacks, Desserts, Main Course
  - South Indian Recipe → South Indian Snacks, Desserts, Main Course

- **User Class**: For user account management

- **Time Class**: For managing recipe preparation time

- **Custom Exceptions**:
  - SignUpException
  - LoginException

## Getting Started

### Prerequisites

- C++ compiler with C++11 support
- Standard Library support

### Compilation

```bash
g++ -o recipe_app test.cpp utility.cpp defs.cpp -std=c++11
```

### Running the Application

```bash
./recipe_app
```

## Usage Examples

1. Sign up or log in to access the application
2. From the main menu, choose an option:
   - Add a new recipe
   - View all recipes
   - Search for a specific recipe
   - Compare ingredients between recipes
   - Sort recipes by popularity or rating
   - Get a recommended recipe of the day

## File Structure

- **Recipe.h**: Contains the class hierarchy for recipes
- **User.h**: User class definition
- **Time.h**: Time management class
- **exception.h**: Custom exception classes
- **utility.cpp**: Implementation of various utility functions
- **defs.cpp**: Implementation of class methods
- **test.cpp**: Main program entry point
- **user.txt**: Storage for user credentials

## Contributing

Feel free to fork this repository and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is for educational purposes. Free to use and modify.

## Acknowledgments

- Developed as part of an Object-Oriented Programming course
- Contributor: Gyan Chandra

