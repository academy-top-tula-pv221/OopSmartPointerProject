#include <iostream>
#include "SmartPointerBeginner.h"
#include "SmartPointerCopy.h"
#include "SmartPointerUnique.h"
#include <memory>

using namespace std;

class User
{
    string name;
    int age;
public:
    User(string name, int age) : name{ name }, age{ age }
    {
        cout << "constr origin\n";
    }
    ~User()
    {
    }

    User(const User&)
    {

    }
    User& operator=(const User&)
    {

    }

    User(User&& u) 
    {
        this->name = u.name;
        this->age = u.age;
    }

    User& operator=(const User&& u)
    {
        this->name = u.name;
        this->age = u.age;
        return *this;
    }

    void Hello()
    {
        cout << "Hello " << name << "\n";
    }
};

SmartPointerUnique<User> GetPtr()
{
    SmartPointerUnique<User> s(new User("aaa", 111));
    return s;
}

User GetUser()
{
    User u("qqq", 333);
    return u;
}


int main()
{
    //SmartPointerUnique<User> u1(new User("Bob", 23));

    //unique_ptr<User> up(new User("Bob", 34));

    //SmartPointerUnique<User> u2;
    //GetPtr();

    User u1("aaa", 111);
    User u2("bbb", 222);

    u1.Hello();
    u2.Hello();

    std::swap(u1, u2);

    u1.Hello();
    u2.Hello();


    //User u3("aaa", 111);
        
    User u3 = u2;
    
    return 0;
}
