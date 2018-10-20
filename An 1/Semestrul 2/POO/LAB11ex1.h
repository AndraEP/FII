#include <string>
#include <list>
#include <set>

using namespace std;

class Contact
{
  public:
    string Name;
    virtual string GetType() = 0;
};

class Friend : public Contact
{
  public:
    string Birthday;
    string Number;
    string Address;
    string GetType() {return "Friend";}
};

class Acquaintance : public Contact
{
  public:
    string Number;
    string GetType() {return "Acquaintance";}
};

class Colleague : public Contact
{
  public:
    string Number;
    string Company;
    string Adresa;
    string GetType () {return "Colleague";}
};

class Agenda
{
  public:
    set <Contact*> Entries;

    Contact* SearchByName (string Name)
    {
        for (auto it : Entries)
        {
            if (Name == it->Name) return it;
        }
        return 0;
    }

    list <Friend> Friends()
    {
        list <Friend> tmp;
        for (auto it : Entries)
        {
            if (it->GetType() == "Friend") tmp.push_back (*(dynamic_cast <Friend*> (it)));
        }
        return tmp;
    }

    bool Delete (string Name)
    {
        for (auto it : Entries)
        {
            if (it->Name == Name)
            {
                Entries.erase (it);
                return 1;
            }
        }
        return 0;
    }

    bool Add (Contact* other)
    {
        Entries.insert (other);
        return 1;
    }
};
