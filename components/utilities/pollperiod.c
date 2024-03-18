#include "utilities.h"

void setPollPeriod(otInstance *aInstance) {
  uint32_t currentPollPeriod = otLinkGetPollPeriod(aInstance);
  return;
}