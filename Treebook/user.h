/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
    User(const std::string& name);
    void add_friend(const std::string& name);
    std::string get_name() const;
    size_t size() const;
    void set_friend(size_t index, const std::string& name);

    /* Part 1 */
    friend std::ostream& operator<<(std::ostream& os, const User& user);

    /* Part 2 */
    ~User(); // Destructor
    User(const User& user); // Copy constructor
    User& operator=(const User& user); // Copy assignment operator
    User(User&& user) = delete; // Delete move constructor
    User& operator=(User&& user) = delete; // Delete move assignment operator

    /* Part 3 */
    User& operator+=(User& other);  // Compound assignment operator
    bool operator<(const User& other) const; // Comparison operator

private:
    std::string _name;
    std::string* _friends;
    size_t _size;
    size_t _capacity;
};