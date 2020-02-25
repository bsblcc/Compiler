#include <stdio.h>

int add(int x, int y)
{
  return x + y + 100;
}


int main()
{


  int a;
  int b = 5 << 2;
  a = 6 ^ 2 & (++b) * (b + 102 / 5);
  if (add(a,b) + 100 <a + a * b)
  {
    b++;
  }
  else
  {
    a++;
  }
  return 0;
}
add (int x, int y)
{
  int D.3026;
  int D.3027;

  D.3027 = x + y;
  D.3026 = D.3027 + 100;
  return D.3026;
}


main ()
{
  int D.3029;
  int D.3030;
  int D.3031;
  int D.3032;
  int D.3033;
  int D.3034;
  int D.3035;
  int D.3039;

  {
    int a;
    int b;

    b = 20;
    b = b + 1;
    D.3029 = b + 20;
    D.3030 = b * D.3029;
    D.3031 = D.3030 & 2;
    a = D.3031 ^ 6;
    D.3032 = add (a, b);
    D.3033 = D.3032 + 100;
    D.3034 = b + 1;
    D.3035 = D.3034 * a;
    if (D.3033 < D.3035) goto <D.3036>; else goto <D.3037>;
    <D.3036>:
    b = b + 1;
    goto <D.3038>;
    <D.3037>:
    a = a + 1;
    <D.3038>:
    D.3039 = 0;
    return D.3039;
  }
  D.3039 = 0;
  return D.3039;
}


