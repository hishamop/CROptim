#include<iostream>
#include <iomanip>
#include "node.h"
node::node()
{
    m_id=0;
    m_xcord=0.0;
    m_ycord=0.0;
    m_zcord=0.0;
}

node::node(int id,float x, float y)
{
    m_id=id;
    m_xcord=x;
    m_ycord=y;
    m_zcord=0;
}

node::node(int id, float x, float y, float z)
{
    m_id=id;
    m_xcord=x;
    m_ycord=y;
    m_zcord=z;
}

void node::printnode()
{
    std::cout<<std::setw(10)<< std::left <<m_id<<std::setw(10)<<std::left<<m_xcord<<std::setw(10)<<std::left<<m_ycord<<"\n";
}



int node::getindex() const
{
    return m_id;
}

void node::count_sharing()
{
    m_shared_by+=1;
}

int node::get_shared_by() const
{
    return m_shared_by;
}
