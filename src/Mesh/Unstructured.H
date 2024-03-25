#include <fstream>
#include <cassert>
#include <filesystem>
#include "Element/Element.H"
#include "Element/CST.H"
#include "Element/LST.H"
#include "Element/Q4.H"
#include "Element/Q9.H"
#include "Mesh/Mesh.H"
#include "eigen3/Eigen/Core"
#include "eigen3/Eigen/SparseCore"
#include "eigen3/Eigen/IterativeLinearSolvers"
#include "Model/Isotropic.H"
namespace Mesh
{
template<class MODEL>
class Unstructured : Mesh
{
public:
    Unstructured()
    {};

    Unstructured(std::string vtkfile)
    {
        //
        // TODO: Complete the Unstructured Mesh file reader.
        //
        // Input: "vtkfile" is the name of a file containing a mesh in
        //        human-readable ASCII vtk format.
        //
        // Output: None - this is a constructor
        //

        // Check to see if the file exists - if not, then exit.
        if (!std::filesystem::exists(vtkfile))
            throw std::runtime_error("Could not find file " + vtkfile);
        std::ifstream in(vtkfile);

        // Create string vectors of points, cells, and cell types.
        std::vector<std::string> str_points;
        std::vector<std::string> str_cells;
        std::vector<std::string> str_cell_types;
        enum status {none, point, cell, cell_type};
        status mystatus = none;

        // Read in all of the data from the mesh file and store in these vectors.
        std::string line;
        while (getline(in,line))
        {
            if (line=="") {mystatus = none; continue;}
            std::stringstream ss(line);
            std::string first;
            ss >> first;
            if (first=="POINTS") {mystatus = point; continue;}
            if (first=="CELLS") {mystatus = cell; continue;}
            if (first=="CELL_TYPES") {mystatus = cell_type; continue;}
            
            if (mystatus == point) str_points.push_back(line);
            if (mystatus == cell) str_cells.push_back(line);
            if (mystatus == cell_type) str_cell_types.push_back(line);
        }
        
        // Make sure we did not miscount.
        assert(str_cells.size() == str_cell_types.size());
        
        // Read in all of the vertices and store in the
        // "Points" array
        for (int n = 0; n < str_points.size(); n++)
        {
            Set::Vector Point;
            std::stringstream in(str_points[n]);
            for (int d = 0; d < DIM; d++) in >> Point(d);
            Points.push_back(Point);
        }
        
        // Read in the CST elements
        for (int n = 0; n < str_cells.size(); n++) // Iterate over all cells
        {
            // CST elements have VTK ID = 5
            // (https://docs.vtk.org/en/latest/design_documents/VTKFileFormats.html)
            //
            // If this cell is of type 5, then read in and add to the CST array
            if (str_cell_types[n] == std::to_string(5)) 
            {
                // Convert the list of nodes to a stringstream
                std::stringstream in(str_cells[n]); 
                // This is an array of node IDS. It has length 3 because
                // the CST has 3 nodes.
                std::array<int,3> id;
                // We don't care about the first number but we have to read it anyway, so
                // call it "dummy"
                int dummy; 
                // Store the IDs in order - note that this order will change
                // depending on the node order we use vs that of the VTK
                // (seee the documentation!)
                in >> dummy >> id[0] >> id[1] >> id[2]; 
                // Add this new CST element to the list.
                CSTs.push_back(Element::CST<MODEL>(Points,id));
            }
        }

        //
        // TODO: Repeat the CST code block above to read in Q4, LST, and Q9 elements.
        //

        //
        // ... your code goes here ...
        // 

    }

    void Print(std::string vtkfile)
    {
        //
        // Todo: Complete the mesh writer.
        //       This function writes the mesh data to VTK format.
        //
        // Input: "vtkfile" - file name to write to.


        // Open the file and write the header information.
        std::ofstream out(vtkfile);
        out << "# vtk DataFile Version 2.0" << std::endl;
        out << "created by fem" << std::endl;
        out << "ASCII" << std::endl;
        out << "DATASET UNSTRUCTURED_GRID" << std::endl;

        // Write out all of the points.
        out << "POINTS " << Points.size() << " double" << std::endl;
        for (int n = 0; n < Points.size(); n++)
            out << Points[n].transpose() << " 0.0" << std::endl;
        
        // Indicate how many total points we are about to write.
        out << std::endl;
        out << "CELLS " << nElements() << " " << nElementNodes() << std::endl;

        // Start with the CSTs. 
        for (int e = 0; e < CSTs.size(); e++)
        {
            // Get the array of node IDs.
            // The CST has three nodes, so the length of the array is 3.
            const std::array<int,3> & id = CSTs[e].getid();
            // Output the node ID order in VTK ordering
            out << "3 " << id[0] << " " << id[1] << " " << id[2] << std::endl;
        }

        // TODO: Write output above for Q4, LST, and Q9 elements, following the example
        //       in the above code block.

        //
        // ... your code goes here ...
        //



        
        // Now we need to specify what kind of element each of the above rows corresponds to.
        out << std::endl;
        out << "CELL_TYPES " << nElements() << std::endl;

        // CSTs are are VTK type 5, so write out one "5" for each CST in the array.
        for (int e = 0; e < CSTs.size(); e++)
            out << "5" << std::endl;

        // TODO: Specify the element types above for Q4, LST, and Q9 element,s following
        //       the example in the previous two lines.

        //
        // ... your code goes here ...
        //

    }

    inline const int size()
    {
        return 2 * Points.size();
    }

    inline const int nPoints()
    {
        return 2 * Points.size();
    }
    
    inline const int nElements()
    {
        return CSTs.size() + Q4s.size() + LSTs.size() + Q9s.size();
    }

    inline const int nElementNodes()
    {
        return 4*CSTs.size() + 5*Q4s.size() + 7*LSTs.size() + 10*Q9s.size();
    }

    std::vector<Eigen::Vector2d> Points;
    std::vector<Element::CST<MODEL>> CSTs;
    std::vector<Element::Q4<MODEL>> Q4s;
    std::vector<Element::LST<MODEL>> LSTs;
    std::vector<Element::Q9<MODEL>> Q9s;

};

}
