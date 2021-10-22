#include "db.h"

//TO DO settery mogly by cos zwracac tak bysmy mieli informacje o powodzeniu operacji
//TO DO enumy zamiast stringów do indeksowania map

namespace  storage{
    DbHelper::DbHelper()
    {

    }

    const std::optional<int> DbStorage::getCoffee(const std::string coffeeType) const
    {
        auto coffeeInf = coffee.find(coffeeType);
        if(coffeeInf == coffee.end()){
            return coffeeInf->second;
        }else{
           return std::nullopt;
        }
    }

    void DbStorage::setCoffee(const std::string &coffeeType, const int amount)
    {
        auto coffeeInf = coffee.find(coffeeType);
        if(coffeeInf != coffee.end()){
            coffeeInf->second = amount;
        }
    }

    const std::optional<int> DbStorage::getCoins(const float coinType) const
    {
        auto coinInf = coins.find(coinType);
        if(coinInf == coins.end()){
            return coinInf->second;
        }else{
           return std::nullopt;
        }
    }

    void DbStorage::setCoins(const float &coinType, const int amount)
    {
        auto coinInf = coins.find(coinType);
        if(coinInf != coins.end()){
            coinInf->second = amount;
        }
    }

    const std::optional<float> DbStorage::getMilk(const std::string milkType) const
    {
        auto milkInf = milk.find(milkType);
        if(milkInf == milk.end()){
            return milkInf->second;
        }else{
           return std::nullopt;
        }
    }

    void DbStorage::setMilk(const std::string &milkType, const float amount)
    {
        auto milkInf = milk.find(milkType);
        if(milkInf != milk.end()){
           milkInf->second = amount;
        }
    }

    const std::optional<float> DbStorage::getWater(const std::string waterType) const
    {
        auto waterInf = water.find(waterType);
        if(waterInf != water.end()){
            return waterInf->second;
        }else{
            return std::nullopt;
        }
    }

    void DbStorage::setWater(const std::string waterType, const float amount)
    {
        auto waterInf = water.find(waterType);
        if(waterInf != water.end()){
           waterInf->second = amount;
        }
    }


    void DbStorage::populateStorage()
    {
        setCoffee("Indonesia Arabica",rand()%(maxCoffee+1));
        setCoffee("Brazil Arabica",rand()%(maxCoffee+1));
        setCoffee("Ethiopia  Arabica",rand()%(maxCoffee+1));
        setCoffee("Vietnam Robusta",rand()%(maxCoffee+1));
        setCoffee("Indonesia Robusta",rand()%(maxCoffee+1));
        setCoffee("Excelsa",rand()%(maxCoffee+1));
        setCoffee("Liberica",rand()%(maxCoffee+1));


        setCoins(0.01,rand()%(maxChange+1));
        setCoins(0.02,rand()%(maxChange+1));
        setCoins(0.05,rand()%(maxChange+1));
        setCoins(0.10,rand()%(maxChange+1));
        setCoins(0.50,rand()%(maxChange+1));
        setCoins(1,rand()%(maxChange+1));
        setCoins(2,rand()%(maxChange+1));
        setCoins(5,rand()%(maxChange+1));

        setMilk("Regular",rand()%(maxMilk+1));
        setMilk("Soy",rand()%(maxMilk+1));

        setWater("Regular",rand()%(maxWater+1));

        setStatus("BrewBasket",false);
        setStatus("Decanter",false);
        setStatus("WarmingPlate",false);
        setStatus("GrindingChamber",false);
        setStatus("TurnOn",false);
        setStatus("Clean",false);
        setStatus("LightOn",false);
        setStatus("PowerSafe",false);
        setStatus("Locks",false);
        setStatus("Water",false);
        setStatus("Milk",false);
        setStatus("Change",false);
        setStatus("Coffee",false);
        setStatus("Unknown",false);



    }

    void DbUsers::populateUsers(){
        addOrChangeUser("admin",true,4321);
        addOrChangeUser("user",false,1234);
    }

    const std::optional<bool> DbUsers::isAdmin(const std::string userName)
    {
        auto user = users.find(userName);
        if(user!=users.end()){
            std::pair<bool,int> userPair = user->second;
            return userPair.first;
        }else{
            return std::nullopt;
        }

    }

    const std::optional<bool> DbUsers::isPinCorrect(const std::string userName, const int pin) const
    {
        auto user = users.find(userName);
        if(user == users.end()){
            return std::nullopt;
        }
        std::pair<bool,int> userPair = user->second;
        return userPair.second == pin;

    }


    void DbUsers::addOrChangeUser(const std::string &userName, const bool &adminPrivliges, const int &pin)
    {
        users[userName] = std::pair<bool,int>(adminPrivliges,pin);
    }


}
