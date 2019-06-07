open Jest;
open Validations;

describe("Validations", () => {
  describe("isEmail", () => {
    open Expect;

    test("it returns false if not isEmail", () =>
      expect(isEmail("invalid")) |> toBe(false)
    );

    test("it returns true if isEmail is valid", () =>
      expect(isEmail("valid@domain.tld")) |> toBe(true)
    );
  });

  describe("hasLength", () => {
    open Expect;

    describe("with min", () => {
      test("return true if greater or equal to min", () =>
        expect("foo" |> hasLength(~min=3, ())) |> toBe(true)
      );

      test("return false if lower than min", () =>
        expect("foo" |> hasLength(~min=5, ())) |> toBe(false)
      );
    });

    describe("with max", () => {
      test("return true if lower or equal to max", () =>
        expect("foo" |> hasLength(~max=3, ())) |> toBe(true)
      );

      test("return false if greater than max", () =>
        expect("foo" |> hasLength(~max=2, ())) |> toBe(false)
      );
    });

    describe("with min and max", () => {
      test("return true if within hasLimit", () =>
        expect("foo" |> hasLength(~min=1, ~max=5, ())) |> toBe(true)
      );

      test("return false if outside of hasLimit (gt)", () =>
        expect("foobar" |> hasLength(~min=1, ~max=3, ())) |> toBe(false)
      );

      test("return false if outside of hasLimit (lt)", () =>
        expect("foo" |> hasLength(~min=5, ~max=10, ())) |> toBe(false)
      );
    });
  });

  describe("isPresent", () => {
    open Expect;

    test("it returns false if hasLength is not greater or equal to 1", () =>
      expect(isPresent("")) |> toBe(false)
    );

    test("it returns true if hasLength is ad least equal to 1", () =>
      expect(isPresent("foo")) |> toBe(true)
    );
  });

  describe("isNumber", () => {
    open Expect;

    test("it returns false if value is not a number", () =>
      expect(isNumber("foo")) |> toBe(false)
    );

    test("it returns true if value is a number", () =>
      expect(isNumber("123")) |> toBe(true)
    );
  });

  describe("hasLimit", () => {
    open Expect;

    describe("with min", () => {
      test("it returns false if less than min", () =>
        expect("1" |> hasLimit(~min=5, ())) |> toBe(false)
      );

      test("it returns true if greater or equal than min", () =>
        expect("5" |> hasLimit(~min=1, ())) |> toBe(true)
      );
    });

    describe("with max", () => {
      test("it return false when more than max", () =>
        expect("10" |> hasLimit(~max=5, ())) |> toBe(false)
      );

      test("it returns true when less or equal than max", () =>
        expect("5" |> hasLimit(~max=10, ())) |> toBe(true)
      );
    });

    describe("with min and max", () => {
      test("it returns false when outside hasLimit (lt)", () =>
        expect("1" |> hasLimit(~min=5, ~max=10, ())) |> toBe(false)
      );

      test("it returns false when outside hasLimit (gt)", () =>
        expect("10" |> hasLimit(~min=1, ~max=5, ())) |> toBe(false)
      );

      test("it returns true when within hasLimit", () =>
        expect("5" |> hasLimit(~min=1, ~max=10, ())) |> toBe(true)
      );
    });
  });

  describe("isIncluded", () => {
    open Expect;
    let filters = ["apple", "orange", "banana"];

    test("it returns false if not in list", () =>
      expect("pineapple" |> isIncluded(filters)) |> toBe(false)
    );

    test("it returns true if in list", () =>
      expect("apple" |> isIncluded(filters)) |> toBe(true)
    );
  });
});
