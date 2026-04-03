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

