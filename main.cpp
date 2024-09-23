#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class: Recipe
class Recipe {
protected:
    string name;
    vector<string> ingredients;
    string instructions;
    string cuisine_type;
    vector<string> steps;

public:
    Recipe(string n, vector<string> ingr, string instr, string ctype, vector<string> stps)
        : name(n), ingredients(ingr), instructions(instr), cuisine_type(ctype), steps(stps) {}

    virtual ~Recipe() {} // Virtual destructor to ensure proper cleanup for derived classes

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
    }

    string get_name() const {
        return this->name;
    }
};

// Derived classes for different regions
class North : public Recipe {
public:
    North(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "North Indian", stps) {}
};

class South : public Recipe {
public:
    South(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "South Indian", stps) {}
};






class Northeast : public Recipe {
public:
    Northeast(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "Northeast Indian", stps) {}
};

class Northwest : public Recipe {
public:
    Northwest(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "Northwest Indian", stps) {}
};

int main() {
    // North Indian Recipes (Using dynamic memory allocation)
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

    // South Indian Recipes (Using dynamic memory allocation)
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

    // Northeast Indian Recipes (Using dynamic memory allocation)
    vector<Recipe*> northeastRecipes = {
        new Northeast("Bamboo Pork", {"Bamboo Shoots", "Pork", "Spices"}, "Cook pork with bamboo shoots and spices", {
            "Clean and chop the bamboo shoots into thin slices.",
            "Boil the bamboo shoots in water to remove bitterness.",
            "Cut the pork into bite-sized pieces.",
            "Marinate the pork with salt, ginger, and garlic paste.",
            "Heat oil in a pot and add whole spices.",
            "Add the marinated pork and cook until browned.",
            "Add the boiled bamboo shoots and stir well.",
            "Pour in water or broth and bring to a boil.",
            "Simmer on low heat until the pork is tender.",
            "Garnish with fresh herbs and serve hot."
        }),
        new Northeast("Fermented Rice", {"Rice", "Fermented Soybeans", "Ginger"}, "Cook rice with fermented soybeans", {
            "Rinse the rice and soak it in water for 30 minutes.",
            "Grind the fermented soybeans into a paste.",
            "Heat oil in a pan and sauté ginger until fragrant.",
            "Add the soybean paste and cook for a few minutes.",
            "Mix the paste with cooked rice.",
            "Steam the mixture until fully cooked.",
            "Garnish with fresh herbs.",
            "Serve hot with a side of vegetable curry.",
            "Enjoy the unique flavors of the dish."
        })
    };

    // Northwest Indian Recipes (Using dynamic memory allocation)
    vector<Recipe*> northwestRecipes = {
        new Northwest("Kebab", {"Wheat", "Meat", "Spices"}, "Grill meat with spices", {
            "Prepare the dough using wheat flour and water.",
            "Knead the dough until smooth and pliable.",
            "Cut the meat into small pieces and marinate with spices.",
            "Shape the marinated meat into kebabs.",
            "Preheat the grill to a medium-high temperature.",
            "Grill the kebabs until they are browned on all sides.",
            "Baste the kebabs with butter or ghee while grilling.",
            "Cook the kebabs until they are fully cooked inside.",
            "Remove the kebabs from the grill and let them rest.",
            "Serve the kebabs hot with mint chutney and naan."
        }),
        new Northwest("Mathri", {"Flour", "Butter", "Sugar"}, "Prepare and deep-fry dough discs", {
            "Mix flour, sugar, and melted butter to form a dough.",
            "Roll out the dough and cut it into small discs.",
            "Heat oil in a pan.",
            "Deep fry the discs until golden brown.",
            "Let them cool and store in an airtight container.",
            "Serve with tea or coffee.",
            "Enjoy the crunchy texture.",
            "Best with a sprinkle of powdered sugar on top."
        })
    };

    int cuisineChoice, dishChoice;
    while (true) {
        cout << "\nChoose a cuisine region by number:" << endl;
        cout << "1. North Indian\n2. South Indian \n3. Northeast Indian\n4. Northwest Indian\n5. Exit" << endl;
        cin >> cuisineChoice;

        if (cuisineChoice == 5) {
            cout << "Exiting program." << endl;
            break;
        }

        vector<Recipe*> chosenRecipes;
        switch (cuisineChoice) {
            case 1:
                chosenRecipes = northRecipes;
                break;
            case 2:
                chosenRecipes = southRecipes;
                break;
            case 3:
                chosenRecipes = northeastRecipes;
                break;
            case 4:
                chosenRecipes = northwestRecipes;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }

        cout << "Choose a dish from this region by number:" << endl;
        for (size_t i = 0; i < chosenRecipes.size(); ++i) {
            cout << i + 1 << ". " << chosenRecipes[i]->get_name() << endl;
        }
        cin >> dishChoice;

        if (dishChoice >= 1 && dishChoice <= chosenRecipes.size()) {
            chosenRecipes[dishChoice - 1]->display_recipe();
        } else {
            cout << "Invalid dish choice. Please try again." << endl;
        }
    }

    // Freeing dynamically allocated memory
    for (auto recipe : northRecipes) delete recipe;
    for (auto recipe : southRecipes) delete recipe;
    for (auto recipe : northeastRecipes) delete recipe;
    for (auto recipe : northwestRecipes) delete recipe;

    return 0;
}
