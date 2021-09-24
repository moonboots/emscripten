typedef int (*myfunc_type)();

static int mydata[10] = { 44 };

static int myfunc() {
  return 43;
}

// Exposing the address of `mydata` in this way forces it to
// be present in the .data segment with it address caclulated
// relative the `__memory_base` at which the DSO is loaded.
int* side_data_address() {
  return mydata;
}

// Exposing the address of `mydata` in this way forces it to
// be present in static table region on the DSO and its
// address will be calulated relative to the `__table_base`
// at which the DSO is loaded.
myfunc_type side_func_address() {
  return &myfunc;
}
