#define DIM 2

#include <iostream>
#include "eigen3/Eigen/Core"
#include "eigen3/Eigen/Dense"
#include "Set/Set.H"
#include "Element/CST.H"
#include "Element/LST.H"
#include "Element/Q4.H"
#include "Element/Q9.H"
#include "Element/Test.H"
#include "Model/Isotropic.H"
#include "Model/Test.H"
#include "Mesh/Unstructured.H"


int main(int argc, char **argv)
{
    srand(0);

    //
    // Model Tests
    //
    std::cout << "model.isotropic.derivative...";
    try {Model::Test<Model::Isotropic>::Derivative(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}
    
    //
    // CST Tests
    //
    
    std::cout << "test.element.cst.diractest...";
    try {Element::Test<Element::CST<Model::Isotropic>>::Dirac(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.cst.sumtounitytest...";
    try {Element::Test<Element::CST<Model::Isotropic>>::SumToUnity(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.cst.etaderivativetest...";
    try {Element::Test<Element::CST<Model::Isotropic>>::EtaDerivative(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.cst.quadrature...";
    try {Element::Test<Element::CST<Model::Isotropic>>::Quadrature(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.cst.isoparametriccheck...";
    try {Element::Test<Element::CST<Model::Isotropic>>::IsoparametricCheck(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.cst.energyderivative...";
    try {Element::Test<Element::CST<Model::Isotropic>>::EnergyDerivative(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    //
    // LST Tests
    //
    
    std::cout << "test.element.lst.diractest...";
    try {Element::Test<Element::LST<Model::Isotropic>>::Dirac(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.lst.sumtounitytest...";
    try {Element::Test<Element::LST<Model::Isotropic>>::SumToUnity(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.lst.etaderivativetest...";
    try {Element::Test<Element::LST<Model::Isotropic>>::EtaDerivative(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.lst.quadrature...";
    try {Element::Test<Element::LST<Model::Isotropic>>::Quadrature(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.lst.isoparametriccheck...";
    try {Element::Test<Element::LST<Model::Isotropic>>::IsoparametricCheck(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.lst.energyderivative...";
    try {Element::Test<Element::LST<Model::Isotropic>>::EnergyDerivative(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    //
    // Q4 Tests
    //
    
    std::cout << "test.element.q4.diractest...";
    try {Element::Test<Element::Q4<Model::Isotropic>>::Dirac(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.q4.sumtounitytest...";
    try {Element::Test<Element::Q4<Model::Isotropic>>::SumToUnity(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.q4.etaderivativetest...";
    try {Element::Test<Element::Q4<Model::Isotropic>>::EtaDerivative(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.q4.quadrature...";
    try {Element::Test<Element::Q4<Model::Isotropic>>::Quadrature(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.q4.isoparametriccheck...";
    try {Element::Test<Element::Q4<Model::Isotropic>>::IsoparametricCheck(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.q4.energyderivative...";
    try {Element::Test<Element::Q4<Model::Isotropic>>::EnergyDerivative(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    //
    // Q9 Tests
    //
    
    std::cout << "test.element.q9.diractest...";
    try {Element::Test<Element::Q9<Model::Isotropic>>::Dirac(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.q9.sumtounitytest...";
    try {Element::Test<Element::Q9<Model::Isotropic>>::SumToUnity(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.q9.etaderivativetest...";
    try {Element::Test<Element::Q9<Model::Isotropic>>::EtaDerivative(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.q9.quadrature...";
    try {Element::Test<Element::Q9<Model::Isotropic>>::Quadrature(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.q9.isoparametriccheck...";
    try {Element::Test<Element::Q9<Model::Isotropic>>::IsoparametricCheck(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}

    std::cout << "test.element.q9.energyderivative...";
    try {Element::Test<Element::Q9<Model::Isotropic>>::EnergyDerivative(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest &e) {std::cout << "failed:" << std::endl << "   --> " << e.what() << std::endl;}



    //
    // MESH IO
    // 


    Mesh::Unstructured<Model::Isotropic> cstmesh("cst.vtk"); // Read in the CST mesh
    cstmesh.Print("cst_out.vtk"); // Save the mesh to a new file
    
    Mesh::Unstructured<Model::Isotropic> q4mesh("q4.vtk"); // Read in the Q4 mesh
    q4mesh.Print("q4_out.vtk"); // Save to a new file

    Mesh::Unstructured<Model::Isotropic> lstmesh("lst.vtk"); // Read in the LST mesh
    lstmesh.Print("lst_out.vtk"); // Save to a new file

    Mesh::Unstructured<Model::Isotropic> q9mesh("q9.vtk"); // Read in the Q9 mesh
    q9mesh.Print("q9_out.vtk");// Save to a new file.

}
