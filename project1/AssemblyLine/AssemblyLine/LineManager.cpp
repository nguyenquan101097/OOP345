#include "LineManager.h"
#include "Utilities.h"
LineManager::LineManager(std::string &str, std::vector<Task *> &vecT, std::vector<CustomerOrder> &vecC)
{

    //move all the customerOrder objects on to the front ToBeFilled queue
    for (size_t i = 0; i < vecC.size(); ++i)
        ToBeFilled.push_back(std::move(vecC[i]));
}

bool LineManager::Run(std::ostream &os)
{
    if (!ToBeFilled.empty())
    {
        *AssemblyLine[m_firstTask] += std::move(ToBeFilled.front());
        ToBeFilled.pop_front();
    }

    for (size_t i = 0; i < AssemblyLine.size(); ++i)
    {
        AssemblyLine[i]->RunProcess(os);
    }

    CustomerOrder buffer;
    if (AssemblyLine[m_lastTask]->getCompleted(buffer))
        Completed.push_back(std::move(buffer));

    for (size_t i = 0; i < AssemblyLine.size(); ++i)
    {
        if (AssemblyLine[i]->MoveTask())
        {
            return false;
        }
    }
    return true;
}