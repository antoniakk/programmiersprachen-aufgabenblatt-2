#include <iostream>
#include <cmath>
#include "mat2.hpp"
#include "vec2.hpp"

Mat2& Mat2::operator*=(Mat2 const& m) {
    Mat2 m_tmp{*this};
    e_00 = m_tmp.e_00*m.e_00 + m_tmp.e_10*m.e_01;
    e_10 = m_tmp.e_00*m.e_10 + m_tmp.e_10*m.e_11;
    e_01 = m_tmp.e_01*m.e_00 + m_tmp.e_11*m.e_01;
    e_11 = m_tmp.e_01*m.e_10 + m_tmp.e_11*m.e_11;
    return *this;
};

float Mat2::det() const {
    return e_00*e_11 - e_10*e_01;
}


Mat2 operator*(Mat2 const& m1 , Mat2 const& m2) {
    Mat2 m3{m1};
    m3 *= m2; 
    return m3;
};

Vec2 operator*(Mat2 const& m, Vec2 const& v) {
    Vec2 w;
    w.x = m.e_00*v.x + m.e_10*v.y;
    w.y = m.e_01*v.x + m.e_11*v.y;
    return w;
};

Mat2 inverse(Mat2 const& m) {
    Mat2 m_inv;
    if (m.det() != 0) {
        m_inv.e_00 = m.e_11 / m.det();
        m_inv.e_10 = -m.e_10 / m.det();
        m_inv.e_01 = -m.e_01 / m.det();
        m_inv.e_11 = m.e_00 / m.det();
        return m_inv;
    }
    else {
        std::cout << "The matrix is not invertible." << std::endl;
    }
    return m_inv;
};

Mat2 transpose(Mat2 const& m) {
    Mat2 m_transpose{m};
    m_transpose.e_01 = m.e_10;
    m_transpose.e_10 = m.e_01; 
    return m;
};

Mat2 make_rotation_mat2(float phi) {
    Mat2 m_rotation;
    m_rotation.e_00 = std::cos(phi);
    m_rotation.e_10 = -std::sin(phi);
    m_rotation.e_01 = std::sin(phi);
    m_rotation.e_11 = std::cos(phi);
};
