[@react.component]
let make = (~children, ~className="", ~style=ReactDOMRe.Style.make(), ()) => {
  let messageClass =
    String.length(className) < 1 ? Styles.errorMessage : className;

  <span className=messageClass style> children </span>;
};
