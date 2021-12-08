#include <elo_rating_system>
int _Volumes_build_elo_rating_system_test_elo_rating_system(int, char**) noexcept
{
  using result = tregana::elo::rating_system<float>::result;
  tregana::elo::rating_system<float> rs{.duel_threshold = 32.0f, .scale = 400.0f, .default_value = 1500.0f};
  if (tregana::elo::rating_system<float>::rate *r; rs.contains(r))
    return 1;
  auto r0 = rs.make_rate();
  if (not rs.contains(r0))
    return 1;
  for (auto i{0}; i != 49 and r0->value < 2000.0f; ++i)
    rs.record<result::win>(r0,  rs.make_rate());
  if (r0->matches.size() != 47)
    return 1;
  return 0;
}
