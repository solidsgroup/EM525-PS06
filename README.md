FEM Coding Assignment: Isoparametric Elements and Unstructured Meshes
=====================================================================


Initial setup (same as before)
------------------------------

1. Check out the problem repository
    
         git clone https://github.com/solidsgroup/EM525-PS06.git
   
2. Change into the problem directory

         cd EM525-PS06
   
3. Use this command to install eigen (optional: you can skip this if you have eigen installed)

         make eigen

4. Now, compile the code

         make

   The code **will not compile** because there are missing files.
   These files must be copied as specified below before you can compile.


Part 1: Copying previous implementation
---------------------------------------

Copy the following files directly from PS05. 

- `src/Element/Element.H`
- `src/Element/LST.H`
- `src/Element/CST.H`
- `src/Element/Q4.H`
- `src/Element/Q9.H`
- `src/Model/Isotropic.H`

If you do this correctly the code will compile.
However, it will **not** pass the tests.


Part 2: Upgrade element energy calculations for isoparametric elements
----------------------------------------------------------------------

Edit the following file

- `src/Element/Element.H`

Update the `W`, `DW`, and `DDW` for isoparametric elements.
Note that you can use the following:

    Set::Matrix J = Jacobian(Qp[q]);

to find the jacobian matrix at quadrature point `q`.
You can also use the following functions

    Set::Matrix Jinv = J.inverse();
    Set::Scalar Jdet = J.determinant();

to calculate the inverse jacobian matrix and the determinant of the jacobian matrix, respectively.

Once you have completed this part, all of the element and model tests should pass.

Part 3: Reading and writing the VTK mesh
----------------------------------------

1.  There are four mesh files in the root directory:

    - `CST.vtk`
    - `Q4.vtk`
    - `LST.vtk`
    - `Q9.vtk`

    These are mesh files stored in the "visualization toolkit" (VTK) file format.
    Open these files using a text editor (emacs, nano, vim, etc) and familiarize yourself with the format.

2.  Download and install one of the following open-source scientific visualization packages:

    - Paraview: https://www.paraview.org/
    - VisIT: https://visit-dav.github.io/visit-website/

    Paraview is recommended if you have never used either before.
    If you have an alternative visualization software that you would like to use, you are free to do so, but only Paraview and Visit are supported in this class.

3.  You will find TODOs in the following file:

    - `src/Mesh/Unstructured.H`

    The class `Mesh::Unstructured` is a general class that stores the points and elements in an unstructured mesh.
    It contains vectors called `Points`, `CSTs`, `Q4s`, `LSTs`, and `Q9s` to store the vertices and the respective lists of elements.
    The Mesh class is responsible for tracking the connectivity of the mesh, which links the elements to their respective points.
    This is done through the element's `id` array, which is an array of indices of points.
    For example, if a `CST` element has an `id` array containing values  `{0,15,23}`, this means that it is an element with nodes stored in `Points[0],Points[15],Points[23]`, respectively.
    It is the job of the `Mesh` class to properly record these IDs.

    Follow the instructions in the TODO comments.
    Keep in mind that the VTK file formats are specified here: https://docs.vtk.org/en/latest/design_documents/VTKFileFormats.html

    If you implement this successfully, running `./bin/main` will create four output meshes `CST_out.vtk`, etc.

4.  Open the output meshes with Paraview or VisIt and verify that the nodes are stored correctly.
    Include screenshots of your meshes in the submission of your problem set.
    
