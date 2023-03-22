#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;

// Define constants
const int MAX_HEALTH = 100;
const int MAX_LIVES = 3;

// Define structs
struct Item {
    string name;
};
struct Enemy {
    string name;
    int health;
    int attack;
    int defense;
};

// Define functions
void printInventory(const vector<Item>& inventory);
void printEnemy(const Enemy& enemy);
bool fightEnemy(Enemy& enemy, int& playerHealth, int& playerAttack, int& playerDefense);
void saveGame(int progress, int health, int lives, const vector<Item>& inventory, int attack, int defense, int score);
void loadGame(int& progress, int& health, int& lives, vector<Item>& inventory, int& attack, int& defense, int& score);

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Define variables
    int progress = 0;
    int health = MAX_HEALTH;
    int lives = MAX_LIVES;
    int attack = 10;
    int defense = 5;
    int score = 0;
    bool position=false;    

    // Create a new vector of Item objects based on str_inventory
    vector<Item> inventory;
    Enemy enemy{"Mandarin", 150, 12, 7};
    Enemy senemy{"Modok", 50, 5, 2};
    
    // Print intro
    cout << "Welcome to the Forest Adventure game!" << endl;
    cout << "You find yourself in a dark forest with no memory of how you got there." << endl;
    
    // Main game loop
    while (true) {
        // Print current progress and options
        cout <<endl <<"Progress: " << progress << endl;
        cout << "Score: " << score << endl;
        cout << "Lives: " << lives << endl;
        cout << "Health: " << health << endl<<endl;
        cout << "Choose your next move:" << endl;
        cout << "1. Walk deeper into the forest" << endl;
        cout << "2. Search for food and supplies" << endl;
        cout << "3. Recover health" << endl;
        cout << "4. Fight the nearby enemy " << endl;
        cout << "5. Check inventory" << endl;
        cout << "6. Craft a weapon" << endl;
        cout << "7. Save game" << endl;
        cout << "8. Load game" << endl;
        cout << "9. Quit game" << endl<<endl;
        
        // Get user input
        int choice;
        cin >> choice;
        cout<<endl;
        try
        {
        // Process user input
        switch (choice) {
            case 1:
                // Walk deeper into the forest
                {
				cout << "You continue walking deeper into the forest." << endl;
                progress++;
                position=true;
                break;
            }
            case 2:
                // Search for food and supplies
                {
                if(position)
                {
				cout << "You search for food and supplies." << endl;
                int loot = rand() % 4; // Randomly generate loot
                if (loot == 0) {
                    inventory.push_back({"Apple"});
                    cout << "You found an apple!" << endl;
                } else if (loot == 1) {
                    inventory.push_back({"Sword"});
                    cout << "You found a sword!" << endl;
                    attack += 5;
                } else if (loot == 2) {
                    inventory.push_back({"Berries"});
                    cout << "You found some berries!" << endl;
                    defense += 3;
                }
                else  {
                    cout << "You found a nothing, try again!" << endl;
                    defense += 3;
                }
                position=false;
                break;
            }
            else
            cout<<"This place has been explored."<<endl<<"Move further in the forest to find new items"<<endl;
            break;
            }
            case 3:
            	{
				cout<<"How do you want to Recover health?"<<endl<<"	1. Eating food"<<endl<<"	2. Resting"<<endl;
            	int cccc;
            	cin>>cccc;
            	cout<<endl;
            	try {
            	if (cccc==2)
            	{
                // Rest and recover health
                cout<<"Resting for 10 seconds";
                this_thread::sleep_for(chrono::seconds(2));
                cout<<".";
                this_thread::sleep_for(chrono::seconds(2));
                cout<<".";
                this_thread::sleep_for(chrono::seconds(2));
                cout<<".";
                this_thread::sleep_for(chrono::seconds(2));
                cout<<".";
                this_thread::sleep_for(chrono::seconds(2));
                cout << "You rest and recover some health." << endl;
                health += 5;
                if (health > MAX_HEALTH) {
                    health = MAX_HEALTH;
                }
                break;
           		}
           		else if (cccc==1)
            	{
	                // Eat and recover health
	                cout<<"What do you want to eat?"<<endl<<"	1. 1 Apple= 10 health points"<<endl<<"	2. 1 Bunch of berries= 5 health points"<<endl;
	                int cx;
	                cin>>cx;
	                cout<<endl;
	                try{
	                if (cx==1)
	                {
						bool hasApple = false;
						for (int i = 0; i < inventory.size(); i++) {
					    if (inventory[i].name == "Apple") {
					        hasApple = true;
					        break;
					    }
						}
						if (hasApple)
						{
			                cout << "You ate an apple and recovered some health." << endl;
			                health += 10;
			                // Find the first occurrence of an item named "Apple"
						    auto it = find_if(inventory.begin(), inventory.end(), [](const Item& item){ 
						        return item.name == "Apple"; 
						    });
						    // Remove 1 apple from the inventory
						    if (it != inventory.end()) {
						        inventory.erase(it);
						    }
			                if (health > MAX_HEALTH) {
			                    health = MAX_HEALTH;
			                }
			                break;
		            	}
		            	else
		            	{
		            		cout<<"You don't have enough apples, you need to search for some first!"<<endl;
		            		break;
						}
		        	}
		        	else if (cx==2)
	                {
						bool hasBerries = false;
						for (int i = 0; i < inventory.size(); i++) {
					    if (inventory[i].name == "Berries") {
					        hasBerries = true;
					        break;
					    }
						}
						if (hasBerries)
						{
			                cout << "You ate some berries and recovered some health." << endl;
			                health += 5;
						    // Find the first occurrence of an item named "Berroes"
						    auto it = find_if(inventory.begin(), inventory.end(), [](const Item& item){ 
						        return item.name == "Berries"; 
						    });
						    // Remove 1 bunch of berries from the inventory
						    if (it != inventory.end()) {
						        inventory.erase(it);
						    }
							if (health > MAX_HEALTH) {
			                    health = MAX_HEALTH;
			                }
			                break;
		            	}
		            	else
		            	{
		            		cout<<"You don't have enough berries, you need to search for some first!"<<endl;
		            		break;
						}
		        	}
		        	else
		        	{
		        		throw runtime_error("Invalid input, Try again.");
		        		cout<< endl;
		        		break;
					}
		        }
		        catch (exception &e) {
		        cout << e.what() << endl;
		        cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
           		}
           		}
				else
				{
                throw runtime_error("Invalid input, Try again.");
				cout<< endl;
                break;
            	}
		        }
		        catch (exception &e) {
		        cout << e.what() << endl;
		        cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
				}
			}
            case 4:
            	{
            	if(position)
            	{
                // Fight the nearby enemy
                bool hasSword = false;
				for (int i = 0; i < inventory.size(); i++) {
				    if (inventory[i].name == "Sword") {
				        hasSword = true;
				        break;
				    }
				}
				if (hasSword) {
					cout<<"Do you want to fight the boss or you want to fight a smaller foe?"<<endl;
					cout<<"		1. Boss"<<endl<<"		2. Small foe"<<endl;
					int ccc;
					cin>>ccc;
					cout<<endl;
					try
					{
					if (ccc==1)
					{
		                if (fightEnemy(enemy, health, attack, defense)) {
		                    // Player wins
		                    cout << "You defeated the " << enemy.name << "!" << endl;
		                    score += 100;
		                    cout << "Your new score is " << score<<endl <<"Your health is "<<health<< endl;
		                    enemy.health = 100;
		                    position=false;
		                } else {
		                    // Player loses
		                    cout << "You were defeated by the " << enemy.name << "." << endl;
		                    lives--;
							// Find the first occurrence of an item named "Sword"
						    auto it = find_if(inventory.begin(), inventory.end(), [](const Item& item){ 
						        return item.name == "Sword"; 
						    });
						    // Remove 1 sword from the inventory
						    if (it != inventory.end()) {
						        inventory.erase(it);
						    }
							health = MAX_HEALTH;
		                    attack = 10;
		                    defense = 5;
		                    position=false;
		                    if (lives < 1) {
		                        // Game over
		                        cout << "Game over!" << endl;
		                        inventory.clear();
		                        return 0;
		                    }
		                }
		            }
		            
		            else if (ccc==2)
					{
		                if (fightEnemy(senemy, health, attack, defense)) {
		                    // Player wins
		                    cout << "You defeated the " << senemy.name << "!" << endl;
		                    score += 50;
		                    cout << "Your new score is " << score <<endl<< "Your health is "<<health<< endl;
		                    enemy.health = 50;
		                    position=false;
		                } else {
		                    // Player loses
		                    cout << "You were defeated by the " << senemy.name << "." << endl;
		                    lives--;
							// Find the first occurrence of an item named "Sword"
						    auto it = find_if(inventory.begin(), inventory.end(), [](const Item& item){ 
						        return item.name == "Sword"; 
						    });
						    // Remove 1 sword from the inventory
						    if (it != inventory.end()) {
						        inventory.erase(it);
						    }							
							health = MAX_HEALTH;
		                    attack = 10;
		                    defense = 5;
		                    position=false;
		                    if (lives < 1) {
		                        // Game over
		                        cout << "Game over!" << endl;
		                        inventory.clear();
		                        return 0;
		                    }
		                }
		            }
		            else
		            {
		            	throw runtime_error("Invalid input, Try again.");
				    cout<< endl;
                    break;
					}
				}
		        catch (exception &e) {
		        cout << e.what() << endl;
		        cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                position=false;
                break;
	            }
	        }
	            else
	            {
	            cout<<"You are defenceless, find a sword first."<<endl;
                break;
            	}
                }
            else
            cout<<"There are no more enemies here. "<<endl<<"Move further in the forest to find new ones."<<endl;
            break;
            }
            case 5:
            	{
                // Check inventory	
				printInventory(inventory);	
                break;
            }
            case 6:
            	{
            	cout<<"To craft a sword, you need"<<endl;
				cout<<"		1. 3 apples"<<endl;
				cout<<"		2. 5 bunches of berries"<<endl;
				cout<<"		3. 2 apples and 3 bunches of berries"<<endl<<endl;
				cout<<"Choose your option"<<endl;
            	int ch;
				cin>>ch;
				cout<<endl;
				try{
				if (ch==1)
				{
				int counts = count_if(inventory.begin(), inventory.end(), [](const Item& item) { return item.name == "Apple"; });
				if (counts>2)
					{
					for (int x=0;x<3;x++)
					{
					    // Find the first occurrence of an item named "Apple"
					    auto it = find_if(inventory.begin(), inventory.end(), [](const Item& item){ 
					        return item.name == "Apple"; 
					    });
					    // Remove 1 apple from the inventory
					    if (it != inventory.end()) {
					        inventory.erase(it);
					    }						
					}
                    inventory.push_back({"Sword"});
					cout<<"Congratulations, crafting has completed, you recieved a Sword"<<endl;
					}
					else
					cout<<"You have insufficient amount of apples. Try again"<<endl;
					break;
			    	}
				else if (ch==2)
					{
			    	int counts = count_if(inventory.begin(), inventory.end(), [](const Item& item) { return item.name == "Berries"; });
					if (counts>4)
					{
					for (int x=0;x<5;x++)
					{
					    // Find the first occurrence of an item named "Berries"
					    auto it = find_if(inventory.begin(), inventory.end(), [](const Item& item){ 
					        return item.name == "Berries"; 
					    });
					    // Remove 1 bunch of berries from the inventory
					    if (it != inventory.end()) {
					        inventory.erase(it);
					    }					
					}
                    inventory.push_back({"Sword"});
					cout<<"Congratulations, crafting has completed, you recieved a Sword"<<endl;
					}
					else
					cout<<"You have insufficient amount of berries. Try again"<<endl;
					break;	
					}
				else if (ch==3)
					{
					int counts = count_if(inventory.begin(), inventory.end(), [](const Item& item) { return item.name == "Berries"; });
					if (counts>=3)
					{
					int counts = count_if(inventory.begin(), inventory.end(), [](const Item& item) { return item.name == "Apple"; });
					if (counts>=2)
					{
					for (int x=0;x<3;x++)
					{
					    // Find the first occurrence of an item named "Berries"
					    auto it = find_if(inventory.begin(), inventory.end(), [](const Item& item){ 
					        return item.name == "Berries"; 
					    });
					    // Remove 1 bunch of berries from the inventory
					    if (it != inventory.end()) {
					        inventory.erase(it);
					    }						
					}
                    for (int x=0;x<2;x++)
					{
					    // Find the first occurrence of an item named "Apple"
					    auto it = find_if(inventory.begin(), inventory.end(), [](const Item& item){ 
					        return item.name == "Apple"; 
					    });
					    // Remove 1 apple from the inventory
					    if (it != inventory.end()) {
					        inventory.erase(it);
					    }					
					}
                	}
                    inventory.push_back({"Sword"});
					cout<<"Congratulations, crafting has completed, you recieved a Sword"<<endl;
					}
			    	else
					cout<<"You have insufficient amount of food items. Try again"<<endl;
					break;
			    	}	
				else {
				throw runtime_error("Invalid input, Try again.");
				cout<< endl;
                break;
					}	
		        }
		        catch (exception &e) {
		        cout << e.what() << endl;
		        cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
		    }
			}
            case 7:
            	{
                // Save game
                saveGame(progress, health, lives, inventory, attack, defense, score);
                cout << "Game saved." << endl;
                break;
            }
            case 8:
            	{
                // Load game
                loadGame(progress, health, lives, inventory, attack, defense, score);
                cout << "Game loaded." << endl;
                break;
            }
            case 9:
                // Quit game
                cout << "Quitting game." << endl;
                return 0;
            default:
            	{
                throw runtime_error("Invalid input, Try again.");
				cout<< endl;
                break;
            }
        }
        }
        catch (exception &e) {
        cout << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
        // Check for victory condition
        if (progress >=100 && score>0) {
            cout << "Congratulations, you have reached the end of the forest!" << endl;
            cout << "Your final score is " << score << "." << endl;
            return 0;
        }
    }
    
    return 0;
}

// Print inventory function
void printInventory(const vector<Item>& inventory) {
		int num_sword=0;
		int num_apple=0;
		int num_berries=0;	
    if (inventory.empty()) {
        cout << "Your inventory is empty." << endl;
    } else {
        cout << "Inventory:" << endl;
        	for (int i = 0; i < inventory.size(); i++) {
				    if (inventory[i].name == "Sword") {
				        num_sword += 1;
				    }
				    else if (inventory[i].name == "Apple") {
				        num_apple += 1;
				    }
				    else if (inventory[i].name == "Berries") {
				        num_berries += 1;
				    }
				}
}

            cout << "	Sword - "<<num_sword<< endl; 
			cout << "	Apple - "<<num_apple<< endl; 
			cout << "	Berries - "<<num_berries<< endl;  
}

// Print enemy function
void printEnemy(const Enemy& enemy) {
    cout << enemy.name << " - Health: " << enemy.health << ", Attack: " << enemy.attack << ", Defense: " << enemy.defense << endl;
}

// Fight enemy function
bool fightEnemy(Enemy& enemy, int& playerHealth, int& playerAttack, int& playerDefense) {
    // Print enemy stats
    cout << "You encounter an enemy named " << enemy.name << "!" << endl;
    printEnemy(enemy);

    // Fight loop
    while (true) {
        // Generate random number to determine who attacks first
        bool playerTurn = (rand() % 2 == 0);

        // Player attacks
        int damage = 0;
        if (playerTurn) {
            damage = playerAttack - enemy.defense;
            if (damage < 0) {
                damage = 0;
            }
            enemy.health -= damage;
            cout << "You attack " << enemy.name << " for " << damage << " damage." << endl;
        }

        // Check for enemy defeat
        if (enemy.health <= 0) {
            return true;
        }

        // Enemy attacks
        damage = enemy.attack - playerDefense;
        if (damage < 0) {
            damage = 0;
        }
        playerHealth -= damage;
        cout << enemy.name << " attacks you for " << damage << " damage." << endl;

        // Check for player defeat
        if (playerHealth <= 0) {
            cout << "You Lost" << endl;
            return false;
        }

        // Print player and enemy stats
        cout << "Player health: " << playerHealth << ", Enemy health: " << enemy.health << endl;

        // Ask player for action
        int choice;
        cout << "What do you want to do?" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Defend" << endl;
        cin >> choice;
        cout<<endl;
		try{
        // Process player action
        switch (choice) {
            case 1:
            	{
                // Player attacks
                if (!playerTurn) {
                    damage = playerAttack - enemy.defense;
                    if (damage < 0) {
                        damage = 0;
                    }
                    enemy.health -= damage;
                    cout << "You attack " << enemy.name << " for " << damage << " damage." << endl;
                    cout << "Player health: " << playerHealth << ", Enemy health: " << enemy.health << endl;
                }
                break;
            }
            case 2:
            	{
                // Player defends
                playerDefense += 5;
                cout << "You defend yourself and increase your defense." << endl;
                cout << "Player health: " << playerHealth << ", Enemy health: " << enemy.health << endl;
                break;
            }
            default:
            	{
                throw runtime_error("Invalid input, Try again.");
				cout<< endl;
                break;
       		}	
    		}
        }
        catch (exception &e) {
        cout << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
        // Check for enemy defeat
        if (enemy.health <= 0) {
            return true;
        }

        // Enemy attacks
        if (playerTurn) {
            damage = enemy.attack - playerDefense;
            if (damage < 0) {
                damage = 0;
            }
            playerHealth -= damage;
            cout << enemy.name << " attacks you for " << damage << " damage." << endl;
            cout << "Player health: " << playerHealth << ", Enemy health: " << enemy.health << endl;
        }

        // Check for player defeat
        if (playerHealth <= 0) {
        	cout << "Player health: " << playerHealth << ", Enemy health: " << enemy.health << endl;
            cout << "You Lost" << endl;
            return false;
        }
    }
}

// Save game function
void saveGame(int progress, int health, int lives, const vector<Item>& inventory, int attack, int defense, int score) {
ofstream saveFile("savegame.txt");
if (saveFile.is_open()) {
saveFile << progress << endl;
saveFile << health << endl;
saveFile << lives << endl;
saveFile << inventory.size() << endl;
for (const auto& item : inventory) {
saveFile << item.name << endl;
}
saveFile << attack << endl;
saveFile << defense << endl;
saveFile << score << endl;
saveFile.close();
} else {
cout << "Error: Unable to save game." << endl;
}
}

// Load game function
void loadGame(int& progress, int& health, int& lives, vector<Item>& inventory, int& attack, int& defense, int& score) {
ifstream saveFile("savegame.txt");
if (saveFile.is_open()) {
inventory.clear();
string name;
int effect, numItems;
saveFile >> progress;
saveFile >> health;
saveFile >> lives;
saveFile >> numItems;
getline(saveFile, name);
for (int i = 0; i < numItems; i++) {
getline(saveFile, name);
inventory.push_back(Item{name});
}
saveFile >> attack;
saveFile >> defense;
saveFile >> score;
saveFile.close();
} else {
cout << "Error: Unable to load game." << endl;
}
}
