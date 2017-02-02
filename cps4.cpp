#include "cps4.h"

cps4::cps4(int id, std::vector<node_ptr> nodes)
{
    m_elem_id=id;
    m_ENode_ptrs.reserve(4);
    m_ENode_ptrs=nodes;
    setedges();
}

void cps4::setedges()
{
        m_edges.push_back(std::make_pair(m_ENode_ptrs.at(0),m_ENode_ptrs.at(1)));
        m_edges.push_back(std::make_pair(m_ENode_ptrs.at(1),m_ENode_ptrs.at(2)));
        m_edges.push_back(std::make_pair(m_ENode_ptrs.at(2),m_ENode_ptrs.at(3)));
        m_edges.push_back(std::make_pair(m_ENode_ptrs.at(3),m_ENode_ptrs.at(0)));
}

bool cps4::is_boundary_element()
{
    for(const auto iter:m_edges)
    {
        if(m_edges.first.get_shared_by<3 or m_edges.second.get_shared_by < 3)
        {

        }


    }
}

