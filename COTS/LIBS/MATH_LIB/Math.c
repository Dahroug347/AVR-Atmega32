
#include "Std_types.h"
#include "Math.h"

u32 Math_u32Power (u32 operand1, u8 operand2)
{
  u8 base = operand1;
  if (operand2 == 0)
  {
	  return 1;
  }
	
  while (operand2 != 1)
  {
      operand1 = operand1*base;
      --operand2;
  }
  return operand1;
}
