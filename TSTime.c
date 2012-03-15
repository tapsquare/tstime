/*
 * TSTime.c
 *
 * Copyright (c) 2010-2012 tapsquare, llc <hello@tapsquare.com> 
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#include "TSTime.h"
#include <stdio.h>

void TSTimeInit(TSTime *outTime) {
    mach_timebase_info(&outTime->info);
    outTime->start = mach_absolute_time();
}

float TSTimeLogElapsed(TSTime *outTime, const char *msg) {
    uint64_t elapsed = mach_absolute_time() - outTime->start;
    float elapsed_sec = (float)elapsed * ((float)outTime->info.numer)/((float)outTime->info.denom) / 1000000000.f;
    printf("%s : %f\n", msg, elapsed_sec);
    return elapsed_sec;
}

void TSTimeDestroy(TSTime *outTime) {
    outTime->start = 0;
}
