#ifndef CS100_MEMCHECK_H
#define CS100_MEMCHECK_H 1

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 1000

int loc = 0;
struct Record {
  void *ptr;              // address of the allocated memory
  long long size;            // size of the allocated memory
  int line_no;            // line number, at which a call to malloc or calloc happens
  const char *file_name;  // name of the file, in which the call to malloc or calloc happens
};

struct Record records[MAX_RECORDS];

void *recorded_malloc(long long size, int line, const char *file) {
  void *ptr = malloc(size);
  if (ptr != NULL) {
    records[loc].ptr = ptr;
    records[loc].size = size;
    records[loc].line_no = line;
    records[loc].file_name = file;
    loc++;
  }
  return ptr;
}

void *recorded_calloc(long long cnt, size_t each_size, int line, const char *file) {
  void *ptr = calloc(cnt, each_size);
  if (ptr != NULL) {
    records[loc].ptr = ptr;
    records[loc].size = each_size*cnt;
    records[loc].line_no = line;
    records[loc].file_name = file;
    loc++;
  }
  return ptr;
}

void recorded_free(void *ptr, int line, const char *file) {
  if (ptr != NULL)
  {
    for (int i=0; i<loc; i++)
    {
      if (ptr == records[i].ptr)
      {
        records[i].ptr = NULL;
        free(ptr);
        return;
      }
      if(i == (loc-1) && ptr != records[i].ptr)
      {
        printf("Invalid free in file %s, line %d\n",file,line);
        break;
      }
    }
  }
}

void check_leak(void) __attribute__((destructor));

void check_leak(void) {
  int count_allocation = 0;
  long long count_byte = 0;
  printf("Summary:\n");
  for (int i=0; i<loc; i++)
  {
    if (records[i].ptr != NULL)
    {
      printf("%lld bytes memory not freed (allocated in file %s, line %d)\n",records[i].size,records[i].file_name,records[i].line_no);
      count_allocation += 1;
      count_byte += records[i].size;
    }
  }
  if (count_allocation == 0 && count_byte == 0)
  {
    printf("All allocations have been freed.\n");
  }
  else if (count_allocation != 0 || count_byte != 0)
  {
    printf("%d allocation records not freed (%lld bytes in total).\n",count_allocation,count_byte);
  }
}

#define malloc(SIZE) recorded_malloc(SIZE, __LINE__, __FILE__)
#define calloc(CNT, EACH_SIZE) recorded_calloc(CNT, EACH_SIZE, __LINE__, __FILE__)
#define free(PTR) recorded_free(PTR, __LINE__, __FILE__)

#endif // CS100_MEMCHECK_H

int main()
{
    printf("Goodbye World");
}