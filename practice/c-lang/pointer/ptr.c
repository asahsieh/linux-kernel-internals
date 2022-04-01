// Declare
struct GraphicsObject;

// An instance / object from GraphicsObject
//

// will cause an error: storage size of ‘x’ isn’t known
//struct GraphicsObject  x; 
  struct GraphicsObject *x;

int main ()
{
    // Exmaple 1
    char A;
    char *ptrA = &A;
    char *ptrX = ptrA;

    ptrA++;
    ptrA--;

    // Not whole arithmetic operations are supported for on pointer
    //ptrX = ptrA * 1;

    ptrX = ptrA + ((int) ptrA * 1);

    // Example 2
    char *X = 0;
    void *Y = 0;

    char c = *X;
	/*
	ptr.c:31:14: warning: dereferencing ‘void *’ pointer
	   31 |     char d = *Y;
	      |              ^~
	ptr.c:31:14: error: void value not ignored as it ought to be
	   31 |     char d = *Y;
	      |
	*/
    //char d = *Y;

	// explicit casting
	char d = * (char *) Y;
}
