#include <stdio.h>
#include <iocslib.h>

#define LOOP 55
#define VSYNC_NOWAIT (1 << 31)

static void spaletNoWait(void) {
  int i;

  for (i = 0; i < LOOP; i += 1) {
    SPALET (VSYNC_NOWAIT + 0, 1, 0);
  }
}

static void spaletVSync(void) {
  int i;

  for (i = 0; i < LOOP; i += 1) {
    SPALET (0, 1, 0);
  }
}


static void spRegstNoWait(void) {
  int i;

  for (i = 0; i < LOOP; i += 1) {
    SP_REGST (VSYNC_NOWAIT + 0, 0, 0, 0, 0);
  }
}

static void spRegstVSync(void) {
  int i;

  for (i = 0; i < LOOP; i += 1) {
    SP_REGST (0, 0, 0, 0, 0);
  }
}

static int count(void (*act) (void)) {
  int start = ONTIME();
  act();
  return ONTIME() - start;
}


int main(void) {
  CRTMOD(0);

  printf ("SPALET()\n");
  printf ("nowait: %d\n", count(spaletNoWait));
  printf ("vsync: %d\n", count(spaletVSync));

  printf ("\nSP_REGST()\n");
  printf ("nowait: %d\n", count(spRegstNoWait));
  printf ("vsync: %d\n", count(spRegstVSync));

  return 0;
}
