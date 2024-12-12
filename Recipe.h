#include <iostream>
#include <string>
#include <vector>
#include "Time.h"
#include "User.h"

using namespace std;

//Abstract class
class Recipe
{
    friend bool operator==(const Recipe&, const Recipe&);
protected:
    string name;
    vector<pair<string, string> > ingredients;
    string instructions;
    Time prep_time;
   
    int ratingCount;
    string addedBy;

public:
    int likes;
    double ratings;
    void addRatings(double);
    void addIngredients(const string &, const string &);
    void removeIngredients(const string &);
    void increaseLikes();
    string getRecipeName() const;
    string getAddedBy() const;
    virtual void display() const = 0;  //pure virtual function
    virtual ~Recipe()
    {
        cout << "Recipe destructor called." << endl;
    }
};

// Derived Class: NorthIndianRecipe(Abstract class)
class NorthIndianRecipe : public Recipe
{

public:
    NorthIndianRecipe(string name, vector<pair<string, string> > ingredients, string instructions, int likes, double ratings, User user, int hour, int minutes, int seconds);

    virtual void display() const = 0;
};

// Derived Class: SouthIndianRecipe(Abstract class)
class SouthIndianRecipe : public Recipe
{

public:
    SouthIndianRecipe(string name, vector<pair<string, string> > ingredients, string instructions, int likes, double ratings, User user, int hour, int minutes, int seconds);

    virtual void display() const = 0;
};

//concrete classes
class NorthIndianSnacks : public NorthIndianRecipe
{
    friend ostream &operator<<(ostream &out, const NorthIndianSnacks &snack);

private:
    string origin;
    string prep_type;
    int spice_level;
    string beverage_pairing;

public:
    NorthIndianSnacks(string name, vector<pair<string, string> > ingredients, string instructions,
                      int likes, double ratings, User user, int hour, int minutes, int seconds,
                      string origin, string prep_type, int spice_level, string beverage_pairing);
    void display() const;
};

class SouthIndianSnacks : public SouthIndianRecipe
{
    friend ostream &operator<<(ostream &out, const SouthIndianSnacks &snack);

private:
    string origin;
    string prep_type;
    int crisp_level;
    string chutney_type;

public:
    SouthIndianSnacks(string name, vector<pair<string, string> > ingredients, string instructions,
                      int likes, double ratings, User user, int hour, int minutes, int seconds,
                      string origin, string prep_type, int crisp_level, string chutney_type);
    void display() const;
};

class NorthIndianDesserts : public NorthIndianRecipe
{
    friend ostream &operator<<(ostream &out, const NorthIndianDesserts &snack);

private:
    string origin;
    int sweet_level;
    int fresh_span;
    vector<string> dryFruits;

public:
    NorthIndianDesserts(string name, vector<pair<string, string> > ingredients, string instructions,
                        int likes, double ratings, User user, int hour, int minutes, int seconds,
                        string origin, int sweet_level, int fresh_span, vector<string> dryFruits);
    void display() const;
};

class SouthIndianDesserts : public SouthIndianRecipe
{
    friend ostream &operator<<(ostream &out, const SouthIndianDesserts &snack);

private:
    string origin;
    int fresh_span;
    string texture_type;

public:
    SouthIndianDesserts(string name, vector<pair<string, string> > ingredients, string instructions,
                        int likes, double ratings, User user, int hour, int minutes, int seconds,
                        string origin, int fresh_span, string texture_type);
    void display() const;
};

class NorthIndianMainCourse : public NorthIndianRecipe
{
    friend ostream &operator<<(ostream &out, const NorthIndianMainCourse &snack);

private:
    string oil_content;
    int ghee_level;
    string origin;

public:
    NorthIndianMainCourse(string name, vector<pair<string, string> > ingredients, string instructions,
                          int likes, double ratings, User user, int hour, int minutes, int seconds,
                          string oil_content, int ghee_level, string origin);
    void display() const;
};

class SouthIndianMainCourse : public SouthIndianRecipe
{
    friend ostream &operator<<(ostream &out, const SouthIndianMainCourse &snack);

private:
    string origin;
    bool isCoconutUsed;
    int ghee_level;

public:
    SouthIndianMainCourse(string name, vector<pair<string, string> > ingredients, string instructions,
                          int likes, double ratings, User user, int hour, int minutes, int seconds,
                          string origin, bool isCoconutUsed, int ghee_level);
    void display() const;
};

//array of abstract base class pointers
extern vector<Recipe *> recipes;