type validate = (Validations.t, string) => unit;

type validationHook = {
  isValid: bool,
  validate,
};

let useValidations = (startValid: bool): validationHook => {
  let (isValid, dispatch) = React.useState(() => startValid);

  let validate = (validation, value) => dispatch(_ => validation(value));

  {isValid, validate};
};
