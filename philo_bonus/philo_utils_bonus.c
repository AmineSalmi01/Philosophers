#include "Philosophers_bonus.h"

size_t time_passed(size_t start)
{
    size_t new;

    new = get_time();
    return (new - start);
}
