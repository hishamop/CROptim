#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <utility>
#include <iostream>
#include "node.h"


using node_ptr=node*;
using node_pair=std::pair<node_ptr,node_ptr>;
class element
{
public:
    element();
    element(int, std::vector<node_ptr>);
    ~element();

    //NON-INTERFACE FUNCTIONS
    int getindex() const;
    void print_element() const;
//    virtual void setedges();

protected:
    int m_elem_id;
    std::vector<node_ptr> m_ENode_ptrs;
    std::vector<node_pair> m_edges;

    //PROTECTED
    //FUNCTIONS RELATED TO MAPPING.
};


#endif // ELEMENT_H
