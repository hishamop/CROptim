#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <utility>
#include <iostream>
#include "node.h"


enum element_type {CPS4=1,CPS8};   //Element types are equated into numbers.

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
    node_ptr getnode(int) const;     //return nth node_ptr.
    virtual std::vector<node_ptr> get_face(unsigned int) const;    // return node_ptrs of nth face of element.
    virtual bool is_boundary() const =0;
    virtual element_type get_element_type() const = 0;
    virtual std::vector<unsigned int>  get_boundary_faces() const =0;

protected:
    int m_elem_id;
    std::vector<node_ptr> m_ENode_ptrs;
    std::vector<node_pair> m_edges;
    element_type m_type;
    //PROTECTED
    //FUNCTIONS RELATED TO MAPPING.
};





#endif // ELEMENT_H
