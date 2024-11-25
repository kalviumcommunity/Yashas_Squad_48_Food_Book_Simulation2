#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract base class: Recipe
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
    Recipe(string n, vector<string> ingr, string instr, string ctype, vector<string> stps)
        : name(n), ingredients(ingr), instructions(instr), cuisine_type(ctype), steps(stps) {
        totalRecipes++;
    }

    virtual ~Recipe() {
        totalRecipes--;
    }

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

    string get_name() const {
        return this->name;
    }

    string get_cuisine_type() const {
        return this->cuisine_type;
    }

    static int getTotalRecipes() {
        return totalRecipes;
    }

    static int getTotalViews() {
        return totalViews;
    }

    // Abstract method: Virtual function
    virtual void showRecipeDetails() = 0;  // Pure virtual function making Recipe an abstract class
};

// Initialize static variables
int Recipe::totalRecipes = 0;
int Recipe::totalViews = 0;

// Derived class for North Indian cuisine (inheritance from Recipe)
class North : public Recipe {
public:
    North(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "North Indian", stps) {}

    ~North() {}

    // Overriding virtual function for North Indian recipes
    void showRecipeDetails() override {
        display_recipe();
    }
};

// Derived class for South Indian cuisine (inheritance from Recipe)
class South : public Recipe {
public:
    South(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "South Indian", stps) {}

    ~South() {}

    // Overriding virtual function for South Indian recipes
    void showRecipeDetails() override {
        display_recipe();
    }
};

// Derived class for East Indian cuisine (inheritance from Recipe)
class East : public Recipe {
public:
    East(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "East Indian", stps) {}

    ~East() {}

    // Overriding virtual function for East Indian recipes
    void showRecipeDetails() override {
        display_recipe();
    }
};

// Function to display cuisine-specific recipes and allow recipe selection
void display_selected_recipes(const vector<Recipe*>& recipes, const string& selection) {
    vector<Recipe*> filtered_recipes;

    cout << "\nAvailable " << selection << " recipes:\n";
    for (const auto& recipe : recipes) {
        if (recipe->get_cuisine_type() == selection) {
            filtered_recipes.push_back(recipe);
            cout << filtered_recipes.size() << ". " << recipe->get_name() << endl;
        }
    }

    if (filtered_recipes.empty()) {
        cout << "No recipes available for " << selection << " cuisine." << endl;
        return;
    }

    int recipe_choice;
    cout << "Select a recipe by number: ";
    cin >> recipe_choice;

    if (recipe_choice >= 1 && recipe_choice <= filtered_recipes.size()) {
        // Calling overridden virtual function through base class pointer
        filtered_recipes[recipe_choice - 1]->showRecipeDetails();
    } else {
        cout << "Invalid recipe selection!" << endl;
    }
}

int main() {
    vector<Recipe*> allRecipes = {
        new North("Biryani", {"Rice", "Chicken", "Spices"}, "Cook rice, add chicken and spices", {
            "Rinse rice.", "Soak rice.", "Marinate chicken.", "Cook rice and chicken."}),
        new North("Butter Chicken", {"Chicken", "Butter", "Cream", "Tomatoes"}, "Marinate chicken, cook with butter and spices", {
            "Marinate chicken with spices.", "Cook tomatoes.", "Add cream and butter.", "Simmer chicken in sauce."}),
        new North("Aloo Gobi", {"Potato", "Cauliflower", "Spices"}, "Saute potatoes and cauliflower with spices", {
            "Heat oil in a pan.", "Add potatoes and spices.", "Add cauliflower.", "Cook until tender."}),

        new South("Fish Curry", {"Coconut", "Rice", "Fish"}, "Cook fish with coconut and spices", {
            "Grate coconut.", "Soak rice.", "Marinate fish.", "Cook fish and serve."}),
        new South("Dosa", {"Rice", "Urad Dal", "Salt"}, "Prepare batter, cook in a pan", {
            "Soak rice and urad dal.", "Grind to form batter.", "Ferment batter.", "Cook batter on a pan to form dosa."}),
        new South("Sambar", {"Lentils", "Vegetables", "Spices"}, "Boil lentils with vegetables and spices", {
            "Cook lentils.", "Add vegetables and spices.", "Simmer until thickened.", "Serve with rice or dosa."}),

        new East("Macher Jhol", {"Fish", "Potatoes", "Spices"}, "Cook fish with potatoes and spices", {
            "Marinate fish.", "Fry fish.", "Add spices.", "Cook with potatoes."}),
        new East("Pakhala Bhata", {"Rice", "Water", "Yogurt"}, "Ferment rice with water and yogurt", {
            "Soak rice in water.", "Let rice ferment.", "Serve with yogurt and spices."}),
        new East("Shukto", {"Vegetables", "Milk", "Spices"}, "Cook mixed vegetables with spices and milk", {
            "Chop vegetables.", "Saute vegetables with spices.", "Add milk.", "Cook until vegetables are tender."})
    };

    int choice;
    do {
        cout << "\nSelect a cuisine to view recipes:\n";
        cout << "1. North Indian\n";
        cout << "2. South Indian\n";
        cout << "3. East Indian\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

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
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    for (const auto& recipe : allRecipes) {
        delete recipe;
    }

    return 0;
}
