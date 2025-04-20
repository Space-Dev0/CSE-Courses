#include <iostream>
#include <string>
#include <vector>
struct item
{
    int ID;
    std::string name;
};

template <typename T>
class InventoryBox
{
private:
    T Items[5];
    int count{0};

public:
    void setCount() { count = 0; }
    void addItem(T item)
    {
        if (count >= 5)
        {
            std::cout << "err: Inventory full!\n";
            return;
        }
        Items[count] = item;
        count++;
    }
    void displayItems()
    {
        for (int i = 0; i < count; i++)
            std::cout << " ID: " << Items[i].ID << ", Name: " << Items[i].name << "\n";
    }
};

template <typename T>
class BaseStats
{
protected:
    T stats[3];

public:
    BaseStats(T h, T s, T d)
    {
        stats[0] = h;
        stats[1] = s;
        stats[2] = d;
    }
    void setStats(T h, T s, T d)
    {
        stats[0] = h;
        stats[1] = s;
        stats[2] = d;
    }
    void displayBaseStats()
    {
        std::cout << "Health: " << stats[0]
                  << ", Strength: " << stats[1]
                  << ", Defense: " << stats[2] << "\n";
    }
};

template <typename T>
class ExtendedStats : public BaseStats<T>
{
private:
    T speed, agility;

public:
    ExtendedStats(T h, T s, T d, T sp, T ag) : BaseStats<T>(h, s, d), speed(sp), agility(ag) {}

    void setExtendedStats(T h, T s, T d, T sp, T ag)
    {
        setStats(h, s, d);
        speed = sp;
        agility = ag;
    }

    double computeAverage()
    {
        return (BaseStats<T>::stats[0] + BaseStats<T>::stats[1] + BaseStats<T>::stats[2] + speed + agility) / 5.0;
    }

    void displayAllStats()
    {
        BaseStats<T>::displayBaseStats();
        std::cout << "Speed: " << speed << ", Agility: " << agility << "\n";
    }
};

int main()
{
    int Pcount{0};
    std::vector<ExtendedStats<double>> Pstats;
    std::vector<InventoryBox<item>> Inventory;

    while (true)
    {
        std::cout << "Enter num of players (Max 10) : ";
        std::cin >> Pcount;
        if (Pcount > 10 || Pcount < 1)
        {
            std::cout << "err: Player Count should be between 1-10\n";
            continue;
        }
        break;
    }

    for (int i = 0; i < Pcount; i++)
    {
        double h{0}, s{0}, d{0}, sp{0}, ag{0};
        int nItems{0};
        std::cout << "\n---Player " << i + 1 << "---\n";
        std::cout << "Enter health, strength, defense, speed, agility: ";
        std::cin >> h >> s >> d >> sp >> ag;

        ExtendedStats S(h, s, d, sp, ag);
        Pstats.push_back(S);

        while (true)
        {
            std::cout << "Enter number of items (max 5): ";
            std::cin >> nItems;
            if (nItems > 5 || nItems < 1)
            {
                std::cout << "err: No. of Items should be less than or equal to 5\n";
                continue;
            }
            break;
        }
        InventoryBox<item> Inv;
        for (int i = 0; i < nItems; i++)
        {
            item it;
            std::cout << "Enter Item ID " << i + 1 << ": ";
            std::cin >> it.ID;
            std::cout << "Enter Item name (no spaces): ";
            std::cin >> it.name;
            Inv.addItem(it);
        }
        Inventory.push_back(Inv);
    }

    for (int i = 0; i < Pcount; i++)
    {
        std::cout << "\n\n===Player " << i + 1 << "===\n";
        Pstats[i].displayAllStats();
        std::cout << "Average: " << Pstats[i].computeAverage() << "\n";
        std::cout << "Inventory: \n";
        Inventory[i].displayItems();
    }

    return 0;
}