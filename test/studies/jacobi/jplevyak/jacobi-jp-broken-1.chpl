var m = 3, n = 4;
var D = [1..m, 1..n];
var a : [D] float = 0.0;
var epsilon = 0.01;

writeln("initial = ", a);

var X = [0..m+1, 0..n+1];
var t : [X] float = 0.0;
[i in 0..n+1] t(m+1, i) = 1.0; // bottom
var stencil = (/ (-1,-1), (1, -1), (-1, 1), (1, 1) /);

//label again;
do {
[i in D] t(i) = a(i);
[i in D] a(i) = 0.0;
for i in D do for c in stencil do a(i) += t(i(1) + c(1), i(2) + c(2))/4.0;
var d : [D] float;
[i in D] d(i) = fabs(a(i) - t(i));
} while ((max(float) reduce d) < epsilon);
//if ((max(float) reduce d) > epsilon) goto again;

writeln("final = ", a);
