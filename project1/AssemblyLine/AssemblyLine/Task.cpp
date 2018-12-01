#include "Task.h"

Task::Task(std::string &rhs) : Item(rhs) //Constructor
{
    this->pNextTask = nullptr;
}

void Task::RunProcess(std::ostream &os) //This function fills the last order on the order queue
{
    if (Orders.size() != 0)
    {
        if (Orders.back().getOrderFillState())
        {
            Orders.back().fillItem(*this, os);
        }
    }
}
bool Task::MoveTask() //This function moves the completed task to the next part of the assembly line
{
    if (Orders.back().getOrderFillState())
    {
        pNextTask->Orders.push_front(Orders.back());
        return true;
    }
    else if (Orders.size() == 0)
    {
        return false;
    }
    else
    {
        return false;
    }
}
void Task::setNextTask(Task &task) //Sets up the pointer to the next task if the tasks names line up
{
    pNextTask = &task;
}
bool Task::getCompleted(CustomerOrder &src)
{
    if (Orders.size() != 0)
    {
        src = std::move(Orders.back());
        Orders.pop_back();
        return true;
    }
    else if (Orders.size() == 0)
    {
        return false;
    }
}
void Task::Validate(std::ostream &os)
{
    if (pNextTask != nullptr)
    {
        os << pNextTask->getName();
    }
}

Task &Task::operator+=(CustomerOrder &&newOrder) //Move a CustomerOrder into the orders queue
{
    Orders.push_front(newOrder);
}