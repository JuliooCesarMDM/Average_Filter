#include "AVERAGEFILTER.h"

/********************INFO**************************/
//AUTOR:DESENVOLVEDOR DESCONHECIDO DA ARDUPILOT MEGA (APM)
//ADAPTADO POR:JULIO CESAR MATIAS
//DATA:FEVEREIRO DE 2020
/**************************************************/

/****************MODO DE USO**********************
  //CATEGORIAS DE FILTRAGEM DO AVERAGE:
  AverageFilterInt8_Size2;   //2 ITERAÇÕES PARA VARIAVEIS DE 8 BITS
  AverageFilterInt8_Size3;   //3 ITERAÇÕES PARA VARIAVEIS DE 8 BITS
  AverageFilterInt8_Size4;   //4 ITERAÇÕES PARA VARIAVEIS DE 8 BITS
  AverageFilterInt8_Size5;   //5 ITERAÇÕES PARA VARIAVEIS DE 8 BITS
  AverageFilterUInt8_Size2;  //2 ITERAÇÕES PARA VARIAVEIS SEM SINAL DE 8 BITS
  AverageFilterUInt8_Size3;  //3 ITERAÇÕES PARA VARIAVEIS SEM SINAL DE 8 BITS
  AverageFilterUInt8_Size4;  //4 ITERAÇÕES PARA VARIAVEIS SEM SINAL DE 8 BITS
  AverageFilterUInt8_Size5;  //5 ITERAÇÕES PARA VARIAVEIS SEM SINAL DE 8 BITS
  AverageFilterInt16_Size2;  //2 ITERAÇÕES PARA VARIAVEIS DE 16 BITS
  AverageFilterInt16_Size3;  //3 ITERAÇÕES PARA VARIAVEIS DE 16 BITS
  AverageFilterInt16_Size4;  //4 ITERAÇÕES PARA VARIAVEIS DE 16 BITS
  AverageFilterInt16_Size5;  //5 ITERAÇÕES PARA VARIAVEIS DE 16 BITS
  AverageFilterUInt16_Size2; //2 ITERAÇÕES PARA VARIAVEIS SEM SINAL DE 16 BITS
  AverageFilterUInt16_Size3; //3 ITERAÇÕES PARA VARIAVEIS SEM SINAL DE 16 BITS
  AverageFilterUInt16_Size4; //4 ITERAÇÕES PARA VARIAVEIS SEM SINAL DE 16 BITS
  AverageFilterUInt16_Size5; //5 ITERAÇÕES PARA VARIAVEIS SEM SINAL DE 16 BITS
  AverageFilterInt32_Size2;  //2 ITERAÇÕES PARA VARIAVEIS DE 32 BITS
  AverageFilterInt32_Size3;  //3 ITERAÇÕES PARA VARIAVEIS DE 32 BITS
  AverageFilterInt32_Size4;  //4 ITERAÇÕES PARA VARIAVEIS DE 32 BITS
  AverageFilterInt32_Size5;  //5 ITERAÇÕES PARA VARIAVEIS DE 32 BITS
  AverageFilterUInt32_Size2; //2 ITERAÇÕES PARA VARIAVEIS SEM SINAL DE 32 BITS
  AverageFilterUInt32_Size3; //3 ITERAÇÕES PARA VARIAVEIS SEM SINAL DE 32 BITS
  AverageFilterUInt32_Size4; //4 ITERAÇÕES PARA VARIAVEIS SEM SINAL DE 32 BITS
  AverageFilterUInt32_Size5; //5 ITERAÇÕES PARA VARIAVEIS SEM SINAL DE 32 BITS
  AverageFilterFloat_Size5;  //5 ITERAÇÕES PARA VARIAVEIS FLOAT
*************************************************/

AverageFilterFloat_Size5 Random_Filter; //5 ITERAÇÕES PARA VARIAVEL FLOAT DO RANDOM

void setup() {
  Serial.begin(115200);
  Random_Filter.Reset(); //RESETA O FILTRO
}

//http://en.wikipedia.org/wiki/Random_number_generation
static uint16_t Random(void) {
  static uint32_t m_z = 1234;
  static uint32_t m_w = 76542;
  m_z = 36969 * (m_z & 65535) + (m_z >> 16);
  m_w = 18000 * (m_w & 65535) + (m_w >> 16);
  return ((m_z << 16) + m_w) & 0xFFFF;
}

//GERA UM NOISE USANDO A FUNÇÃO RANDOM ACIMA
static float Random_Noise(void) {
  return ((Random() % 100) - 50) * 0.010;
}

void loop() {
  delay(30);
  Serial.print("RandomSemFiltro:");
  Serial.print(Random_Noise());
  Serial.print("\t");
  Serial.print("RandomFiltrado:");
  Serial.print(Random_Filter.Apply(Random_Noise()));
  Serial.println("");
}
