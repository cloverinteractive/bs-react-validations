[@react.component]
let make = (~children, ~className="", ~style=ReactDOMRe.Style.make(), ()) => {
  let messageClass =
    String.length(className) < 1 ? Styles.errorMessage : className;

  <label className=messageClass style> children </label>;
};
