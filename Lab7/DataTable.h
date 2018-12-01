#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>

namespace w7
{
template <typename T>

class DataTable
{
    std::vector<T> x, y;
    int m_slope;
    int m_intercept;

  public:
    //constructor
    DataTable(std::ifstream &fs, int slope, int intercept) : m_slope{slope}, m_intercept{intercept}
    {
        if (fs.is_open())
        {
            T m_x, m_y;
            while (fs >> m_x >> m_y)
            {
                x.push_back(m_x);
                y.push_back(m_y);
            }
        }
        fs.close();
    }

    //return the average of all y values;
    T mean() const
    {
        return std::accumulate(y.begin(), y.end(), (T)0) / (T)y.size();
    }

    //return the standard deviation of the data
    T sigma() const
    {
        T mean_y = mean();
        T total = 0;
        //stack flow using
        std::for_each(y.begin(), y.end(), [&](const T t) {
            total += (t - mean_y) * (t - mean_y);
        });
        return std::sqrt(total / ((T)y.size() - 1));
    }

    //! query that returns median value of the dependant coordinate
    T median() const
    {
        std::vector<T> temp = y;
        std::sort(temp.begin(), temp.end());
        return temp[(temp.size() / 2)];
    }

    //returns the slope and intercept for the data set
    void regression(T &slope, T &y_intercept) const
    {
        T m_size = (T)x.size();
        T sum_x = std::accumulate(x.begin(), x.end(), (T)0);
        T sum_y = std::accumulate(y.begin(), y.end(), (T)0);
        auto elements = [](T m_x, T m_y) { return m_x + m_y * m_y; };
        T sum_xx = accumulate(x.begin(), x.end(), (T)0, elements);
        T sum_xy = 0;
        for (int i = 0; i < m_size; ++i)
        {
            sum_xy += x.at(i) * y.at(i);
        }

        slope = (m_size * sum_xy - sum_x * sum_y) / (m_size * sum_xx - sum_x * sum_x);
        y_intercept = mean() - slope * (sum_x / m_size);
    }

    void display(std::ostream &os) const
    {
        os << std::setw(m_slope) << std::right << "x";
        os << std::setw(m_slope) << std::right << "y" << std::endl;
        for (int i = 0; i < x.size(); ++i)
        {
            os << std::setw(m_slope) << std::fixed << std::setprecision(m_intercept) << x[i];
            os << std::setw(m_slope) << std::fixed << std::setprecision(m_intercept) << y[i];
            os << std::endl;
        }
    }
};
template <typename T>
std::ostream &operator<<(std::ostream &os, const DataTable<T> &d)
{
    d.display(os);
    return os;
}

} // namespace w7
