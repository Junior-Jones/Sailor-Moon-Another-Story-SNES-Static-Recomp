#ifndef SAILOR_MOON_CLOCK_DOMAIN_H
#define SAILOR_MOON_CLOCK_DOMAIN_H
#include <stdint.h>

/* Deterministic NTSC timing profile matched to the qualified headless
 * reference. S-CPU and SMP share the same master-clock conversion. */
enum {
    SM09_MASTER_NUMERATOR = 21477270u,
    SM09_MASTER_DENOMINATOR = 1u,
    SM09_SMP_NUMERATOR = 102400u,
    SM09_SMP_DENOMINATOR = 2147727u,
    SM09_NORMAL_LINE = 1364u,
    SM09_SHORT_LINE = 1360u,
    SM09_FIELD_LINES = 262u
};
typedef struct Sm09SmpJoin {
    uint64_t target_cycles;
    uint32_t remainder;
} Sm09SmpJoin;
typedef struct Sm09TimingProfile {
    uint32_t master_numerator, master_denominator;
    uint32_t smp_numerator, smp_denominator;
    uint16_t normal_line, short_line, field_lines;
} Sm09TimingProfile;
const Sm09TimingProfile *sm09_timing_profile(void);
void sm09_smp_cold(Sm09SmpJoin *);
int sm09_smp_advance(Sm09SmpJoin *, uint32_t);
#endif
