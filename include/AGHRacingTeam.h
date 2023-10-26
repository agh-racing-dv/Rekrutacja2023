#include <vector>
#include <string>

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