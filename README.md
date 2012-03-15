# TSTime
## A very simple time profiling API.

You probably don't need this code. You should probably be using Instruments to
profile your app. For those occasions when you absolutely just have to figure
out which function or method call is taking too long (and how long), TSTime can
save you some, uh, time.

We've used TSTime a ton over the past couple of years at tapsquare, usually to
hunt down draw calls that are killing animation performance (e.g. trying to get
the smoothest scrolling possible.)

Usage is ridiculously simple:

* Add `TSTime.c` and `TSTime.h` to your project.
* Write some code like so:

```

    #include "TSTime.h"

    - (void)someVexinglySlowMethod:(id)someStandinParameterOfNoUseWhatsoever {
        TSTime t;
        TSTimeInit(&t);
        [self someCallWeSuspectMightBeTheCulprit];
        // this line will spit `someCallWeSuspectMightBeTheCulprit: 0.080812` to `stdout`
        // This means the call took 80.8ms
        TSTimeLogElapsed(&t, "someCallWeSuspectMightBeTheCulprit");
        // subsequent calls to `TSTimeLogElapsed` will report the elapsed time
        // since the last call to TSTimeInit, i.e., calls are cumulative. You can
        // call `TSTimeInit` to re-start the timer without first destroying the TSTime
        // instance.
        TSTimeDestroy(&t);
    }
```
