#ifndef NODE_H
#define NODE_H


#include <vector>
class node
{
private:
    float m_xcord,m_ycord,m_zcord;
    int m_id;
    std::vector<unsigned int>m_incident_elements;   // ids of shared elements.
    std::vector<double>m_nodeTract;          // Traction in x,y(,z) directions at node.
    std::vector<double>m_dispDof;            // x,y,z displacement at nodes.
    std::vector<double>m_stressDof;          // stress Dof at node.

public:
    node();
    node(int id,float x,float y);
    node(int id,float x, float y, float z);
    void printnode();
    void set_stressDof(int pos, double val);
    void set_nodeTract(int axis_no,double val);
    void set_dispDof(int constrain_no);
    int getindex() const;
    std::vector<unsigned int> get_shared_elements_id()const ;
    bool is_boundary_node();
    void add_incident_elem_id(unsigned int);
};
#endif // NODE_H
