#include<iostream>
/* NULL vs nullptr 
 
 ===============================================================================================
  In C++, NULL is by default 0 (defined in most of the complier) and not necessarily always a pointer.
  I will say that NULL is more of C style thing brought to C++. Most importantly NULL is a macro . 

  nullptr is really a “null pointer” and always a pointer. If you try assigning it to integer. 
  It will cause an error.

  nullptrt is type safe compare to NULL and you should always use nullptr instead of NULL.

  =============================================================================================

  OUTPUT :
  1
  1
  =============================================================================================

*/

int main() {

	int *p = NULL; 
	int ip = NULL;  // also fine

	// NULL is equal to  0 (define in most of the complier)
	std::cout << (p == 0) << std::endl;
	
	// nullptr 
	//int iq = nullptr; //compilation error 

	int *q = nullptr;

	//nullptr value is also  0 but you can use it as integer type . 
	std::cout << (q == 0) << std::endl;

}