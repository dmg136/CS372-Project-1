#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "sortedPoints.h"


static void stressTest();


int main(int argc, char **argv)
{
  SortedPoints *sp1;
  Point p1;

  sp1 = (SortedPoints*)malloc(sizeof(SortedPoints));
  assert(sp1);
  sp_init(sp1);

  int ret = sp_addNewPoint(sp1, 2.0, 2.0);
  assert(ret);

  ret =   sp_addNewPoint(sp1, 3.0, 4.0);
  assert(ret);

  ret =   sp_addNewPoint(sp1, 1.0, 1.0);
  assert(ret);

  ret =   sp_addNewPoint(sp1, 2.0, 1.0);
  assert(ret);

  ret =   sp_addNewPoint(sp1, 1.0, 2.0);
  assert(ret);

  ret =   sp_addNewPoint(sp1, 2.0, 2.0);
  assert(ret);

  Point temp = (sp1->pointArray)[0];
  Point temp2 = (sp1->pointArray)[1];
  Point temp3 = (sp1->pointArray)[2];
  Point temp4 = (sp1->pointArray)[3];
  Point temp5 = (sp1->pointArray)[4];
  Point temp6 = (sp1->pointArray)[5];


  printf("sp1 first: (%f, %f)\n", point_getX(&temp), point_getY(&temp));
  printf("sp1 second: (%f, %f)\n", point_getX(&temp2), point_getY(&temp2));
  printf("sp1 third: (%f, %f)\n", point_getX(&temp3), point_getY(&temp3));
  printf("sp1 fourth: (%f, %f)\n", point_getX(&temp4), point_getY(&temp4));
  printf("sp1 fifth: (%f, %f)\n", point_getX(&temp5), point_getY(&temp5));
  printf("sp1 sixth: (%f, %f)\n", point_getX(&temp6), point_getY(&temp6));

  Point *aTemp = (Point*)malloc(sizeof(Point));
  ret = sp_removeFirst(sp1, aTemp);

  printf("----------------------------------\n");
  sp_printArray(sp1);

  ret = sp_removeFirst(sp1, aTemp);

  printf("----------------------------------\n");
  sp_printArray(sp1);

  ret = sp_removeLast(sp1, aTemp);

  printf("-----------------------------------\n");
  sp_printArray(sp1);

  /*
  ret =   sp_addNewPoint(sp2, 3.0, 1.0);
  assert(ret);
  ret =   sp_addNewPoint(sp2, 2.0, 1.0);
  assert(ret);
  ret =   sp_addNewPoint(sp2, 1.0, 1.0);
  assert(ret);
  
  ret =   sp_addNewPoint(sp1, 2.0, 2.0);
  assert(ret);
  ret =   sp_addNewPoint(sp1, 2.0, 2.0);
  assert(ret);
  ret =   sp_addNewPoint(sp1, 2.0, 2.0);
  assert(ret);

  ret= sp_removeFirst(sp1, &p1);
  assert(ret);
  assert(point_getX(&p1) == 1.0);
  assert(point_getY(&p1) == 1.0);
  ret = sp_removeIndex(sp1, 2, &p1);
  assert(ret);
  assert(point_getX(&p1) == 2.0);
  assert(point_getY(&p1) == 2.0);

  ret = sp_addNewPoint(sp1, 2.0, 2.0);
  assert(ret);
  ret = sp_addNewPoint(sp1, 2.0, 2.0);
  assert(ret);
  ret = sp_addNewPoint(sp1, 2.0, 2.0);
  assert(ret);  

  ret= sp_removeFirst(sp1, &p1);
  assert(ret);
  assert(point_getX(&p1) == 1.0);
  assert(point_getY(&p1) == 1.0);
  sp_deleteDuplicates(sp1);
  
  ret= sp_removeFirst(sp1, &p1);
  assert(ret);
  assert(point_getX(&p1) == 1.0);
  assert(point_getY(&p1) == 1.0);
  ret= sp_removeFirst(sp1, &p1);
  assert(ret);
  assert(point_getX(&p1) == 2.0);
  assert(point_getY(&p1) == 2.0);
  ret= sp_removeFirst(sp1, &p1);
  assert(!ret);

  sp_deleteDuplicates(sp2);

  stressTest();
  printf("OK\n");

  */
  return 0;
}

  /*
   * Rudimentary check for memory leaks
   */
static void stressTest()
{
  SortedPoints *sp;
  Point dummy;
  static const int NINSERT = 1024;
  static const int NITER = 20*1024;
  static const int SIZE = 10;
  int ii;
  int jj;
  int ret;
  char *before, *after;
  
  sp = (SortedPoints*)malloc(sizeof(SortedPoints));
  assert(sp);
  sp_init(sp);

  before = (char *)malloc(1);
  printf("This test may take a minute.\n");
  printf("Before: %p\n", before);

  for(ii = 0; ii < NITER; ii++){
    for(jj = 0; jj < NINSERT; jj++){
      sp_addNewPoint(sp, (double)(NINSERT - jj), 1.0);
    }
    ret = sp_removeIndex(sp, SIZE, &dummy);
    assert(0 == ret);
    ret = sp_removeIndex(sp, SIZE - 1, &dummy);
    assert(1 == ret);
    for(jj = 0; jj < SIZE - 1; jj++){
      ret = sp_removeFirst(sp, &dummy);
      assert (1 == ret);
    }
    ret = sp_removeFirst(sp, &dummy);
    assert(0 == ret);
  }

  after = (char *)malloc(1);
  printf("After: %p\n", after);
  printf("Difference: %p\n", (void *)((long)after - (long)before));
  assert(after - before < 1024 * 1024);

}  
