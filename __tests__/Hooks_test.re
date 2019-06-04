open Jest;
open Expect;
open Hooks;

open ReasonHooksTestingLibrary.Testing;

let initialState: bool = true;

describe("useValidations", () => {
  open Result;

  let container = renderHook(() => useValidations(initialState));

  test("isValid matches initialState", () =>
    expect(container->result->current.isValid) |> toEqual(initialState)
  );

  test("isValid will be false if validation fails", () => {
    act(() =>
      container->result->current.validate(Validations.isEmail, "invalid")
    );
    expect(container->result->current.isValid) |> toBe(false);
  });

  test("isValid will be true if validation succeeds", () => {
    act(() =>
      container->result->current.validate(
        Validations.isEmail,
        "valid@domain.tld",
      )
    );
    expect(container->result->current.isValid) |> toBe(true);
  });
});
