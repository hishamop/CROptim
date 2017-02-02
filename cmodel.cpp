#include "cmodel.h"
#include <cassert>

CModel::CModel()
{

}

void CModel::add_node(node t)    // Add node as push back
{
    m_nodes.push_back(t);
}

void CModel::add_element(element t)
{
    m_elements.push_back(t);
}

void CModel::add_nodeset(nodeset t)
{
    m_nset.push_back(t);
}

void CModel::add_elset(elset t)
{
    m_elemset.push_back(t);
}

void CModel::assert_nodeID(int id) const
{
    assert(m_nodes.at(id-1).getindex() == id);
}

node_ptr CModel::get_node_ptr(int id)
{
    assert(m_nodes.at(id-1).getindex() == id);      // Make sure that correct node is returned.
    return &m_nodes.at(id-1);
}

node_ptr CModel::get_node_ptr_with_count(int id)
{
    assert(m_nodes.at(id-1).getindex() == id);      // Make sure that correct node is returned.
    m_nodes.at(id-1).count_sharing();
    return &m_nodes.at(id-1);

}

elem_ptr CModel::get_elem_ptr(int id)
{

    assert(m_elements.at(id-1).getindex() == id);    //Make sure correct element is returned.
    return &m_elements.at(id-1);
}


//void CModel::print_elems() const
//{
//    std::cout<<"...............ELEMENTS DATA................\n";
//    for (auto iter=m_elements.begin(); iter != m_elements.end(); ++iter)
//    {
//        iter->print_element();
//    }
//}

void CModel::print_elems() const
{
    std::cout<<"...............ELEMENTS DATA................\n";
    for (auto iter:m_elements)
    {
        iter.print_element();
    }
}

// public function for printing node data
void CModel::print_nodes()
{
    if(m_nodes.empty())
    {
        std::cout<<"node empty\n";
        return;
    }

    std::cout<<".............NODE DATA.................\n";
    for(auto iter:m_nodes)
    {
        iter.printnode();
    }
}

void CModel::print_nodeset()
{
    if(m_nset.empty())
    {
        std::cout<<"No nodesets \n";
        return;
    }

    for (auto iter=m_nset.begin(); iter != m_nset.end(); iter++)
    {
        iter->print_nodeset();
    }
}

void CModel::print_node_count() const
{
    std::cout<<"Count of nodes :    "<<m_nodes.size()<<std::endl;
}

void CModel::print_elem_count() const
{
    std::cout<<"Count of elements :    "<<m_elements.size()<<std::endl;
}

void CModel::print_elset()
{
    if(m_elemset.empty())
    {
        std::cout<<"No element sets \n";
        return;
    }

    for (auto iter:m_elemset)
    {
        iter.print_elset();
    }
}
