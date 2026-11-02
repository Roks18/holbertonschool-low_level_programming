# Green Efficiency Analysis

## Measurement Methodology

The experiments were conducted using C programs compiled with the required GCC flags: `-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`. Execution time was measured using the C `clock()` function and `CLOCKS_PER_SEC`.

The baseline experiment executed 100,000,000 iterations three times. The measured execution times were 0.126282 seconds, 0.124377 seconds, and 0.122675 seconds. The average execution time was approximately 0.124445 seconds.

The algorithm comparison was also executed three times. Both algorithms were measured separately during each execution. Their average execution times were calculated from the three recorded results.

Finally, the instrumentation experiment measured the total execution time and the duration of three individual phases: dataset construction, dataset processing, and checksum reduction.

## Observed Performance Differences

The baseline loop showed relatively consistent execution times across its three runs. The difference between the fastest and slowest measurements was only 0.003607 seconds. Its average execution time was approximately 0.124445 seconds for 100 million iterations.

The algorithm comparison showed a much larger difference. The naive algorithm recorded execution times of 2.364210, 2.501148, and 2.274518 seconds, giving an average of approximately 2.379959 seconds. The single-pass algorithm recorded 0.000092, 0.000066, and 0.000061 seconds, with an average of approximately 0.000073 seconds.

Based on these averages, the naive implementation took approximately 32,602 times longer than the single-pass implementation. The source code helps explain this difference: the naive implementation uses nested loops, while the single-pass implementation traverses the array once.

However, their results were different: 625025000 for the naive algorithm and 25000 for the single-pass algorithm. Therefore, the measurements do not represent two implementations producing the same result.

The instrumentation experiment measured a total of 0.000414 seconds. Dataset construction took 0.000182 seconds, processing took 0.000148 seconds, and checksum reduction took 0.000082 seconds.

## Relation Between Runtime and Energy Consumption

Execution time can be useful when studying software efficiency because it indicates how long a program takes to perform its work. A program that completes its task faster may spend less time using the CPU.

The algorithm comparison demonstrates a substantial runtime difference between the two implementations. However, this experiment did not directly measure electricity consumption or CPU power. Consequently, it cannot prove that the single-pass implementation consumed a specific amount of energy or calculate an exact energy saving.

Runtime is therefore an indicator that can help investigate energy efficiency, but it is not an energy measurement by itself.

## Limitations of the Experiment

Several limitations must be considered. First, all measurements were performed on one machine and may vary depending on the hardware, operating system, and system activity.

Second, the instrumentation experiment was recorded only once. Its phase measurements are very short, so small timing variations can have a noticeable effect on the results.

Third, the algorithm comparison is not a perfectly equivalent comparison because the two functions return different results. Their execution times cannot establish that one is a faster replacement for the other while preserving identical behavior.

Finally, the experiments used CPU execution time rather than direct power or energy measurements.

## Practical Engineering Takeaway

These experiments demonstrate why measuring software performance matters. The baseline provides a reference measurement, while the algorithm comparison illustrates how implementation structure can strongly influence execution time.

The instrumentation experiment also shows how measuring individual phases helps identify where execution time is spent.

A practical engineering approach is to measure performance, verify that implementations produce equivalent results, repeat experiments, and consider the limitations of the measurement environment. Efficient software should not only execute quickly but also produce correct results. Direct energy measurements are necessary before making precise claims about electricity consumption or environmental impact.
