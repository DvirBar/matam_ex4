//
//  Vampire.h
//  matam_ex4
//
//  Created by Dvir Bartov on 14/06/2022.
//

#ifndef Vampire_h
#define Vampire_h

#include <string>
#include "Battle.h"

const std::string NAME = "Vampire";
const int FORCE = 10;
const int DAMAGE_UPON_LOSS = 10;
const int COINS = 2;
const bool IS_DRAGON = false;

class Vampire: public Battle {
public:
    Vampire();
    
    // TODO: constructors?
    Vampire(const Vampire& vampire) = default;
    ~Vampire() = default;
};

#endif /* Vampire_h */
