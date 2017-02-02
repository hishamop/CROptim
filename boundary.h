#ifndef BOUNDARY_H
#define BOUNDARY_H
#include <vector>
#include <tuple>
#include "element.h"
using elem_ptr=element*;

class boundary
{
public:
    boundary();
private:
    elem_ptr m_boundElem;           // pointer to boundary element.
    std::tuple <node_ptr,int,double> m_traction;

};

#endif // BOUNDARY_H
