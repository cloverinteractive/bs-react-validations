open Jest;
open Validations;

describe("Validations", () => {
  describe("email", () => {
    open Expect;

    test("it returns false if not email", () =>
      expect(email("invalid")) |> toBe(false)
    );

    test("it returns true if email is valid", () =>
      expect(email("valid@domain.tld")) |> toBe(true)
    );
  });

  describe("length", () => {
    open Expect;

    describe("with min", () => {
      test("return true if greater or equal to min", () =>
        expect("foo" |> length(~min=3, ())) |> toBe(true)
      );

      test("return false if lower than min", () => 
        expect("foo" |> length(~min=5, ())) |> toBe(false)
      );
    });

    describe("with max", () => {
      test("return true if lower or equal to max", () =>
        expect("foo" |> length(~max=3, ())) |> toBe(true)
      );

      test("return false if greater than max", () =>
        expect("foo" |> length(~max=2, ())) |> toBe(false)
      );
    });

    describe("with min and max", () => {
      test("return true if within limit", () => 
        expect("foo" |> length(~min=1, ~max=5, ())) |> toBe(true)
      );

      test("return false if outside of limit (gt)", () =>
        expect("foobar" |> length(~min=1, ~max=3, ())) |> toBe(false)
      );

      test("return false if outside of limit (lt)", () =>
        expect("foo" |> length(~min=5, ~max=10, ())) |> toBe(false)
      );
    });
  });

  describe("presence", () => {
    open Expect;

    test("it returns false if length is not greater or equal to 1", () =>
      expect(presence("")) |> toBe(false)
    );

    test("it returns true if length is ad least equal to 1", () =>
      expect(presence("foo")) |> toBe(true)
    );
  });

  describe("numericality", () => {
    open Expect;

    test("it returns false if value is not a number", () =>
      expect(numericality("foo")) |> toBe(false)
    );

    test("it returns true if value is a number", () =>
      expect(numericality("123")) |> toBe(true)
    );
  });

  describe("limit", () => {
    open Expect;

    describe("with min", () => {
      test("it returns false if less than min", () =>
        expect("1" |> limit(~min=5, ())) |> toBe(false)
      );

      test("it returns true if greater or equal than min", () =>
        expect("5" |> limit(~min=1, ())) |> toBe(true)
      );
    });

    describe("with max", () => {
      test("it return false when more than max", () =>
        expect("10" |> limit(~max=5, ())) |> toBe(false)
      );

      test("it returns true when less or equal than max", () =>
        expect("5" |> limit(~max=10, ())) |> toBe(true)
      );
    });

    describe("with min and max", () => {
      test("it returns false when outside limit (lt)", () =>
        expect("1" |> limit(~min=5, ~max=10, ())) |> toBe(false)
      );

      test("it returns false when outside limit (gt)", () =>
        expect("10" |> limit(~min=1, ~max=5, ())) |> toBe(false)
      );

      test("it returns true when within limit", () =>
        expect("5" |> limit(~min=1, ~max=10, ())) |> toBe(true)
      );
    });
  });

  describe("inclusion", () => {
    open Expect;
    let filters = ["apple", "orange", "banana"];

    test("it returns false if not in list", () =>
      expect("pineapple" |> inclusion(filters)) |> toBe(false)
    );

    test("it returns true if in list", () =>
      expect("apple" |> inclusion(filters)) |> toBe(true)
    );
  });
});
