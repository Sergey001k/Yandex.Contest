#include<iostream>
#include<string>
#include<map>


std::map<std::string, double> bonuses;

#include <cmath>
class Employee
{
protected:
    std::string name, post;
    int money;

public:
    Employee(std::string name, std::string post, int money) {
        this->name = name;
        this->post = post;
        this->money = money;
    }

    virtual int bonus(float percent) const{
        return round(percent * money);
    }

    int salary() {
        return bonus(bonuses[post]) + money;
    }

    friend std::ostream& operator<<(std::ostream& out, const Employee& emp) {
        out << emp.name << " (" << emp.post << "): " << emp.money + emp.bonus(bonuses[emp.post]);
        return out;
    }

};

class Manager : public Employee 
{
public:
    Manager(std::string name, int money = 16242)
        :Employee(name, "manager", money) {}

    int bonus(float percent) const override {
        if (percent < 0.1) {
            percent = 0.1;
        }
        return round(money * percent);
    }

};



class Boss : public Employee {
public:
    Boss(std::string name, int money = 16242)
        :Employee(name, "boss", money) {
    }
};

int main() {
    double boss_bonus, manager_bonus;
    std::cin >> boss_bonus >> manager_bonus;
    bonuses["manager"] = manager_bonus;
    bonuses["boss"] = boss_bonus;

    int john_money, bob_money, alice_money;
    std::cin >> john_money >> bob_money >> alice_money;
    Boss john("John", john_money);
    Manager bob("Bob", bob_money);
    Manager alice("Alice", alice_money);

    std::cout << john << '\n' << bob << '\n' << alice << std::endl;
}