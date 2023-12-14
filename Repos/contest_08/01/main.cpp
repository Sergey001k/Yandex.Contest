#include <iostream>

class Keeper {
    int trash;
    int secret;

public:
    Keeper() {
        std::cin >> secret;
    }
};

class Hack_Keeper {
public:
    int trash;
    int secret;
};


int hack_it(Keeper keeper) {
    Hack_Keeper* hack = reinterpret_cast<Hack_Keeper*>(&keeper);
    return hack->secret;
}

int main() {
    Keeper keeper;
    int secret = hack_it(keeper);
    std::cout << secret;
}