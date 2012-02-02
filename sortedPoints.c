#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "sortedPoints.h"

Point originPoint = {0.0, 0.0};

void sp_shiftPoints(SortedPoints *sp, int position);

/*
 * Initialize data structures, returning pointer
 * to the object.
 */
SortedPoints *sp_init(SortedPoints *sp){

  //init sp data structure here
  sp->size = 0;

  int position;

  for (position = 0; position < sp->size; position++)
  {
	sp->used[position] = 'n';
  }

  return sp;
}

/*
 * Allocate a new point and initialize it to x,y. Then
 * add that point to the SortedPointss list. Return
 * 1 on success and 0 on error (e.g., out of memory).
 */

int sp_addNewPoint(SortedPoints *sp, double x, double y)
{
        
	if (sp->size == 10)
	{
		printf("SortedPoint list full\n");
		return 0;
	}
	else if (sp->size > 10)
	{
		printf("List above 10 for some reason, error\n");
		return 0;
	}

	else
	{
		Point *originPointer = &originPoint;

		//printf("origin point: %f, %f\n", point_getX(originPointer), point_getY(originPointer));

		Point *newPoint = (Point*)malloc(sizeof(Point));
		point_set(newPoint, x, y);

		//printf("new point: %f, %f\n", point_getX(newPoint), point_getY(newPoint));

		int position;
		Point tempPoint;
		Point *tempPointer;

		for (position = 0; position < sp->size; position++)
		{

			if (sp->used[position] == 'n')
			{
				sp->pointArray[position] = *newPoint;
				sp->used[position] = 'y';
				break;
			}

			else
			{
				tempPoint = sp->pointArray[position];
				tempPointer = &tempPoint;

				if (point_distance(originPointer, newPoint) == point_distance(originPointer, tempPointer))
				{
					if (point_getX(newPoint) == point_getX(tempPointer))
					{
						if (point_getY(newPoint) < point_getY(tempPointer))
						{
							//this position holds newPoint
							sp->pointArray[position] = *newPoint;
							//shift everything else over
							sp_shiftPoints(sp, position);

							break;
						} 
					}

					else if (point_getX(newPoint) < point_getX(tempPointer))
					{
						//this position holds newPoint
						sp->pointArray[position] = *newPoint;
						//shift everything else over
						sp_shiftPoints(sp, position);

						break;
					}
				}

				else if (point_distance(originPointer, newPoint) < point_distance(originPointer, tempPointer))
				{
					//this position holds newPoint
					sp->pointArray[position] = *newPoint;
					//shift everything else over
					sp_shiftPoints(sp, position);

					break;
				}

			}
		
		}		

		sp->size = sp->size + 1;
		return 1;
	}
        
	
}

void sp_shiftPoints(SortedPoints *sp, int position)
{

	//stub

}

/*
int sp_addNewPoint(SortedPoints *sp, double x, double y)
{
  if (sp->size >= 10)
  {
	printf("SortedPoint list full\n");
	return 0;
  }
  else
  {

	Point *originPointer = &originPoint;

	printf("origin point: %f, %f\n", point_getX(originPointer), point_getY(originPointer));

	Point *newPoint = (Point*)malloc(sizeof(Point));
	point_set(newPoint, x, y);

	double newPointDistance = point_distance(originPointer, newPoint);

	int position;
	double tempDistance;

	Point tempPoint;
	Point *tempPointer; 
	Point swapPoint;
	Point *swapPointer;

        for (position = 0; position < sp->size; position++)
	{
		tempPoint = sp->pointArray[position];
		tempPointer = &tempPoint;

		if (tempPointer == NULL)
		{
			sp->pointArray[position] = *newPoint;
			sp->size = sp->size + 1;
			break;
		}

		tempDistance = point_distance(originPointer, tempPointer);
		if (newPointDistance < tempDistance)
		{
			
			swapPoint = sp->pointArray[position];
			swapPointer = &swapPoint;
			sp->pointArray[position] = *newPoint;

			while (position < sp->size)
			{
				position++;
				swapPoint = sp->pointArray[position];
				sp->pointArray[position] = tempPoint;
				tempPoint = sp->pointArray[position];
			}

			break;
		}
		else if (newPointDistance == tempDistance)
		{
			if (point_getX(newPoint) < point_getX(tempPointer))
			{
				swapPoint = sp->pointArray[position];
				swapPointer = &swapPoint;
				sp->pointArray[position] = *newPoint;

				while (position < sp->size)
				{
					position++;
					swapPoint = sp->pointArray[position];
					sp->pointArray[position] = tempPoint;
					tempPoint = sp->pointArray[position];
				}

				break;
	
			}
			else if (point_getX(newPoint) == point_getX(tempPointer))
			{
				if (point_getY(newPoint) < point_getY(tempPointer))
				{
					swapPoint = sp->pointArray[position];
					swapPointer = &swapPoint;
					sp->pointArray[position] = *newPoint;

					while (position < sp->size)
					{
						position++;
						swapPoint = sp->pointArray[position];
						sp->pointArray[position] = tempPoint;
						tempPoint = sp->pointArray[position];
					}

					break;
				}
				
				else if (point_getY(newPoint) == point_getY(tempPointer))
				{
					position++;
				}
			}
		}
        }
	sp->size = sp->size + 1;
	free(tempPointer);
	free(swapPointer);
	return 1;
  
}
*/

/*
  * Remove the first point from the sorted list,
  * storing its value in *ret. Returns 1 on success
  * and 0 on failure (empty list).
  */

int sp_removeFirst(SortedPoints *sp, Point *ret)
{
	assert(0);
	return 0;
}

/*
int sp_removeFirst(SortedPoints *sp, Point *ret)
{
  //don't forget to free point!
  Point temp;  
  if (sp->size == 0)
  	REturn 0;
  else {

	int i;

	//get first point and assign to ret
	temp = sp->pointArray[0];
	ret = &temp;
	
	free(ret);

	for (i = 1; i < sp->size; i++) {
		sp->pointArray[i-1] = sp->pointArray[i];	
	}
	return 1;
  }
  assert(0);
  return 0;

}
*/
/*
  * Remove the last point from the sorted list,
  * storing its value in *ret. Returns 1 on success
  * and 0 on failure (empty list).
  */

int sp_removeLast(SortedPoints *sp, Point *ret)
{
	assert(0);
	return 0;
}

/*
int sp_removeLast(SortedPoints *sp, Point *ret)
{
  Point temp;

  //don't forget to free point!
  if (sp->size == 0)
	return 0;
  else {
  	temp = sp->pointArray[sp->size - 1];
	ret = &temp;
  	free(ret);
  	sp->size = sp->size - 1;
  	return 1;
  }

  assert(0);
  return 0;
}
*/

/*
  * Remove the point that appears in position
  * <index> on the sorted list, storing its 
  * value in *ret. Returns 1 on success
  * and 0 on failure (too short list).
  *
  * The first item on the list is at index 0.
  */
int sp_removeIndex(SortedPoints *sp, int index, Point *ret)
{

  //don't forget to free point!
  assert(0); // TBD
  return 0;
}


/*
  * Delete any duplicate records. E.g., if
  * two points on the list have *identical*
  * x and y values, then delete one of them.
  * Return the number of records deleted.
  */
int sp_deleteDuplicates(SortedPoints *sp)
{
  assert(0); // TBD
  return -1;
}


