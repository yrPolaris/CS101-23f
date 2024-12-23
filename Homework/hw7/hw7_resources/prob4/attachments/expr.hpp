#ifndef EXPR_HPP
#define EXPR_HPP

#include <memory>
#include <string>
#include <cassert>

class NodeBase
{                                                             // 注释是孩子不懂事，写着玩，做笔记的
 public:
  NodeBase() = default;
  virtual double eval(double x) const = 0;
  virtual double derivative(double x) const = 0;
  virtual std::string rep() const = 0;
  ~NodeBase() = default;                          
};

class Expr
{
 public:
  std::shared_ptr<NodeBase> m_ptr;

  Expr(std::shared_ptr<NodeBase> ptr) : m_ptr{ptr} {}

  static const Expr x;

  Expr(double value);

  double eval(double x) const
  {
    return m_ptr->eval(x);
  }

  double derivative(double x) const
  {
    return m_ptr->derivative(x);
  }

  std::string rep() const
  {
    return m_ptr->rep();
  }


  friend Expr operator-(const Expr&);
  friend Expr operator+(const Expr&);
  friend Expr operator+(const Expr&, const Expr&);
  friend Expr operator-(const Expr&, const Expr&);
  friend Expr operator*(const Expr&, const Expr&);
  friend Expr operator/(const Expr&, const Expr&);
};


class Variable : public NodeBase
{
public:
  virtual double eval(double x) const override
  {
    return x;
  }

  virtual double derivative(double x) const override
  {
    x = 1;
    return x;
  }

  std::string rep() const override
  {
    return "x";
  }
};


class Constant : public NodeBase
{
  double m_value;

 public:
  Constant(double value) : m_value{value} {}

  double eval(double x) const override
  {
    x = m_value;
    return x;
  }

  double derivative(double x) const override
  {
    x = 0;
    return x;
  }

  std::string rep() const override
  {
    return std::to_string(m_value);
  }


};


const Expr Expr::x{std::make_shared<Variable>()};

Expr::Expr(double value) : m_ptr{std::make_shared<Constant>(value)} {}


class UnaryOperator : public NodeBase
{
  char m_op;
  Expr m_operand;

  double eval(double x) const override
  {
    if (m_op == '-')
    {
      return -m_operand.eval(x);
    }
    else if (m_op == '+')
    {
      return m_operand.eval(x);
    }
    assert(0);
    return 0;
  }

  double derivative(double x) const override
  {
    if (m_op == '-')
    {
      return -m_operand.derivative(x);
    }
    else if (m_op == '+')
    {
      return m_operand.derivative(x);
    }
    assert(0);
    return 0;
  }

  std::string rep() const override
  {
    if (m_op == '+')
    {
      return m_operand.rep();
    }
    else if (m_op == '-')
    {
      return std::string(1,m_op) + "(" + m_operand.rep() + ")";
    }
    assert(0);
    return 0;
  }

 public:
  UnaryOperator(char op, const Expr &operand) : m_op{op}, m_operand{operand} {}
};


class BinaryOperator : public NodeBase
{
 protected:
  char m_op;
  Expr m_left;
  Expr m_right;

 public:
  BinaryOperator(char op, const Expr &left, const Expr &right)
      : m_op{op}, m_left{left}, m_right{right} {}
};


class PlusOp : public BinaryOperator
{
  using BinaryOperator::BinaryOperator;
  double eval(double x) const override
  {
    return m_left.eval(x) + m_right.eval(x);
  }

  double derivative(double x) const override
  {
    return m_left.derivative(x) + m_right.derivative(x);
  }

  std::string rep() const override
  {
    return "(" + m_left.rep() + ") + (" + m_right.rep() + ")";
  }
};

class MinusOp : public BinaryOperator
{
  using BinaryOperator::BinaryOperator;
  double eval(double x) const override
  {
    return m_left.eval(x) - m_right.eval(x);
  }

  double derivative(double x) const override
  {
    return m_left.derivative(x) - m_right.derivative(x);
  }

  std::string rep() const override
  {
    return "(" + m_left.rep() + ") - (" + m_right.rep() + ")";
  }
};

class MultiplyOp : public BinaryOperator {
  using BinaryOperator::BinaryOperator;
  double eval(double x) const override
  {
    return m_left.eval(x) * m_right.eval(x);
  }

  double derivative(double x) const override
  {
    return m_left.derivative(x) * m_right.eval(x) + m_right.derivative(x) * m_left.eval(x);
  }

  std::string rep() const override
  {
    return "(" + m_left.rep() + ") * (" + m_right.rep() + ")";
  }
};

class DivideOp : public BinaryOperator {
  using BinaryOperator::BinaryOperator;
  double eval(double x) const override
  {
    return m_left.eval(x) / m_right.eval(x);
  }

  double derivative(double x) const override
  {
    return (m_left.derivative(x) * m_right.eval(x) - m_right.derivative(x) * m_left.eval(x)) /  (m_right.eval(x) *  m_right.eval(x));
  }

  std::string rep() const override
  {
    return "(" + m_left.rep() + ") / (" + m_right.rep() + ")";
  }
};


Expr operator-(const Expr &operand) {
  return {std::make_shared<UnaryOperator>('-', operand)};
}

Expr operator+(const Expr &operand) {
  return {std::make_shared<UnaryOperator>('+', operand)};
}

Expr operator+(const Expr &left, const Expr &right) {
  return {std::make_shared<PlusOp>('+', left, right)};
}

Expr operator-(const Expr &left, const Expr &right) {
  return {std::make_shared<MinusOp>('-', left, right)};
}

Expr operator*(const Expr &left, const Expr &right) {
  return {std::make_shared<MultiplyOp>('*', left, right)};
}

Expr operator/(const Expr &left, const Expr &right) {
  return {std::make_shared<DivideOp>('/', left, right)};
}

#endif // EXPR_HPP