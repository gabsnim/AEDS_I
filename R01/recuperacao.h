#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool isOperador (char c)
{
  int count = 0;
  bool resposta = false;

  if(c == '!' || c == '&' || c == '|')
  {
    count+= 1;
  }
  else if(c == '+' || c == '-' || c == '/' || c == '*' || c == '%')
  {
    count+= 1;
  }
  else if(c == '>' || c == '<' || c == '=')
  {
    count+=1;
  }

  if(count > 0)
  {
    resposta = true;
  }
  return resposta;
}

bool isLetra (char c)
{   
    bool resposta = false;

    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        resposta = true;
    }
    return resposta;
}

bool isMaiuscula (char c)
{
    bool resposta = false;

    if(c >= 'A' && c <= 'Z')
    {
        resposta = true;
    }
    return resposta;
}

bool isMinuscula (char c)
{
    bool resposta = false;

    if(c >= 'a' && c <= 'z')
    {
        resposta = true;
    }
    return resposta;
}

bool isDigit (char c)
{
    bool resposta = false;

    if(c >= '0' && c <= '9')
    {
        resposta = true;
    }
    return resposta;
}