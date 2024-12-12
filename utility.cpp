#include "Recipe.h"
#include <fstream>
#include <algorithm>
#include <time.h>
#include"exception.h"
using namespace std;

// Function tempelates to filter/sort recipes on basis of likes/ratings(int,double)
template <typename T>
void bubbleSortRecipes(vector<Recipe *> &recipes, T Recipe::*member)
{
    bool swapped;
    for (int i = 0; i < recipes.size() - 1; ++i)
    {
        swapped = false;
        for (int j = 0; j < recipes.size() - i - 1; ++j)
        {
            if (recipes[j]->*member < recipes[j + 1]->*member)
            {
                swap(recipes[j], recipes[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void signUp(User &u)
{
    try
    {
        cout << "Enter details (username, password):" << endl;
        cin >> u; 

        // Check if the user already exists
        if (login(u.getUsername(), u.getPass()))
        {
            u.setUserToNull();
            throw SignUpException("User already exists! Please login.");
        }

        // Open file in append mode
        ofstream out("user.txt", ios::app);
        if (!out)
        {
            throw SignUpException("Error while opening the file for saving user data.");
        }

        // Save user details to file
        out << u << endl;
        out.close();

        cout << "\nUser details have been successfully saved to the file.\n" << endl;
    }
    catch (const SignUpException &e)
    {
        cerr << "SignUp Error: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "An unknown error occurred." << endl;
    }
}

// login function
bool login(const string &username, const string &password)
{
    try
    {
        ifstream in("user.txt");
        if (!in)
        {
            throw LoginException("Error opening file for reading user data.");
        }

        User u; // Assuming User class is properly defined
        while (in >> u)
        {
            if (u.getUsername() == username && u.getPass() == password)
            {
                return true; // User found
            }
        }

        // if no match is found
        return false;
    }
    catch (const LoginException &e)
    {
        cerr << "Login Error: " << e.what() << endl;
        return false;
    }
    catch (const exception &e)
    {
        cerr << "Unexpected Error: " << e.what() << endl;
        return false;
    }
    catch (...)
    {
        cerr << "An unknown error occurred during login." << endl;
        return false;
    }
}


// handler for signup when already existing user signup
int handleSignup(User &u)
{
    signUp(u);
    if (u.getUsername() == " ")
    {
        return 1;
    }
    cout << "Hello " << u.getUsername() << " Welcome! to our Recipe App" << endl;
    return 0;
}

// handler function for login
int handleLogin(User &u)
{
    string name, password;
    cout << "Enter username: ";
    cin >> name;
    cout << "Enter password: ";
    cin >> password;
    cout << endl;

    if (login(name, password))
    {
        cout << "Login successful!" << "Welcome back " << name << endl<< endl;
        u.setName(name);
        u.setPass(password);
        return 1;
    }
    else
    {
        return 0;
    }
}

void test(User &u)
{
    int choice2;
    while (true)
    {
        cout << "Enter 1 to add your Recipe" << endl;
        cout << "Enter 2 to display all recipes" << endl;
        cout << "Enter 3 to search and display a particular recipe" << endl;
        cout << "Enter 4 to display common ingredients between two recipes" << endl;
        cout << "Enter 5 to sort/filter recipes based on likes/ratings" << endl;
        cout << "Enter 6 to get the recipe of the day" << endl;
        cout << "Enter 7 to exit" << endl;

        cin >> choice2;
        switch (choice2)
        {
        case 1:
        {
            cout << "Select recipe type:\n"
                 << "1. North Indian Snack\n"
                 << "2. South Indian Snack\n"
                 << "3. North Indian Dessert\n"
                 << "4. South Indian Dessert\n"
                 << "5. North Indian Main Course\n"
                 << "6. South Indian Main Course\n";
            int typeChoice;
            cin >> typeChoice;
            cin.ignore();

            string name, instructions;
            cout << "Enter the name of the recipe: ";
            getline(cin, name);

            vector<pair<string, string> > ingredients;
            int numIngredients;
            cout << "Enter the number of ingredients: ";
            cin >> numIngredients;
            cin.ignore();

            for (int i = 0; i < numIngredients; ++i)
            {
                string ingredientName, ingredientQuantity;
                cout << "Enter ingredient name: ";
                getline(cin, ingredientName);
                cout << "Enter ingredient quantity: ";
                getline(cin, ingredientQuantity);
                ingredients.push_back(make_pair(ingredientName,ingredientQuantity));
            }

            cout << "Enter cooking instructions: ";
            getline(cin, instructions);

            int h, m, s;
            cout << "Enter preparation time (hours minutes seconds): ";
            cin >> h >> m >> s;


            Recipe *newRecipe = nullptr;
            switch (typeChoice)
            {
            case 1:
            {
                string origin, prepType, beveragePairing;
                int spiceLevel;
                cout << "Enter origin: ";
                cin.ignore();
                getline(cin, origin);
                cout << "Enter preparation type: ";
                getline(cin, prepType);
                cout << "Enter spice level (1-5): ";
                cin >> spiceLevel;
                cout << "Enter beverage pairing: ";
                cin.ignore();
                getline(cin, beveragePairing);

                newRecipe = new NorthIndianSnacks(name, ingredients, instructions, 0, 0, u, h, m, s, origin, prepType, spiceLevel, beveragePairing);
                break;
            }
            case 2:
            {
                string origin, prepType, chutneyType;
                int crispLevel;
                cout << "Enter origin: ";
                cin.ignore();
                getline(cin, origin);
                cout << "Enter preparation type: ";
                getline(cin, prepType);
                cout << "Enter crisp level (1-5): ";
                cin >> crispLevel;
                cout << "Enter chutney type: ";
                cin.ignore();
                getline(cin, chutneyType);

                newRecipe = new SouthIndianSnacks(name, ingredients, instructions, 0, 0, u, h, m, s, origin, prepType, crispLevel, chutneyType);
                break;
            }
            case 3:
            {
                string origin;
                int sweetLevel, freshSpan;
                vector<string> dryFruits;
                cout << "Enter origin: ";
                cin.ignore();
                getline(cin, origin);
                cout << "Enter sweet level (1-5): ";
                cin >> sweetLevel;
                cout << "Enter freshness span (in days): ";
                cin >> freshSpan;
                cout << "Enter number of dry fruits: ";
                int numDryFruits;
                cin >> numDryFruits;
                cin.ignore();

                for (int i = 0; i < numDryFruits; ++i)
                {
                    string dryFruit;
                    cout << "Enter dry fruit: ";
                    getline(cin, dryFruit);
                    dryFruits.push_back(dryFruit);
                }

                newRecipe = new NorthIndianDesserts(name, ingredients, instructions, 0, 0, u, h, m, s, origin, sweetLevel, freshSpan, dryFruits);
                break;
            }
            case 4:
            {
                string origin, textureType;
                int freshSpan;
                cout << "Enter origin: ";
                cin.ignore();
                getline(cin, origin);
                cout << "Enter freshness span (in days): ";
                cin >> freshSpan;
                cout << "Enter texture type: ";
                cin.ignore();
                getline(cin, textureType);

                newRecipe = new SouthIndianDesserts(name, ingredients, instructions, 0, 0, u, h, m, s, origin, freshSpan, textureType);
                break;
            }
            case 5:
            {
                string origin, oilContent;
                int gheeLevel;
                cout << "Enter origin: ";
                cin.ignore();
                getline(cin, origin);
                cout << "Enter oil content: ";
                getline(cin, oilContent);
                cout << "Enter ghee level (1-5): ";
                cin >> gheeLevel;

                newRecipe = new NorthIndianMainCourse(name, ingredients, instructions, 0, 0, u, h, m, s, oilContent, gheeLevel, origin);
                break;
            }
            case 6:
            {
                string origin;
                bool isCoconutUsed;
                int gheeLevel;
                cout << "Enter origin: ";
                cin.ignore();
                getline(cin, origin);
                cout << "Is coconut used (1 for Yes, 0 for No): ";
                cin >> isCoconutUsed;
                cout << "Enter ghee level (1-5): ";
                cin >> gheeLevel;

                newRecipe = new SouthIndianMainCourse(name, ingredients, instructions, 0, 0, u, h, m, s, origin, isCoconutUsed, gheeLevel);
                break;
            }
            default:
                cout << "Invalid recipe type!" << endl;
                continue;
            }

            recipes.push_back(newRecipe);
            cout << "Your Recipe has been added!" << endl;
            newRecipe->display();
            break;
        }

        case 2:
        {
            cout << "Recipes available:" << endl;
            for (const auto &recipe : recipes)
            {
                recipe->display();
                cout << endl;
            }
            break;
        }

        case 3:
        {
            cout << "Enter the name of the recipe to be displayed:" << endl;
            string name;
            cin.ignore(); // To clear the input buffer
            getline(cin, name);

            int size = recipes.size();
            bool recipeFound = false;

            for (int i = 0; i < size; i++)
            {
                if (recipes[i]->getRecipeName() == name)
                {
                    recipeFound = true;
                    recipes[i]->display(); // Display the full recipe details

                    int input;
                    while (true)
                    {
                        cout << "\nEnter 1 to give a rating to this recipe." << endl;
                        cout << "Enter 2 to like this recipe." << endl;
                        cout << "Enter 3 to add more ingredients to this recipe." << endl;
                        cout << "Enter 4 to remove ingredients from this recipe." << endl;
                        cout << "Enter 5 to exit to the main menu." << endl;

                        cin >> input;

                        if (input == 1)
                        {
                            double rating;
                            cout << "Enter the rating (between 0 and 5): ";
                            cin >> rating;

                            if (rating >= 0 && rating <= 5)
                            {
                                recipes[i]->addRatings(rating); 
                                cout << "Thank you. Your rating was added." << endl;
                                recipes[i]->display(); // Display updated recipe
                            }
                            else
                            {
                                cout << "Invalid rating. Enter a value between 0 and 5." << endl;
                            }
                        }
                        else if (input == 2)
                        {
                            recipes[i]->increaseLikes(); 
                            cout << "Recipe liked." << endl;
                            recipes[i]->display(); // Display updated recipe
                        }
                        else if (input == 3)
                        {
                            string ingredient, quantity;
                            cout << "Enter the name of ingredient and its quantity:" << endl;
                            cin.ignore(); // Clear the input buffer
                            getline(cin, ingredient);
                            getline(cin, quantity);

                            if (recipes[i]->getAddedBy() != u.getUsername())
                            {
                                cout << "You don't have permission to edit this recipe." << endl;
                            }
                            else
                            {
                                recipes[i]->addIngredients(ingredient, quantity);
                                cout << "Ingredient added." << endl;
                                recipes[i]->display(); // Display updated recipe
                            }
                        }
                        else if (input == 4)
                        {
                            string ingredient;
                            cout << "Enter the name of ingredient to be removed:" << endl;
                            cin.ignore(); // Clear the input buffer
                            getline(cin, ingredient);

                            if (recipes[i]->getAddedBy() != u.getUsername())
                            {
                                cout << "You don't have permission to edit this recipe." << endl;
                            }
                            else
                            {
                                recipes[i]->removeIngredients(ingredient); 
                                cout << "Ingredient removed." << endl;
                                recipes[i]->display(); // Display updated recipe
                            }
                        }
                        else if (input == 5)
                        {
                            break; // Exit to main menu
                        }
                        else
                        {
                            cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                    break; // Exit the loop once the recipe is found and displayed
                }
            }

            if (!recipeFound)
            {
                cout << "No recipe found with the name: " << name << endl;
            }

            break; // Exit the switch case after the operation is complete
        }

        case 4:
        {
            cout << "Enter the name of the 1st recipe: ";
            string name1;
            cin.ignore();
            getline(cin, name1);

            cout << "Enter the name of the 2nd recipe: ";
            string name2;
            getline(cin, name2);

            Recipe *recipe1 = nullptr, *recipe2 = nullptr;

            for (const auto &recipe : recipes)
            {
                if (recipe->getRecipeName() == name1)
                {
                    recipe1 = recipe;
                }
                if (recipe->getRecipeName() == name2)
                {
                    recipe2 = recipe;
                }
            }

            if (!recipe1 || !recipe2)
            {
                cout << "One or both recipes not found!" << endl;
                break;
            }
            if(*recipe1==*recipe2)
            {

            }
            else
            {
                cout<<"No Common Ingredients found!"<<endl;
            }
            break;
        }

        case 5:
        {
            int sortOption;
            cout << "Enter 1 to sort by likes (descending)\nEnter 2 to sort by ratings (descending)\n";
            cin >> sortOption;

            // Sort by likes or ratings using the template function
            if (sortOption == 1)
            {
                // Sorting by likes (descending)
                bubbleSortRecipes(recipes, &Recipe::likes); // Using the likes member
            }
            else if (sortOption == 2)
            {
                // Sorting by ratings (descending)
                bubbleSortRecipes(recipes, &Recipe::ratings); // Using the ratings member
            }
            else
            {
                cout << "Invalid choice!" << endl;
            }

            // Display the sorted recipes
            cout << "Sorted Recipes:" << endl;
            for (const auto &recipe : recipes)
            {
                recipe->display(); 
                cout << endl;
            }
            break;
        }

        case 6:
        {
            if (recipes.empty())
            {
                cout << "No recipes available!" << endl;
            }
            else
            {
                srand(time(0));
                int randomIndex = rand() % recipes.size();
                cout << "Recipe of the Day:" << endl;
                recipes[randomIndex]->display();
            }
            break;
        }

        case 7:
        {
            cout << "Exiting..." << endl;
            return;
        }

        default:
            cout << "Invalid choice! Try again." << endl;
            break;
        }
    }
}
