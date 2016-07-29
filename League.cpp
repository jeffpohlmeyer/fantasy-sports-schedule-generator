// This file contains the function definitions for the League class 

#ifndef LEAGUE_HPP
#define LEAGUE_HPP

#include "League.hpp"
#include <iostream>
#include <sstream>

// Default constructor - Not to be used
League::League() : divisions(2), num_teams(14), num_weeks(13) {
	teams.resize(14);
}

// Constructor with input
League::League(const int& divs, const int& n_teams, const int& n_weeks, const std::vector<Player>& team_list, const std::map<int, std::string>& names_list) : divisions(divs), num_teams(n_teams), num_weeks(n_weeks), teams(team_list), names(names_list) { }

// Copy constructor
League::League(const League& input) : divisions(input.divisions), num_teams(input.num_teams), num_weeks(input.num_weeks), teams(input.teams), names(input.names) {}

// Destructor
League::~League(){}

// Assignment operator
League& League::operator = (const League& input){
	if (this == &input)
		return *this;

	divisions = input.divisions;
	num_teams = input.num_teams;
	num_weeks = input.num_weeks;
	teams = input.teams;
	names = input.names;
	return *this;
}

// Getter functions
int League::Divisions() const{	// Get the number of divisions
	return divisions;
}

int League::Num_Teams() const{	// Get the number of teams
	return num_teams;
}

int League::Num_Weeks() const{	// Get the number of weeks
	return num_weeks;
}

std::vector<Player> League::Teams() const{	// Get the list of teams
	return teams;
}

std::map<int, std::string> League::TeamNames() const{	//Get the team names
	return names;
}

// Setter functions
void League::Divisions(const int& divs){	// Set the number of divisions
	divisions = divs;
}

void League::Num_Teams(const int& n_teams){	// Set the number of teams
	num_teams = n_teams;
	teams.resize(n_teams);
	std::cout << "The size of the vector holding the list of teams has been automatically resized." << std::endl;
}

void League::Num_Weeks(const int& n_weeks){	// Set the number of weeks
	num_weeks = n_weeks;
}

void League::Teams(const std::vector<Player>& team_list){	// Set the list of teams
	if (teams.size() == team_list.size())
		teams = team_list;
	else
		std::cout << "The vectors are not the same size." << std::endl;
}

void League::TeamNames(const std::map<int, std::string>& names_list){	// Set the names of the teams
	names = names_list;
}

// Function to print out the information as a string
std::string League::ToString() const{
	std::stringstream ss;
	ss << "Number of teams: " << num_teams << std::endl << "Number of weeks: " << num_weeks << std::endl << "Number of divisions: " << divisions << std::endl;
	ss << "Team List" << std::endl;
	for (std::map<int, std::string>::const_iterator iter = names.begin(); iter != names.end(); ++iter){
		ss << iter->second << std::endl;
	}
	return ss.str();
}

// Send to ostream
std::ostream& operator << (std::ostream& os, const League& input){
	os << input.ToString();
	return os;
}

#endif //! LEAGUE_HPP