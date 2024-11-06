/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt
 * to change this license Click
 * nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this
 * template
 */

/*
 * File:   Softmax.cpp
 * Author: ltsach
 *
 * Created on August 25, 2024, 2:46 PM
 */

#include "layer/Softmax.h"

#include <filesystem>  //require C++17

#include "ann/functions.h"
#include "sformat/fmt_lib.h"
namespace fs = std::filesystem;

Softmax::Softmax(int axis, string name) : m_nAxis(axis) {
  if (trim(name).size() != 0)
    m_sName = name;
  else
    m_sName = "Softmax_" + to_string(++m_unLayer_idx);
}

Softmax::Softmax(const Softmax& orig) {}

Softmax::~Softmax() {}

xt::xarray<double> Softmax::forward(xt::xarray<double> X) {
  // Todo CODE YOUR
  // xt::xarray<double> expX = xt::exp(X);
  // xt::xarray<double> sumExpX = xt::sum(expX, m_nAxis);
  // m_aCached_Y = expX / sumExpX;
  // return m_aCached_Y;
  xt::xarray<double> Z = xt::zeros_like(X);

    for (size_t i = 0; i < X.shape()[0]; ++i) {
        auto maxX = xt::amax(xt::view(X, i, xt::all())); 
        auto expX = xt::exp(xt::view(X, i, xt::all()) - maxX);

        auto sumExpX = xt::sum(expX);

        xt::view(Z, i, xt::all()) = expX / sumExpX;
    }

    m_aCached_Y = Z;
    return m_aCached_Y;

}

// xt::xarray<double> Softmax::backward(xt::xarray<double> DY) {
//   // Todo CODE YOUR
//   xt::xarray<double> DZ = xt::zeros_like(DY);
//   // xt::xarray<double> sumGradient = xt::sum(gradient, m_nAxis);

//   xt::xarray<double> stack = diag_stack(m_aCached_Y) - outer_stack(m_aCached_Y, m_aCached_Y);
//   DZ = matmul_on_stack(stack, DY);
//   return DZ;
// }

xt::xarray<double> Softmax::backward(xt::xarray<double> DY) {
    xt::xarray<double> Dz = xt::zeros_like(DY);
    xt::xarray<double> diagY_stack = diag_stack(m_aCached_Y);

    xt::xarray<double> outerY_stack = outer_stack(m_aCached_Y, m_aCached_Y);

    xt::xarray<double> js = diagY_stack - outerY_stack;

    Dz = matmul_on_stack(js, DY);

    return Dz;
}

string Softmax::get_desc() {
  string desc = fmt::format("{:<10s}, {:<15s}: {:4d}", "Softmax",
                            this->getname(), m_nAxis);
  return desc;
}
