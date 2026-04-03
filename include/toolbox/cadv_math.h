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
static inline float ABS_FLOAT(float n) { return ((n < 0) ? (n * -1) : (n)); }

#define ABS(n) _Generic((n), \
    int: ABS_INT,            \
    float: ABS_FLOAT)(n)

static inline int CLAMP_INT(int val, int min, int max) {return ((val < min) ? (min) : (val > max) ? (max) : (val)); }
static inline float CLAMP_FLOAT(float val, float min, float max) { return ((val < min) ? (min) : (val > max) ? (max) : (val)); }

#define CLAMP(x, y, z) _Generic((x), \
    int: CLAMP_INT,                  \
    float: CLAMP_FLOAT)(x, y, z)

#define ROUND(x) ((long long)((x) + 0.5))
#define EPSILON (1e-9)
