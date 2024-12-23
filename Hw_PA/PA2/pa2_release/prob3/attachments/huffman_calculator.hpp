#ifndef HUFFMAN_CALCULATOR_HPP
#define HUFFMAN_CALCULATOR_HPP

#include <tuple>
#include <vector>
#include <algorithm>

void percolate(std::vector<std::pair<size_t, size_t>> &vector, int i)
{
  int size = vector.size();
  while ((2 * i + 1) < size)
  {
    if (2 * i + 2 >= size)
    {
      if (vector[i].first > vector[2 * i + 1].first)
      {
        std::swap(vector[i], vector[2 * i + 1]);
        i = 2 * i + 1;
      }
      else if (vector[i].first <= vector[2 * i + 1].first)
      {
        break;
      }
    }

    else if (2 * i + 2 < size)
    {
      if (vector[2 * i + 1].first <= vector[2 * i + 2].first)
      {
        if (vector[i].first > vector[2 * i + 1].first)
        {
          std::swap(vector[i], vector[2 * i + 1]);
          i = 2 * i + 1;
        }
        else if (vector[i].first <= vector[2 * i + 1].first)
        {
          break;
        }
      }

      else if (vector[2 * i + 1].first > vector[2 * i + 2].first)
      {
        if (vector[i].first > vector[2 * i + 2].first)
        {
          std::swap(vector[i], vector[2 * i + 2]);
          i = 2 * i + 2;
        }
        else if (vector[i].first <= vector[2 * i + 2].first)
        {
          break;
        }
      }
    }
  }
}

void push(std::vector<std::pair<size_t, size_t>> &vector, std::pair<size_t, size_t> pair)
{
  vector.push_back(pair);
  int i = vector.size() - 1;
  while (i > 0)
  {
    if (i % 2 == 1)
    {
      if (vector[i].first < vector[(i - 1) / 2].first)
      {
        std::swap(vector[i], vector[(i - 1) / 2]);
        i = (i - 1) / 2;
      }
      else if (vector[i].first >= vector[(i - 1) / 2].first)
      {
        break;
      }
    }

    else if (i % 2 == 0)
    {
      if (vector[i].first < vector[(i - 2) / 2].first)
      {
        std::swap(vector[i], vector[(i - 2) / 2]);
        i = (i - 2) / 2;
      }
      else if (vector[i].first >= vector[(i - 2) / 2].first)
      {
        break;
      }
    }
  }
}

void pop(std::vector<std::pair<size_t, size_t>> &vector)
{
  int i = vector.size() - 1;
  std::swap(vector[0], vector[i]);
  vector.pop_back();
  percolate(vector, 0);
}

size_t get_huffman_length(const std::vector<std::pair<size_t, size_t>> &data)
{
  // TODO: Implement this.
  std::vector<std::pair<size_t, size_t>> heap(data);
  std::sort(heap.begin(), heap.end());
  size_t ans = 0;
  while (heap.size() > 1 || heap[0].second > 1)
  {
    if (heap[0].second != 0 && heap[0].second % 2 == 0)
    {
      ans += heap[0].first * heap[0].second;
      heap[0].first *= 2;
      heap[0].second /= 2;
      percolate(heap, 0);
    }

    else if (heap[0].second != 1 && heap[0].second % 2 == 1)
    {
      ans += heap[0].first * (heap[0].second - 1);
      push(heap, std::pair<size_t, size_t>(heap[0].first * 2, (heap[0].second - 1) / 2));
      heap[0].second = 1;
    }

    else if (heap[0].second == 1)
    {
      if (heap.size() >= 3)
      {
        if (heap[1].first <= heap[2].first)
        {
          if (heap[1].second == 1)
          {
            ans += heap[0].first + heap[1].first;
            heap[1].first += heap[0].first;
            percolate(heap, 1);
            pop(heap);
          }
          else if (heap[1].second > 1)
          {
            ans += heap[0].first + heap[1].first;
            heap[0].first += heap[1].first;
            heap[1].second -= 1;
            percolate(heap, 0);
          }
        }

        else if (heap[1].first > heap[2].first)
        {
          if (heap[2].second == 1)
          {
            ans += heap[0].first + heap[2].first;
            heap[2].first += heap[0].first;
            percolate(heap, 2);
            pop(heap);
          }
          else if (heap[2].second > 1)
          {
            ans += heap[0].first + heap[2].first;
            heap[0].first += heap[2].first;
            heap[2].second -= 1;
            percolate(heap, 0);
          }
        }
      }

      else if (heap.size() == 2)
      {
        if (heap[1].second == 1)
        {
          ans += heap[0].first + heap[1].first;
          return ans;
        }
        else if (heap[1].second > 1)
        {
          ans += heap[0].first + heap[1].first;
          heap[0].first += heap[1].first;
          heap[1].second -= 1;
          percolate(heap, 0);
        }
      }
    }
  }
  return ans;
}
#endif // HUFFMAN_CALCULATOR_HPP