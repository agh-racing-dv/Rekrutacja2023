#include "../include/AGHRacingTeam.h"

#include <string>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <map>

void AGHRacingTeam::addMember(std::string name, int height, int yearOfJoining)
{
    bool shouldAdd = true;
    if (!(typeid(height) == typeid(int) && typeid(yearOfJoining) == typeid(int) && typeid(name) == typeid(std::string))) {  // && !name.empty()
        throw std::invalid_argument("Invalid input data. Check data types and non-empty string.");
    }
    if(!(100 <= height && height <= 250)) {
        shouldAdd = false;
    }
    if(!(2000 <= yearOfJoining && yearOfJoining <= 2023)){
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
    if(members.empty()){
        throw std::runtime_error("No members in the team");
    }
    std::vector<std::pair<int, std::string>> temp; // aka #include <map>, & not coping elements
    for (const auto &member : members) {
        temp.emplace_back(member.height, member.name);
    }

    std::sort(temp.begin(), temp.end());

    std::vector<std::string> sortedNames;
    for (const auto &item : temp) {
        sortedNames.push_back(item.second);
    }

    return sortedNames;
}

int AGHRacingTeam::getNumberOfMembersWhoJoinedInLeapYear()
{
    if(members.empty()){
        throw std::runtime_error("No members in the team");
    }
    int leapJoinCounter = 0;
    for (const auto &member : members) {
        if(member.yearOfJoining % 4 == 0){
            leapJoinCounter++;
        }
    }
    return leapJoinCounter;
}

int AGHRacingTeam::getMaxNumberOfJoinedInTheSameYear()
{
    if(members.empty()){
        throw std::runtime_error("No members in the team");
    }

    std::map<int, int> yearNOJoins;
    for (const auto &member : members) {
        yearNOJoins[member.yearOfJoining]++;
    }

    int maxValue = 0;
    for (const auto &yearJoinsPairs : yearNOJoins) {
        if (yearJoinsPairs.second > maxValue) {
            maxValue = yearJoinsPairs.second;
        }
    }

    return maxValue;
}
