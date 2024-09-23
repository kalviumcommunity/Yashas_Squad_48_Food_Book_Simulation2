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

    // Static variables to track total number of recipes and total views
    static int totalRecipes;
    static int totalViews;

public:
    Recipe(string n, vector<string> ingr, string instr, string ctype, vector<string> stps)
        : name(n), ingredients(ingr), instructions(instr), cuisine_type(ctype), steps(stps) {
        totalRecipes++; // Increment the total number of recipes each time a new one is created
    }

    virtual ~Recipe() {
        totalRecipes--; // Decrement totalRecipes when a recipe is destroyed
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
        totalViews++; // Increment totalViews each time a recipe is viewed
    }

    string get_name() const {
        return this->name;
    }

    // Static function to get total number of recipes
    static int getTotalRecipes() {
        return totalRecipes;
    }

    // Static function to get total views
    static int getTotalViews() {
        return totalViews;
    }
};

// Initialize static variables
int Recipe::totalRecipes = 0;
int Recipe::totalViews = 0;

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

class East : public Recipe {
public:
    East(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "East Indian", stps) {}
};

class West : public Recipe {
public:
    West(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "West Indian", stps) {}
};

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
        }),
        new North("Rajma", {"Kidney Beans", "Onions", "Tomatoes"}, "Cook kidney beans with spices", {
            "Soak the kidney beans overnight.",
            "Boil the beans in a pressure cooker until soft.",
            "Heat oil in a pan and sauté onions until golden brown.",
            "Add ginger-garlic paste and cook until fragrant.",
            "Add chopped tomatoes and cook until soft.",
            "Add spices like cumin, coriander, and garam masala.",
            "Add the boiled kidney beans and mix well.",
            "Simmer for 10-15 minutes until flavors combine.",
            "Garnish with fresh coriander leaves.",
            "Serve hot with rice."
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
        }),
        new South("Hyderabadi Biryani", {"Basmati Rice", "Mutton", "Spices"}, "Cook rice and marinated mutton in layers", {
            "Marinate mutton with yogurt, spices, and lemon juice for 2 hours.",
            "Cook rice with whole spices until 70% done.",
            "Layer the marinated mutton and rice in a large pot.",
            "Seal the pot with dough to trap steam.",
            "Cook on low heat for 30-40 minutes.",
            "Unseal the pot and gently mix the biryani.",
            "Serve hot with raita and a boiled egg."
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
        }),
        new East("Chingri Malai Curry", {"Prawns", "Coconut Milk", "Spices"}, "Cook prawns in coconut milk", {
            "Clean the prawns and marinate with turmeric and salt.",
            "Heat mustard oil in a pan and lightly fry the prawns.",
            "In the same pan, add bay leaves, cumin seeds, and green chilies.",
            "Add coconut milk and bring to a simmer.",
            "Add the fried prawns and cook for a few minutes.",
            "Let the curry thicken to your desired consistency.",
            "Garnish with fresh coriander and serve hot with steamed rice."
        }),
        new East("Litti Chokha", {"Wheat Flour", "Gram Flour", "Eggplant"}, "Bake stuffed dough balls with chokha", {
            "Prepare dough using wheat flour and water.",
            "Make a stuffing using roasted gram flour, spices, and mustard oil.",
            "Shape the dough into balls and stuff them with the mixture.",
            "Bake the littis until golden brown.",
            "Roast eggplant, mash it with mustard oil, onions, and spices to make chokha.",
            "Serve the litti with chokha and ghee."
        })
    };

    // West Indian Recipes
    vector<Recipe*> westRecipes = {
        new West("Pav Bhaji", {"Mixed Vegetables", "Pav Bread", "Spices"}, "Cook vegetables and serve with pav bread", {
            "Boil and mash mixed vegetables (potatoes, peas, carrots).",
            "Heat butter in a pan, add onions and sauté till golden.",
            "Add ginger-garlic paste and sauté.",
            "Add chopped tomatoes and cook until soft.",
            "Add spices like pav bhaji masala, red chili powder, and salt.",
            "Add the mashed vegetables and cook for 10-15 minutes.",
            "Toast the pav bread with butter.",
            "Serve hot with buttered pav, onions, and lemon wedges."
        }),
        new West("Vada Pav", {"Potatoes", "Chickpea Flour", "Pav Bread"}, "Deep fry potato fritters and serve with bread", {
            "Boil and mash potatoes with spices.",
            "Shape the potato mixture into small balls.",
            "Dip them in chickpea flour batter and deep fry until golden brown.",
            "Serve the vada in a pav with chutney and fried green chilies."
        }),
        new West("Dhokla", {"Gram Flour", "Yogurt", "Spices"}, "Steam gram flour batter to make spongy cakes", {
            "Mix gram flour with yogurt, water, and spices to form a batter.",
            "Let the batter ferment for a few hours.",
            "Add fruit salt or baking soda and mix well.",
            "Pour the batter into a greased dish and steam until cooked.",
            "Prepare tempering with mustard seeds, curry leaves, and green chilies.",
            "Pour the tempering over the steamed dhokla.",
            "Serve with chutney."
        })
    };

    int cuisineChoice, dishChoice;
    while (true) {
        cout << "\nChoose a cuisine region by number:" << endl;
        cout << "1. North Indian\n2. South Indian\n3. East Indian\n4. West Indian\n5. Exit" << endl;
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
                chosenRecipes = eastRecipes;
                break;
            case 4:
                chosenRecipes = westRecipes;
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

        // Display total recipes and views after each selection
        cout << "\nTotal Recipes: " << Recipe::getTotalRecipes() << endl;
        cout << "Total Views: " << Recipe::getTotalViews() << endl;
    }

    // Freeing dynamically allocated memory
    for (auto recipe : northRecipes) delete recipe;
    for (auto recipe : southRecipes) delete recipe;
    for (auto recipe : eastRecipes) delete recipe;
    for (auto recipe : westRecipes) delete recipe;

    return 0;
}
