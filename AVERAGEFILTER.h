#ifndef AVERAGEFILTER_h
#define AVERAGEFILTER_h

#include <inttypes.h>
#include "FILTER.h"
#include "FILTERWITHBUFFER.h"

template <class T, class U, uint8_t FILTER_SIZE>class AverageFilter : public FilterWithBuffer<T, FILTER_SIZE> {
  public:
    AverageFilter() : FilterWithBuffer<T, FILTER_SIZE>(), _num_samples(0) {
    };
    virtual T       Apply(T sample);
    virtual void    Reset();
  private:
    uint8_t       _num_samples;
};

typedef AverageFilter<int8_t, int16_t, 2> AverageFilterInt8_Size2;
typedef AverageFilter<int8_t, int16_t, 3> AverageFilterInt8_Size3;
typedef AverageFilter<int8_t, int16_t, 4> AverageFilterInt8_Size4;
typedef AverageFilter<int8_t, int16_t, 5> AverageFilterInt8_Size5;
typedef AverageFilter<uint8_t, uint16_t, 2> AverageFilterUInt8_Size2;
typedef AverageFilter<uint8_t, uint16_t, 3> AverageFilterUInt8_Size3;
typedef AverageFilter<uint8_t, uint16_t, 4> AverageFilterUInt8_Size4;
typedef AverageFilter<uint8_t, uint16_t, 5> AverageFilterUInt8_Size5;
typedef AverageFilter<int16_t, int32_t, 2> AverageFilterInt16_Size2;
typedef AverageFilter<int16_t, int32_t, 3> AverageFilterInt16_Size3;
typedef AverageFilter<int16_t, int32_t, 4> AverageFilterInt16_Size4;
typedef AverageFilter<int16_t, int32_t, 5> AverageFilterInt16_Size5;
typedef AverageFilter<uint16_t, uint32_t, 2> AverageFilterUInt16_Size2;
typedef AverageFilter<uint16_t, uint32_t, 3> AverageFilterUInt16_Size3;
typedef AverageFilter<uint16_t, uint32_t, 4> AverageFilterUInt16_Size4;
typedef AverageFilter<uint16_t, uint32_t, 5> AverageFilterUInt16_Size5;
typedef AverageFilter<int32_t, float, 2> AverageFilterInt32_Size2;
typedef AverageFilter<int32_t, float, 3> AverageFilterInt32_Size3;
typedef AverageFilter<int32_t, float, 4> AverageFilterInt32_Size4;
typedef AverageFilter<int32_t, float, 5> AverageFilterInt32_Size5;
typedef AverageFilter<uint32_t, float, 2> AverageFilterUInt32_Size2;
typedef AverageFilter<uint32_t, float, 3> AverageFilterUInt32_Size3;
typedef AverageFilter<uint32_t, float, 4> AverageFilterUInt32_Size4;
typedef AverageFilter<uint32_t, float, 5> AverageFilterUInt32_Size5;
typedef AverageFilter<float, float, 5> AverageFilterFloat_Size5;

template <class T, class U, uint8_t FILTER_SIZE>T AverageFilter<T, U, FILTER_SIZE>::Apply(T sample) {
  U result = 0;
  FilterWithBuffer<T, FILTER_SIZE>::Apply(sample);
  _num_samples++;
  if ( _num_samples > FILTER_SIZE || _num_samples == 0 )_num_samples = FILTER_SIZE;
  for (uint8_t i = 0; i < FILTER_SIZE; i++)result += FilterWithBuffer<T, FILTER_SIZE>::samples[i];
  return (T)(result / _num_samples);
}

template <class T, class U, uint8_t FILTER_SIZE>
void AverageFilter<T, U, FILTER_SIZE>::Reset() {
  FilterWithBuffer<T, FILTER_SIZE>::Reset();
  _num_samples = 0;
}
#endif
