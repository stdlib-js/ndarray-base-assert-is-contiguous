<!--

@license Apache-2.0

Copyright (c) 2018 The Stdlib Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

-->


<details>
  <summary>
    About stdlib...
  </summary>
  <p>We believe in a future in which the web is a preferred environment for numerical computation. To help realize this future, we've built stdlib. stdlib is a standard library, with an emphasis on numerical and scientific computation, written in JavaScript (and C) for execution in browsers and in Node.js.</p>
  <p>The library is fully decomposable, being architected in such a way that you can swap out and mix and match APIs and functionality to cater to your exact preferences and use cases.</p>
  <p>When you use stdlib, you can be absolutely certain that you are using the most thorough, rigorous, well-written, studied, documented, tested, measured, and high-quality code out there.</p>
  <p>To join us in bringing numerical computing to the web, get started by checking us out on <a href="https://github.com/stdlib-js/stdlib">GitHub</a>, and please consider <a href="https://opencollective.com/stdlib">financially supporting stdlib</a>. We greatly appreciate your continued support!</p>
</details>

# isContiguous

[![NPM version][npm-image]][npm-url] [![Build Status][test-image]][test-url] [![Coverage Status][coverage-image]][coverage-url] <!-- [![dependencies][dependencies-image]][dependencies-url] -->

> Determine if an array is contiguous.

<!-- Section to include introductory text. Make sure to keep an empty line after the intro `section` element and another before the `/section` close. -->

<section class="intro">

An array is **contiguous** if the memory address of each array element is adjacent to the memory address of the next array element.

</section>

<!-- /.intro -->

<!-- Package usage documentation. -->



<section class="usage">

## Usage

```javascript
import isContiguous from 'https://cdn.jsdelivr.net/gh/stdlib-js/ndarray-base-assert-is-contiguous@v0.2.1-esm/index.mjs';
```

#### isContiguous( shape, strides, offset )

Returns a `boolean` indicating if an array is contiguous.

```javascript
var shape = [ 2, 2 ];
var strides = [ 2, 1 ];
var offset = 25;

var bool = isContiguous( shape, strides, offset );
// returns true

shape = [ 10 ];
strides = [ 3 ]; // every third memory element
offset = 0;

bool = isContiguous( shape, strides, offset );
// returns false
```

</section>

<!-- /.usage -->

<!-- Package usage notes. Make sure to keep an empty line after the `section` element and another before the `/section` close. -->

<section class="notes">

</section>

<!-- /.notes -->

<!-- Package usage examples. -->

<section class="examples">

## Examples

<!-- eslint no-undef: "error" -->

```html
<!DOCTYPE html>
<html lang="en">
<body>
<script type="module">

import discreteUniform from 'https://cdn.jsdelivr.net/gh/stdlib-js/random-base-discrete-uniform@esm/index.mjs';
import shape2strides from 'https://cdn.jsdelivr.net/gh/stdlib-js/ndarray-base-shape2strides@esm/index.mjs';
import strides2offset from 'https://cdn.jsdelivr.net/gh/stdlib-js/ndarray-base-strides2offset@esm/index.mjs';
import randu from 'https://cdn.jsdelivr.net/gh/stdlib-js/random-base-randu@esm/index.mjs';
import isContiguous from 'https://cdn.jsdelivr.net/gh/stdlib-js/ndarray-base-assert-is-contiguous@v0.2.1-esm/index.mjs';

var strides;
var offset;
var shape;
var bool;
var i;
var j;

shape = [ 0, 0, 0 ];

for ( i = 0; i < 100; i++ ) {
    // Generate a random array shape:
    shape[ 0 ] = discreteUniform( 1, 10 );
    shape[ 1 ] = discreteUniform( 1, 10 );
    shape[ 2 ] = discreteUniform( 1, 10 );

    // Generate strides:
    if ( randu() < 0.5 ) {
        strides = shape2strides( shape, 'row-major' );
    } else {
        strides = shape2strides( shape, 'column-major' );
    }
    j = discreteUniform( 0, shape.length-1 );
    strides[ j ] *= ( randu() < 0.5 ) ? -1 : 1;

    strides[ 0 ] *= discreteUniform( 1, 2 ); // if scaled by 1, then single segment

    // Compute the index offset:
    offset = strides2offset( shape, strides ) + 25; // include a view offset

    // Determine if the array is contiguous:
    bool = isContiguous( shape, strides, offset );
    console.log( 'Shape: %s. Strides: %s. Offset: %d. Contiguous: %s.', shape.join( 'x' ), strides.join( ',' ), offset, bool );
}

</script>
</body>
</html>
```

</section>

<!-- /.examples -->

<!-- Section to include cited references. If references are included, add a horizontal rule *before* the section. Make sure to keep an empty line after the `section` element and another before the `/section` close. -->

<section class="references">

</section>

<!-- /.references -->

<!-- Section for related `stdlib` packages. Do not manually edit this section, as it is automatically populated. -->

<section class="related">

</section>

<!-- /.related -->

<!-- Section for all links. Make sure to keep an empty line after the `section` element and another before the `/section` close. -->


<section class="main-repo" >

* * *

## Notice

This package is part of [stdlib][stdlib], a standard library with an emphasis on numerical and scientific computing. The library provides a collection of robust, high performance libraries for mathematics, statistics, streams, utilities, and more.

For more information on the project, filing bug reports and feature requests, and guidance on how to develop [stdlib][stdlib], see the main project [repository][stdlib].

#### Community

[![Chat][chat-image]][chat-url]

---

## License

See [LICENSE][stdlib-license].


## Copyright

Copyright &copy; 2016-2024. The Stdlib [Authors][stdlib-authors].

</section>

<!-- /.stdlib -->

<!-- Section for all links. Make sure to keep an empty line after the `section` element and another before the `/section` close. -->

<section class="links">

[npm-image]: http://img.shields.io/npm/v/@stdlib/ndarray-base-assert-is-contiguous.svg
[npm-url]: https://npmjs.org/package/@stdlib/ndarray-base-assert-is-contiguous

[test-image]: https://github.com/stdlib-js/ndarray-base-assert-is-contiguous/actions/workflows/test.yml/badge.svg?branch=v0.2.1
[test-url]: https://github.com/stdlib-js/ndarray-base-assert-is-contiguous/actions/workflows/test.yml?query=branch:v0.2.1

[coverage-image]: https://img.shields.io/codecov/c/github/stdlib-js/ndarray-base-assert-is-contiguous/main.svg
[coverage-url]: https://codecov.io/github/stdlib-js/ndarray-base-assert-is-contiguous?branch=main

<!--

[dependencies-image]: https://img.shields.io/david/stdlib-js/ndarray-base-assert-is-contiguous.svg
[dependencies-url]: https://david-dm.org/stdlib-js/ndarray-base-assert-is-contiguous/main

-->

[chat-image]: https://img.shields.io/gitter/room/stdlib-js/stdlib.svg
[chat-url]: https://app.gitter.im/#/room/#stdlib-js_stdlib:gitter.im

[stdlib]: https://github.com/stdlib-js/stdlib

[stdlib-authors]: https://github.com/stdlib-js/stdlib/graphs/contributors

[umd]: https://github.com/umdjs/umd
[es-module]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Modules

[deno-url]: https://github.com/stdlib-js/ndarray-base-assert-is-contiguous/tree/deno
[deno-readme]: https://github.com/stdlib-js/ndarray-base-assert-is-contiguous/blob/deno/README.md
[umd-url]: https://github.com/stdlib-js/ndarray-base-assert-is-contiguous/tree/umd
[umd-readme]: https://github.com/stdlib-js/ndarray-base-assert-is-contiguous/blob/umd/README.md
[esm-url]: https://github.com/stdlib-js/ndarray-base-assert-is-contiguous/tree/esm
[esm-readme]: https://github.com/stdlib-js/ndarray-base-assert-is-contiguous/blob/esm/README.md
[branches-url]: https://github.com/stdlib-js/ndarray-base-assert-is-contiguous/blob/main/branches.md

[stdlib-license]: https://raw.githubusercontent.com/stdlib-js/ndarray-base-assert-is-contiguous/main/LICENSE

</section>

<!-- /.links -->
