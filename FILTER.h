#ifndef FILTER_h
#define FILTER_h

#include <inttypes.h>

template <class T>
class Filter {
  public:
    Filter() {
    };
    virtual T        Apply(T sample) {
      return sample;
    };
    virtual void        Reset() {
    };
};

typedef Filter<int8_t> FilterInt8;
typedef Filter<uint8_t> FilterUInt8;
typedef Filter<int16_t> FilterInt16;
typedef Filter<uint16_t> FilterUInt16;
typedef Filter<int32_t> FilterInt32;
typedef Filter<uint32_t> FilterUInt32;
#endif
