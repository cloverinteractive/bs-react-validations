type validate = (Validations.t, string) => unit;

type touchHook = {
  isTouched: bool,
  touch: unit => unit,
};

type validationHook = {
  isValid: bool,
  isTouched: bool,
  validate,
};

let useTouch = (defaultState: bool): touchHook => {
  let (isTouched, dispatch) = React.useState(() => defaultState);

  let touch = () => dispatch(_ => true);

  {isTouched, touch};
};

let useValidations = (startValid: bool): validationHook => {
  let (isValid, dispatch) = React.useState(() => startValid);
  let {isTouched, touch} = useTouch(!startValid);

  let validate = (validation, value) => {
    touch();
    dispatch(_ => validation(value));
  };

  {isValid, isTouched, validate};
};
