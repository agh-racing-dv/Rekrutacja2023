#include "../include/AGHRacingTeam.h"

#include <string>
#include <cctype>
#include <algorithm>
#include <typeinfo>
#include <stdexcept>

void AGHRacingTeam::addMember(std::string name, int height, int yearOfJoining)
{
    bool shouldAdd = true;
    if (!(typeid(height) == typeid(int) && typeid(yearOfJoining) == typeid(int) && typeid(name) == typeid(std::string) && !name.empty())) {
        throw std::invalid_argument("Invalid input data. Check data types and non-empty string.");
    }
    if(!(100 <= height && height <= 250)) {
        shouldAdd = false;
    }
    if(!(2000 < yearOfJoining && yearOfJoining <= 2023)){
        shouldAdd = false;
    }
    if(name.length() >= 20){
        shouldAdd = false;
    }
    if(!std::isupper(name[0])){
        shouldAdd = false;
    }
    if (!std::all_of(name.begin(), name.end(), ::isalnum)) {
        shouldAdd = false;
    }

    if(shouldAdd) {
        members.emplace_back(std::move(name), height, yearOfJoining);
    }
}

std::vector<std::string> AGHRacingTeam::getMembersSortedByHeightAsc()
{
    // add your code here
    return std::vector<std::string>();
}

int AGHRacingTeam::getNumberOfMembersWhoJoinedInLeapYear()
{
    // add your code here
    return 0;
}

int AGHRacingTeam::getMaxNumberOfJoinedInTheSameYear()
{
    // add your code here
    return 0;
}