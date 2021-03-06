/* *
 * Copyright (c) 2015, Suayb S. Arslan
 * MEF University, Ayazaga, Maslak, IST/TURKEY.
 * All rights reserved.
 *
 * Encoder.h file for struct and file declerations.
*/
#include <stdio.h>
//#include <sys/time.h>
#include <sys/stat.h>
#include <stdint.h>

#include "omp.h"

#ifndef ENCODER_H
#define ENCODER_H

//typedef __uint128_t sym_t;

typedef uint64_t sym_t;

typedef struct stat stat_t;

typedef struct distribution{
  int maxdeg;
  char *name;
  double *cdf;
} dist_t;

typedef struct symbolS{ // Source symbol
  int *connections;
  int deg;
} symbol_s;

typedef struct symbolT{ // Coded symbol
  unsigned ID;
  int deg;
  int *connections;
} symbol_t;

typedef struct encoder{
  int sizesb;
  int sizek;
  int sizen;
  int sizet;
  unsigned encSeed;
  sym_t *srcdata;
  sym_t *encdata;
  //sym_t __attribute__((aligned(16))) *srcdata;
  //sym_t __attribute__((aligned(16))) *encdata;
  symbol_s *srcSymbolArray; 
  symbol_t *encSymbolArray;
}encoder_t;

typedef struct temp_conn{
    symbol_s *conn;
}temp_conn_t;

void *PrepareEnc( encoder_t *codeword, dist_t *Dist, int disks);

void SWOR(int samSize, int popSize, int *connections);

void EncodeCompute(encoder_t *EncoderObj);

void EncodeComputeFast(encoder_t *EncoderObj);

void EncodeComputeFast2(encoder_t *EncoderObj);

void EncodeComputeFast_mt(encoder_t *EncoderObj, int numOfThreads);

void align_XOR(sym_t * __restrict a, sym_t * __restrict b, int size);

void SetDistribution(dist_t *Dist);

void align_XOR2(sym_t * __restrict a, sym_t ** __restrict b, int size, int deg);

int numofzeros(temp_conn_t *temp, int n);

int* setXOR(int* connections_a, int deg_a, int* connections_b, int deg_b);

void* uniqueSET(int unique_set[], int* connections_a, int deg_a, int* connections_b, int deg_b);

#endif /*ENCODER_H*/
