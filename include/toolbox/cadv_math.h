#include <toolbox/cadv_bool.h>

static inline float MAX_FLOAT(float x, float y) { return ((x > y) ? (x) : (y)); }
static inline int MAX_INT(int x, int y) { return ((x > y) ? (x) : (y)); }

static inline float MIN_FLOAT(float x, float y) { return ((x < y) ? (x) : (y)); }
static inline int MIN_INT(int x, int y) { return ((x < y) ? (x) : (y)); }

#define MAX(x, y) _Generic((x), \
    int: MAX_INT,               \
    float: MAX_FLOAT)(x, y)

#define MIN(x, y) _Generic((x), \
    int: MIN_INT,               \
    float: MIN_FLOAT)(x, y)

static inline int ABS_INT(int n) { return ((n < 0) ? (-n) : (n)); }
static inline float ABS_FLOAT(float n) { return ((n < 0.0f) ? (n * -1.0f) : (n)); }

#define ABS(n) _Generic((n), \
    int: ABS_INT,            \
    float: ABS_FLOAT)(n)

static inline int CLAMP_INT(int val, int min, int max) { return ((val < min) ? (min) : (val > max) ? (max)
                                                                                                   : (val)); }
static inline float CLAMP_FLOAT(float val, float min, float max) { return ((val < min) ? (min) : (val > max) ? (max)
                                                                                                             : (val)); }

#define CLAMP(x, y, z) _Generic((x), \
    int: CLAMP_INT,                  \
    float: CLAMP_FLOAT)(x, y, z)

static inline int SIGN_INT(int x) { return ((x < 0) ? -1 : (x >= 1) ? 1
                                                                    : 0); }
static inline float SIGN_FLOAT(float x) { return ((x < 0.0f) ? -1.0f : (x >= 1.0f) ? 1.0f
                                                                                   : 0.0f); }

#define SIGN(x) _Generic((x), \
    int: SIGN_INT,            \
    float: SIGN_FLOAT)(x)

static inline bool IN_RANGE_INT(int val, int low, int high) { return ((val > high || val < low) ? false : true); }
static inline bool IN_RANGE_FLOAT(float val, float low, float high) { return ((val > high || val < low) ? false : true); }

#define IN_RANGE(val, low, high) _Generic((val), \
    int: IN_RANGE_INT,                           \
    float: IN_RANGE_FLOAT)(val, low, high)


#define ROUND(x) ((long long)((x) + 0.5))
#define EPSILON (1e-9)
