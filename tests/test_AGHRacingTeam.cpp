#include <gtest/gtest.h>
#include "../include/AGHRacingTeam.h"

TEST(AGHRacingTeamTest, AddMemberValidData)
{
    std::vector<std::string> names = {"Bolek", "Lolek", "Romek"};
    std::vector<int> heights = {165, 130, 170};
    std::vector<int> years = {2010, 2020, 2021};

    AGHRacingTeam team;
    for (int idx = 0; idx < names.size(); ++idx)
    {
        team.addMember(names[idx], heights[idx], years[idx]);
        ASSERT_EQ(team.getMembers().size(), idx + 1);
        ASSERT_EQ(team.getMembers()[idx].name, names[idx]);
        ASSERT_EQ(team.getMembers()[idx].height, heights[idx]);
        ASSERT_EQ(team.getMembers()[idx].yearOfJoining, years[idx]);
    }
}

TEST(AGHRacingTeamTest, AddMemberInvalidName)
{
    std::vector<std::string> names = {"bolek", "LolekLolekLolekLolek", ""};
    std::vector<int> heights = {165, 130, 170};
    std::vector<int> years = {2010, 2020, 2021};

    AGHRacingTeam team;
    for (int idx = 0; idx < names.size(); ++idx)
    {
        team.addMember(names[idx], heights[idx], years[idx]);
        ASSERT_EQ(team.getMembers().size(), 0);
    }
}

TEST(AGHRacingTeamTest, AddMemberInvalidHeight)
{
    std::vector<std::string> names = {"Bolek", "Lolek", "Romek"};
    std::vector<int> heights = {-2, 99, 270};
    std::vector<int> years = {2010, 2020, 2021};

    AGHRacingTeam team;
    for (int idx = 0; idx < names.size(); ++idx)
    {
        team.addMember(names[idx], heights[idx], years[idx]);
        ASSERT_EQ(team.getMembers().size(), 0);
    }
}

TEST(AGHRacingTeamTest, AddMemberInvalidYear)
{
    std::vector<std::string> names = {"Bolek", "Lolek", "Romek"};
    std::vector<int> heights = {165, 130, 170};
    std::vector<int> years = {1999, 2030, 0};

    AGHRacingTeam team;
    for (int idx = 0; idx < names.size(); ++idx)
    {
        team.addMember(names[idx], heights[idx], years[idx]);
        ASSERT_EQ(team.getMembers().size(), 0);
    }
}

TEST(AGHRacingTeamTest, NotSortedArrays)
{
    std::vector<std::string> names = {"Bolek", "Lolek", "Romek"};
    std::vector<int> heights = {165, 130, 170};
    std::vector<int> years = {2020, 2015, 2021};
    AGHRacingTeam team;
    for (int idx = 0; idx < names.size(); ++idx)
    {
        team.addMember(names[idx], heights[idx], years[idx]);
    }
    ASSERT_EQ(team.getMembersSortedByHeightAsc(), std::vector<std::string>({"Lolek", "Bolek", "Romek"}));

    team.addMember("Atomek", 140, 2022);
    ASSERT_EQ(team.getMembersSortedByHeightAsc(), std::vector<std::string>({"Lolek", "Atomek", "Bolek", "Romek"}));

    team.addMember("Tomek", 100, 2023);
    ASSERT_EQ(team.getMembersSortedByHeightAsc(), std::vector<std::string>({"Tomek", "Lolek", "Atomek", "Bolek", "Romek"}));
}

TEST(AGHRacingTeamTest, SortedArrays)
{
    std::vector<std::string> names = {"Bolek", "Lolek", "Romek"};
    std::vector<int> heights = {200, 222, 240};
    std::vector<int> years = {2020, 2015, 2021};
    AGHRacingTeam team;
    for (int idx = 0; idx < names.size(); ++idx)
    {
        team.addMember(names[idx], heights[idx], years[idx]);
    }
    ASSERT_EQ(team.getMembersSortedByHeightAsc(), std::vector<std::string>({"Bolek", "Lolek", "Romek"}));

    team.addMember("Atomek", 241, 2022);
    ASSERT_EQ(team.getMembersSortedByHeightAsc(), std::vector<std::string>({"Bolek", "Lolek", "Romek", "Atomek"}));
}

TEST(AGHRacingTeamTest, JoinedInLeapYear)
{
    std::vector<std::string> names = {"Bolek", "Lolek", "Romek"};
    std::vector<int> heights = {200, 222, 240};
    std::vector<int> years = {2020, 2000, 2021};
    AGHRacingTeam team;
    for (int idx = 0; idx < names.size(); ++idx)
    {
        team.addMember(names[idx], heights[idx], years[idx]);
    }
    ASSERT_EQ(team.getNumberOfMembersWhoJoinedInLeapYear(), 2);

    team.addMember("Atomek", 241, 2022);
    ASSERT_EQ(team.getNumberOfMembersWhoJoinedInLeapYear(), 2);

    team.addMember("Tomek", 216, 2016);
    ASSERT_EQ(team.getNumberOfMembersWhoJoinedInLeapYear(), 3);
}

TEST(AGHRacingTeamTest, MaxJoinedInTheSameYear)
{
    std::vector<std::string> names = {"A", "B", "C", "D", "E", "F", "G"};
    std::vector<int> heights = {200, 200, 200, 200, 200, 200, 200};
    std::vector<int> years = {2020, 2000, 2021, 2020, 2021, 2020, 2000};
    AGHRacingTeam team;
    for (int idx = 0; idx < names.size(); ++idx)
    {
        team.addMember(names[idx], heights[idx], years[idx]);
    }
    ASSERT_EQ(team.getMaxNumberOfJoinedInTheSameYear(), 3);

    team.addMember("X", 200, 2000);
    ASSERT_EQ(team.getMaxNumberOfJoinedInTheSameYear(), 3);

    team.addMember("Y", 200, 2000);
    ASSERT_EQ(team.getMaxNumberOfJoinedInTheSameYear(), 4);

    team.addMember("Z", 200, 2000);
    ASSERT_EQ(team.getMaxNumberOfJoinedInTheSameYear(), 5);
}