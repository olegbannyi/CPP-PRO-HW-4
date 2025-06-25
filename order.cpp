#include "order.h"
#include <string>
#include <vector>

Order::Order(int id) : id_(id), status_("initial")
{
}

int Order::getId() const
{
    return id_;
}

std::vector<Item> Order::getItems() const
{
    return items_;
}

double Order::getTotalPrice() const
{
    return totalPrice_;
}

void Order::setTotalPrice(double totalPrice)
{
    totalPrice_ = totalPrice;
}

std::string Order::getStatus() const
{
    return status_;
}

void Order::setStatus(const std::string &status)
{
    status_ = status;
}

void Order::addItem(const Item item)
{
    items_.push_back(item);
}