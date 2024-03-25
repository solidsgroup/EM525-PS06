#ifndef MODEL_TEST_H
#define MODEL_TEST_H

#include "Util/Exception.H"
#include "Model/Model.H"

namespace Model
{
template<class MODEL>
class Test
{
public:
    static void Derivative()
    {
        MODEL model;

        double small = 1E-8;
        double tolerance = 1E-6;

        for (int iter = 0; iter < 100 ; iter++)
        {
            Set::Matrix gradu = Set::Matrix::Random();

            Set::Matrix dw_exact = model.DW(gradu);
            for (int i = 0 ; i < 2 ; i++)
                for (int j = 0 ; j < 2 ; j++)
                {
                    Set::Matrix dx = Set::Matrix::Zero();
                    dx(i,j) = small;

                    double dw_numerical_ij = (model.W(gradu) - model.W(gradu-dx)) / small;

                    double diff = dw_exact(i,j) - dw_numerical_ij;
                    double norm = std::max(dw_exact(i,j) + dw_numerical_ij,1.0);

                    if (fabs(diff/norm) > tolerance)
                        throw Util::Exception::UnitTest("Model::DerivativeTest failed, DWnumerical != DWexact ");
                }


            typename Set::Tensor4 ddw_exact = model.DDW(gradu);
            for (int i = 0 ; i < 2 ; i++)
                for (int j = 0 ; j < 2 ; j++)
                {
                    Set::Matrix dx = Set::Matrix::Zero();
                    dx(i,j) = small;
                

                    Set::Matrix ddw_numerical_ij = (model.DW(gradu) - model.DW(gradu-dx)) / small;

                    for (int k = 0; k < 2 ; k++)
                        for (int l = 0; l < 2 ; l++)
                        {
                            double diff = ddw_exact(i,j,k,l) - ddw_numerical_ij(k,l);
                            double norm = std::max(ddw_exact(i,j,k,l) + ddw_numerical_ij(k,l), 1.0);

                            if (fabs(diff/norm) > tolerance)
                                throw Util::Exception::UnitTest("Model::DerivativeTest failed, DDWnumerical != DDWexact ");
                        }
                }
        }        
    }
};
}




#endif
