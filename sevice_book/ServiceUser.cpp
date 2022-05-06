#include "ServiceUser.h"

int ServiceUser::get_reward(SimpleUser user)
{
  user.setRewardCount(user.getRewardCount() + 1);
}
