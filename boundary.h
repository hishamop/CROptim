#ifndef BOUNDARY_H
#define BOUNDARY_H
#include <vector>
#include <tuple>
#include "element.h"
using elem_ptr=element*;

class boundary
{
public:
    boundary(elem_ptr);
    virtual void set_boundary_faces() = 0;
protected:
    elem_ptr m_boundary_element;           // pointer to boundary element.
    std::vector<unsigned int> m_faces;
    std::tuple <node_ptr,int,double> m_traction;    
};



class boundary_cps4 : public boundary
{
public:
    boundary_cps4(elem_ptr);
};


#endif // BOUNDARY_H
