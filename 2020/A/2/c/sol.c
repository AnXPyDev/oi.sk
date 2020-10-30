#include <stdio.h>
#include <malloc.h>

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

const char U = 4;

unsigned int n;
unsigned int result;
signed char *cps;

void load() {
  char *buf = malloc(1024);
  loadsym(buf, stdin);
  n = (unsigned int)atol(buf);
  cps = (signed char*)malloc(n);
  for (unsigned int i = 0; i < n; ++i) {
    loadsym(buf, stdin);
    *(cps + i) = (signed char)atoi(buf);
  }
  free(buf);
}

unsigned int checkp() {
  unsigned int result = 0;
  unsigned int cnt = 0;
  for (unsigned int x = 0; x < n; ++x) {
    ++cnt;
    if (*(cps + x) == (signed char)4) {
      if (cnt > result) {
        result = cnt;
      }
      cnt = 0;
    }
  }
  if (cnt > result) {
    return cnt;
  }
  return result;
  
}

void solve() {
  for (unsigned int s = 1; s < n; ++s) {
    unsigned int nf = 0;
    for (unsigned int x = 0; x < ((n - s) + 1); ++x) {
      if (*(cps + x) == (signed char)4) {
        continue;
      }
      int sum = 0;
      for (unsigned int o = 0; o < s; ++o) {
        int c = (int)(*(cps + (x + o)));
        if (c == 4) {
          sum = 1;
          break;
        }
        sum += c;
      }
      if (sum == 0) {
        nf = 0;
        ++result;
        for (unsigned int o = 0; o < s; ++o) {
          *(cps + (x + o)) = (signed char)4;
        }
      } else {
        ++nf;
      }
    }
    if (nf > (signed char)5) {
      unsigned int max = checkp();
      if (max < s) {
        break;
      } else {
        nf = 0;
      }
    }
  }
}

int main() {
  load();
  result = 0;
  solve();
  printf("%u\n", result);
  free(cps);
  return 0;
}
