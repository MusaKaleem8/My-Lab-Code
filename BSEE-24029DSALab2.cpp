// BSEE-24029DSALab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Character {
public:
    string name;
    int health;
    int attackPower;
    int defensePower;


    Character(string name, int attack, int defense)
        : name(name), health(100), attackPower(attack), defensePower(defense) {
    }

    string getName() const { return name; }
    int getHealth() const { return health; }
    int getAttackPower() const { return attackPower; }
    int getDefensePower() const { return defensePower; }

    virtual void performDefense() = 0;
    virtual void doAttackOn(Character& target) = 0;

    void takeDamage(int damage) {
        health = health - damage;
        if (health < 0)
            health = 0;
    }

    void heal(int healthamount) {
        health = health + healthamount;
        cout << name << "HEALS " << healthamount << "Total health: " << health << endl;
    }

    virtual ~Character() {}
};


class CloseCombatant : public Character {
public:
    CloseCombatant(string name, int attack, int defense) : Character(name, attack, defense) {}
    void performDefense() {
        cout << name << ": Blocking with armor! Defense: " << defensePower << endl;
    }
};

class Marksman : public Character {
public:
    Marksman(string name, int attack, int defense) : Character(name, attack, defense) {}
    void performDefense() {
        cout << name << ": Keeping distance! Defense: " << defensePower << endl;
    }
};

class Spellcaster : public Character {
public:
    Spellcaster(string name, int attack, int defense) : Character(name, attack, defense) {}
    void performDefense() {
        cout << name << ": Using magic shield! Defense: " << defensePower << endl;
    }
};

class ShieldBearer : public CloseCombatant {
public:
    ShieldBearer(string name, int attack, int defense) : CloseCombatant(name, attack, defense) {}
    void doAttackOn(Character& target) {
        int baseattack = attackPower;
        cout << name << ": Swinging shield! Raw attack: " << baseattack << endl;
        target.performDefense();
        int finalattack = baseattack - target.getDefensePower();
        if (finalattack < 0) finalattack = 0;
        cout << " Damage dealt to " << target.getName() << ": " << finalattack << endl;
        target.takeDamage(finalattack);
    }
};

class SneakAttacker : public CloseCombatant {
public:
    SneakAttacker(string name, int attack, int defense) : CloseCombatant(name, attack, defense) {}
    void doAttackOn(Character& target) {
        int baseattack = attackPower * 2;
        cout << name << ": Striking from shadows! Raw attack: " << baseattack << endl;
        target.performDefense();
        int finalattack = baseattack - target.getDefensePower();
        if (finalattack < 0) finalattack = 0;
        cout << "Damage dealt to " << target.getName() << ": " << finalattack << endl;
        target.takeDamage(finalattack);
    }
};

class Archer : public Marksman {
public:
    Archer(string n, int a, int d) : Marksman(n, a, d) {}
    void doAttackOn(Character& target) {
        int baseattack = attackPower;
        cout << name << ": Firing arrow! Raw attack: " << baseattack << endl;
        target.performDefense();
        int finalattack = baseattack - target.getDefensePower();
        if (finalattack < 0) finalattack = 0;
        cout << "Damage dealt to " << target.getName() << ": " << finalattack << endl;
        target.takeDamage(finalattack);
    }
};

class Healer : public Spellcaster {
public:
    Healer(string n, int a, int d) : Spellcaster(n, a, d) {}
    void doAttackOn(Character& target) {
        cout << name << ": Healing self! Restoring " << attackPower << " health" << endl;
        heal(attackPower);
    }
};

class Firecaster : public Spellcaster {
public:
    Firecaster(string n, int a, int d) : Spellcaster(n, a, d) {}
    void doAttackOn(Character& target) {
        int baseattack = (attackPower * 3) / 2;
        cout << name << ": Casting fire blast! Raw attack: " << baseattack << endl;
        target.performDefense();
        int finalattack = baseattack - target.getDefensePower();
        if (finalattack < 0) finalattack = 0;
        cout << "Damage dealt to " << target.getName() << ": " << finalattack << endl;
        target.takeDamage(finalattack);
    }
};


Character* createCharacter(int choice, string name, int attack, int defense) {
    switch (choice) {
    case 1: return new ShieldBearer(name, attack, defense);
    case 2: return new SneakAttacker(name, attack, defense);
    case 3: return new Archer(name, attack, defense);
    case 4: return new Healer(name, attack, defense);
    case 5: return new Firecaster(name, attack, defense);
    default: return nullptr;
    }
}


int main() {
    cout << "Choose a character type:" << endl;
    cout << "1) ShieldBearer (Close combat)" << endl;
    cout << "2) SneakAttacker (Close combat, 2x attack)" << endl;
    cout << "3) Archer (Marksman)" << endl;
    cout << "4) Healer (Spellcaster, heals instead of attacking)" << endl;
    cout << "5) Firecaster (Spellcaster, 1.5x attack)" << endl;

    int choice1, choice2, attack1, defense1, attack2, defense2;
    string name1, name2;

    cout << "Select type for 1st character (1-5):" << endl;
    cin >> choice1;
    cout << "Enter name for 1st character:" << endl;
    cin >> name1;
    cout << "Enter attack power:" << endl;
    cin >> attack1;
    cout << "Enter defense power:" << endl;
    cin >> defense1;

    Character* c1 = createCharacter(choice1, name1, attack1, defense1);

    cout << "Select character type for 2nd character:" << endl;
    cin >> choice2;
    cout << "Enter name for 2nd character:" << endl;
    cin >> name2;
    cout << "Enter attack power:" << endl;
    cin >> attack2;
    cout << "Enter defense power:" << endl;
    cin >> defense2;

    Character* c2 = createCharacter(choice2, name2, attack2, defense2);
    if (!c1 || !c2) { cout << "Invalid input." << endl; }
    cout << " Battle begins: " << c1->getName() << " VS " << c2->getName() << endl;

    Character* attacker = c1;
    Character* defender = c2;
    int turn = 1;

    while (c1->getHealth() > 0 && c2->getHealth() > 0) {
        cout << "---Turn " << turn << "---" << endl;
        cout << attacker->getName() << " attacks " << endl;
        attacker->doAttackOn(*defender);
        cout << defender->getName() << "'s health: " << defender->getHealth() << endl;

        if (defender->getHealth() <= 0) {
            cout << defender->getName() << " has fallen " << endl;
            cout << attacker->getName() << " wins the battle " << endl;
            break;
        }

        Character* temp = attacker;
        attacker = defender;
        defender = temp;
        turn++;
    }
    if (c1->getHealth() <= 0 && c2->getHealth() <= 0) {
        cout << " Both fighters have fallen! It's a tie. " << endl;
    }  delete c1;
    delete c2;
}
