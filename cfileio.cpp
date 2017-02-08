#include "cfileio.h"
#include "auxil.h"
#include "cps4.h"
#include <algorithm>
#include <iomanip>
#include <assert.h>


CFileio::CFileio(std::string szFile, CModel *model)
{
    {
        m_model = model;
        m_File.open(szFile,std::ios::in);
        if(!m_File)
        std::cout<<"Coudn't open the file";

        //read the file line by line
        std::string s;
        while(std::getline(m_File,s))
        {
            //convert all letters into upper.
            std::string upper(s);
            std::transform(upper.begin(),upper.end(),upper.begin(),toupper);

            if(upper.find("*NODE") != std::string::npos)
            {
                read_nodes();
            }

            if(upper.find("*ELEMENT") != std::string::npos)
            {
                read_elems(upper);
            }

            if(upper.find("*NSET") != std::string::npos)
            {
                read_nodeset(upper);

            }

            if(upper.find("*ELSET") != std::string::npos)
            {
                read_elset(upper);

            }
            if(upper.find("*NLOAD") != std::string::npos)
            {
                read_loads();
            }
        }

        read_boundary();

        //set_faces();   // set faces by iterating over elements.
    }
}



//prive class functions
void CFileio::read_nodes()
{
    char c;                         //temp.variable for recieving ','.
    int id;
    float x,y,z;
    //The program will fail if the input file contains blank lines.
    while(m_File.peek() != '*' and m_File.peek() != EOF )
    {
        if(m_File.peek() == '\n')              //if the line is blank skip to next line.
        {
            std::string skipline;
            std::getline(m_File,skipline); continue;
        }

        if(m_File>>id>>c>>x>>c>>y)              //input file consist only x,y coordinates
        {
            node temp(id,x,y);
            m_model->add_node(temp);
            std::string dummy;
            std::getline(m_File,dummy);
            continue;
        }

        if(m_File>>id>>c>>x>>c>>y>>c>>z)           //input file consist x,y,z coordinates.
        {
            node temp(id,x,y,z);
            m_model->add_node(temp);
            std::string dummy;
            std::getline(m_File,dummy);
            continue;
        }
    }
}





void CFileio::read_nodeset(std::string line)
{
    std::string nodeset_name = parse_label(line,"NSET");
    nodeset temp(nodeset_name);
    while(m_File.peek() != '*' and m_File.peek() != EOF )
    {
        if(m_File.peek() == '\n')
        {
            std::string dummy;
            std::getline(m_File,dummy);continue;        // skip the blank line.
        }
        std::string ss; int id;
        std::getline(m_File,ss);
        std::stringstream str(ss);
        while(str>>id)
        {
            temp.add_nset_node(m_model->get_node_ptr(id));
            if(str.peek() == ',' or str.peek() == ' ')
            {
                str.ignore();
            }

        }
    }
    m_model->add_nodeset(temp);
}


void CFileio::read_elset(std::string line)
{
    std::string elset_name = parse_label(line,"ELSET");
    elset temp(elset_name);
    while(m_File.peek() != '*' and m_File.peek() != EOF )
    {
        if(m_File.peek() == '\n')
        {
            std::string dummy;
            std::getline(m_File,dummy);continue;        // skip the blank line.
        }
        std::string ss; int id;
        std::getline(m_File,ss);
        std::stringstream str(ss);
        while(str>>id)
        {
            temp.add_elset_elem(m_model->get_elem_ptr(id));
            if(str.peek() == ',' or str.peek() == ' ')
            {
                str.ignore();
            }

        }
    }
    m_model->add_elset(temp);
}


//read elements from the input fle and store it in m_element.
void CFileio::read_elems(std::string upper)
{
    int id; char c;

    //below loop for quad4 element
    if(upper.find("CPS4") !=std::string::npos)
    {

        while(m_File.peek() != '*' and m_File.peek() != EOF)
        {
            if(m_File.peek() == '\n')
            {
                std::string dummy;
                std::getline(m_File,dummy); continue;    // skip the blank line.
            }
            int n[4];
            if(m_File>> id >> c >> n[0]>> c >> n[1]>> c >> n[2]>> c >>n[3])
            {
                std::vector<node_ptr> temp;
                for(int i=0; i<4; i++)
                {
                    temp.push_back(m_model->get_node_ptr_with_count(n[i]));
                }

                cps4 temp_elem(id,temp);
                for(int i=1;i<5;i++)
                {
                    temp_elem.getnode(i)->add_incident_elem_id(id);
                }

                m_model->add_element(temp_elem);


                std::string dummy;
                std::getline(m_File,dummy);
                continue;  // dummy string to collect junk data is not used
            }
        }
    }

}

void CFileio::read_loads()
{
    while(m_File.peek() != '*' and m_File.peek() != EOF )
    {
        if(m_File.peek() == '\n')
        {
            std::string dummy;
            std::getline(m_File,dummy);continue;        // skip the blank line.
        }
        std::string ss;
        std::getline(m_File,ss);


    }

}

void CFileio::read_boundary()
{
    for(auto &iter:m_model->m_elements)
    {
        if(iter.is_boundary())
        {
            m_model->add_boundary_element(&iter);
        }
    }

}

bool CFileio::is_boundary(elem_ptr)
{
    return false;
}
