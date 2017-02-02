#include "element.h"
#include <iomanip>
element::element()
{

}


element::element(int id, std::vector<node_ptr> nodes)
{
    m_elem_id =id;
    m_ENode_ptrs = nodes;
}

element::~element()
{

}

// void element::setedges()
//{

//}

void element::print_element() const
{
    std::cout<<std::setw(10)<< std::left <<m_elem_id;
    for (auto iter=m_ENode_ptrs.begin(); iter != m_ENode_ptrs.end(); ++iter)
    {
        std::cout << std::setw(10) << std::left << (*iter)->getindex();
    }
    std::cout<<"\n";
}


int element::getindex() const
{
    return m_elem_id;
}


