/**
* @license Apache-2.0
*
* Copyright (c) 2018 The Stdlib Authors.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/**
* Benchmark `is_contiguous`.
*/
#include "stdlib/ndarray/base/assert/is_contiguous.h"
#include "stdlib/ndarray/dtypes.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#define NAME "is-contiguous"
#define ITERATIONS 1000000
#define REPEATS 3

/**
* Prints the TAP version.
*/
void print_version() {
	printf( "TAP version 13\n" );
}

/**
* Prints the TAP summary.
*
* @param total     total number of tests
* @param passing   total number of passing tests
*/
void print_summary( int total, int passing ) {
	printf( "#\n" );
	printf( "1..%d\n", total ); // TAP plan
	printf( "# total %d\n", total );
	printf( "# pass  %d\n", passing );
	printf( "#\n" );
	printf( "# ok\n" );
}

/**
* Prints benchmarks results.
*
* @param elapsed   elapsed time in seconds
*/
void print_results( double elapsed ) {
	double rate = (double)ITERATIONS / elapsed;
	printf( "  ---\n" );
	printf( "  iterations: %d\n", ITERATIONS );
	printf( "  elapsed: %0.9f\n", elapsed );
	printf( "  rate: %0.9f\n", rate );
	printf( "  ...\n" );
}

/**
* Returns a clock time.
*
* @return clock time
*/
double tic() {
	struct timeval now;
	gettimeofday( &now, NULL );
	return (double)now.tv_sec + (double)now.tv_usec/1.0e6;
}

/**
* Generates a random double on the interval [0,1].
*
* @return random double
*/
double rand_double() {
	int r = rand();
	return (double)r / ( (double)RAND_MAX + 1.0 );
}

/**
* Runs a benchmark.
*
* @return elapsed time in seconds
*/
double benchmark() {
	double elapsed;
	int8_t b;
	double t;
	int i;

	int64_t shape[] = { 10, 10, 10 };
	int64_t strides[] = { 1, 10, 100 };
	int64_t offset = 0;
	int64_t ndims = 3;

	t = tic();
	for ( i = 0; i < ITERATIONS; i++ ) {
		offset += 1;
		b = stdlib_ndarray_is_contiguous( STDLIB_NDARRAY_UINT8, ndims, shape, strides, offset );
		if ( b != 0 && b!= 1 ) {
			printf( "unexpected result\n" );
			break;
		}
	}
	elapsed = tic() - t;
	if ( b != 0 && b != 1 ) {
		printf( "unexpected result\n" );
	}
	return elapsed;
}

/**
* Main execution sequence.
*/
int main( void ) {
	double elapsed;
	int i;

	// Use the current time to seed the random number generator:
	srand( time( NULL ) );

	print_version();
	for ( i = 0; i < REPEATS; i++ ) {
		printf( "# c::native::%s\n", NAME );
		elapsed = benchmark();
		print_results( elapsed );
		printf( "ok %d benchmark finished\n", i+1 );
	}
	print_summary( REPEATS, REPEATS );
}
