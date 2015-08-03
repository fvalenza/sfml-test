#ifndef __SFML_CATEGORY__
#define __SFML_CATEGORY__

namespace Category
{
  enum Type
  {
    None = 0,
    Scene = 1 << 0,
    PlayerAircraft = 1 << 1,
    AlliedAircraft = 1 << 2,
    EnnemyAircraft = 1 << 3,
  };
}
#endif
