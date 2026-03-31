
#include <stdio.h>
#include "dice.h"

// TODO: define the struct called Armor with the following fields
// - id: character array of 20
// - armor_class: an integer
struct Armor;

// TODO: define the struct called AttackType with the following fields
// - id: character array of 20
// - dice_count: should be an integer
// - dice_type: use the DiceType enum from dice.h
// - damage_bonus: an other integer
struct AttackType;

// TODO: a struct called Creature with the following fields
// - id: character array of 20
// - hp: an integer holding the health points of the creature
// - attack_bonus: an other integer
// - armor: a field with type Armor
// - attack_type: a field with type AttackType
struct Creature;

// TODO: implement the following function that takes a file handle and parses
// input in the format <id> <armor_class>. It should use the fscanf function for
// parsing and return an Armor. For example:
//
//   "leather 11"
//
// means a leather armor (id) with armor class 11. The id of the armor doesn't
// have whitespace characters in it.
struct Armor parse_armor(FILE *fp);

// TODO: implement the following function that takes a file handle and parses
// the input in <id> <dice_count> <dice_type> <bonus> format. It should use the
// fscanf function for parsing and return an AttackType. For example:
//
//   "dagger 1 D4 2"
//
// means a dagger (id) with damage defined as 1d4+2. The id of the attack type
// doesn't have whitespace characters in it.
struct AttackType parse_attack_type(FILE *fp);

// TODO: implement the following function that takes a file handle and parses
// input in the format of <id> <hp> <attack_bonus> <armor_id> <attack_type_id>.
//
// The function should use fscanf to parse the line and return a Creature.
// For example the line
//
//   "Hero   30 6 leather    dagger"
//
// translates to a creature with id 'Hero' having 30 hp, and an attack bonus
// of 6. He is equipped with leather armor and a dagger. You can suppose that an
// armor with the id 'leather' is provided in the armors array, as well as an
// attack type with the id 'dagger'. You need to look them up by their ids; you
// can use the `strcmp` function for that. The id of the creature doesn't
// contain whitespace characters.
struct Creature parse_creature(
    FILE *fp, 
    struct Armor armors[], int armor_count,
    struct AttackType attack_types[], int attack_type_count
);

// TODO: using the `roll` function from dice.h implement the fight between
// two creatures as follows.
// - The fight is turn-based. c1 attacks first, then c2, and they
//   alternate until one of them is reduced to 0 hit points or below.
// - On its turn, the attacker makes an attack roll using a single D20 dice and
//   its own attack bonus. (Use the provided roll function).
// - The attack hits if the attack roll is greater than or equal to the
//   defender's armor class.
// - On a hit, damage is computed from the attacker's AttackType using the
//   dice rolling function again, but this time you 'roll' with the values
//   stored in the AttackType (dice type, count and damage_bonus).
//   The defender's hp is then reduced by this damage value.
// - If, after taking damage, a creature's hp reaches 0 the fight ends
// immediately
//   and the attacking creature is considered the winner.
// - The function returns the pointer to the winner.
struct Creature *fight(struct Creature *c1, struct Creature *c2);

// TODO: main should take a filename argument, open the file, parse
// its contents and simulate the fights. Print out the first character
// of the winner of each fight.
int main(int argc, char *argv[]);
