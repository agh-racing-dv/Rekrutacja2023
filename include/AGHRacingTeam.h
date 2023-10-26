#include <vector>
#include <string>

#include <stdexcept>
#include <algorithm>

struct Member
{
    std::string name;
    int height;
    int yearOfJoining;

    Member(std::string name, int height, int yearOfJoining) : name(name), height(height), yearOfJoining(yearOfJoining){};

};

class AGHRacingTeam
{
public:
    AGHRacingTeam(){}

    AGHRacingTeam(const std::vector<Member>& newMembers) {
        for (const auto& member : newMembers) {
            if (isValidMember(member)) {
                members.push_back(member);
            }
        }
    }

    bool isValidMember(const Member& member){
        bool shouldAdd = true;
        if (!(typeid(member.height) == typeid(int) && typeid(member.yearOfJoining) == typeid(int) && typeid(member.name) == typeid(std::string))) {  // && !name.empty()
            throw std::invalid_argument("Invalid input data. Check data types and non-empty string.");
        }
        if(!(100 <= member.height && member.height <= 250)) {
            shouldAdd = false;
        }
        if(!(2000 <= member.yearOfJoining && member.yearOfJoining <= 2023)){
            shouldAdd = false;
        }
        if(member.name.length() >= 20){
            shouldAdd = false;
        }
        if(!std::isupper(member.name[0])){
            shouldAdd = false;
        }
        if (!std::all_of(member.name.begin(), member.name.end(), ::isalnum)) {
            shouldAdd = false;
        }

        return shouldAdd;
    }

    std::vector<Member> getMembers() { return members; }

    /**
     * Add new member to the members array only when input is valid.
     */
    void addMember(std::string name, int height, int yearOfJoining);

    /**
     * Return list of names sorted by height of team members in ascending order.
     */
    std::vector<std::string> getMembersSortedByHeightAsc();

    /**
     * Return number of members who joined the team in leap year.
     */
    int getNumberOfMembersWhoJoinedInLeapYear();

    /**
     * Return maximum number of members who joined in the same year.
    */
    int getMaxNumberOfJoinedInTheSameYear();

private:
    std::vector<Member> members;
};