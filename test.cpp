#include "Recipe.h"

vector<Recipe *> recipes;

int main()
{
    User myUser("gyan", "12233");

    vector<pair<string, string> > kachoriIngredients;
    kachoriIngredients.push_back(make_pair("Flour", "200g"));
    kachoriIngredients.push_back(make_pair("Lentils", "100g"));
    kachoriIngredients.push_back(make_pair("Oil", "500ml"));
    kachoriIngredients.push_back(make_pair("Ginger", "1 tsp"));
    kachoriIngredients.push_back(make_pair("Spices", "10g"));
    kachoriIngredients.push_back(make_pair("Salt", "to taste"));
    NorthIndianSnacks* recipe1 = new NorthIndianSnacks("Kachori", kachoriIngredients, "Make dough, fill lentils, and deep fry.", 250, 4.7, myUser, 0, 50, 0, "Rajasthan", "Fried", 6, "Masala Chai");
    recipes.push_back(recipe1);

    vector<pair<string, string> > jalebiIngredients;
    jalebiIngredients.push_back(make_pair("Flour", "2 cups"));
    jalebiIngredients.push_back(make_pair("Sugar", "3 cups"));
    jalebiIngredients.push_back(make_pair("Saffron", "Pinch"));
    jalebiIngredients.push_back(make_pair("Cardamom", "1 tsp"));
    jalebiIngredients.push_back(make_pair("Ghee", "500ml"));
    jalebiIngredients.push_back(make_pair("Water", "2 cups"));
    vector<string> dryFruits;
    dryFruits.push_back("Pistachios");
    NorthIndianDesserts* recipe5 = new NorthIndianDesserts("Jalebi", jalebiIngredients, "Make batter, fry spirals, and soak in syrup.", 400, 4.9, myUser, 0, 30, 0, "Uttar Pradesh", 9, 1,dryFruits);
    recipes.push_back(recipe5);

    int choice;
    while (true)
    {
        cout << "Enter 1 to Signup into our app" << endl;
        cout << "Enter 2 to login" << endl;
        cout << "Enter 3 to exit" << endl;
        cin >> choice;

        if (choice == 3)
        {
            break;
        }
        else if (choice == 1)
        {
            User newUser;
            if (handleSignup(newUser))
            {
                continue;
            }
            test(newUser);
        }
        else
        {
            User loginUser;
            if (!handleLogin(loginUser))
            {
                continue;
            }
            test(loginUser);
        }
    }
}
