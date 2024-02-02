#include <iostream>
#include <vector>
#include <memory>

class ShopItem 
{
public:
    ShopItem(int id, const std::string& name, double price) : id_(id), name_(name), price_(price) {}

    int getId() const 
    { 
        return id_; 
    }
    std::string getName() const 
    { 
        return name_; 
    }
    double getPrice() const 
    { 
        return price_; 
    }

private:
    int id_;
    std::string name_;
    double price_;
};

class ShopOrder 
{
public:
    ShopOrder() : totalCost_(0.0) {}

    void addItem(std::shared_ptr<ShopItem> item, int quantity) 
    {
        items_.push_back(std::make_pair(item, quantity));
        totalCost_ += (item->getPrice() * quantity);
    }

    double getTotalCost() const 
    { 
        return totalCost_; 
    }

    void displayOrder() const 
    {
        std::cout << "Замовлення:\n";

        for (const auto& pair : items_) 
        {
            std::shared_ptr<ShopItem> item = pair.first;
            int quantity = pair.second;
            std::cout << "Назва товару: " << item->getName() << "\n";
            std::cout << "Ціна одиниці товару: " << item->getPrice() << "\n";
            std::cout << "Кількість: " << quantity << "\n";
            std::cout << "Загальна вартість: " << (item->getPrice() * quantity) << "\n";
            std::cout << "-----------------------------\n";
        }
        std::cout << "Загальна вартість замовлення: " << getTotalCost() << "\n";
    }

private:
    std::vector<std::pair<std::shared_ptr<ShopItem>, int>> items_;
    double totalCost_;
};

int main() 
{
    system("chcp 1251 > null");
    std::shared_ptr<ShopItem> item1 = std::make_shared<ShopItem>(1, "Ручка", 28.0);
    std::shared_ptr<ShopItem> item2 = std::make_shared<ShopItem>(2, "Зошит", 45.0);
    std::shared_ptr<ShopItem> item3 = std::make_shared<ShopItem>(3, "Книжка", 50.0);

    ShopOrder order;
    order.addItem(item1, 7);
    order.addItem(item2, 5);
    order.addItem(item3, 2);

    order.displayOrder();

    return 0;
}
