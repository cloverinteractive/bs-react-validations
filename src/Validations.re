let emailExpr = [%re "/^([a-z0-9_\-.])+@([a-z0-9_\-.])+\.([a-z]{2,4})$/i"];

let isGreater = (x: option(int), value: float): bool =>
  switch (x) {
  | Some(x') => float_of_int(x') > value
  | None => true
  };

let isLower = (x: option(int), value: float): bool =>
  switch (x) {
  | Some(x') => float_of_int(x') < value
  | None => true
  };

/* Check if value is email */
let email = (value: string): bool => Js.Re.test_(emailExpr, value);

/* Check value's min lenght */
let length = (~min: int=5, (), value: string): bool =>
  String.length(value) >= min;

/* Check if value is a number */
let numericality = (value: string): bool =>
  !value->Js.Float.fromString->Js.Float.isNaN;

let presence = length(~min=1, ());

/* Check if value is included in a list */
let inclusion = (xs: list(string), x: string): bool =>
  xs |> List.filter(x' => x' == x) |> List.length >= 1;

/* Check if value is numeric and between two numbers */
let limit = (~min: option(int)=?, ~max: option(int)=?, (), value: string) =>
  if (numericality(value)) {
    let parsed = value->Js.Float.fromString;
    isLower(min, parsed) && isGreater(max, parsed);
  } else {
    false;
  };
