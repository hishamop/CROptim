#include "cps4.h"
#include <cassert>
#include <algorithm>

cps4::cps4(int id, std::vector<node_ptr> nodes)
{
    m_type =CPS4;
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

std::vector<node_ptr> cps4::get_face(unsigned int i) const
{
    std::vector<node_ptr> temp;
    assert(i<5 and i>0);
    if(i<4)
    {
       temp.push_back(this->getnode(i));
       temp.push_back(this->getnode(i+1));
    }
    else
    {
        temp.push_back(this->getnode(4));
        temp.push_back(this->getnode(1));
    }
    return temp;
}

bool cps4::is_boundary()
{
    for(int i=1;i<5;i++)
    {
        if (elements_shared_by_face(get_face(i))>1)
            return false;    
    }
    return true;
}

int cps4::elements_shared_by_face(std::vector<node_ptr> face) const
{
    std::vector<unsigned int> v1 = face[1]->get_shared_elements_id() ; std::sort(v1.begin(),v1.end());
    std::vector<unsigned int> v2 = face[2]->get_shared_elements_id() ; std::sort(v2.begin(),v2.end());
    std::vector<unsigned int> intersection ;
    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),std::inserter(intersection,intersection.begin()));
    return intersection.size();
}

element_type cps4::get_element_type()
{
    return m_type;
}
