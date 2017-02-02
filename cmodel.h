#ifndef CMODEL_H
#define CMODEL_H

#include<vector>
#include "node.h"
#include "element.h"
#include "nodeset.h"
#include "elset.h"
using elem_ptr= element*;
class CModel
{
public:
    CModel();

    //INTERFACE FUNCTIONS
    void print_nodes();
    void print_nodeset();
    void print_elems() const;
    void print_elset();
    void print_node_count() const;
    void print_elem_count() const;


    void add_node(node);
    void add_element(element);
    void add_nodeset(nodeset);
    void add_elset(elset);
    void assert_nodeID(int) const;    
    elem_ptr get_elem_ptr(int);
    node_ptr get_node_ptr(int);
    node_ptr get_node_ptr_with_count(int);
private:
    std::vector<node>m_nodes;
    std::vector<nodeset> m_nset;
    std::vector<element>m_elements;
    std::vector<elset>m_elemset;
    std::vector<elem_ptr>m_loaded_elems;
};

#endif // CMODEL_H
