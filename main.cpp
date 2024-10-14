#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract base class: Recipe (provides an interface for derived classes)
class Recipe {
protected:
    string name;
    vector<string> ingredients;
    string instructions;
    string cuisine_type;
    vector<string> steps;

    static int totalRecipes;
    static int totalViews;

public:
    // Constructor to initialize recipe attributes
    Recipe(string n, vector<string> ingr, string instr, string ctype, vector<string> stps)
        : name(n), ingredients(ingr), instructions(instr), cuisine_type(ctype), steps(stps) {
        totalRecipes++;
    }

    virtual ~Recipe() {
        totalRecipes--;
    }

    // Function to display the recipe
    void display_recipe() {
        cout << "Recipe: " << this->name << endl;
        cout << "Cuisine Type: " << this->cuisine_type << endl;
        cout << "Ingredients: ";
        for (const auto& ing : this->ingredients)
            cout << ing << " ";
        cout << endl;
        cout << "Instructions: " << this->instructions << endl;
        cout << "How to Cook:" << endl;
        for (size_t i = 0; i < this->steps.size(); ++i) {
            cout << i + 1 << ". " << this->steps[i] << endl;
        }
        totalViews++;
    }

    // Getter functions for name and cuisine type
    string get_name() const {
        return this->name;
    }

    string get_cuisine_type() const {
        return this->cuisine_type;
    }

    // Static functions to get total recipes and views
    static int getTotalRecipes() {
        return totalRecipes;
    }

    static int getTotalViews() {
        return totalViews;
    }

    // Pure virtual function (abstraction) - must be implemented in derived classes
    virtual void showRecipeDetails() = 0; // Abstract function for showing recipe details
};

// Initialize static variables
int Recipe::totalRecipes = 0;
int Recipe::totalViews = 0;

// Derived classes for different regions
class North : public Recipe {
public:
    North(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "North Indian", stps) {}

    // Implementing the abstract function in the derived class
    void showRecipeDetails() override {
        display_recipe(); // Calling the base class function to show details
    }
};

class South : public Recipe {
public:
    South(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "South Indian", stps) {}

    // Implementing the abstract function in the derived class
    void showRecipeDetails() override {
        display_recipe(); // Calling the base class function to show details
    }
};

class East : public Recipe {
public:
    East(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "East Indian", stps) {}

    // Implementing the abstract function in the derived class
    void showRecipeDetails() override {
        display_recipe(); // Calling the base class function to show details
    }
};

// Function to display cuisine-specific recipes and allow recipe selection
void display_selected_recipes(const vector<Recipe*>& recipes, const string& selection) {
    vector<Recipe*> filtered_recipes;

    // Collect recipes from the selected cuisine
    cout << "\nAvailable " << selection << " recipes:\n";
    for (const auto& recipe : recipes) {
        if (recipe->get_cuisine_type() == selection) {
            filtered_recipes.push_back(recipe);
            cout << filtered_recipes.size() << ". " << recipe->get_name() << endl;
        }
    }

    // Check if any recipes are available for the selected cuisine
    if (filtered_recipes.empty()) {
        cout << "No recipes available for " << selection << " cuisine." << endl;
        return;
    }

    // Let the user select a recipe
    int recipe_choice;
    cout << "Select a recipe by number: ";
    cin >> recipe_choice;

    if (recipe_choice >= 1 && recipe_choice <= filtered_recipes.size()) {
        filtered_recipes[recipe_choice - 1]->showRecipeDetails(); // Call the abstract method
    } else {
        cout << "Invalid recipe selection!" << endl;
    }
}

int main() {
    // North Indian Recipes
    vector<Recipe*> northRecipes = {
        new North("Biryani", {"Rice", "Chicken", "Spices"}, "Cook rice, add chicken and spices", {
            "Rinse the rice thoroughly until the water runs clear.",
            "Soak the rice in water for 30 minutes.",
            "Marinate the chicken with yogurt, spices, and lemon juice for 1 hour.",
            "Heat ghee in a large pot and add whole spices.",
            "Add sliced onions and sauté until golden brown.",
            "Add the marinated chicken and cook until browned.",
            "Add water, bring to a boil, and add the soaked rice.",
            "Cover and cook on low heat until the rice is fully cooked.",
            "Let the biryani rest for 10 minutes before serving.",
            "Garnish with fried onions, coriander, and serve hot."
        }),
        new North("Paneer Butter Masala", {"Paneer", "Tomato", "Cream"}, "Cook paneer with tomato and cream", {
            "Cut paneer into cubes and set aside.",
            "Make a tomato puree by blending fresh tomatoes.",
            "Heat oil in a pan, add cumin seeds.",
            "Add ginger-garlic paste and sauté.",
            "Pour in the tomato puree and cook until oil separates.",
            "Add spices like turmeric, cumin, and coriander powder.",
            "Add cream and mix well.",
            "Add the paneer cubes and simmer for 5-7 minutes.",
            "Garnish with fresh coriander leaves.",
            "Serve hot with naan or rice."
        })
    };

    // South Indian Recipes
    vector<Recipe*> southRecipes = {
        new South("Fish Curry", {"Coconut", "Rice", "Fish"}, "Cook fish with coconut and spices", {
            "Grate fresh coconut and extract the coconut milk.",
            "Rinse the rice and soak it in water for 30 minutes.",
            "Clean and cut the fish into pieces.",
            "Marinate the fish with turmeric, salt, and chili powder.",
            "Heat oil in a pan and sauté onions, garlic, and ginger.",
            "Add tomatoes and cook until soft and pulpy.",
            "Add the marinated fish and cook until it turns white.",
            "Pour in the coconut milk and bring to a simmer.",
            "Cook the fish in the coconut milk until tender.",
            "Serve the fish curry hot with steamed rice."
        }),
        new South("Masala Dosa", {"Rice", "Urad Dal", "Fenugreek Seeds"}, "Make dosa batter and prepare dosa", {
            "Soak rice, urad dal, and fenugreek seeds separately overnight.",
            "Grind them separately into a smooth batter.",
            "Mix the batters together and let it ferment overnight.",
            "Heat a tawa and pour a ladle of batter onto it.",
            "Spread the batter evenly to form a thin dosa.",
            "Drizzle oil around the edges.",
            "Cook until the edges start lifting.",
            "Flip the dosa and cook the other side for a few seconds.",
            "Serve hot with coconut chutney and sambar.",
            "Enjoy the dosa!"
        })
    };

    // East Indian Recipes
    vector<Recipe*> eastRecipes = {
        new East("Macher Jhol", {"Fish", "Potatoes", "Spices"}, "Cook fish with potatoes and spices", {
            "Marinate the fish with turmeric and salt.",
            "Heat mustard oil in a pan and fry the fish pieces lightly.",
            "In the same pan, add cumin seeds, ginger, and green chilies.",
            "Add chopped tomatoes and cook till soft.",
            "Add spices like cumin, coriander, and turmeric powder.",
            "Add fried fish and potato slices.",
            "Pour water and bring to a simmer.",
            "Cook until the potatoes are tender.",
            "Garnish with fresh coriander and serve hot with rice."
        })
    };

    // Collect all recipes in one vector
    vector<Recipe*> allRecipes;
    allRecipes.insert(allRecipes.end(), northRecipes.begin(), northRecipes.end());
    allRecipes.insert(allRecipes.end(), southRecipes.begin(), southRecipes.end());
    allRecipes.insert(allRecipes.end(), eastRecipes.begin(), eastRecipes.end());

    // Main menu loop
    int choice;
    do {
        cout << "\nSelect a cuisine to view recipes:\n";
        cout << "1. North Indian\n";
        cout << "2. South Indian\n";
        cout << "3. East Indian\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Show recipes based on selection and prompt to select a specific recipe
        switch (choice) {
        case 1:
            display_selected_recipes(allRecipes, "North Indian");
            break;
        case 2:
            display_selected_recipes(allRecipes, "South Indian");
            break;
        case 3:
            display_selected_recipes(allRecipes, "East Indian");
            break;
        case 4:
            cout << "Exiting program. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    // Cleanup dynamically allocated memory
    for (auto& recipe : allRecipes) {
        delete recipe;
    }

    return 0;
}
