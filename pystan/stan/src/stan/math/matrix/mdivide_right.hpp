#ifndef __STAN__MATH__MATRIX__MDIVIDE_RIGHT_HPP__
#define __STAN__MATH__MATRIX__MDIVIDE_RIGHT_HPP__

#include <boost/math/tools/promotion.hpp>
#include <stan/math/matrix/Eigen.hpp>
#include <stan/math/matrix/mdivide_left.hpp>
#include <stan/math/matrix/transpose.hpp>
#include <stan/math/matrix/validate_multiplicable.hpp>
#include <stan/math/matrix/validate_square.hpp>

namespace stan {
  namespace math {

    /**
     * Returns the solution of the system Ax=b.
     * @param A Matrix.
     * @param b Right hand side matrix or vector.
     * @return x = b A^-1, solution of the linear system.
     * @throws std::domain_error if A is not square or the rows of b don't
     * match the size of A.
     */
    template <typename T1, typename T2, int R1, int C1, int R2, int C2>
    inline 
    Eigen::Matrix<typename boost::math::tools::promote_args<T1,T2>::type,R1,C2>
    mdivide_right(const Eigen::Matrix<T1,R1,C1> &b,
                  const Eigen::Matrix<T2,R2,C2> &A) {
      stan::math::validate_square(A,"mdivide_right");
      stan::math::validate_multiplicable(b,A,"mdivide_right");
      // FIXME: This is nice and general but likely slow.
      return transpose(mdivide_left(transpose(A),transpose(b)));
//      return promote_common<Eigen::Matrix<T1,R2,C2>,
//                            Eigen::Matrix<T2,R2,C2> >(A)
//        .transpose()
//        .lu()
//        .solve(promote_common<Eigen::Matrix<T1,R1,C1>,
//                              Eigen::Matrix<T2,R1,C1> >(b)
//               .transpose())
//        .transpose();
    }

  }
}
#endif
