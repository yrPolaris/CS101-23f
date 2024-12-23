#ifndef CS10123F_PA1_HASHTABLE
#define CS10123F_PA1_HASHTABLE

#include <cstdint>
#include <cstdio>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include "hash_types.hpp"

template <>
struct std::hash<Website>
{
  static const uint32_t base = 1009u; // 1009 is a prime number.
  uint32_t operator()(const Website &S) const noexcept
  {
    // ------------------------START YOUR CODE----------------
    uint32_t hash_value = 0;
    for (auto k : S.name)
    {
      hash_value = base * hash_value + k;
    }
    return hash_value;
    // ------------------------END OF YOUR CODE----------------
  }
};

template <class Key = Website, class T = IPv4> // template for key type class
                                               // Key and value type class T
class HashTable
{
private:
  enum entrystate
  {
    Unused,
    Used,
    Erased
  };
  const size_t Mod = 1000037u; // 1000037 is a prime number
  std::vector<T> Table;        // main table stores value
  std::vector<Key> Stored_Key; // used for storing original key
  std::vector<entrystate>
      State;                    // keeps the state of every table entry : {Unused, Used or Erased};
  std::vector<size_t> Used_pos; // hint: used for function clear()

public:
  static const std::size_t npos = -1;
  HashTable() : Table(Mod), Stored_Key(Mod), State(Mod, entrystate::Unused) {}

  const T &operator[](const Key &x) const
  {
    std::size_t pos = find(x);
    if (pos == npos)
      throw std::invalid_argument("Key does not exist");
    return Table[pos];
  }

  // ------------------------START YOUR CODE----------------

  std::size_t Search(const Key &x) const
  {
    std::size_t Start = std::hash<Key>{}(x) % Mod;
    auto pos = find(x);
    if (pos != npos)
    {
      return pos;
    }
    auto size = Table.size();
    auto index = Start;
    while (State[index] == entrystate::Used)
    {
      index = (index + 1) % size;
    }
    return index;
  }

  std::size_t find(const Key &x) const
  {
    std::size_t Start = std::hash<Key>{}(x) % Mod;
    auto size = Table.size();
    auto index = Start;
    while (State[index] == entrystate::Used || State[index] == entrystate::Erased)
    {
      if (State[index] == entrystate::Used && Stored_Key[index] == x)
      {
        return index;
      }
      index = (index + 1) % size;
      if (index == Start)
      {
        return npos;
      }
    }
    return npos;
  }

  void insert(const Key &x, const T &value)
  {
    auto pos = find(x);
    if (pos != npos)
    {
      Table[pos] = value;
    }
    else if (pos == npos)
    {
      pos = Search(x);
      Table[pos] = value;
      Stored_Key[pos] = x;
      State[pos] = entrystate::Used;
      Used_pos.push_back(pos);
    }
  }

  bool erase(const Key &x)
  {
    auto pos = find(x);
    if (pos == npos)
    {
      return false;
    }
    State[pos] = entrystate::Erased;
    return true;
  }

  void clear()
  {
    for (auto k : Used_pos)
    {
      State[k] = entrystate::Unused;
    }
    Used_pos.clear();
  }
};

#endif // CS10123F_PA1_HASHTABLE