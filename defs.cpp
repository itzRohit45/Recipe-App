#include "Recipe.h"

// Recipe Class(definitions)
void Recipe::addRatings(double addedRating)
{
    double newRatingsSum = (ratings * ratingCount + addedRating);
    ratingCount++;
    ratings = newRatingsSum / (double)(ratingCount); // increases ratingCount and increases ratings and calculates average
}

void Recipe::addIngredients(const string &takeIngredient, const string &quantity) // adds ingredients based on user input
{
    ingredients.push_back(make_pair(takeIngredient, quantity));
}

void Recipe::removeIngredients(const string &removeIngredients) // removes ingredients based on user input
{
    for (int i = 0; i < ingredients.size(); i++)
    {
        if (ingredients[i].first == removeIngredients)
        {
            ingredients.erase(ingredients.begin() + i);
            break;
        }
    }
}

void Recipe::increaseLikes() // increase likes
{
    likes++;
}

string Recipe::getRecipeName() const
{
    return name;
}

string Recipe::getAddedBy() const
{
    return addedBy;
}

// Time class(definitions)
Time::Time(int hour, int minutes, int seconds)
{
    if ((hour < 0 || hour > 23) || (minutes < 0 || minutes > 59) || (seconds < 0 || seconds > 59))
    {
        this->hour = 0;
        this->minutes = 30;
        this->seconds = 0;
    }
    else
    {
        this->hour = hour;
        this->minutes = minutes;
        this->seconds = seconds;
    }
}

ostream &operator<<(ostream &out, const Time &t)
{
    out << t.hour << " hours, " << t.minutes << " minutes, " << t.seconds << " seconds";

    return out;
}

// User class(definitions)

User::User(string username, string pass)
{
    this->username = username;
    this->password = pass;
}

string User::getUsername() const
{
    return username;
}

string User::getPass() const
{
    return password;
}

istream &operator>>(istream &in, User &u)
{
    in >> u.username >> u.password;
    return in;
}

void User::setUserToNull()
{
    username = " ";
}

void User::setName(const string &name)
{
    username = name;
}

void User::setPass(const string &pass)
{
    password = pass;
}

ostream &operator<<(ostream &out, const User &u)
{
    out << u.username << " " << u.password;
    return out;
}

// Recipe class (definitions)
//  NorthIndianRecipe(constructor)
NorthIndianRecipe::NorthIndianRecipe(string name, vector<pair<string, string> > ingredients, string instructions, int likes, double ratings, User user, int hour, int minutes, int seconds)
{
    this->name = name;
    this->ingredients = ingredients;
    this->instructions = instructions;
    this->likes = likes;
    this->ratings = ratings;
    this->addedBy = user.getUsername();
    ratingCount = 1;
}

// SouthIndianRecipe(constructor)
SouthIndianRecipe::SouthIndianRecipe(string name, vector<pair<string, string> > ingredients, string instructions, int likes, double ratings, User user, int hour, int minutes, int seconds)
{
    this->name = name;
    this->ingredients = ingredients;
    this->instructions = instructions;
    this->likes = likes;
    this->ratings = ratings;
    this->addedBy = user.getUsername();
    ratingCount = 1;
}

NorthIndianSnacks::NorthIndianSnacks(string name, vector<pair<string, string> > ingredients, string instructions,
                                     int likes, double ratings, User user, int hour, int minutes, int seconds,
                                     string origin, string prep_type, int spice_level, string beverage_pairing)
    : NorthIndianRecipe(name, ingredients, instructions, likes, ratings, user, hour, minutes, seconds)
{
    this->origin = origin;
    this->prep_type = prep_type;
    this->spice_level = spice_level;
    this->beverage_pairing = beverage_pairing;
}

SouthIndianSnacks::SouthIndianSnacks(string name, vector<pair<string, string> > ingredients, string instructions,
                                     int likes, double ratings, User user, int hour, int minutes, int seconds,
                                     string origin, string prep_type, int crisp_level, string chutney_type)
    : SouthIndianRecipe(name, ingredients, instructions, likes, ratings, user, hour, minutes, seconds)
{
    this->origin = origin;
    this->prep_type = prep_type;
    this->crisp_level = crisp_level;
    this->chutney_type = chutney_type;
}

NorthIndianDesserts::NorthIndianDesserts(string name, vector<pair<string, string> > ingredients, string instructions,
                                         int likes, double ratings, User user, int hour, int minutes, int seconds,
                                         string origin, int sweet_level, int fresh_span, vector<string> dryFruits)
    : NorthIndianRecipe(name, ingredients, instructions, likes, ratings, user, hour, minutes, seconds)
{
    this->origin = origin;
    this->sweet_level = sweet_level;
    this->fresh_span = fresh_span;
    this->dryFruits = dryFruits;
}

SouthIndianDesserts::SouthIndianDesserts(string name, vector<pair<string, string> > ingredients, string instructions,
                                         int likes, double ratings, User user, int hour, int minutes, int seconds,
                                         string origin, int fresh_span, string texture_type)
    : SouthIndianRecipe(name, ingredients, instructions, likes, ratings, user, hour, minutes, seconds)
{
    this->origin = origin;
    this->fresh_span = fresh_span;
    this->texture_type = texture_type;
}

NorthIndianMainCourse::NorthIndianMainCourse(string name, vector<pair<string, string> > ingredients, string instructions,
                                             int likes, double ratings, User user, int hour, int minutes, int seconds,
                                             string oil_content, int ghee_level, string origin)
    : NorthIndianRecipe(name, ingredients, instructions, likes, ratings, user, hour, minutes, seconds)
{
    this->oil_content = oil_content;
    this->ghee_level = ghee_level;
    this->origin = origin;
}

SouthIndianMainCourse::SouthIndianMainCourse(string name, vector<pair<string, string> > ingredients, string instructions,
                                             int likes, double ratings, User user, int hour, int minutes, int seconds,
                                             string origin, bool isCoconutUsed, int ghee_level)
    : SouthIndianRecipe(name, ingredients, instructions, likes, ratings, user, hour, minutes, seconds)
{
    this->origin = origin;
    this->isCoconutUsed = isCoconutUsed;
    this->ghee_level = ghee_level;
}

//display function overriden
void NorthIndianSnacks::display() const
{
    cout << "============================" << endl;
    cout << "       Recipe Details       " << endl;
    cout << "============================" << endl;
    cout << "🍲 Recipe Name: " << name << endl;
    cout << "----------------------------" << endl;

    cout << "🥄 Ingredients:" << endl;
    cout << "----------------------------" << endl;
    cout << "Name     |     Quantity" << endl;
    cout << "----------------------------" << endl;
    for (const auto &ingredient : ingredients)
    {
        cout << ingredient.first << "\t\t" << ingredient.second << endl;
    }
    cout << "----------------------------" << endl;

    cout << "📖 Preparation Time:" << endl;
    cout << "----------------------------" << endl;
    cout << prep_time << endl;
    cout << "----------------------------" << endl;

    cout << "📖 Cooking Instructions:" << endl;
    cout << "----------------------------" << endl;
    cout << instructions << endl;
    cout << "----------------------------" << endl;

    cout << "👍 Likes: " << likes << endl;
    cout << "----------------------------" << endl;
    cout << "⭐ Average Rating: " << ratings << endl;
    cout << "----------------------------" << endl;
    cout << "👤 Added By: " << addedBy << endl;
    cout << "----------------------------" << endl;

    cout << "🌍 Origin: " << origin << endl;
    cout << "----------------------------" << endl;
    cout << "🍴 Preparation Type: " << prep_type << endl;
    cout << "----------------------------" << endl;
    cout << "🌶️ Spice Level: " << spice_level << endl;
    cout << "----------------------------" << endl;
    cout << "🥤 Beverage Pairing: " << beverage_pairing << endl;
    cout << "============================" << endl;
}


void SouthIndianSnacks::display() const
{
    cout << "============================" << endl;
    cout << "       Recipe Details       " << endl;
    cout << "============================" << endl;
    cout << "🍲 Recipe Name: " << name << endl;
    cout << "----------------------------" << endl;

    cout << "🥄 Ingredients:" << endl;
    cout << "----------------------------" << endl;
    cout << "Name     |     Quantity" << endl;
    cout << "----------------------------" << endl;
    for (const auto &ingredient : ingredients)
    {
        cout << ingredient.first << "\t\t" << ingredient.second << endl;
    }
    cout << "----------------------------" << endl;

    cout << "📖 Preparation Time:" << endl;
    cout << "----------------------------" << endl;
    cout << prep_time << endl;
    cout << "----------------------------" << endl;

    cout << "📖 Cooking Instructions:" << endl;
    cout << "----------------------------" << endl;
    cout << instructions << endl;
    cout << "----------------------------" << endl;

    cout << "👍 Likes: " << likes << endl;
    cout << "----------------------------" << endl;
    cout << "⭐ Average Rating: " << ratings << endl;
    cout << "----------------------------" << endl;
    cout << "👤 Added By: " << addedBy << endl;
    cout << "----------------------------" << endl;

    cout << "🌍 Origin: " << origin << endl;
    cout << "----------------------------" << endl;
    cout << "🍴 Preparation Type: " << prep_type << endl;
    cout << "----------------------------" << endl;
    cout << "🍪 Crisp Level: " << crisp_level << endl;
    cout << "----------------------------" << endl;
    cout << "🥣 Chutney Type: " << chutney_type << endl;
    cout << "============================" << endl;
}


void NorthIndianDesserts::display() const
{
    cout << "============================" << endl;
    cout << "       Recipe Details       " << endl;
    cout << "============================" << endl;
    cout << "🍮 Dessert Name: " << name << endl;
    cout << "----------------------------" << endl;

    cout << "🥄 Ingredients:" << endl;
    cout << "----------------------------" << endl;
    cout << "Name     |     Quantity" << endl;
    cout << "----------------------------" << endl;
    for (const auto &ingredient : ingredients)
    {
        cout << ingredient.first << "\t\t" << ingredient.second << endl;
    }
    cout << "----------------------------" << endl;

    cout << "📖 Preparation Time:" << endl;
    cout << "----------------------------" << endl;
    cout << prep_time << endl;
    cout << "----------------------------" << endl;

    cout << "📖 Cooking Instructions:" << endl;
    cout << "----------------------------" << endl;
    cout << instructions << endl;
    cout << "----------------------------" << endl;

    cout << "👍 Likes: " << likes << endl;
    cout << "----------------------------" << endl;
    cout << "⭐ Average Rating: " << ratings << endl;
    cout << "----------------------------" << endl;
    cout << "👤 Added By: " << addedBy << endl;
    cout << "----------------------------" << endl;

    cout << "🌍 Origin: " << origin << endl;
    cout << "----------------------------" << endl;
    cout << "🍬 Sweet Level: " << sweet_level << endl;
    cout << "----------------------------" << endl;
    cout << "📅 Freshness Span: " << fresh_span << " days" << endl;
    cout << "----------------------------" << endl;
    cout << "🌰 Dry Fruits: ";
    for (const auto &fruit : dryFruits)
    {
        cout << fruit << " ";
    }
    cout << endl;
    cout << "============================" << endl;
}


void SouthIndianDesserts::display() const
{
    cout << "============================" << endl;
    cout << "       Recipe Details       " << endl;
    cout << "============================" << endl;
    cout << "🍨 Dessert Name: " << name << endl;
    cout << "----------------------------" << endl;

    cout << "🥄 Ingredients:" << endl;
    cout << "----------------------------" << endl;
    for (const auto &ingredient : ingredients)
    {
        cout << ingredient.first << "\t\t" << ingredient.second << endl;
    }
    cout << "----------------------------" << endl;

    cout << "📖 Preparation Time:" << endl;
    cout << prep_time << endl;

    cout << "📖 Cooking Instructions:" << endl;
    cout << instructions << endl;

    cout << "👍 Likes: " << likes << endl;
    cout << "⭐ Average Rating: " << ratings << endl;

    cout << "👤 Added By: " << addedBy << endl;

    cout << "🌍 Origin: " << origin << endl;
    cout << "📅 Freshness Span: " << fresh_span << " days" << endl;
    cout << "🌟 Texture Type: " << texture_type << endl;
    cout << "============================" << endl;
}

void NorthIndianMainCourse::display() const
{
    cout << "============================" << endl;
    cout << "       Recipe Details       " << endl;
    cout << "============================" << endl;
    cout << "🍛 Main Course Name: " << name << endl;
    cout << "----------------------------" << endl;

    cout << "🥄 Ingredients:" << endl;
    for (const auto &ingredient : ingredients)
    {
        cout << ingredient.first << "\t\t" << ingredient.second << endl;
    }

    cout << "📖 Preparation Time:" << endl;
    cout << prep_time << endl;

    cout << "📖 Cooking Instructions:" << endl;
    cout << instructions << endl;

    cout << "👍 Likes: " << likes << endl;
    cout << "⭐ Average Rating: " << ratings << endl;

    cout << "🛢️ Oil Content: " << oil_content << endl;
    cout << "🧈 Ghee Level: " << ghee_level << endl;
    cout << "🌍 Origin: " << origin << endl;
    cout << "============================" << endl;
}

void SouthIndianMainCourse::display() const
{
    cout << "============================" << endl;
    cout << "       Recipe Details       " << endl;
    cout << "============================" << endl;
    cout << "🍚 Main Course Name: " << name << endl;
    cout << "----------------------------" << endl;

    cout << "🥄 Ingredients:" << endl;
    for (const auto &ingredient : ingredients)
    {
        cout << ingredient.first << "\t\t" << ingredient.second << endl;
    }

    cout << "📖 Preparation Time:" << endl;
    cout << prep_time << endl;

    cout << "📖 Cooking Instructions:" << endl;
    cout << instructions << endl;

    cout << "👍 Likes: " << likes << endl;
    cout << "⭐ Average Rating: " << ratings << endl;

    cout << "🌴 Coconut Used: " << (isCoconutUsed ? "Yes" : "No") << endl;
    cout << "🧈 Ghee Level: " << ghee_level << endl;
    cout << "🌍 Origin: " << origin << endl;
    cout << "============================" << endl;
}

//common ingreduents check(== operator overload)
bool operator==(const Recipe& recipe1, const Recipe& recipe2)
{
    cout << "The common Ingredients in the given two recipes are:" << endl;
    bool checkCommon = false;

    for (const auto &ingredient1 : recipe1.ingredients)
    {
        for (const auto &ingredient2 : recipe2.ingredients)
        {
            if (ingredient1.first == ingredient2.first)
            {
                cout << ingredient1.first << endl;
                checkCommon = true;
            }
        }
    }
    if (!checkCommon)
    {
        cout << "No common ingredients found." << endl;
    }
    return checkCommon;
}

ostream& operator<<(ostream& out, const NorthIndianSnacks& s)
{
    out << "Recipe Details:\n";
    out << "Recipe Name: " << s.name << "\n";

    out << "Ingredients:\n";
    for (const auto &ingredient : s.ingredients)
    {
        out << "- " << ingredient.first << ": " << ingredient.second << "\n";
    }

    out << "Preparation Time: " << s.prep_time << " minutes\n";
    out << "Cooking Instructions: " << s.instructions << "\n";
    out << "Likes: " << s.likes << "\n";
    out << "Average Rating: " << s.ratings << "\n";
    out << "Added By: " << s.addedBy << "\n";
    out << "Origin: " << s.origin << "\n";
    out << "Preparation Type: " << s.prep_type << "\n";
    out << "Spice Level: " << s.spice_level << "\n";
    out << "Beverage Pairing: " << s.beverage_pairing << "\n";

    return out;
}

ostream& operator<<(ostream& out, const SouthIndianSnacks& s)
{
    out << "Recipe Details:\n";
    out << "Recipe Name: " << s.name << "\n";

    out << "Ingredients:\n";
    for (const auto &ingredient : s.ingredients)
    {
        out << "- " << ingredient.first << ": " << ingredient.second << "\n";
    }

    out << "Preparation Time: " << s.prep_time << " minutes\n";
    out << "Cooking Instructions: " << s.instructions << "\n";
    out << "Likes: " << s.likes << "\n";
    out << "Average Rating: " << s.ratings << "\n";
    out << "Added By: " << s.addedBy << "\n";
    out << "Origin: " << s.origin << "\n";
    out << "Preparation Type: " << s.prep_type << "\n";
    out << "Crisp Level: " << s.crisp_level << "\n";
    out << "Chutney Type: " << s.chutney_type << "\n";

    return out;
}

ostream& operator<<(ostream& out, const NorthIndianDesserts& d)
{
    out << "Recipe Details:\n";
    out << "Dessert Name: " << d.name << "\n";

    out << "Ingredients:\n";
    for (const auto &ingredient : d.ingredients)
    {
        out << "- " << ingredient.first << ": " << ingredient.second << "\n";
    }

    out << "Preparation Time: " << d.prep_time << " minutes\n";
    out << "Cooking Instructions: " << d.instructions << "\n";
    out << "Likes: " << d.likes << "\n";
    out << "Average Rating: " << d.ratings << "\n";
    out << "Added By: " << d.addedBy << "\n";
    out << "Origin: " << d.origin << "\n";
    out << "Sweet Level: " << d.sweet_level << "\n";
    out << "Freshness Span: " << d.fresh_span << " days\n";
    
    out << "Dry Fruits: ";
    for (const auto &fruit : d.dryFruits)
    {
        out << fruit << " ";
    }
    out << "\n";

    return out;
}

ostream& operator<<(ostream& out, const SouthIndianDesserts& d)
{
    out << "Recipe Details:\n";
    out << "Dessert Name: " << d.name << "\n";

    out << "Ingredients:\n";
    for (const auto &ingredient : d.ingredients)
    {
        out << "- " << ingredient.first << ": " << ingredient.second << "\n";
    }

    out << "Preparation Time: " << d.prep_time << " minutes\n";
    out << "Cooking Instructions: " << d.instructions << "\n";
    out << "Likes: " << d.likes << "\n";
    out << "Average Rating: " << d.ratings << "\n";
    out << "Added By: " << d.addedBy << "\n";
    out << "Origin: " << d.origin << "\n";
    out << "Freshness Span: " << d.fresh_span << " days\n";
    out << "Texture Type: " << d.texture_type << "\n";

    return out;
}

ostream& operator<<(ostream& out, const NorthIndianMainCourse& course)
{
    out << "Recipe Details:\n";
    out << "Main Course Name: " << course.name << "\n";

    out << "Ingredients:\n";
    for (const auto &ingredient : course.ingredients)
    {
        out << "- " << ingredient.first << ": " << ingredient.second << "\n";
    }

    out << "Preparation Time: " << course.prep_time << " minutes\n";
    out << "Cooking Instructions: " << course.instructions << "\n";
    out << "Likes: " << course.likes << "\n";
    out << "Average Rating: " << course.ratings << "\n";
    out << "Oil Content: " << course.oil_content << "\n";
    out << "Ghee Level: " << course.ghee_level << "\n";
    out << "Origin: " << course.origin << "\n";

    return out;
}

ostream& operator<<(ostream& out, const SouthIndianMainCourse& course)
{
    out << "Recipe Details:\n";
    out << "Main Course Name: " << course.name << "\n";

    out << "Ingredients:\n";
    for (const auto &ingredient : course.ingredients)
    {
        out << "- " << ingredient.first << ": " << ingredient.second << "\n";
    }

    out << "Preparation Time: " << course.prep_time << " minutes\n";
    out << "Cooking Instructions: " << course.instructions << "\n";
    out << "Likes: " << course.likes << "\n";
    out << "Average Rating: " << course.ratings << "\n";
    out << "Coconut Used: " << (course.isCoconutUsed ? "Yes" : "No") << "\n";
    out << "Ghee Level: " << course.ghee_level << "\n";
    out << "Origin: " << course.origin << "\n";

    return out;
}
