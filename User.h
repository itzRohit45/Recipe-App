#include <string>
#include <fstream>
using namespace std;

class User
{
    friend istream &operator>>(istream &, User &);
    friend ostream &operator<<(ostream &, const User &);

private:
    string username;
    string password;

public:
    User(string = "alice", string = "alice@45");
    string getUsername() const;
    string getPass() const;
    void setUserToNull();
    void setPass(const string &);
    void setName(const string &);
};

bool login(const string &, const string &);
void signUp(User &);
int handleLogin(User &);
int handleSignup(User &);
void test(User &);