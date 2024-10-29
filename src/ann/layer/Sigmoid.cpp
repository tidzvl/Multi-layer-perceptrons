/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt
 * to change this license Click
 * nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this
 * template
 */

/*
 * File:   Sigmoid.cpp
 * Author: ltsach
 *
 * Created on August 25, 2024, 2:45 PM
 */

#include "layer/Sigmoid.h"

#include "ann/functions.h"
#include "sformat/fmt_lib.h"

Sigmoid::Sigmoid(string name) {
  if (trim(name).size() != 0)
    m_sName = name;
  else
    m_sName = "Sigmoid_" + to_string(++m_unLayer_idx);
}

Sigmoid::Sigmoid(const Sigmoid& orig) {
  m_sName = "Sigmoid_" + to_string(++m_unLayer_idx);
}

Sigmoid::~Sigmoid() {}
xt::xarray<double> Sigmoid::forward(xt::xarray<double> X) {
  // Todo CODE YOUR
}

xt::xarray<double> Sigmoid::backward(xt::xarray<double> DY) {
  // Todo CODE YOUR
}

string Sigmoid::get_desc() {
  string desc = fmt::format("{:<10s}, {:<15s}:", "Sigmoid", this->getname());
  return desc;
}