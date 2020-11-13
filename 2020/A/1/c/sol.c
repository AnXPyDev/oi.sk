#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

struct Cross {
  char flooded;
  int nlinked;
  struct Cross **linked;
};

int n, m, k;
struct Cross *crosses;

void loadsym(char *buf, FILE *file) {
  char c;
  while (1) {
    c = fgetc(file);
    if (c == ' ' || c == '\n' || feof(file)) {
      *buf = '\0';
      break;
    }
    *buf = c;
    ++buf;
  }
}

void load() {
  char *buf = malloc(1024);
  loadsym(buf, stdin);
  n = atoi(buf);
  loadsym(buf, stdin);
  m = atoi(buf);
  loadsym(buf, stdin);
  k = atoi(buf);

  crosses = calloc(n, sizeof(struct Cross));
  for (int i = 0; i < n; ++i) {
    loadsym(buf, stdin);
    if (*buf == '1') {
      (crosses + i)->flooded = 1;
    }
  }

  int *nol = (int*)calloc(n, sizeof(int));
  int *roads = (int*)malloc(sizeof(int) * m * 2);
  int a, b;
  for (int i = 0; i < m; ++i) {
    loadsym(buf, stdin);
    a = atoi(buf);
    loadsym(buf, stdin);
    b = atoi(buf);
    *(nol + a) += 1;
    *(nol + b) += 1;
    *(roads + 2 * i) = a;
    *(roads + 2 * i + 1) = b;
  }

  for (int i = 0; i < n; ++i) {
    (crosses + i)->linked = malloc(sizeof(struct Cross*) * (*(nol + i)));
    (crosses + i)->nlinked = *(nol + i);
  }

  memset(nol, 0, sizeof(int) * n);

  
  for (int i = 0; i < m; ++i) {
    int a = *roads;
    int b = *(roads + 1);
    *((crosses + a)->linked + *(nol + a)) = crosses + b;
    *((crosses + b)->linked + *(nol + b)) = crosses + a;
    *(nol + a) += 1;
    *(nol + b) += 1;
    roads += 2;
  }

  free(buf);
  free(nol);
  free(roads - (m * 2));
}

int result = -1;

void findway(struct Cross *pos, struct Cross *last, int ck, int depth) {
  if (depth > result && result != -1) {
    return;
  }
  if (pos - crosses == n - 1) {
    result = depth;
    return;
  }
  if (pos->flooded && ck < 0) {
    ck = k;
  }
  if (ck == 0) {
    return;
  }

  for (int i = 0; i < pos->nlinked; ++i) {
    if (*(pos->linked + i) == last) {
      continue;
    }
    findway(*(pos->linked + i), pos, ck - 1, depth + 1);
  }
  return;
} 

struct State {
  struct Cross *pos;
  struct Cross *last;
  int ck;
  int i;  
};

void printstate(struct State* state) {
  printf("%li %li %i %i", state->pos - crosses, state->last - crosses, state->ck, state->i);
}

void findwaynr() {
}

int main() {
  load();
  result = -1;
  findwaynr();
  printf("%li\n", result);
}
