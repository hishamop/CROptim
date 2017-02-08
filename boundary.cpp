#include "boundary.h"

boundary::boundary(elem_ptr elem,std::vector<unsigned int> faces)
{
    m_boundary_element = elem;

}






//BOUNDARY_CPS4 CLASS

boundary_cps4::boundary_cps4(elem_ptr elem)
{
    m_boundary_element = elem;
}
