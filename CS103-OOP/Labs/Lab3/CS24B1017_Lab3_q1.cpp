#include <iostream>

class iceCream
{
protected:
    int t_cost{0};
};

class vanilla : virtual protected iceCream
{
protected:
    int v_cost;

public:
    vanilla(int v) : v_cost(v) {}
};

class butterscotch : virtual protected iceCream
{
protected:
    int b_cost;

public:
    butterscotch(int v) : b_cost(v) {}
};

class chocolate : virtual protected iceCream
{
protected:
    int c_cost;

public:
    chocolate(int v) : c_cost(v) {}
};

class mixin : virtual protected iceCream
{
protected:
    int nuts_cost;
    int sprinkles_cost;
    int cherries_cost;

public:
    mixin(int nu, int sp, int ch) : nuts_cost(nu), sprinkles_cost(sp), cherries_cost(ch) {}
};

class order : protected butterscotch, protected chocolate, protected vanilla, protected mixin
{
public:
    order(int v, int b, int c, int nu, int sp, int ch) : butterscotch(b), vanilla(v), chocolate(c), mixin(nu, sp, ch) {}
    void placeOrder(std::string fl, std::string tp)
    {
        if (fl == "Vanilla")
            t_cost = v_cost;
        else if (fl == "ButterScotch")
            t_cost = b_cost;
        else if (fl == "Chocolate")
            t_cost = c_cost;
        else
        {
            std::cout << "err: no such flavour\n";
            exit(1);
        }

        if (tp == "Nuts")
            t_cost += nuts_cost;
        else if (tp == "Sprinkles")
            t_cost += sprinkles_cost;
        else if (tp == "Cherries")
            t_cost += cherries_cost;
        else if (tp == "None")
            ;
        else
        {
            std::cout << "err: no such topping\n";
            exit(1);
        }
    }

    void displayTotalCost()
    {
        std::cout << "\nTotal cost of ice cream is Rs." << t_cost << "\n";
    }
};

int main()
{
    int v, b, c, nu, sp, ch;
    std::cout << "Enter price for flavours\n"
              << "Vanilla: ";
    std::cin >> v;
    std::cout << "ButterScotch: ";
    std::cin >> b;
    std::cout << "Chocolate: ";
    std::cin >> c;
    std::cout << "Enter price for toppings\n"
              << "Nuts: ";
    std::cin >> nu;
    std::cout << "Sprinkles: ";
    std::cin >> sp;
    std::cout << "Cherries: ";
    std::cin >> ch;

    order O(v, b, c, nu, sp, ch);
    std::string fl, tp;
    std::cout << "Give order: ";
    std::cin >> fl >> tp;

    O.placeOrder(fl, tp);
    O.displayTotalCost();
}
