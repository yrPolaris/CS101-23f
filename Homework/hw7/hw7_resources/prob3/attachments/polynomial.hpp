#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <vector>
#include <math.h> 
#include <stdio.h>

class Polynomial {
  std::vector<double> m_coeffs;
public:
  static auto isZero(double x) {
    static constexpr auto eps = 1e-8;
    return x < eps && -x < eps;
  }

  void adjust()
  {
    while (!m_coeffs.empty() && isZero(m_coeffs.back()))
    {
      m_coeffs.pop_back();
    }
    if (m_coeffs.empty())
    {
      m_coeffs.push_back(0.0);
    }
  }


public:
  Polynomial()
  {
    m_coeffs.push_back(0.0);
    adjust();
  }

  explicit Polynomial(const std::vector<double> &other)
  {
    m_coeffs = other;
    adjust();
  }

  explicit Polynomial(std::vector<double> &&other)
  {
    m_coeffs = std::move(other);
    adjust();
  }

template <
    typename InputIterator,
    typename = std::enable_if_t<std::is_base_of_v<
        std::input_iterator_tag,
        typename std::iterator_traits<InputIterator>::iterator_category>>>
Polynomial(InputIterator begin, InputIterator end) : m_coeffs(begin, end) {
  adjust();
}


  Polynomial(const Polynomial &other)
  {
    m_coeffs = other.m_coeffs;
    adjust();
  }

  Polynomial &operator=(const Polynomial &other)
  {
    m_coeffs = other.m_coeffs;
    adjust();
    return *this;
  }

  Polynomial(Polynomial &&other)
  {
    m_coeffs = std::move(other.m_coeffs);
    adjust();
  }

  Polynomial &operator=(Polynomial &&other)
  {
    if (*this != other)
    {
      m_coeffs = std::move(other.m_coeffs);
      adjust();
    }
    return *this;
  }

  ~Polynomial(){};


  std::size_t deg() const
  {
    return m_coeffs.size()-1;
  }

  const double &operator[](std::size_t i) const
  {
      return m_coeffs[i];
  }

  void setCoeff(std::size_t i, double c)
  {
    if (i >= this->deg())
    {
      m_coeffs.resize(i+1, 0.0);
      m_coeffs[i] = c;
    }
    else if (i < this->deg())
    {
      m_coeffs[i] = c;
    }
    adjust();
  }

  bool operator==(const Polynomial& other) const
  {
    if (deg() == other.deg())
    {
      for (std::size_t i = 0; i <= this->deg(); i++)
      {
        if (!isZero((this->m_coeffs)[i] - other.m_coeffs[i]))
        {
          return false;
        }
        else if (isZero((this->m_coeffs)[i] - other.m_coeffs[i]) && i == this->deg())
        {
          return true;
        }
      }
    }
    return false;
  }

  bool operator!=(const Polynomial& other) const
  {
    return !(*this == other);
  }

  double operator()(double x) const
  {
    double res = 0;
    for (std::size_t i = 0; i <= this->deg(); i++)
    {
      res += m_coeffs[i] * pow(x, i);
    }
    return res;
  }

  Polynomial operator-() const
  {
    Polynomial res = *this;
    for (std::size_t i = 0; i <= this->deg(); i++)
    {
      res.m_coeffs[i] = -res.m_coeffs[i];
    }
    return res;
  }

  Polynomial operator+(const Polynomial& other) const
  {
    Polynomial res = *this;
    if (this->deg() >= other.deg())
    {
      res.m_coeffs = this->m_coeffs;
      for (std::size_t i = 0; i <= other.deg(); i++)
      {
        res.m_coeffs[i] = res.m_coeffs[i] + other.m_coeffs[i];
      }
    }
    else
    {
      res.m_coeffs = other.m_coeffs;
      for (std::size_t i = 0; i <= this->deg(); i++)
      {
        res.m_coeffs[i] = res.m_coeffs[i] + this->m_coeffs[i];
      }
    }
    res.adjust();
    return res;
  }

  Polynomial& operator+=(const Polynomial& other)
  {
    *this = *this + other;
    return *this;
  }

  Polynomial operator-(const Polynomial& other) const
  {
    return *this + (-other);
  }

  Polynomial& operator-=(const Polynomial& other)
  {
    return *this += (-other);
  }

  Polynomial operator*(const Polynomial& other) const
  {
    std::size_t degree = this->deg() + other.deg();
    Polynomial res;
    res.m_coeffs.resize(degree+1, 0.0);
    for (std::size_t i = 0; i <= this->deg(); i++)
    {
      for (std::size_t j = 0; j <= other.deg(); j++)
      {
        res.m_coeffs[i + j] += (this->m_coeffs[i] * other.m_coeffs[j]);
      }
    }
    res.adjust();
    return Polynomial(res);
  }

  Polynomial& operator*=(const Polynomial& other)
  {
    *this = (*this * other);
    this->adjust();
    return *this;
  }

  Polynomial derivative() const
  {
    Polynomial res;
    if (this->deg() == 0)
    {
      res.m_coeffs.resize(1, 0.0);
      return res;
    }
    else
    {
      res.m_coeffs.resize(this->deg(), 0.0);
      for (std::size_t i = 1; i <= this->deg(); i++)
      {
        res.m_coeffs[i - 1] = m_coeffs[i] * i;
      }
      return res;
    }

  }

  Polynomial integral() const
  {
    Polynomial res;
    res.m_coeffs.resize(this->deg()+2, 0.0);
    for (std::size_t i = 0; i <= this->deg(); i++)
    {
      res.m_coeffs[i + 1] = m_coeffs[i] / (i + 1);
    }
    return res;
  }



  // Other members ...
};

// Add non-member functions if you need.

#endif // POLYNOMIAL_HPP