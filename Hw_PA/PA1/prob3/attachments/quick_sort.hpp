#include <iostream>
#include <vector>

auto random_choice(auto begin, auto end)
{
  // This is only a possible implementation of random_choice.
  // You can use this for your convenience or design a better one.
  std::size_t length = end - begin;
  std::size_t idx = std::rand() % length;
  return begin + idx;
}

void quick_sort(std::random_access_iterator auto begin,
                std::random_access_iterator auto end, auto compare)
{
  // TODO: IMPLEMENT THIS.
  if (begin == end || begin == end - 1)
  {
    return;
  }
  else if (begin == end - 2)
  {
    if (compare(*(end - 1), *(begin)))
    {
      std::swap(*(begin), *(end - 1));
    }
  }
  else
  {
    auto pivot = random_choice(begin, end);
    std::swap(*pivot, *(end - 1));
    auto left = begin;
    auto right = end - 2;
    while (left < right)
    {
      while (left < right + 1 && compare(*(left), *(end - 1)))
      {
        left++;
      }
      while (right > left && !compare(*(right), *(end - 1)))
      {
        right--;
      }
      if (left < right)
      {
        std::swap(*(left), *(right));
      }
    }
    std::swap(*left, *(end - 1));
    quick_sort(begin, left, compare);
    quick_sort(left + 1, end, compare);
  }
}

void quick_sort(std::random_access_iterator auto begin,
                std::random_access_iterator auto end)
{
  quick_sort(begin, end, std::less<>{});
}