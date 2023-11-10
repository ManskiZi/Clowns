#include <iostream>
using namespace std;

// Define a Clown class
class Clown {
private:
    int hp = 50;
    int dmg = 10;
    int x_coord;
    int y_coord;

public:
    int weaponDmg;
    int weaponDb;

    // Constructor to initialize Clown object with weapon damage, durability, and coordinates
    Clown(int weaponDmg, int weaponDb, int x, int y)
        : weaponDmg(weaponDmg), weaponDb(weaponDb), x_coord(x), y_coord(y) {}

    // Getter function to retrieve Clown's health
    int getHealth() {
        return hp;
    }

    // Function to calculate overall damage considering the weapon damage
    int overallDmg() {
        return dmg += weaponDmg;
    }

    // Function to make the Clown take damage from another Clown
    int takeDmg(const Clown& clown) {
        if (x_coord == clown.x_coord && y_coord == clown.y_coord) {
            return hp -= clown.dmg;
        }
        return 0;
    }

    // Function to perform an attack on another Clown
    bool Attack(Clown& clown) {
        if (weaponDb > 0) {
            if (x_coord == clown.x_coord && y_coord == clown.y_coord) {
                clown.hp -= overallDmg();
                weaponDb--;
                return true; // Successful attack
            }
        } else {
            cout << "Your weapon is broken\n";
        }
        return false; // Unsuccessful attack
    }
};

// Define a SpikedBat class
class SpikedBat {
public:
    int dmg = 13;
    int durability = 7;
    bool weapon = true;

    // Function to increase the damage of the SpikedBat
    void bleedDmg() {
        for (int i = 0; i < 5; i++) {
            dmg++;
        }
    }

    // Function to check if the SpikedBat has remaining uses
    bool uses() {
        if (durability <= 0) {
            return false;
        } else {
            cout << "You have " << durability << " uses left";
            return true;
        }
    }
};

// Main function
int main() {
    // Create a SpikedBat object
    SpikedBat spikedbat;

    // Create two Clown objects with the same weapon parameters and coordinates
    Clown crazyClown(spikedbat.dmg, spikedbat.durability, 5, 7);
    Clown sillyClown(spikedbat.dmg, spikedbat.durability, 5, 7);

    // Display initial information about the crazyClown
    cout << "Crazy clown has " << crazyClown.getHealth() << " Health\n";
    cout << "Crazy clown does " << crazyClown.overallDmg() << " Damage\n";
    cout << "Crazy clown attacked silly clown\n";

    // Display information about the sillyClown after taking damage
    cout << "Silly clown has " << sillyClown.takeDmg(crazyClown) << " health\n";
    cout << "Silly clown attacked crazy clown\n";

    // Perform an attack from sillyClown to crazyClown
    sillyClown.Attack(crazyClown);

    // Display the remaining health of crazyClown after the attack
    cout << "Crazy clown has " << crazyClown.getHealth() << " health";

    return 0;
}
