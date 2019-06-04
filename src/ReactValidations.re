open BsUuid;
open Hooks;

type renderState = {
  inputClass: string,
  inputId: string,
  validate: ReactEvent.Keyboard.t => unit,
};

type renderProp = renderState => ReasonReact.reactElement;

[@react.component]
let make =
    (
      ~children: ReasonReact.reactElement=React.null,
      ~id: string="",
      ~label: string="",
      ~render: renderProp,
      ~startValid: bool=true,
      ~validation: Validations.t,
    ) => {
  let {isValid, isTouched, validate} = useValidations(startValid);

  let inputId =
    String.length(id) > 1 ? id : Uuid.V4.create() |> Uuid.V4.toString;

  let handleValidation = event =>
    event->ReactEvent.Keyboard.target##value |> validate(validation);

  <div className=Styles.withValidation role="presentation">
    <label className=Styles.label htmlFor=inputId>
      label->React.string
      <div className={Styles.styledInput(isTouched, isValid)}>
        <div className={Styles.styledInnerInput(isTouched, isValid)}>
          {
            render({
              inputClass: Styles.validatableInput,
              inputId,
              validate: handleValidation,
            })
          }
        </div>
        {isValid ? React.null : children}
      </div>
    </label>
  </div>;
};
