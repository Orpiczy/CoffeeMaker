#ifndef DB_H
#define DB_H
#include <map>

namespace  storage{

//TO DO wzorce projektowe, zaimplementuj te zajebiste settery i gettery wygladajace jak zmienne
//TO DO porozdzielaj to db na osobne pliki

struct DbStorage{

    DbStorage(){populateStorage();}

    const std::optional<int> getCoffee(const std::string coffeeType) const;
    void setCoffee(const std::string &coffeeType, const int amount);

    const std::optional<int> getCoins(const float coinType) const;
    void setCoins(const float &coinType, const int amount);

    const std::optional<float> getMilk(const std::string milkType) const;
    void setMilk(const std::string &milkType, const float amount);

    const std::optional<float> getWater(const std::string waterType = "Regular") const;
    void setWater(const std::string $waterType, const float amount);

    const  std::optional<bool> getStatus(const std::string element) const;
    void setStatus(const std::string &param,const bool newStatus);
    void changeStatus(const std::string param);


private:
    void populateStorage();

    std::map<std::string,int> coffee;
    std::map<float,int> coins;
    std::map<std::string,float> milk;
    std::map<std::string,float> water;
    std::map<std::string,bool> status;
    std::map<std::string,int> users;
    static const int maxCoffee = 10000;
    static const int maxChange = 20;
    static const int maxMilk = 10;
    static const int maxWater = 50;
};

struct DbUsers{
    DbUsers(){populateUsers();}
    std::map<std::string,std::pair<bool,int>> users;
    const std::optional<bool> isAdmin(const std::string userName);
    const std::optional<bool> isPinCorrect(const std::string userName, const int pin) const;

private:
    void populateUsers();
    void addOrChangeUser(const std::string &userName, const bool &isAdmin, const int &pin);
};

class DbHelper
{
public:
    DbHelper();

    const int &getCoffee(const std::string coffeeType) const;
    void setCoffee(const std::string &coffeeType, const int &amount);

    const int &getChange() const;
    void setChange(const float &coinType, const int &amount);

    const float &getMilk() const;
    void setMilk(const std::string &milkType, const float &amount);

    const float &getWater() const;
    void setWater(const std::string $waterType, const float &amount);

    const  bool& getStatus() const;
    void setStatus(const std::string &param,const bool &newStatus);
    void changeStatus(const std::string &param);

    void addUser(const std::string &user, const int &pin);
    void checkUser(const std::string &user, const int &pin);

private:
    DbStorage storage;


};

}
#endif // DB_H
