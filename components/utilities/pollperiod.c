#include "utilities.h"

void setPollPeriod(uint32_t pollPeriod) {
  otInstance *aInstance = esp_openthread_get_instance();

  otLogNotePlat("Poll period is currently %" PRIu32 "",
                otLinkGetPollPeriod(aInstance));

  otError error = otLinkSetPollPeriod(aInstance, pollPeriod);
  if (error == OT_ERROR_INVALID_ARGS) {
    otLogCritPlat("Failed to set poll period with value %" PRIu32 "", pollPeriod);
    return;
  }

  uint32_t newPollPeriod = otLinkGetPollPeriod(aInstance);
  assert(newPollPeriod == pollPeriod);
  otLogNotePlat("Poll period has now been set to %" PRIu32 "", newPollPeriod);

  return;
}