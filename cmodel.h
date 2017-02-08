#ifndef CMODEL_H
#define CMODEL_H
#include<vector>
#include "node.h"
#include "element.h"
#include "nodeset.h"
#include "elset.h"
#include "boundary.h"
using elem_ptr= element*;
using boundary_ptr = boundary*;
class CFileio;
class CModel
{
public:
    CModel();

    //INTERFACE FUNCTIONS
    void set_boundary();

    //INTERFACE DISPLAY
    void print_nodes();
    void print_nodeset();
    void print_elems() const;
    void print_elset();
    void print_node_count() const;
    void print_elem_count() const;


    void add_node(node);
    void add_element(elem_ptr);
    void add_boundary_element(boundary_ptr);
    void add_nodeset(nodeset);
    void add_elset(elset);
    void assert_nodeID(int) const;    
    elem_ptr get_elem_ptr(int);
    node_ptr get_node_ptr(int);
    node_ptr get_node_ptr_with_count(int);

    //friend void CFileio::read_boundary(); // A friend class is not a member function but can access members of this class.
    friend class CFileio;
private:
    std::vector<node>m_nodes;
    std::vector<nodeset> m_nset;
    std::vector<element>m_elements;
    std::vector<elset>m_elemset;
    std::vector<boundary>m_boundary;
};

#endif // CMODEL_H
