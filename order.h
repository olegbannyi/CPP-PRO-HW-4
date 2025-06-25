#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

struct Item
{
    std::string name;
    double price;
};

class Order
{
  private:
    int id_;
    std::vector<Item> items_;
    double totalPrice_;
    std::string status_;

  public:
    explicit Order(int id);
    int getId() const;
    std::vector<Item> getItems() const;
    double getTotalPrice() const;
    void setTotalPrice(double totalPrice);
    std::string getStatus() const;
    void setStatus(const std::string &);
    void addItem(const Item);
};

#endif // ORDER_H
