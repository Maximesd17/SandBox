#include <criterion/criterion.h>
#include "MapGenerator.hpp"

Test(mapGenerator_valid, small) {
    std::string file = "./maps/small.txt";
    SandBox::MapGenerator mg(file);

    cr_assert(mg.isValid(), "Expected true but isValid() returns false");
}

Test(mapGenerator_valid, medium) {
    std::string file = "maps/medium.txt";
    SandBox::MapGenerator mg(file);

    cr_assert(mg.isValid(), "Expected true but isValid() returns false");
}

Test(mapGenerator_valid, large) {
    std::string file = "maps/large.txt";
    SandBox::MapGenerator mg(file);

    cr_assert(mg.isValid(), "Expected true but isValid() returns false");
}

Test(mapGenerator_valid, tests) {
    std::string file = "maps/tests.txt";
    SandBox::MapGenerator mg(file);

    cr_assert(mg.isValid(), "Expected true but isValid() returns false");
}

Test(mapGenerator_invalid, size) {
    std::string file = "maps/invalid/inconsistent_size.txt";
    SandBox::MapGenerator mg(file);

    cr_assert(!mg.isValid(), "Expected false but isValid() returns true");
}

Test(mapGenerator_invalid, missing_air) {
    std::string file = "maps/invalid/no_air.txt";
    SandBox::MapGenerator mg(file);

    cr_assert(!mg.isValid(), "Expected false but isValid() returns true");
}

Test(mapGenerator_invalid, missing_end) {
    std::string file = "maps/invalid/no_end.txt";
    SandBox::MapGenerator mg(file);

    cr_assert(!mg.isValid(), "Expected false but isValid() returns true");
}

Test(mapGenerator_invalid, missing_ground) {
    std::string file = "maps/invalid/no_ground.txt";
    SandBox::MapGenerator mg(file);

    cr_assert(!mg.isValid(), "Expected false but isValid() returns true");
}

Test(mapGenerator_invalid, missing_spawn) {
    std::string file = "maps/invalid/no_spawn.txt";
    SandBox::MapGenerator mg(file);

    cr_assert(!mg.isValid(), "Expected false but isValid() returns true");
}

Test(mapGenerator_invalid, too_many_ends) {
    std::string file = "maps/invalid/too_many_ends.txt";
    SandBox::MapGenerator mg(file);

    cr_assert(!mg.isValid(), "Expected false but isValid() returns true");
}

Test(mapGenerator_invalid, too_many_spawns) {
    std::string file = "maps/invalid/too_many_spawns.txt";
    SandBox::MapGenerator mg(file);

    cr_assert(!mg.isValid(), "Expected false but isValid() returns true");
}