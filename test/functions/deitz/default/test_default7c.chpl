proc foo(x : int = 2, y : int = x * x) : int {
  return x + y;
}

writeln(foo(y=20));
